/************************************************************************
* Project : Multi Task Monitoring and Logger System
* Version : V1.0
* Date    : 06/29/2011
* Author  : Erfan Jazeb Nikoo
* Compiler: KEIL uVision V4.01
* Chip type           : LPC2368 NXP ARM7
* Clock frequency     : 12.000000 MHz
************************************************************************/

#include "Logger.h"

int temp=-1;
FILE *f;
BOOL append=0;
char Temp1[40],Temp2[40],Temp3[40],Temp4[40],Temp5[40],Temp6[40],Temp7[40],Temp8[40];
char fname[40];	
int number =0;

void Make_Log (void)
{

if(temp != min)
{
	if(temp != -1)
		fclose (f);
	if(temp == -1)
	sprintf(fname,"%02d_%02d_%02d_Start.c",hour,min,sec);														
	else
	sprintf(fname,"%02d_%02d_%02d.c",hour,min,sec);
    f = fopen (fname,append ? "a" : "w");
	temp = min;
}
}


void Write_File (void)
{
char data_rx[8];
int status=0;
int i;

if (RxID == Kicker_Rx_ID)
{
	if(Rx_Data.Rx_Data0 == 0xAF)
	{
		sprintf(Temp1,"%03d Kicker(0x31) 0xAF %02d:%02d:%02d %02d/%02d/%04d  \r\n\n",number,hour,min,sec,month,day,year);
		fputs (Temp1, f);
		sprintf(Temp2,"\t 24V Battrey: %02.01f V  Capacitors Voltage: %02.01f V  Shoot Status: %01d  Fuse Status: %01d  Kicker Status: %01d  \r\n\n",
				Rx_Data.Input_Vol/10,Rx_Data.Cap_Vol/10,Rx_Data.Shoot_Status,Rx_Data.Fuse_Status,Rx_Data.Kicker_Status);
		fputs (Temp2, f);
		number +=1;
	}

	if(Rx_Data.Rx_Data0 == 0xCE)
	{
		sprintf(Temp3,"%03d Kicker(0x31) 0xCE %02d:%02d:%02d %02d/%02d/%04d  \r\n\n",number,hour,min,sec,month,day,year);
		fputs (Temp3, f);
		sprintf(Temp4,"\t KICK!  \n\n");
		fputs (Temp4, f);
		number +=1;
	}

}
if (RxID == Power_Rx_ID1)
{
	if(Rx_Data.Rx_Data0 == 0x12)
	{		
		sprintf(Temp5,"%03d Power(0x41) 0x12 %02d:%02d:%02d %02d/%02d/%04d  \r\n\n",number,hour,min,sec,month,day,year);
		fputs (Temp5, f);
		sprintf(Temp6,"\t 48V Battrey Cell 1: %02.01f V  48V Battrey Cell 2: %02.01f V  48V Battrey Total: %02.01f V  \n\n",
				Rx_Data.BT48V_Cell1/10,Rx_Data.BT48V_Cell2/10,Rx_Data.BT48V/10);
		fputs (Temp6, f);
		number +=1;      
	}
}

if (RxID == Power_Rx_ID2)
{
	if(Rx_Data.Rx_Data0 == 0x15 )
	{	
		sprintf(Temp7,"%03d Power(0x51) 0x15 %02d:%02d:%02d %02d/%02d/%04d  \r\n\n",number,hour,min,sec,month,day,year);
		fputs (Temp7, f);
		sprintf(Temp8,"\t General Key Status: %01d  Vision Reset Key Status: %01d  IR 1 Status: %01d  IR 2 Status: %01d  \n\n",
				Rx_Data.General_Key,Rx_Data.Vision_Reset,Rx_Data.IR1,Rx_Data.IR2);
		fputs (Temp8, f);
		number +=1;			
	}
}

}


void Logging (void)
{

Make_Log();
Write_File();
//fputs (Temp1, f);
//fputs (Temp2, f);
//fputs (Temp3, f);
//fputs (Temp4, f);
//fputs (Temp5, f);
//fputs (Temp6, f);
//fputs (Temp7, f);
//fputs (Temp8, f);
			

}
