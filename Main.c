/************************************************************************
* Project : Multi Task Monitoring and Logger System
* Version : V0.9 - MMC
* Date    : 05/19/2011
* Author  : Erfan Jazeb Nikoo
* Compiler: KEIL uVision V4.01
* Chip type           : LPC2368 NXP ARM7
* Clock frequency     : 12.000000 MHz
************************************************************************/

#include "initialization.h"

char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int CounterFlag = 0;
char clock[30],date[30];
int year = 0;
int month = 0;
int day = 0;
int hour = 0;
int min = 0;
int sec = 0;


/*------------------------------------------------------------------------------
  convert one byte to string in hexadecimal notation
 *------------------------------------------------------------------------------*/
void Hex_Str (unsigned char hex, char *str) {
//  *str++ = '0';
//  *str++ = 'x';
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


void ReadRTC(void) __irq{


//Clear Interrupt
RTC_ILR |= 1;
//Read Time registers
hour = (RTC_CTIME0 & 0x3F0000)>>16; //MASKHR:0x1f0000
min = (RTC_CTIME0 & 0X3F00)>>8;//MASKMIN:0X3F00
sec = (RTC_CTIME0 & 0X3F); // MASKSEC:0X3F
year = (RTC_CTIME1)>>16;
month = (RTC_CTIME1 & 0X3F00)>>8;
day = (RTC_CTIME1 & 0X3F);

sprintf(clock,"Time: %02d:%02d:%02d",hour,min,sec);
sprintf(date,"Date: %02d/%02d/%04d",month,day,year);

//updateing VIC
VICVectAddr = 0;

}


/*----------------------------------------------------------------------------
 *        Main: 
 *---------------------------------------------------------------------------*/
int main (void) {

char counter[30];


main_init();
GLCD_ClearScreen();						
Welcome();
//sprintf(fname,"%02d_%02d_%02d.txt",hour,min,sec);
//    f = fopen (fname,append ? "a" : "w");
//	temp = sec;
//	fclose(f);
for(;;){
	
	Can_Rx();
	Multi_Tasking();
	Can_Tx (SendToCan());

 }
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
