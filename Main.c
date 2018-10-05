/************************************************************************
* Project : Multi Task Monitoring and Logger System
* Version : V0.6
* Date    : 03/30/2011
* Author  : Erfan Jazeb Nikoo
* Compiler: KEIL uVision V4.01
* Chip type           : LPC2368 NXP ARM7
* Clock frequency     : 12.000000 MHz
************************************************************************/

#include "initialization.h"

char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int CounterFlag = 0;
FILE *f;
BOOL append=0;
char Temp[40];
U32 TimeTemp;
char fname[40];

/*------------------------------------------------------------------------------
  convert one byte to string in hexadecimal notation
 *------------------------------------------------------------------------------*/
void Hex_Str (unsigned char hex, char *str) {
  *str++ = '0';
  *str++ = 'x';
  *str++ = hex_chars[hex >>  4];
  *str++ = hex_chars[hex & 0xF];
}

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Interrupt /////////////////////////////////////////

void FlagCounter(void) __irq {

CounterFlag++;
T1IR = 0x01;
VICVectAddr = 0;		/* Acknowledge Interrupt */

}

/*----------------------------------------------------------------------------
 *        Main: 
 *---------------------------------------------------------------------------*/
int main (void) {

main_init();
GLCD_ClearScreen();						
Welcome();
for(;;){

	Can_Rx();
	Multi_Tasking();
	Can_Tx (SendToCan());


 }
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
