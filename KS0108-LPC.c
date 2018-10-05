/************************************************************************
* Project : Multi Task Monitoring and Logger System
* Version : V0.9 - MMC
* Date    : 05/19/2011
* Author  : Erfan Jazeb Nikoo
* Compiler: KEIL uVision V4.01
* Chip type           : LPC2368 NXP ARM7
* Clock frequency     : 12.000000 MHz
************************************************************************/

#include "LPC23xx.h"

#define GLCD_DATA_DIR		FIO1DIR
#define GLCD_DATA_PIN		FIO1PIN
#define GLCD_DATA_SET		FIO1SET
#define GLCD_DATA_CLR		FIO1CLR

#define GLCD_D0				0
  
#define GLCD_RS				(1 << 3)
#define GLCD_RW				(1 << 2)
#define GLCD_EN				(1 << 29)

#define GLCD_CS1			(1 << 16)
#define GLCD_CS2			(1 << 17)
#define GLCD_CS3			(1 << 17)
#define GLCD_RST			(1 << 6)

#define DISPLAY_STATUS_BUSY	0x80
					   	
#define DELAY    			 0

extern unsigned char screen_x;
extern unsigned char screen_y;

//////////////////////////////////////////////////////////////////////////
  
void delay(int counter)
{
int i;
for( i = 0 ; i < counter ; i++);
}

//////////////////////////////////////////////////////////////////////////
void SetData(unsigned char Port_Value)
{

FIO1CLR |= 0xFFFF;

if(Port_Value & 0x01)
	FIO1SET |= (1<<0);
if(Port_Value & 0x02)
	FIO1SET |= (1<<1);
if(Port_Value & 0x04)
	FIO1SET |= (1<<4);
if(Port_Value & 0x08)
	FIO1SET |= (1<<8);
if(Port_Value & 0x10)
	FIO1SET |= (1<<9);
if(Port_Value & 0x20)
	FIO1SET |= (1<<10);
if(Port_Value & 0x40)
	FIO1SET |= (1<<14);
if(Port_Value & 0x80)
	FIO1SET |= (1<<15);

}

/////////////////////////////////////////////////////////////////////////

void LatchLCD()   
{

FIO4SET |= GLCD_EN; 
delay(100);
FIO4CLR |= GLCD_EN; 	

}

//////////////////////////////////////////////////////////////////////////
void GLCD_EnableController(unsigned char chip)
{
switch(chip)
{
	case 0 : FIO1SET = GLCD_CS1; break;
	case 1 : FIO1SET = GLCD_CS2; break;
}
}

//////////////////////////////////////////////////////////////////////////

void GLCD_DisableController(unsigned char chip)
{
switch(chip)
{
	case 0 : FIO1CLR = GLCD_CS1; break;
	case 1 : FIO1CLR = GLCD_CS2; break;
}
} 

//////////////////////////////////////////////////////////////////////////
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char chip)
{

FIO0CLR |= (GLCD_RS | GLCD_RW);
GLCD_EnableController(chip);
SetData(commandToWrite);
LatchLCD();
GLCD_DisableController(chip);

}

//////////////////////////////////////////////////////////////////////////

void GLCD_WriteData(unsigned char dataToWrite)
{

FIO0CLR |= GLCD_RW;
FIO0SET |= GLCD_RS;

SetData(dataToWrite);
GLCD_EnableController(screen_x / 64);
LatchLCD();
GLCD_DisableController(screen_x / 64);
screen_x++;

}

//////////////////////////////////////////////////////////////////////////

void GLCD_InitalizePorts(void)
{
  
FIO0DIR |= ( GLCD_RS | GLCD_RW | GLCD_RST );
FIO1DIR |= ( GLCD_CS1 | GLCD_CS2 );
FIO4DIR |= GLCD_EN;
FIO1DIR	|= 0xFFFF;

FIO0CLR |= GLCD_RST;
delay(100);
FIO0SET |= GLCD_RST; 
SetData(0x3F);

}

////////////////////////////////////////////////////////////////////////// 

unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
return *(ptr);
}

//////////////////////////////////////////////////////////////////////////
