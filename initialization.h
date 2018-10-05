
#ifndef _INITIALIZATION_H
#define _INITIALIZATION_H

#include "CAN.h" 
#include "type.h"
#include "delay.h"
//#include <RTL.h>                      /* RTL kernel functions & defines      */
#include <stdio.h>                    /* standard I/O .h-file                */
#include <ctype.h>                    /* character functions                 */
#include <string.h>                   /* string and memory functions         */
#include "LPC23xx.h"
//#include "File_Config.h"
//#include "SD_File.h"
#include "KS0108.h"
#include <stdint.h>                             /* Include standard types */                      
#include "Tab.h"
#include "tc_ad7843_v1_00.h"
#include "app_config.h"
#include "pic1_glcd.h"
#include "rgbled.h"
#include "Network.h"
#include "irq.h"
#include <math.h>                               /* LPC1766 CAN adaption layer */
//#ifdef RT_AGENT
//#include "RT_Agent.h"                           /* Real-Time Agent definitions */
//#endif

#define Power_ID		0x20
#define Kicker_ID		0x30
#define Handeling_ID	0x40
#define BEEP 			0x18
#define Kicker_EN		0xCE
#define Handeling_EN	0xEE
#define Kicker_Pwr	5000	
#define Handeling_Spd_CW	1500
#define Handeling_Spd_CCW	-1500


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

extern int CounterFlag;

void IO_Init (void);
void card_Init (void);
void can_Init (void);
void main_init(void);
void RGBLED_init (void);
int Touch_Lock(void);
int Lock_Screen(int State);
void Lock(int j);
//void Tab_Interrupt(void) __irq ;
void CfgTabInterrupt (void);
void Welcome(void);
void FlagCounter(void) __irq;

#endif
