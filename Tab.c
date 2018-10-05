/************************************************************************
* Project : Multi Task Monitoring and Logger System
* Version : V0.9 - MMC
* Date    : 05/19/2011
* Author  : Erfan Jazeb Nikoo
* Compiler: KEIL uVision V4.01
* Chip type           : LPC2368 NXP ARM7
* Clock frequency     : 12.000000 MHz
************************************************************************/

#include "Tab.h"


int Num;
static int counter;
static int LockNum;
 
////////////////////////////////////////////////////////////////////////////////////////

void Main_Page (float BT48V_Cell1 , float BT48V_Cell2 ,float BT48V , float BT24V , int Conn_Status , int Charge_Status){
char c_48_1[20],c_48_2[20],bt48v[20],bt24v[20],cst[20],chs[20];

BT48V = (float)BT48V/10;
BT24V = (float)BT24V/10;
BT48V_Cell1 = (float)BT48V_Cell1/10;
BT48V_Cell2 = (float)BT48V_Cell2/10;

//sprintf(bt48v,"48V: %02.01fV",BT48V);
sprintf(bt24v,"24V   : %02.01fV",BT24V);
sprintf(cst,"CAN_ST: %01d",Conn_Status);
sprintf(chs,"KCk_CH: %01d",Charge_Status);
sprintf(c_48_1,"48V V1: %02.01fV",BT48V_Cell1);
sprintf(c_48_2,"48V V2: %02.01fV",BT48V_Cell2);

GLCD_GoTo(0,0);
GLCD_WriteString("                   ");
GLCD_GoTo(0,1);
GLCD_WriteString("                   ");
GLCD_GoTo(0,2);
GLCD_WriteString("                ");
GLCD_GoTo(0,3);
GLCD_WriteString("                ");
GLCD_GoTo(0,4);
GLCD_WriteString("                ");
GLCD_GoTo(0,5);
GLCD_WriteString("                ");
GLCD_GoTo(0,6);
GLCD_WriteString("                   ");
GLCD_GoTo(0,7);
GLCD_WriteString("                ");

//GLCD_GoTo(0,0);
//GLCD_WriteString(bt48v);
//GLCD_SetPixel(41,6,1);
GLCD_GoTo(0,0);
GLCD_WriteString(bt24v);
//GLCD_SetPixel(41,14,1);
GLCD_GoTo(0,1);
GLCD_WriteString(c_48_1);
//GLCD_SetPixel(47,22,1);
GLCD_GoTo(0,2);
GLCD_WriteString(c_48_2);
//GLCD_SetPixel(47,30,1);


//GLCD_GoTo(0,2);
//GLCD_WriteString(cst);
//GLCD_GoTo(0,3);
//GLCD_WriteString(chs);

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
GLCD_WriteString("|L&R");
GLCD_GoTo(80,1);
GLCD_WriteString("+---");
GLCD_GoTo(80,2);
GLCD_WriteString("    ");
GLCD_GoTo(80,3);
GLCD_WriteString("    ");
//GLCD_GoTo(80,4);
//GLCD_WriteString("    ");
//GLCD_GoTo(80,5);
//GLCD_WriteString("    ");

}

////////////////////////////////////////////////////////////////////////////////////////

void Handling_Left (int Motor_L_RPM , int Motor_L_Current , int HL_Status){

char mlr[20],mlc[20],hls[20];
sprintf(mlr,"ML_RPM: %05d",Motor_L_RPM);
sprintf(mlc,"ML_Cur: %03dA",Motor_L_Current);
sprintf(hls,"BHL_ST: %01d",HL_Status);

GLCD_GoTo(0,0);
GLCD_WriteString("                   ");
GLCD_GoTo(0,1);
GLCD_WriteString("                   ");
GLCD_GoTo(0,2);
GLCD_WriteString("             ");
GLCD_GoTo(0,3);
GLCD_WriteString("             ");
GLCD_GoTo(0,4);
GLCD_WriteString("             ");
GLCD_GoTo(0,5);
GLCD_WriteString("             ");
GLCD_GoTo(0,6);
GLCD_WriteString("             ");

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

void Handling_Right (int Motor_R_RPM , int Motor_R_Current , int HR_Status){
char mrr[20],mrc[20],hrs[20];
sprintf(mrr,"MR_RPM: %05d",Motor_R_RPM);
sprintf(mrc,"MR_Cur: %03dA",Motor_R_Current);
sprintf(hrs,"BHR_ST: %01d",HR_Status);

GLCD_GoTo(0,0);
GLCD_WriteString("                   ");
GLCD_GoTo(0,1);
GLCD_WriteString("                   ");
GLCD_GoTo(0,2);
GLCD_WriteString("             ");
GLCD_GoTo(0,3);
GLCD_WriteString("             ");
GLCD_GoTo(0,4);
GLCD_WriteString("             ");
GLCD_GoTo(0,5);
GLCD_WriteString("             ");
GLCD_GoTo(0,6);
GLCD_WriteString("             ");

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

void Kicker (float In_Vol , float Cap_Vol , int Shoot_Status , int Fuse_Status ,
		  int Kicker_Status){
char inv[20],capv[20];

sprintf(inv,"IN_V: %02.01fV",In_Vol/10);
sprintf(capv,"CAP_V: %03.01fV",Cap_Vol/10);

GLCD_GoTo(0,0);
GLCD_WriteString("                   ");
GLCD_GoTo(0,1);
GLCD_WriteString("                   ");
GLCD_GoTo(0,2);
GLCD_WriteString("             ");
GLCD_GoTo(0,3);
GLCD_WriteString("             ");
GLCD_GoTo(0,4);
GLCD_WriteString("             ");
GLCD_GoTo(0,5);
GLCD_WriteString("             ");
GLCD_GoTo(0,6);
GLCD_WriteString("             ");

GLCD_GoTo(0,0);
GLCD_WriteString(inv);
//GLCD_SetPixel(47,6,1);
GLCD_GoTo(0,1);
GLCD_WriteString(capv);
//GLCD_SetPixel(53,14,1);

if(Shoot_Status == 1)
{
	GLCD_GoTo(0,2);
	GLCD_WriteString("SHT_ST: Ch");	
}

else if (Shoot_Status == 2)
{
	GLCD_GoTo(0,2);
	GLCD_WriteString("SHT_ST: Drc");	
}
else
{
	GLCD_GoTo(0,2);
	GLCD_WriteString("SHT_ST: Null");	
}

if(Fuse_Status == 0)
{
	GLCD_GoTo(0,3);
	GLCD_WriteString("Fuse_ST: Fld");	
}

else if (Fuse_Status == 1)
{
	GLCD_GoTo(0,3);
	GLCD_WriteString("Fuse_ST: OK");	
}

if(Kicker_Status == 0)
{
	GLCD_GoTo(0,4);
	GLCD_WriteString("KCK_ST: DS");	
}

else if (Kicker_Status == 1)
{
	GLCD_GoTo(0,4);
	GLCD_WriteString("KCK_ST: EN");
}

GLCD_GoTo(104,0);
GLCD_WriteString("|BHL|");
GLCD_GoTo(104,1);
GLCD_WriteString("+---");
GLCD_GoTo(104,2);
GLCD_WriteString("|BHR|");
GLCD_GoTo(104,3);
GLCD_WriteString("+---");
GLCD_GoTo(104,4);
GLCD_WriteString("|   |");
GLCD_GoTo(104,5);
GLCD_WriteString("+---");
GLCD_GoTo(104,6);
GLCD_WriteString("|PWR|");
GLCD_GoTo(104,7);
GLCD_WriteString("+---");
GLCD_GoTo(0,7);
GLCD_WriteString("|BACK|");

GLCD_GoTo(80,0);
GLCD_WriteString("|KCK");
GLCD_GoTo(80,1);
GLCD_WriteString("+---");
GLCD_GoTo(80,2);
GLCD_WriteString("|ChS");
GLCD_GoTo(80,3);
GLCD_WriteString("+---");
GLCD_GoTo(80,4);
GLCD_WriteString("|E/D");
GLCD_GoTo(80,5);
GLCD_WriteString("+---");

}
 
//////////////////////////////////////////////////////////////////////////////////////////

void Power (float BT48V_Cell1 , float BT48V_Cell2 , float BT48V_Total , float BT24V ,
        	int IR1 , int IR2 , int Vision_Reset , int General_Key ,
			int BT48_Curr , int BT24_Curr){

char c_48[20],t_48_24[20],b48c[20],b24c[20];
sprintf(c_48,"C1:%02.01fV C2:%02.01fV",BT48V_Cell1/10,BT48V_Cell2/10);
sprintf(t_48_24,"48:%02.01fV 24:%02.01fV",BT48V_Total/10,BT24V/10);
sprintf(b48c,"BT48_C: %03dA",BT48_Curr);
sprintf(b24c,"BT24_C: %03dA",BT24_Curr);

GLCD_GoTo(0,0);		    
GLCD_WriteString("                   ");
GLCD_GoTo(0,1);
GLCD_WriteString("                   ");
GLCD_GoTo(0,2);		  
GLCD_WriteString("             ");
GLCD_GoTo(0,3);
GLCD_WriteString("             ");
GLCD_GoTo(0,4);
GLCD_WriteString("             ");
GLCD_GoTo(0,5);
GLCD_WriteString("             ");
GLCD_GoTo(0,6);
GLCD_WriteString("             ");

GLCD_GoTo(0,0);
GLCD_WriteString(c_48);
//GLCD_SetPixel(29,6,1);
//GLCD_SetPixel(71,6,1);
GLCD_GoTo(0,1);
GLCD_WriteString(t_48_24);
//GLCD_SetPixel(29,14,1);
//GLCD_SetPixel(71,14,1);
GLCD_GoTo(0,2);
GLCD_WriteString(b48c);
GLCD_GoTo(0,3);
GLCD_WriteString(b24c);

if(IR1 == 1 && IR2 == 1)
{
	GLCD_GoTo(0,4);
	GLCD_WriteString("IR1: T IR2: T");	
}

else if(IR1 == 1 && IR2 == 0)
{
	GLCD_GoTo(0,4);
	GLCD_WriteString("IR1: T IR2: F");	
}

else if(IR1 == 0 && IR2 == 1)
{
	GLCD_GoTo(0,4);
	GLCD_WriteString("IR1: F IR2: T");	
}

else if(IR1 == 0 && IR2 == 0)
{
	GLCD_GoTo(0,4);
	GLCD_WriteString("IR1: F IR2: F");	
}

if(Vision_Reset == 0)
{
	GLCD_GoTo(0,5);
	GLCD_WriteString("VR: F");	
}

else if(Vision_Reset == 1)
{
	GLCD_GoTo(0,5);
	GLCD_WriteString("VR: T");	
}

if(General_Key == 0)
{
	GLCD_GoTo(0,6);
	GLCD_WriteString("GPK: F");	
}

else if (General_Key == 1)
{
	GLCD_GoTo(0,6);
	GLCD_WriteString("GPK: T");
}

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
GLCD_WriteString("|   |");
GLCD_GoTo(104,7);
GLCD_WriteString("+---");
GLCD_GoTo(0,7);
GLCD_WriteString("|BACK|");

//GLCD_GoTo(80,0);
//GLCD_WriteString("    ");
//GLCD_GoTo(80,1);
//GLCD_WriteString("    ");
GLCD_GoTo(80,2);
GLCD_WriteString("    ");
GLCD_GoTo(80,3);
GLCD_WriteString("+---");
GLCD_GoTo(80,4);
GLCD_WriteString("|BEP");
GLCD_GoTo(80,5);
GLCD_WriteString("+---");

}

//////////////////////////////////////////////////////////////////////////////////////////

int Push_Touch (int x1 , int x2 , int y1 , int y2){
int Touch_X,Touch_Y;

if(TCIsPenOn())
{
	TCRead();
	Touch_X = TCGetX()/(26.8)-12; 
	Touch_Y = TCGetY()/(46.4)-12;	
}
else
{
	Touch_X = 0;
	Touch_Y = 0;
}	
if(x1<Touch_X && Touch_X<x2)
{
	if(y1<Touch_Y && Touch_Y<y2)
	    return(1); 	
	else
		return(0);
}
else
return(0);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Multi_Tasking (void)
{
int upd;
static int k = 8;
static int flag;

upd = Num;

if(k == 1)
{
	Handling_Left (0,0,0);
	counter = k;
}

else if(k == 2)
{
	Handling_Right (0,0,0);
	counter = k;
}
			
else if (k == 3)
{
	Kicker (Rx_Data.Input_Vol,Rx_Data.Cap_Vol,Rx_Data.Shoot_Status,Rx_Data.Fuse_Status,Rx_Data.Kicker_Status);
	counter = k;
}

if(k == 4)
{
	Power (Rx_Data.BT48V_Cell1,Rx_Data.BT48V_Cell2,Rx_Data.BT48V,Rx_Data.Input_Vol,
	Rx_Data.IR1,Rx_Data.IR2,Rx_Data.Vision_Reset,Rx_Data.General_Key,0,0);
	counter = k;
}

else if (k == 8)
{
	Main_Page(Rx_Data.BT48V_Cell1,Rx_Data.BT48V_Cell2,Rx_Data.BT48V,Rx_Data.Input_Vol,0,0);
	if (FIO2PIN & (1<<0))
	{
		GLCD_GoTo(31,7);
	    GLCD_WriteString(" |BCKL: ON |");
	}
	else
	{
		GLCD_GoTo(31,7);
	    GLCD_WriteString(" |BCKL: OFF|");
	}
	counter = k;
}
else if (k == 9)
{
	if (flag == 0)
	{
		BackLight(1);
		GLCD_GoTo(31,7);
	    GLCD_WriteString(" |BCKL: ON |");
		flag = 1;
	}
	else
	{
		BackLight(0);
		GLCD_GoTo(31,7);
	    GLCD_WriteString(" |BCKL: OFF|");
		flag = 0;
	}
		counter = k;
	}

else if (k == 6)
{
 	if(counter == 3)
		Num = KCK_ChS ;
}

else if (k == 7)
{
 	if(counter == 3)
		Num = KCK_ED;	
}

else if(k == 14)
{		    
		if(counter == 3)
			Num = KCK_KCK;	

		if(counter == 1)
			Num = BHL_CW;

		if(counter == 2)
			Num = BHR_CW;

		if(counter == 8)
			LockNum = 148;
}

else if(k == 15)
{

		if(counter == 1)
			Num = BHL_CCW;

		if(counter == 2)
			Num = BHR_CCW;		
		
}

else if(k == 16)
{
		if(counter == 1)
			Num = BHL_STP;

		if(counter == 2)
			Num = BHR_STP;

		if(counter == 4)
			Num = PWR_BEEP;		
}

RefreshTab();

k = Key_Read();

if (upd == Num)
Num = 0;

}
//////////////////////////////////////////////////////////////////////////////////////////

void RefreshTab(void)
{
//if(counter == 1)
//{
//	if (CounterFlag>200)
//	{
//		//Kicker (Rx_Data.Input_Vol,Rx_Data.Cap_Vol,Rx_Data.Shoot_Status,Rx_Data.Fuse_Status,Rx_Data.Kicker_Status);
//		CounterFlag = 0;
//	}         
//}
//if(counter == 2)
//{
//	if (CounterFlag>200)
//	{
//		//Kicker (Rx_Data.Input_Vol,Rx_Data.Cap_Vol,Rx_Data.Shoot_Status,Rx_Data.Fuse_Status,Rx_Data.Kicker_Status);
//		CounterFlag = 0;
//	}         
//}
if(counter == 3)
{
	if (CounterFlag>300)
	{	
		Kicker (Rx_Data.Input_Vol,Rx_Data.Cap_Vol,Rx_Data.Shoot_Status,Rx_Data.Fuse_Status,Rx_Data.Kicker_Status);
		Logging();
		CounterFlag = 0;
	}         
} 
if(counter == 4)
{
	if (CounterFlag>300)
	{
		Power (Rx_Data.BT48V_Cell1,Rx_Data.BT48V_Cell2,Rx_Data.BT48V,Rx_Data.Input_Vol,
		Rx_Data.IR1,Rx_Data.IR2,Rx_Data.Vision_Reset,Rx_Data.General_Key,0,0);
		Logging();
		CounterFlag = 0;
	}
}
if(counter == 8)
{

	if (CounterFlag>500)
	{
		Main_Page(Rx_Data.BT48V_Cell1,Rx_Data.BT48V_Cell2,Rx_Data.BT48V,Rx_Data.Input_Vol,0,0);
		if (FIO2PIN & (1<<0))
		{
			GLCD_GoTo(31,7);
	    	GLCD_WriteString(" |BCKL: ON |");
		}
		else
		{
			GLCD_GoTo(31,7);
	    	GLCD_WriteString(" |BCKL: OFF|");
		}
		GLCD_GoTo(0,4);							  
		GLCD_WriteString(clock);
		GLCD_GoTo(0,5);
		GLCD_WriteString(date);
		Logging();
		CounterFlag = 0;
	}
} 
       
}

//////////////////////////////////////////////////////////////////////////////////////////

int SendToCan(void)
{
 return Num;         
}

//////////////////////////////////////////////////////////////////////////////////////////

int Button (void)
{
//int flag;
int is_Push;
Key BHL_Btn , BHR_Btn , KCK_Btn , PWR_Btn;
Key Back_Btn , BCKL_Btn;
Key Btn1 , Btn2 , Btn3 ;

/////////////////////////////////////////////

BHL_Btn.X1 = 102;
BHL_Btn.X2 = 128;
BHL_Btn.Y1 = 54;
BHL_Btn.Y2 = 64;

/////////////////////////////////////////////

BHR_Btn.X1 = 102;
BHR_Btn.X2 = 128;
BHR_Btn.Y1 = 40;
BHR_Btn.Y2 = 52;

/////////////////////////////////////////////

KCK_Btn.X1 = 102;
KCK_Btn.X2 = 128;
KCK_Btn.Y1 = 26;
KCK_Btn.Y2 = 38;

/////////////////////////////////////////////

PWR_Btn.X1 = 102;
PWR_Btn.X2 = 128;
PWR_Btn.Y1 = 10;
PWR_Btn.Y2 = 23;

/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////

Back_Btn.X1 = 0;
Back_Btn.X2 = 31;
Back_Btn.Y1 = 0;
Back_Btn.Y2 = 12;

/////////////////////////////////////////////

BCKL_Btn.X1 = 46;
BCKL_Btn.X2 = 99;
BCKL_Btn.Y1 = 0;
BCKL_Btn.Y2 = 13;

/////////////////////////////////////////////  	
/////////////////////////////////////////////
/////////////////////////////////////////////

Btn1.X1 = 76;
Btn1.X2 = 98;
Btn1.Y1 = 54;
Btn1.Y2 = 64;

/////////////////////////////////////////////

Btn2.X1 = 76;
Btn2.X2 = 98;
Btn2.Y1 = 40;
Btn2.Y2 = 52;

/////////////////////////////////////////////

Btn3.X1 = 76;
Btn3.X2 = 98;
Btn3.Y1 = 26;
Btn3.Y2 = 38;

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
return (0);

}
///////////////////////////////////////////////////////////////////////////

int Key_Read(void){
static U32 KeyPushCounter,KeyMem,KeyLastState;
KeyMem = Button();
if (KeyMem)
{
	KeyLastState = KeyMem; KeyPushCounter = 0;
	while ((KeyMem == KeyLastState)&&(KeyPushCounter < 50))
	{
		KeyLastState = KeyMem;
		KeyMem = Button();
		KeyPushCounter++;
		delay_ms(10);
	}
	if (KeyPushCounter < 50)
		return (KeyLastState);
	else
		return (KeyLastState+9);
}
return 0;
}

///////////////////////////////////////////////////////////////////////////

void BackLight(int counter){

if (counter)
	Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
else
	Clrb(GLCD_BCKL_CLR,GLCD_BCKL_PIN);
}

//////////////////////////////////////////////////////////////////////////

void Calibration(void)
{
unsigned int x,y;
char Touch_X[20],Touch_Y[20];

GLCD_ClearScreen();

Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
GLCD_GoTo(0,4);
GLCD_WriteString("|    Calibration    |");
GLCD_GoTo(0,5);
GLCD_WriteString("|-------------------|");
GLCD_GoTo(0,6);
GLCD_WriteString("| Monitoring System |");

if(TCIsPenOn())
{
	TCRead();
	x = TCGetX()/(26.8)-12; 
	y = TCGetY()/(46.4)-12;	
}
else
{
	x = 0;
	y = 0;
}

sprintf(Touch_X,"      X: %04d",x);
sprintf(Touch_Y,"      Y: %04d",y);

GLCD_GoTo(6,0);
GLCD_WriteString(Touch_X);
GLCD_GoTo(6,2);
GLCD_WriteString(Touch_Y);

}

//////////////////////////////////////////////////////////////////////////

