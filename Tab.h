#include "initialization.h"

#ifndef _TAB_H
#define _TAB_H

typedef struct{

int X1,X2,Y1,Y2;

}Key;


void Main_Page (int BT48V , int BT24V , int Conn_Status , int Charge_Status);

void Handling_Left (int Motor_L_RPM , int Motor_L_Current , int HL_Status
										   	 ,int *CW_L , int *CCW_L , int *Stop);

void Handling_Right (int Motor_R_RPM , int Motor_R_Current , int HR_Status
											 ,int *CW_R , int *CCW_R , int *Stop);

//void Kicker (int In_Vol , int Cap_Vol , int Motor_Current , int Charge_Status
//		  ,int Kicker_Status , int &Kick , int &Change_State , int &Kicker_Power);
//
//void Power (int BT48V_Cell1 , int BT48V_Cell2 , int BT48V_Total , int BT24V
//        	,int IR1 , int IR2 , int Vision_Status , int General_Key , int &Beep);

void Multi_Tasking (void);
int Push_Touch (int x1,int x2,int y1,int y2);
int Button(void);
int Key_Read(void);
void BackLight(int counter);

#endif
