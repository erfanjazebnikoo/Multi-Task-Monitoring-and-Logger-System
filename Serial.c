/*----------------------------------------------------------------------------
 *      R T L   F l a s h   F i l e   S y s t e m   E x a m p l e
 *----------------------------------------------------------------------------
 *      Name:    SERIAL.C
 *      Purpose: Serial Input Output for Philips LPC23xx
 *      Rev.:    V3.20
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2008 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include "LPC23xx.H"                    /* LPC23xx definitions               */

/*----------------------------------------------------------------------------
 *       init_serial:  Initialize Serial Interface
 *---------------------------------------------------------------------------*/
void init_serial (void) {
   /* Initialize the serial interface */

   /* Configure UART1 for 115200 baud. */
   PINSEL0 &= ~0xC0000000;
   PINSEL0 |=  0x40000000;                   /* Enable TxD1 pin              */
   PINSEL1 &= ~0x00000003;
   PINSEL1 |=  0x00000001;                   /* Enable RxD1 pin              */

   U1LCR = 0x83;                             /* 8 bits, no Parity, 1 Stop bit*/
   U1DLL = 3;                                /* for 12MHz PCLK Clock         */
   U1FDR = 0x67;                             /* Fractional Divider           */
   U1LCR = 0x03;                             /* DLAB = 0                     */
}

/*----------------------------------------------------------------------------
 *       sendchar:  Write a character to Serial Port
 *---------------------------------------------------------------------------*/
int sendchar (int ch) {
   if (ch == '\n') {
      while (!(U1LSR & 0x20));
      U1THR = '\r';
   }
   while (!(U1LSR & 0x20));
   return (U1THR = ch);
}

/*----------------------------------------------------------------------------
 *       getkey:  Read a character from Serial Port
 *---------------------------------------------------------------------------*/
int getkey (void) {
   while (!(U1LSR & 0x01));
   return (U1RBR);
}

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/


