#include "initialization.h"

#ifndef _TAB_H
#define _TAB_H
 

////////////////////// Struct ////////////////////////

typedef struct{

int X1,X2,Y1,Y2;

}Key;

//////////////////////////////////////////////////////



typedef struct{

int CW_L,CW_R;
int CCW_L,CCW_R;
int Stop_L,Stop_R;
int Kick;
int Kicker_Change_State,Kicker_Power;
int Beep;

}Transmitter_Var;

//////////////////////////////////////////////////////

typedef struct{

int D0,D1,D2,D3,D4,D5,D6,D7;

}DATA;

//////////////////////////////////////////////////////
void Main_Page (int BT48V , int BT24V , int Conn_Status , int Charge_Status);

void Handling_Left (int Motor_L_RPM , int Motor_L_Current , int HL_Status);

void Handling_Right (int Motor_R_RPM , int Motor_R_Current , int HR_Status);

void Kicker (int In_Vol , int Cap_Vol , int Shoot_Status , int Fuse_Status ,
		  int Kicker_Status);

void Power (int BT48V_Cell1 , int BT48V_Cell2 , int BT48V_Total , int BT24V ,
        	int IR1 , int IR2 , int Vision_Reset , int General_Key ,
			int BT48_Curr , int BT24_Curr);

void Multi_Tasking(void);
int SendToCan(void);
int Push_Touch (int x1,int x2,int y1,int y2);
int Button(void);
int Key_Read(void);
void BackLight(int counter);
void RefreshTab(void);


#endif
