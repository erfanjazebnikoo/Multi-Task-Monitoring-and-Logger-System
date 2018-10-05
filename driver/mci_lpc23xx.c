/*----------------------------------------------------------------------------
 *      R T L  -  F l a s h   F i l e   S y s t e m
 *----------------------------------------------------------------------------
 *      Name:    MCI_LPC23XX.C 
 *      Purpose: Multimedia Card Interface Driver for LPC23xx
 *      Rev.:    V3.21
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2008 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <File_Config.h>
#include "LPC23xx.h"                 /* LPC23xx/24xx definitions             */
#include "MCI_LPC23xx.h"

/* Wait timeouts, in multiples of 6 byte send over MCI (for 1 bit mode)      */
#define WR_TOUT           100000     /* ~ 200 ms with MCI clk 24MHz */
#define RD_STOP_TOUT      100        /* ~ 200 us with MCI clk 24MHz */

/* Wait time in for loop cycles */
#define DMA_TOUT          10000


/* Local variables */
static U8  CardType;
static U16 CardRCA;
static U32 sernum;

/*----------------------------------------------------------------------------
 *      MMC Driver Functions
 *----------------------------------------------------------------------------
 *  Required functions for MMC driver module:
 *   - BOOL mci_init ()
 *   - BOOL mci_read_sect (U32 sect, U8 *buf, U32 cnt)
 *   - BOOL mci_write_sect (U32 sect, U8 *buf, U32 cnt)
 *   - BOOL mmc_read_config (MMCFG *cfg)
 *---------------------------------------------------------------------------*/

/* Local Function Prototypes */
static void mci_set_speed (U32 speed);
static void mci_bus_mode (U32 mode);
static BOOL mci_send_acmd (void);
static BOOL mci_set_address (void);
static BOOL mci_read_cid (void);
static BOOL mci_select_card (void);
static BOOL mci_set_bus_4bit (void);
static BOOL mci_set_block_len (void);
static BOOL mci_cmd_read_block (U32 block, U32 cnt);
static BOOL mci_cmd_write_block (U32 block, U32 cnt);
static U32  mci_read_status (void);
static BOOL mci_send_stop (void);
static BOOL mci_wait_for_tran (void);
static U32  mci_command (U8 cmd, U32 arg, U32 resp, U32 *rp);
static void mci_dma_start (U32 mode, U8 *buf);

/*--------------------------- mci_init --------------------------------------*/

BOOL mci_init (void) {
   /* Initialize and enable the Flash Card. */
   U32 i,rstat,rval[4];

   /* Power Up the MCI and DMA controller. */
   PCONP |= 0x30000000;

   /* MCIPWR pin is active high. */
   /* Required for the silicon rev. 'B' and later. */
   SCS |= 0x08;

   /* Enable MCI Pins on P0,P2. */
   PINSEL1 &= ~0x00003FC0;
   PINSEL1 |=  0x00002A80;
   PINSEL4 &= ~0x0FC00000;
   PINSEL4 |=  0x0A800000;

   /* Clear all pending interrupts. */
   MCI_COMMAND   = 0;
   MCI_DATA_CTRL = 0;
   MCI_CLEAR     = 0x7FF;

   /* Power up, switch on VCC for the Flash Card. */
   MCI_POWER  = 0x02;
   for (i = 0; i < 50000; i++);

   mci_set_speed (LOW_SPEED);

   /* Power on the Flash Card. */
   MCI_POWER |= 0x01;
   for (i = 0; i < 50000; i++);

   /* Reset the card, send CMD0. */
   mci_command (GO_IDLE_STATE, 0, RESP_NONE, NULL);

   /* Set Open Drain output control for MMC */
   mci_bus_mode (OPEN_DRAIN_MODE);

   CardType = CARD_NONE;
   /* First try MMC, send CMD1. */
   for (i = 0; i < 100; i++) {
      rstat = mci_command (SEND_OP_COND, OCR_INDEX, RESP_SHORT, &rval[0]);
      if (!(rstat & MCI_CMD_TIMEOUT) && rval[0] & 0x80000000) {
         CardType = CARD_MMC;
         break;
      }
   }

   if (CardType == CARD_NONE) {
      /* Check for SD card, clear Open Drain output control. */
      mci_bus_mode (PUSH_PULL_MODE);
      for (i = 0; i < 500; i++) {
         if (mci_send_acmd () == __TRUE) {
            rstat = mci_command (SEND_APP_OP_COND, 
                                 OCR_INDEX, RESP_SHORT, &rval[0]);
            if (!(rstat & MCI_CMD_TIMEOUT) && rval[0] & 0x80000000) {
               /* OK, SD card initialized. */
               CardType = CARD_SD;
               break;
            }
         }
      }
   }
   if (CardType == CARD_NONE) {
      /* Failed, no card found. */
      goto fail;
   }

   /* Initialize the Card to SD/MMC mode. */
   if (mci_read_cid () == __FALSE) {
      goto fail;
   }
   if (mci_set_address () == __FALSE) {
      goto fail;
   }

   /* Disable Open Drain mode for MMC. */
   if (CardType == CARD_MMC) {
      mci_bus_mode (PUSH_PULL_MODE);
   }

   /* Data Transfer Mode, end of Card-Identification Mode. */
   mci_set_speed (HIGH_SPEED);

   if (mci_select_card () == __FALSE) {
      goto fail;
   }

   if (CardType == CARD_SD) {
      /* Use wide 4-bit bus for SD */
      MCI_CLOCK |= 0x0800;
      for (i = 0; i < 100; i++);
      if (mci_set_bus_4bit () == __FALSE) {
         /* Failed to enable 4-bit bus. */
         goto fail;
      }
   }
   /* Set block length to 512 bytes. */
   if (mci_set_block_len () == __FALSE) {
fail: MCI_POWER = 0x00;
      return (__FALSE);
   }

   /* Success, card initialized. */
   return (__TRUE);
}


/*--------------------------- mci_set_speed ---------------------------------*/

static void mci_set_speed (U32 speed) {
   /* Set a MCI clock speed to desired value. */
   U32 i,clkdiv;

   if (speed == HIGH_SPEED) {
      /* Max. 25 MBit used for Data Transfer. */
      clkdiv = 0;
   }
   else {
      /* Max. 400 kBit used in Card Initialization. */
      clkdiv = 240;
   }
   MCI_CLOCK = (MCI_CLOCK & ~0xFF) | 0x300 | clkdiv;

   /* delay 3MCLK + 2PCLK before next write */
   for ( i = 0; i < 100; i++ );
}


/*--------------------------- mci_bus_mode ----------------------------------*/

static void mci_bus_mode (U32 mode) {
   /* Set MCI Bus mode to Open Drain or Push Pull. */
   U32 i;

   if (mode == OPEN_DRAIN_MODE) {
      MCI_POWER |= 0x40;
   }
   else {
      MCI_POWER &= ~0x40;
   }
   /* A small delay after switching mode. */
   for (i = 0; i < 100; i++);
}


/*--------------------------- mci_send_acmd ---------------------------------*/

static BOOL mci_send_acmd (void) {
   /* Send CMD55 to enable ACMD */
   U32 arg,rstat,rval;

   arg = 0;
   if (CardType == CARD_SD) {
      /* Use address from SET_RELATIVE_ADDR. */
      arg = CardRCA << 16;
   }
   rstat = mci_command (APP_CMD, arg, RESP_SHORT, &rval);
   if (rstat == 0 && (rval & STAT_ACMD_ENABLE)) {
      return (__TRUE);
   }
   return (__FALSE);
}


/*--------------------------- mci_set_address -------------------------------*/

static BOOL mci_set_address (void) {
   /* Set Relative Address, send CMD3 after CMD2. */
   U32 i,arg,rstat,rval;

   arg = 0;
   if (CardType == CARD_MMC) {
      /* Fix the RCA address for MMC card. */
      arg = 0x00010000;
   }

   for (i = 0; i < 20; i++) {
      rstat = mci_command (SET_RELATIVE_ADDR, arg, RESP_SHORT, &rval);
      if (!(rstat & MCI_CMD_TIMEOUT) && (rval & 0x0F00) == 0x0500) {
         /* Response is back and correct. */
         CardRCA = rval >> 16;
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_read_cid ----------------------------------*/

static BOOL mci_read_cid (void) {
   /* Check CID, send CMD2 after CMD1 (MMC) or ACMD41 (SD). */
   U32 i,rstat,rval[4];

   for (i = 0; i < 20; i++) {
      rstat = mci_command (ALL_SEND_CID, 0, RESP_LONG, &rval[0]);
      if (!(rstat & MCI_CMD_TIMEOUT)) {
         /* Response is back and correct. */
         if (CardType == CARD_SD) {
            /* Serial Number for SD Card. */
            sernum = (rval[2] << 8)  | (rval[3] >> 24);
         }
         else {
            /* Serial Number for MMC Card. */
            sernum = (rval[2] << 16) | (rval[3] >> 16);
         }
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_select_card -------------------------------*/

static BOOL mci_select_card (void) {
   /* Select the Card, send CMD7 after CMD9, inter-change state */
   /* between STBY and TRANS after this command. */
   U32 i,arg,rstat,rval;

   arg = 0x00010000;
   if (CardType == CARD_SD) {
      /* Use address from SET_RELATIVE_ADDR. */
      arg = CardRCA << 16;
   }

   for (i = 0; i < 200; i++) {
      rstat = mci_command (SELECT_CARD, arg, RESP_SHORT, &rval);
      if (rstat == 0 && (rval & 0x0F00) == 0x0700) {
         /* Should be in STBY state now and ready. */
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_set_bus_4bit ------------------------------*/

static BOOL mci_set_bus_4bit (void) {
   /* Select 4-bit bus width for SD Card. */
   U32 i,rstat,rval;

   for (i = 0; i < 20; i++) {
      if (mci_send_acmd () == __FALSE) {
         continue;
      }
      /* Send ACMD6 command to set the bus width. */
      rstat = mci_command (SET_ACMD_BUS_WIDTH, BUS_WIDTH_4BITS, RESP_SHORT, &rval);
      if (rstat == 0 && (rval & 0x0F00) == 0x0900) {
         /* Response is back and correct. */
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_set_block_len -----------------------------*/

static BOOL mci_set_block_len (void) {
   /* Set block length to 512 bytes. */
   U32 i,rstat,rval;

   for (i = 0; i < 20; i++) {
      /* Send ACMD6 command to set the bus width. */
      rstat = mci_command (SET_BLOCK_LEN, 512, RESP_SHORT, &rval);
      if (rstat == 0 && (rval & 0x0F00) == 0x0900) {
         /* Response is back and correct. */
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_cmd_read_block ----------------------------*/

static BOOL mci_cmd_read_block (U32 block, U32 cnt) {
   /* Send a command to Read Single/Multiple blocks. */
   U32 i,rstat,rval;
   U8  cmd;

   cmd = READ_BLOCK;
   if (cnt > 1) {
      cmd = READ_MULT_BLOCK;
   }
   block *= 512;
   for (i = 0; i < 20; i++) {
      rstat = mci_command (cmd, block, RESP_SHORT, &rval);
      if (rstat == 0 && (rval & 0x0F00) == 0x0900) {
         /* Ready and in TRAN state. */
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_cmd_write_block ---------------------------*/

static BOOL mci_cmd_write_block (U32 block, U32 cnt) {
   /* Send a command to Write Single/Multiple block. */
   U32 i,rstat,rval;
   U8  cmd;

   cmd = WRITE_BLOCK;
   if (cnt > 1) {
      cmd = WRITE_MULT_BLOCK;
   }
   block *= 512;
   for (i = 0; i < 20; i++) {
      rstat = mci_command (cmd, block, RESP_SHORT, &rval);
      if (rstat == 0 && (rval & 0x0F00) == 0x0900) {
         /* Ready and in TRAN state. */
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_read_status -------------------------------*/

static U32 mci_read_status (void) {
   /* Read the status of Flash Card. */
   U32 i,arg,rstat,rval;

   arg = 0x00010000;
   if (CardType == CARD_SD) {
      /* Use address from SET_RELATIVE_ADDR. */
      arg = CardRCA << 16;
   }

   for (i = 0; i < 200; i++) {
      rstat = mci_command (SEND_STATUS, arg, RESP_SHORT, &rval);
      if (rstat == 0 && (rval & 0x0100)) {
         /* The Ready bit should be set, state TRAN or RCV. */
         return (rval);
      }
   }
   return (MCI_RESP_INVALID);
}


/*--------------------------- mci_send_stop ---------------------------------*/

static BOOL mci_send_stop (void) {
   /* Stop transmission, Flash Card is in wrong state. */
   U32 i,rstat,rval;

   for (i = 0; i < 20; i++) {
      rstat = mci_command (STOP_TRANSMISSION, 0, RESP_SHORT, &rval);
      if (rstat == 0 && (rval & 0x0100)) {
         /* The Ready bit should be set. */
         return (__TRUE);
      }
   }
   return (__FALSE);
}


/*--------------------------- mci_wait_for_tran -----------------------------*/

static BOOL mci_wait_for_tran (void) {
   /* Wait for Card state TRAN. */
   U32 i;

   for (i = WR_TOUT; i; i--) {
      /* Wait for Card state TRAN to continue. */
      if ((mci_read_status () & 0x0F00) == 0x0900) {
         break;
      }
   }
   if (i == 0) {
      /* Previous request has Failed. */
      mci_send_stop ();
      return (__FALSE);
   }
   return (__TRUE);
}


/*--------------------------- mmc_command -----------------------------------*/

static U32 mci_command (U8 cmd, U32 arg, U32 resp_type, U32 *rp) {
   /* Send a Command to Flash card and get a Response. */
   U32 cmdval,stat;

   cmd   &= 0x3F;
   cmdval = 0x400 | cmd;
   switch (resp_type) {
      case RESP_SHORT:
         cmdval |= 0x40;
         break;
      case RESP_LONG:
         cmdval |= 0xC0;
         break;
   }
   /* Send the command. */
   MCI_ARGUMENT = arg;
   MCI_COMMAND  = cmdval;

   if (resp_type == RESP_NONE) {
      /* Wait until command finished. */
      while (MCI_STATUS & MCI_CMD_ACTIVE);
      MCI_CLEAR = 0x7FF;
      return (0);
   }

   for (;;) {
      stat = MCI_STATUS;
      if (stat & MCI_CMD_TIMEOUT) {
         MCI_CLEAR = stat & MCI_CLEAR_MASK;
         return (stat);
      }
      if (stat & MCI_CMD_CRC_FAIL) {
         MCI_CLEAR = stat & MCI_CLEAR_MASK;
         if ((cmd == SEND_OP_COND)      ||
             (cmd == SEND_APP_OP_COND)  ||
             (cmd == STOP_TRANSMISSION)) {
            MCI_COMMAND = 0;
            break;
         }
         return (stat);
      }
      if (stat & MCI_CMD_RESP_END) {
         MCI_CLEAR = stat & MCI_CLEAR_MASK;
         break;
      }
   }
   if ((MCI_RESP_CMD & 0x3F) != cmd) {
      if ((cmd != SEND_OP_COND)     &&
          (cmd != SEND_APP_OP_COND) &&
          (cmd != ALL_SEND_CID)     &&
          (cmd != SEND_CSD))         {
         return (MCI_RESP_INVALID);
      }
   }
   if (rp == NULL) {
      /* Response pointer undefined. */
      return (MCI_RESP_INVALID);
   }
   /* Read MCI response registers */
   rp[0] = MCI_RESP0;
   if (resp_type == RESP_LONG) {
      rp[1] = MCI_RESP1;
      rp[2] = MCI_RESP2;
      rp[3] = MCI_RESP3;
   }
   return (0);
}


/*--------------------------- mci_dma_start ---------------------------------*/

static void mci_dma_start (U32 mode, U8 *buf) {
   /* Configure DMA controller Ch0 for read or write. */

   if (mode == DMA_READ) {
      /* Transfer from MCI-FIFO to memory. */
      GPDMA_CH0_SRC  = (U32)&MCI_FIFO;
      GPDMA_CH0_DEST = (U32)buf;
      /* The burst size set to 8, transfer size 512 bytes. */
      GPDMA_CH0_CTRL = (512 >> 2)   | (0x02 << 12) | (0x02 << 15) | 
                       (0x02 << 18) | (0x02 << 21) | (1 << 27)    | (1u << 31);
      GPDMA_CH0_CFG  = 0x10001 | (0x04 << 1) | (0x00 << 6) | (0x06 << 11);
   }
   else {
      /* Transfer from memory to MCI-FIFO. */
      GPDMA_CH0_SRC  = (U32)buf;
      GPDMA_CH0_DEST = (U32)&MCI_FIFO;
      /* The burst size set to 8, transfer size 512 bytes. */
      GPDMA_CH0_CTRL = (512 >> 2)   | (0x02 << 12) | (0x02 << 15) |
                       (0x02 << 18) | (0x02 << 21) | (1 << 26)    | (1u << 31);
      GPDMA_CH0_CFG  = 0x10001 | (0x00 << 1) | (0x04 << 6) | (0x05 << 11);
   }
   /* Enable DMA channels, little endian */
   GPDMA_INT_TCCLR = 0x01;
   GPDMA_CONFIG    = 0x01;
}


/*--------------------------- mci_read_sect ---------------------------------*/

BOOL mci_read_sect (U32 sect, U8 *buf, U32 cnt) {
   /* Read one or more 512 byte sectors from Flash Card. */
   U32 i;

   if (mci_wait_for_tran () == __FALSE) {
      /* Card not in TRAN state. */
      return (__FALSE);
   }

   if (mci_cmd_read_block (sect, cnt) == __FALSE) {
      /* Command Failed. */
      return (__FALSE);
   }

   /* Set MCI Transfer registers. */
   MCI_DATA_TMR  = DATA_RD_TOUT_VALUE;
   MCI_DATA_LEN  = cnt * 512;

   /* Start DMA Peripheral to Memory transfer. */
   mci_dma_start (DMA_READ, buf);
   MCI_DATA_CTRL = 0x9B;

   for (i = DMA_TOUT; i; i--) {
      if (GPDMA_RAW_INT_TCSTAT & 0x01) {
         /* Data transfer finished. */
         break;
      }
   }

   if (i == 0) {
      /* DMA Transfer timeout. */
      return (__FALSE);
   }

   if (cnt > 1) {
      /* Stop reading Multiple sectors. */
      mci_send_stop ();
   }
   return (__TRUE);
}


/*--------------------------- mci_write_sect --------------------------------*/

BOOL mci_write_sect (U32 sect, U8 *buf, U32 cnt) {
   /* Write a 512 byte sector to Flash Card. */
   U32 i,j;

   if (mci_wait_for_tran () == __FALSE) {
      /* Card not in TRAN state. */
      return (__FALSE);
   }

   if (mci_cmd_write_block (sect, cnt) == __FALSE) {
      /* Command Failed. */
      return (__FALSE);
   }

   for (j = 0; j < cnt; buf += 512, j++) {
      /* Set MCI Transfer registers. */
      MCI_DATA_TMR  = DATA_WR_TOUT_VALUE;
      MCI_DATA_LEN  = 512;

      /* Start DMA Memory to Peripheral transfer. */
      mci_dma_start (DMA_WRITE, buf);
      MCI_DATA_CTRL = 0x99;

      for (i = DMA_TOUT; i; i--) {
         if (GPDMA_RAW_INT_TCSTAT & 0x01) {
            /* Data transfer finished. */
            break;
         }
      }

      if (i == 0) {
         /* DMA Data Transfer timeout. */
         mci_send_stop ();
         /* Write request Failed. */
         return (__FALSE);
      }

      if (cnt == 1) {
         return (__TRUE);
      }

      /* Wait until Data Block sent to Card. */
      while (MCI_STATUS != (MCI_DATA_END | MCI_DATA_BLK_END)) {
         if (MCI_STATUS & (MCI_DATA_CRC_FAIL | MCI_DATA_TIMEOUT)) {
            /* If error while Data Block sending occured. */
            mci_send_stop ();
            /* Write request Failed. */
            return (__FALSE);
         }
      }
      for (i = WR_TOUT; i; i--) {
         if ((mci_read_status () & 0x0F00) == 0x0D00) {
            /* Buffer available for further sending, card state RCV. */
            break;
         }
      }
   }
   mci_send_stop ();

   /* Write request Ok. */
   return (__TRUE);
}


/*--------------------------- mci_read_config -------------------------------*/

BOOL mci_read_config (MMCFG *cfg) {
   /* Read MMC/SD Card device configuration. */
   U32 i,rstat,arg,v,m,rval[4];

   /* Wait if potential Write in progress. */
   mci_wait_for_tran ();

   /* Deselect the Card, transit to STBY state. */
   mci_command (SELECT_CARD, 0, RESP_NONE, NULL);

   /* Read the CID - Card Identification. */
   cfg->sernum = sernum;

   /* Read the CSD - Card Specific Data. */
   arg = 0x00010000;
   if (CardType == CARD_SD) {
      /* Use address from SET_RELATIVE_ADDR. */
      arg = CardRCA << 16;
   }

   for (i = 20; i; i--) {
      rstat = mci_command (SEND_CSD, arg, RESP_LONG, &rval[0]);
      if (rstat == 0) {
         /* Response is back and correct. */
         break;
      }
   }
   if (i == 0) {
      /* Read CSD failed. */
      return (__FALSE);
   }

   /* Read Block length. */
   v = (rval[1] >> 16) & 0x0F;
   cfg->read_blen = 1 << v;

   /* Write Block length */
   v = (rval[3] >> 22) & 0x0F;
   cfg->write_blen = 1 << v;

   /* Total Number of blocks */
   v = ((rval[1] << 2) | (rval[2] >> 30)) & 0x0FFF;
   m =  (rval[2] >> 15) & 0x07;
   cfg->blocknr = (v + 1) << (m + 2);

   /* Re-select the Card, back to TRAN state. */
   return (mci_select_card ());
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
