
#ifndef _INITIALIZATION_H
#define _INITIALIZATION_H

#include "CAN.h" 
#include "type.h"
#include "delay.h"
#include <RTL.h>                      /* RTL kernel functions & defines      */
#include <stdio.h>                    /* standard I/O .h-file                */
#include <ctype.h>                    /* character functions                 */
#include <string.h>                   /* string and memory functions         */
#include "LPC23xx.h"
#include "File_Config.h"
#include "SD_File.h"
#include "KS0108.h"
#include <stdint.h>                             /* Include standard types */                      
#include "Tab.h"
#include "tc_ad7843_v1_00.h"
#include "app_config.h"
#include <math.h>                               /* LPC1766 CAN adaption layer */
#ifdef RT_AGENT
#include "RT_Agent.h"                           /* Real-Time Agent definitions */
#endif

#endif

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

void IO_Init (void);
void card_Init (void);
void can_Init (void);
void main_init(void);

