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

#ifndef _TAB_H
#define _TAB_H
 

////////////////////// Struct ////////////////////////

typedef struct{

int X1,X2,Y1,Y2;

}Key;

//////////////////////////////////////////////////////

typedef struct{

int D0,D1,D2,D3,D4,D5,D6,D7;

}DATA;

//////////////////////////////////////////////////////
void Main_Page (float BT48V_Cell1 , float BT48V_Cell2 ,float BT48V , float BT24V , int Conn_Status , int Charge_Status);

void Handling_Left (int Motor_L_RPM , int Motor_L_Current , int HL_Status);

void Handling_Right (int Motor_R_RPM , int Motor_R_Current , int HR_Status);

void Kicker (float In_Vol , float Cap_Vol , int Shoot_Status , int Fuse_Status ,
		  int Kicker_Status);

void Power (float BT48V_Cell1 , float BT48V_Cell2 , float BT48V_Total , float BT24V ,
        	int IR1 , int IR2 , int Vision_Reset , int General_Key ,
			int BT48_Curr , int BT24_Curr);

void Multi_Tasking(void);
int SendToCan(void);
int Push_Touch (int x1,int x2,int y1,int y2);
int Button(void);
int Key_Read(void);
void BackLight(int counter);
void RefreshTab(void);
void Calibration(void);


#endif
