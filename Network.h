#ifndef _NETWORK_H
#define _NETWORK_H

#include "initialization.h" 

#define BHL_CW 		114
#define BHL_CCW 	115
#define BHL_STP 	116
#define BHR_CW 		214
#define BHR_CCW 	215
#define BHR_STP 	216
#define KCK_KCK 	314
#define KCK_ChS 	36
#define KCK_ED 		37
#define PWR_BEEP	414

#endif


void Can_Tx	(int TabNum);
void can_Send (int ID , int Data_Length , DATA *Data);
