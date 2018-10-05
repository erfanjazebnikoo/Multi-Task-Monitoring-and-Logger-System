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

#define Power_Rx_ID1		0x21
#define Power_Rx_ID2		0x22
#define Kicker_Rx_ID		0x31
#define Handeling_L_Rx_ID	0x41
#define Handeling_R_Rx_ID	0x51

typedef struct{

int BHL_Motor_Current;
int BHL_Motor_RPM;
int BHL_Status;
int BHR_Motor_Current;
int BHR_Motor_RPM;
int BHR_Status;
int Input_Vol;
int Cap_Vol;
int Shoot_Status;					 
int Fuse_Status;
int Kicker_Status;
int BT48V_Cell1;
int BT48V_Cell2;
int BT48V;
int IR1,IR2;
int Vision_Reset;
int General_Key;

}Rx_Var;

extern Rx_Var Rx_Data;

//////////////////////////////////////////////////////


void Can_Tx	(int TabNum);
void Can_Rx (void);
void can_Send (int ID , int Data_Length , DATA *Data);


#endif



