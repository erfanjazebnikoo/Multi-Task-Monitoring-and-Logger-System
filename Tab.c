#include "Tab.h"

int counter = 0;
int Num;


 
////////////////////////////////////////////////////////////////////////////////////////

void Main_Page (int BT48V , int BT24V , int Conn_Status , int Charge_Status){
char bt48v[20],bt24v[20],cst[20],chs[20];

sprintf(bt48v,"48V: %03dV",BT48V);
sprintf(bt24v,"24V: %03dV",BT24V);
sprintf(cst,"CAN_ST: %01d",Conn_Status);
sprintf(chs,"KCk_CH: %01d",Charge_Status);


	GLCD_GoTo(0,0);
	GLCD_WriteString("                ");
	GLCD_GoTo(0,1);
	GLCD_WriteString("                ");
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
GLCD_WriteString("|L&R");
GLCD_GoTo(80,1);
GLCD_WriteString("+---");
GLCD_GoTo(80,2);
GLCD_WriteString("    ");
GLCD_GoTo(80,3);
GLCD_WriteString("    ");
GLCD_GoTo(80,4);
GLCD_WriteString("    ");
GLCD_GoTo(80,5);
GLCD_WriteString("    ");
//
//for	(z=0;z<10000;z++);

}

////////////////////////////////////////////////////////////////////////////////////////

void Handling_Left (int Motor_L_RPM , int Motor_L_Current , int HL_Status ,
										   	 int *CW_L , int *CCW_L , int *Stop_L){

char mlr[20],mlc[20],hls[20];
sprintf(mlr,"ML_RPM: %05d",Motor_L_RPM);
sprintf(mlc,"ML_Cur: %03dA",Motor_L_Current);
sprintf(hls,"BHL_ST: %01d",HL_Status);


	GLCD_GoTo(0,0);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,1);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,2);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,3);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,4);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,5);
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

void Handling_Right (int Motor_R_RPM , int Motor_R_Current , int HR_Status ,
											 int *CW_R , int *CCW_R , int *Stop_R){
char mrr[20],mrc[20],hrs[20];
sprintf(mrr,"MR_RPM: %05d",Motor_R_RPM);
sprintf(mrc,"MR_Cur: %03dA",Motor_R_Current);
sprintf(hrs,"BHR_ST: %01d",HR_Status);


	GLCD_GoTo(0,0);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,1);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,2);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,3);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,4);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,5);
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

void Kicker (int In_Vol , int Cap_Vol , int Motor_Current , int Charge_Status ,
		  int Kicker_Status , int *Kick , int *Change_State , int *Kicker_Power){
char inv[20],capv[20],mtc[20],chs[20],ks[20];

sprintf(inv,"IN_V: %03dV",In_Vol);
sprintf(capv,"CAP_V: %03dV",Cap_Vol);
sprintf(mtc,"MT_Cur: %03dA",Motor_Current);
sprintf(chs,"CHR_ST: %01d",Charge_Status);
sprintf(ks,"KCk_ST: %03d",Kicker_Status);

	GLCD_GoTo(0,0);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,1);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,2);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,3);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,4);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,5);
	GLCD_WriteString("             ");

GLCD_GoTo(0,0);
GLCD_WriteString(inv);
GLCD_GoTo(0,1);
GLCD_WriteString(capv);
GLCD_GoTo(0,2);
GLCD_WriteString(mtc);
GLCD_GoTo(0,3);
GLCD_WriteString(chs);
GLCD_GoTo(0,4);
GLCD_WriteString(ks);

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

void Power (int BT48V_Cell1 , int BT48V_Cell2 , int BT48V_Total , int BT24V ,
        	int IR1 , int IR2 , int Vision_Reset , int General_Key ,
			int BT48_Curr , int BT24_Curr , int *Beep){

char c_48[20],t_48_24[20],ir[20],vs[20],b48c[20],b24c[20];
sprintf(c_48,"C1:%03d C2:%03d",BT48V_Cell1,BT48V_Cell2);
sprintf(t_48_24,"48:%03d 24:%03d",BT48V_Total,BT24V);
sprintf(ir,"IR1: %01d IR2: %01d",IR1,IR2);
sprintf(vs,"V_R: %01d G_K: %01d",Vision_Reset,General_Key);
sprintf(b48c,"BT48_C: %03dA",BT48_Curr);
sprintf(b24c,"BT24_C: %03dA",BT24_Curr);

	GLCD_GoTo(0,0);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,1);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,2);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,3);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,4);
	GLCD_WriteString("             ");
	GLCD_GoTo(0,5);
	GLCD_WriteString("             ");


	GLCD_GoTo(0,0);
	GLCD_WriteString(c_48);
	GLCD_GoTo(0,1);
	GLCD_WriteString(t_48_24);
	GLCD_GoTo(0,2);
	GLCD_WriteString(b48c);
	GLCD_GoTo(0,3);
	GLCD_WriteString(b24c);
	GLCD_GoTo(0,4);
	GLCD_WriteString(ir);
	GLCD_GoTo(0,5);
	GLCD_WriteString(vs);

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
	
	GLCD_GoTo(80,0);
	GLCD_WriteString("|BEP");
	GLCD_GoTo(80,1);
	GLCD_WriteString("+---");
	GLCD_GoTo(80,2);
	GLCD_WriteString("    ");
	GLCD_GoTo(80,3);
	GLCD_WriteString("    ");
	GLCD_GoTo(80,4);
	GLCD_WriteString("    ");
	GLCD_GoTo(80,5);
	GLCD_WriteString("    ");

}

//////////////////////////////////////////////////////////////////////////////////////////

int Push_Touch (int x1 , int x2 , int y1 , int y2){
int Touch_X,Touch_Y;
if(TCIsPenOn()){
TCRead();
	Touch_X = TCGetX()/(26.6)-12; 
	Touch_Y = TCGetY()/(46.2)-12;	
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

void Multi_Tasking (int FlagInterrupt)
{
int cnt;
int m,n,p,beep;
//int Lock_State,i=0;
//int h;
char a[20];
static int k = 8;
static int flag;
unsigned int val_Rx = 0;
unsigned int rxid;
if (FlagInterrupt)
{
cnt = Num;

if (CAN_RxRdy[0]) {                           /* rc message on CAN Controller #1 */
      CAN_RxRdy[0] = 0;
	  val_Rx = CAN_RxMsg[0].data[0];
	  rxid = CAN_RxMsg[0].id;
   }
   if (val_Rx == 0xAF){
   	delay_ms(1000);
	RGBLED_ColorSET(2,Kck_RX_Color);
	delay_ms(100);
	RGBLED_ColorCLR(2,Kck_RX_Color);
	GLCD_Initalize();
	delay_ms(10);
   }
//   sprintf(a,"RX: %06d",val_Rx);
//
//	GLCD_GoTo(0,5);
//	GLCD_WriteString(a);	
	
		
delay_ms(10);

sprintf(a,"ID: %02d",rxid);

//	GLCD_GoTo(0,6);
//	GLCD_WriteString(a);


if(k == 1)
	{
	Handling_Left (0,0,0,&m,&n,&p);
	counter = k;
	}
else if(k == 2)
	{
	Handling_Right (0,0,0,&m,&n,&p);
	counter = k;
	}
else if(k == 3)
	{
	Kicker (0,0,0,0,0,&m,&n,&p);
	counter = k;
	}
else if(k == 4)
	{
	Power (0,0,0,0,0,0,0,0,0,0,&beep);
	counter = k;
	}
else if (k == 8)
	{
	Main_Page(0,0,0,0);
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
else if (k == 5)
{
		if(counter == 8)
		//	Lock(1);
		GLCD_Initalize();

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
		if(counter == 4)
			Num = PWR_BEEP;
		    
		if(counter == 3)
			Num = KCK_KCK;	

		if(counter == 1)
			Num = BHL_CW;

		if(counter == 2)
			Num = BHR_CW;

		if(counter == 8)
			Lock(1);
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
}

//sprintf(k2,"K: %01d C: %01d",k,counter);
//GLCD_GoTo(0,6);
//GLCD_WriteString(k2);

k = Key_Read();

if (cnt == Num)
Num = 0;
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
Back_Btn.Y2 = 12;

/////////////////////////////////////////////

BCKL_Btn.X1 = 39;
BCKL_Btn.X2 = 99;
BCKL_Btn.Y1 = 0;
BCKL_Btn.Y2 = 12;

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



