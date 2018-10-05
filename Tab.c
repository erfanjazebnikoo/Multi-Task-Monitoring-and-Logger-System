#include "Tab.h"


int z;
int h=1;

////////////////////////////////////////////////////////////////////////////////////////

void Main_Page (int BT48V , int BT24V , int Conn_Status , int Charge_Status){
char bt48v[20],bt24v[20],cst[20],chs[20];

sprintf(bt48v,"48V: %03dV",BT48V);
sprintf(bt24v,"24V: %03dV",BT24V);
sprintf(cst,"CAN_ST: %01d",Conn_Status);
sprintf(chs,"KCk_CH: %01d",Charge_Status);

//GLCD_ClearScreen();


GLCD_GoTo(0,0);
GLCD_WriteString("            ");
GLCD_GoTo(0,1);
GLCD_WriteString("            ");
GLCD_GoTo(0,2);
GLCD_WriteString("            ");
GLCD_GoTo(0,3);
GLCD_WriteString("            ");
GLCD_GoTo(0,4);
GLCD_WriteString("            ");

GLCD_GoTo(0,0);
GLCD_WriteString(bt48v);
GLCD_GoTo(0,1);
GLCD_WriteString(bt24v);
GLCD_GoTo(0,2);
GLCD_WriteString(cst);
GLCD_GoTo(0,3);
GLCD_WriteString(chs);

GLCD_GoTo(104,0);
GLCD_WriteString("|BHL|");
GLCD_GoTo(104,1);
GLCD_WriteString("+---");
GLCD_GoTo(104,2);
GLCD_WriteString("|BHR|");
GLCD_GoTo(104,3);
GLCD_WriteString("+---");
GLCD_GoTo(104,4);
GLCD_WriteString("|KCK|");
GLCD_GoTo(104,5);
GLCD_WriteString("+---");
GLCD_GoTo(104,6);
GLCD_WriteString("|PWR|");
GLCD_GoTo(104,7);
GLCD_WriteString("+---");
GLCD_GoTo(0,7);
GLCD_WriteString("      ");

GLCD_GoTo(80,0);
GLCD_WriteString("|   ");
GLCD_GoTo(80,1);
GLCD_WriteString("+---");
GLCD_GoTo(80,2);
GLCD_WriteString("|   ");
GLCD_GoTo(80,3);
GLCD_WriteString("+---");
GLCD_GoTo(80,4);
GLCD_WriteString("|   ");
GLCD_GoTo(80,5);
GLCD_WriteString("+---");
//
//for	(z=0;z<10000;z++);

}

////////////////////////////////////////////////////////////////////////////////////////

void Handling_Left (int Motor_L_RPM , int Motor_L_Current , int HL_Status ,
										   	 int *CW_L , int *CCW_L , int *Stop){

char mlr[20],mlc[20],hls[20];
sprintf(mlr,"ML_RPM: %03d",Motor_L_RPM);
sprintf(mlc,"ML_Cur: %03dA",Motor_L_Current);
sprintf(hls,"BHL_ST: %01d",HL_Status);


GLCD_GoTo(0,0);
GLCD_WriteString("            ");
GLCD_GoTo(0,1);
GLCD_WriteString("            ");
GLCD_GoTo(0,2);
GLCD_WriteString("            ");
GLCD_GoTo(0,3);
GLCD_WriteString("            ");
GLCD_GoTo(0,4);
GLCD_WriteString("            ");

GLCD_GoTo(0,0);
GLCD_WriteString(mlr);
GLCD_GoTo(0,1);
GLCD_WriteString(mlc);
GLCD_GoTo(0,2);
GLCD_WriteString(hls);


GLCD_GoTo(104,0);
GLCD_WriteString("|   |");
GLCD_GoTo(104,1);
GLCD_WriteString("+---");
GLCD_GoTo(104,2);
GLCD_WriteString("|BHR|");
GLCD_GoTo(104,3);
GLCD_WriteString("+---");
GLCD_GoTo(104,4);
GLCD_WriteString("|KCK|");
GLCD_GoTo(104,5);
GLCD_WriteString("+---");
GLCD_GoTo(104,6);
GLCD_WriteString("|PWR|");
GLCD_GoTo(104,7);
GLCD_WriteString("+---");
GLCD_GoTo(0,7);
GLCD_WriteString("|BACK|");

GLCD_GoTo(80,0);
GLCD_WriteString("|CW ");
GLCD_GoTo(80,1);
GLCD_WriteString("+---");
GLCD_GoTo(80,2);
GLCD_WriteString("|CCW");
GLCD_GoTo(80,3);
GLCD_WriteString("+---");
GLCD_GoTo(80,4);
GLCD_WriteString("|STP");
GLCD_GoTo(80,5);
GLCD_WriteString("+---");

}

//////////////////////////////////////////////////////////////////////////////////////////

void Handling_Right (int Motor_R_RPM , int Motor_R_Current , int HR_Status ,
											 int *CW_R , int *CCW_R , int *Stop){
char mrr[20],mrc[20],hrs[20];
sprintf(mrr,"MR_RPM: %03d",Motor_R_RPM);
sprintf(mrc,"MR_Cur: %03dA",Motor_R_Current);
sprintf(hrs,"BHR_ST: %01d",HR_Status);


GLCD_GoTo(0,0);
GLCD_WriteString("            ");
GLCD_GoTo(0,1);
GLCD_WriteString("            ");
GLCD_GoTo(0,2);
GLCD_WriteString("            ");
GLCD_GoTo(0,3);
GLCD_WriteString("            ");
GLCD_GoTo(0,4);
GLCD_WriteString("            ");

GLCD_GoTo(0,0);
GLCD_WriteString(mrr);
GLCD_GoTo(0,1);
GLCD_WriteString(mrc);
GLCD_GoTo(0,2);
GLCD_WriteString(hrs);


GLCD_GoTo(104,0);
GLCD_WriteString("|BHL|");
GLCD_GoTo(104,1);
GLCD_WriteString("+---");
GLCD_GoTo(104,2);
GLCD_WriteString("|   |");
GLCD_GoTo(104,3);
GLCD_WriteString("+---");
GLCD_GoTo(104,4);
GLCD_WriteString("|KCK|");
GLCD_GoTo(104,5);
GLCD_WriteString("+---");
GLCD_GoTo(104,6);
GLCD_WriteString("|PWR|");
GLCD_GoTo(104,7);
GLCD_WriteString("+---");
GLCD_GoTo(0,7);
GLCD_WriteString("|BACK|");

GLCD_GoTo(80,0);
GLCD_WriteString("|CW ");
GLCD_GoTo(80,1);
GLCD_WriteString("+---");
GLCD_GoTo(80,2);
GLCD_WriteString("|CCW");
GLCD_GoTo(80,3);
GLCD_WriteString("+---");
GLCD_GoTo(80,4);
GLCD_WriteString("|STP");
GLCD_GoTo(80,5);
GLCD_WriteString("+---");

}

//////////////////////////////////////////////////////////////////////////////////////////
//
//void Kicker (int In_Vol , int Cap_Vol , int Motor_Current , int Charge_Status ,
//		  int Kicker_Status , int &Kick , int &Change_State , int &Kicker_Power){
//
//
//
//
//}
// 
//////////////////////////////////////////////////////////////////////////////////////////
//
//void Power (int BT48V_Cell1 , int BT48V_Cell2 , int BT48V_Total , int BT24V ,
//        	int IR1 , int IR2 , int Vision_Status , int General_Key , int &Beep){
//
//
//
//
//}

//////////////////////////////////////////////////////////////////////////////////////////

int Push_Touch (int x1 , int x2 , int y1 , int y2){
int Touch_X,Touch_Y;
if(TCIsPenOn()){
TCRead();
	Touch_X = (TCGetX() - 220) / 28;
	Touch_Y = (TCGetY() - 500) / 45;
}
else{
	Touch_X = 0;
	Touch_Y = 0;
}	
if(x1<Touch_X && Touch_X<x2){
	if(y1<Touch_Y && Touch_Y<y2)
	    return(1); 	
	else
		return(0);
}
else
return(0);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Multi_Tasking (void){

int m,n,p;
char b[20];
int k;
int flag;

//int x,y;
//char Touch_X[40],Touch_Y[40];

//if(!TCIsPenOn()){
//flag = 0;
//}
//if(flag == 0 && TCIsPenOn()){
////BackLight(1);
//if (FIO2PIN & (1<<0))
//Clrb(GLCD_BCKL_CLR,GLCD_BCKL_PIN);
//else
//Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
//flag = 1;
//}

//TCRead();
//	x = (TCGetX() - 220) / 28;
//	y = (TCGetY() - 500) / 45;
//else{
//	x = 0;
//	y = 0;
//}	
//
//sprintf(Touch_X,"X: %03d",x);
//sprintf(Touch_Y,"Y: %03d",y);
//
//GLCD_GoTo(0,0);
//GLCD_WriteString(Touch_X);
//GLCD_GoTo(0,2);
//GLCD_WriteString(Touch_Y);
		


k = Key_Read();

if(k == 1)
Handling_Left (0,0,0,&m,&n,&p);
else if(k == 2)
Handling_Right (0,0,0,&m,&n,&p);
else
Main_Page(0,0,0,0);


}
//////////////////////////////////////////////////////////////////////////////////////////

int Button (void)
{
int flag;
int is_Push;
Key BHL_Btn , BHR_Btn , KCK_Btn , PWR_Btn;
Key Back_Btn , BCKL_Btn;
Key Btn1 , Btn2 , Btn3 ;

/////////////////////////////////////////////

BHL_Btn.X1 = 108;
BHL_Btn.X2 = 128;
BHL_Btn.Y1 = 52;
BHL_Btn.Y2 = 64;

/////////////////////////////////////////////

BHR_Btn.X1 = 108;
BHR_Btn.X2 = 128;
BHR_Btn.Y1 = 35;
BHR_Btn.Y2 = 50;

/////////////////////////////////////////////

KCK_Btn.X1 = 108;
KCK_Btn.X2 = 128;
KCK_Btn.Y1 = 18;
KCK_Btn.Y2 = 33;

/////////////////////////////////////////////

PWR_Btn.X1 = 108;
PWR_Btn.X2 = 128;
PWR_Btn.Y1 = 0;
PWR_Btn.Y2 = 16;

/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////

Back_Btn.X1 = 0;
Back_Btn.X2 = 31;
Back_Btn.Y1 = 0;
Back_Btn.Y2 = 6;

/////////////////////////////////////////////

BCKL_Btn.X1 = 39;
BCKL_Btn.X2 = 99;
BCKL_Btn.Y1 = 0;
BCKL_Btn.Y2 = 6;

/////////////////////////////////////////////  	
/////////////////////////////////////////////
/////////////////////////////////////////////

Btn1.X1 = 83;
Btn1.X2 = 107;
Btn1.Y1 = 52;
Btn1.Y2 = 64;

/////////////////////////////////////////////

Btn2.X1 = 83;
Btn2.X2 = 107;
Btn2.Y1 = 35;
Btn2.Y2 = 50;

/////////////////////////////////////////////

Btn3.X1 = 83;
Btn3.X2 = 107;
Btn3.Y1 = 18;
Btn3.Y2 = 33;

/////////////////////////////////////////////

//// BHL
is_Push = Push_Touch (BHL_Btn.X1,BHL_Btn.X2,BHL_Btn.Y1,BHL_Btn.Y2);
if (is_Push)
return (1);

//// BHR
is_Push = Push_Touch (BHR_Btn.X1,BHR_Btn.X2,BHR_Btn.Y1,BHR_Btn.Y2);
if (is_Push)
	return (2);

//// KCK
is_Push = Push_Touch (KCK_Btn.X1,KCK_Btn.X2,KCK_Btn.Y1,KCK_Btn.Y2);
if (is_Push)
	return (3);

//// PWR
is_Push = Push_Touch (PWR_Btn.X1,PWR_Btn.X2,PWR_Btn.Y1,PWR_Btn.Y2);
if (is_Push)
	return (4);

//// BTN1
is_Push = Push_Touch (Btn1.X1,Btn1.X2,Btn1.Y1,Btn1.Y2);
if (is_Push)
	return (5);

//// BTN2
is_Push = Push_Touch (Btn2.X1,Btn2.X2,Btn2.Y1,Btn2.Y2);
if (is_Push)
	return (6);

//// BTN3
is_Push = Push_Touch (Btn3.X1,Btn3.X2,Btn3.Y1,Btn3.Y2);
if (is_Push)
	return (7);

//// BACK
is_Push = Push_Touch (Back_Btn.X1,Back_Btn.X2,Back_Btn.Y1,Back_Btn.Y2);
if (is_Push)
	return (8);

//// BCKL
is_Push = Push_Touch (BCKL_Btn.X1,BCKL_Btn.X2,BCKL_Btn.Y1,BCKL_Btn.Y2);
if (is_Push)
	return (9);
//else
//	return (0);

}

///////////////////////////////////////////////////////////////////////////

int Key_Read(void){

return Button();

}

///////////////////////////////////////////////////////////////////////////

void BackLight(int counter){

if (counter == 1)
Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
else if (counter == 0)
Clrb(GLCD_BCKL_CLR,GLCD_BCKL_PIN);
}
