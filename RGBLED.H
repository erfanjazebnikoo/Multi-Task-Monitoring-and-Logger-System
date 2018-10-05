#ifndef _RGBLED_H
#define _RGBLED_H

#include "initialization.h" 

#define	Blue	1
#define Green	2
#define Red		3
#define Cyan	12
#define Yellow	23
#define Magenta	13
#define White	123

#define Kck_TX_Color	Green
#define BHL_TX_Color	Magenta
#define BHR_TX_Color	Cyan
#define Pwr_TX_Color	White
#define NoCAN_TX_Color	Yellow
#define Fault_TX_Color	Red
#define Other_TX_Color	Blue

#define Kck_RX_Color	Green
#define BHL_RX_Color	Magenta
#define BHR_RX_Color	Cyan
#define Pwr_RX_Color	White
#define NoCAN_RX_Color	Yellow
#define Fault_RX_Color	Red
#define Other_RX_Color	Blue




void RGBLED_ColorSET (int  LED_Num, int LED_Color);
void RGBLED_ColorCLR (int  LED_Num, int LED_Color);

#endif
