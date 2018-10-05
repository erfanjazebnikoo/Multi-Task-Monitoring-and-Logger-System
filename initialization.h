/************************************************************************
* Project : Multi Task Monitoring and Logger System
* Version : V1.0
* Date    : 06/29/2011
* Author  : Erfan Jazeb Nikoo
* Compiler: KEIL uVision V4.01
* Chip type           : LPC2368 NXP ARM7
* Clock frequency     : 12.000000 MHz
************************************************************************/

#ifndef _INITIALIZATION_H
#define _INITIALIZATION_H

#include "driver/can.h" 
#include "util/type.h"
#include "util/delay.h"
#include <stdio.h>                    /* standard I/O .h-file                */
#include <ctype.h>                    /* character functions                 */
#include <string.h>                   /* string and memory functions         */
#include "LPC23xx.h"
#include "driver/ks0108.h"
#include <stdint.h>                             /* Include standard types */                      
#include "util/tab.h"
#include "driver/tc_ad7843_v1_00.h"
#include "pic1_glcd.h"
#include "app_config.h"
#include "util/rgb_led.h"
#include "util/network.h"
#include "util/irq.h"
#include <math.h>                               /* LPC1766 CAN adaption layer */

#define Power_ID		0x20
#define Kicker_ID		0x30
#define Handeling_ID	0x40
#define BEEP 			0x16
#define Kicker_EN		0xCE
#define Handeling_EN	0xEE
#define Kicker_Pwr	10000	
#define Handeling_Spd_CW	250
#define Handeling_Spd_CCW	-250


//////////////////////////// RGB LED /////////////////////////////////

#define RGBLED_PORT		FIO1DIR
#define RGBLED_SET		FIO1SET
#define RGBLED_CLR		FIO1CLR
#define RGBLED1_B	18
#define RGBLED1_G	19
#define RGBLED1_R	20
#define RGBLED2_B	21
#define RGBLED2_G	22
#define RGBLED2_R	23


#define PCLK            18000000//HZ

////////////////////// GLCD Back Light /////////////////////////////////

#define GLCD_BCKL_PORT		FIO2DIR
#define GLCD_BCKL_SET		FIO2SET
#define GLCD_BCKL_CLR		FIO2CLR
#define GLCD_BCKL_PIN		0

/////////////////////////////////////////////////////////////////////////

#define Orb(target,bitnum)			target |= 1 << bitnum
#define Setb(FIOnSET,bitnum)		FIOnSET = 1 << bitnum
#define Clrb(FIOnCLR,bitnum)		FIOnCLR = 1 << bitnum
#define Rdb(FIOnPIN,bitnum)			FIOnPIN & 1 << bitnum

#define VIC_RTC 13

extern int CounterFlag;
extern char clock[30],date[30];

void IO_Init (void);
void card_Init (void);
void can_Init (void);
void main_init(void);
void RGBLED_init (void);
int Button_Lock(void);
void Lock(void);
void CfgTabInterrupt (void);
void Welcome(void);
void FlagCounter(void) __irq;
void ReadRTC(void) __irq;
void Paint (void);

#endif
