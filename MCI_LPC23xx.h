/*----------------------------------------------------------------------------
 *      R T L  -  F l a s h   F i l e   S y s t e m
 *----------------------------------------------------------------------------
 *      Name:    MCI_LPC23XX.H 
 *      Purpose: Multimedia Card Interface Driver for LPC23xx definitions
 *      Rev.:    V3.21
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2008 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#ifndef __MCI_LPC23XX_H
#define __MCI_LPC23XX_H

/* Macros for compatibility with existing SPI interface. */
#define mci_init        mmc_init
#define mci_read_sect   mmc_read_sect
#define mci_write_sect  mmc_write_sect
#define mci_read_config mmc_read_config

/* SD Card communication speed */
#define SD_CLK              24000000

/* Expected Response from mci_command */
#define RESP_NONE           0
#define RESP_SHORT          1
#define RESP_LONG           2

/* MMC/SD Commands */
#define GO_IDLE_STATE       0       /* Resetthe card to idle state  (MMC,SD) */
#define SEND_OP_COND        1       /* Send Op.Cond. Register       (MMC)    */
#define ALL_SEND_CID        2       /* Send Card CID number         (MMC,SD) */
#define SET_RELATIVE_ADDR   3       /* Set Relative Address         (MMC,SD) */
#define SET_ACMD_BUS_WIDTH  6
#define SELECT_CARD         7       /* Select/Deselect the Card     (MMC,SD) */
#define SEND_CSD            9       /* Send Card Specific Data      (MMC,SD) */
#define SEND_CID            10      /* Send Card Identification Data(MMC,SD) */
#define STOP_TRANSMISSION   12      /* Stop Read or Write transm.   (MMC,SD) */
#define SEND_STATUS         13      /* Send Status Resiger          (MMC,SD) */
#define SET_BLOCK_LEN       16      /* Set Block Length in bytes    (MMC,SD) */
#define READ_BLOCK          17      /* Read a Single Block          (MMC,SD) */
#define READ_MULT_BLOCK     18      /* Read Multiple Blocks         (MMC,SD) */
#define WRITE_BLOCK         24      /* Write a Block                (MMC,SD) */
#define WRITE_MULT_BLOCK    25      /* Write Multiple Blocks        (MMC,SD) */
#define SEND_APP_OP_COND    41      /* Send App. Op.Cond Register       (SD) */
#define APP_CMD             55      /* App.Specific Command follow  (MMC,SD) */

/* Card Status definitions */
#define STAT_ACMD_ENABLE    0x00000020
#define STAT_RDY_DATA       0x00000100
#define STAT_CURRENT_STATE  0x00001E00
#define STAT_ERASE_RESET    0x00002000

/* SD Card Bus Width definitions */
#define BUS_WIDTH_1BIT      0
#define BUS_WIDTH_4BITS     10

/* MMC/SD definitions */
#define OCR_INDEX           0x00FF8000

/* MCI Status register bit information */
#define MCI_CMD_CRC_FAIL    0x00000001
#define MCI_DATA_CRC_FAIL   0x00000002
#define MCI_CMD_TIMEOUT     0x00000004
#define MCI_DATA_TIMEOUT    0x00000008
#define MCI_TX_UNDERRUN     0x00000010
#define MCI_RX_OVERRUN      0x00000020
#define MCI_CMD_RESP_END    0x00000040
#define MCI_CMD_SENT        0x00000080
#define MCI_DATA_END        0x00000100
#define MCI_START_BIT_ERR   0x00000200
#define MCI_DATA_BLK_END    0x00000400
#define MCI_CMD_ACTIVE      0x00000800
#define MCI_TX_ACTIVE       0x00001000
#define MCI_RX_ACTIVE       0x00002000
#define MCI_TX_HALF_EMPTY   0x00004000
#define MCI_RX_HALF_FULL    0x00008000
#define MCI_TX_FIFO_FULL    0x00010000
#define MCI_RX_FIFO_FULL    0x00020000
#define MCI_TX_FIFO_EMPTY   0x00040000
#define MCI_RX_FIFO_EMPTY   0x00080000
#define MCI_TX_DATA_AVAIL   0x00100000
#define MCI_RX_DATA_AVAIL   0x00200000

#define MCI_RESP_INVALID    0xFFFFFFFF
#define MCI_CLEAR_MASK      0x000007FF

/* General mode definitions */
#define LOW_SPEED           0
#define HIGH_SPEED          1
#define OPEN_DRAIN_MODE     0
#define PUSH_PULL_MODE      1
#define DMA_READ            0
#define DMA_WRITE           1

#define DATA_RD_TOUT_VALUE  (10*(SD_CLK/1000))  /* ~10ms  at 24MHz SD clock */
#define DATA_WR_TOUT_VALUE  (200*(SD_CLK/1000)) /* ~200ms at 24MHz SD clock */

#endif

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
