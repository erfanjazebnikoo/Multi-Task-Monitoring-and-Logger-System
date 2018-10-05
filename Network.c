#include "Network.h"

DATA data;
static char flagKCK;
static char flagset;
Rx_Var Rx_Data;

////////////////////////////////////////////////////////////////////////////
///////////////////////////CAN Transmitter//////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void Can_Tx	(int TabNum)
{
	if(TabNum == BHL_CW)
	{
		data.D0 = Handeling_EN;
		data.D1 = (char)(Handeling_Spd_CW >>8 & 0xFF);
		data.D2 = (char)(Handeling_Spd_CW & 0xFF);
		RGBLED_ColorSET(1,BHL_TX_Color);
		can_Send (Handeling_ID , 5 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,BHL_TX_Color);
		delay_ms (10);
	}
	else if(TabNum == BHL_CCW)
	{
		data.D0 = Handeling_EN;
		data.D1 = (char)(Handeling_Spd_CCW >>8 & 0xFF);
		data.D2 = (char)(Handeling_Spd_CCW & 0xFF);
		RGBLED_ColorSET(1,BHL_TX_Color);
		can_Send (Handeling_ID , 5 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,BHL_TX_Color);
		delay_ms (10);
	}
	else if(TabNum == BHL_STP)
	{
		data.D0 = Handeling_EN;
		data.D1 = 0x00;
		data.D2 = 0x00;
		RGBLED_ColorSET(1,BHL_TX_Color);
		can_Send (Handeling_ID , 5 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,BHL_TX_Color);
		delay_ms (10);
	}
	else if(TabNum == BHR_CW)
	{
		data.D0 = Handeling_EN;
		data.D3 = (char)(Handeling_Spd_CW >>8 & 0xFF);
		data.D4 = (char)(Handeling_Spd_CW & 0xFF);
		RGBLED_ColorSET(1,BHR_TX_Color);
		can_Send (Handeling_ID , 5 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,BHR_TX_Color);
		delay_ms (10);
	}
	else if(TabNum == BHR_CCW)
	{
		data.D0 = Handeling_EN;
		data.D3 = (char)(Handeling_Spd_CCW >>8 & 0xFF);
		data.D4 = (char)(Handeling_Spd_CCW & 0xFF);
		RGBLED_ColorSET(1,BHR_TX_Color);
		can_Send (Handeling_ID , 5 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,BHR_TX_Color);
		delay_ms (10);
	}
	else if(TabNum == BHR_STP)
	{
		data.D0 = Handeling_EN;
		data.D3 = 0x00;
		data.D4 = 0x00;
		RGBLED_ColorSET(1,BHR_TX_Color);
		can_Send (Handeling_ID , 5 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,BHR_TX_Color);
		delay_ms (10);
	}
	else if(TabNum == KCK_KCK)
	{
		data.D0 = BEEP;
		RGBLED_ColorSET(1,Pwr_TX_Color);
		can_Send (Power_ID , 1 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,Pwr_TX_Color);
	 	delay_ms (500);
		RGBLED_ColorSET(1,Pwr_TX_Color);
		can_Send (Power_ID , 1 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,Pwr_TX_Color);
	 	delay_ms (500);
		RGBLED_ColorSET(1,Pwr_TX_Color);
		can_Send (Power_ID , 1 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,Pwr_TX_Color);
	 	delay_ms (500);
		data.D0 = Kicker_EN;
		data.D1 = (char)(Kicker_Pwr >>8 & 0xFF);
		data.D2 = (char)(Kicker_Pwr & 0xFF);
		RGBLED_ColorSET(1,Kck_TX_Color);
		can_Send (Kicker_ID , 3 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,Kck_TX_Color);
		delay_ms (10);
	}
	else if(TabNum == KCK_ChS)
	{
		data.D0 = Kicker_EN;
		data.D1 = 0x00;
		data.D2 = 0x00;
		if (flagset)
			{
			data.D3 = 0x01;
			flagset = 0;
			}
		else
			{
			data.D3 = 0x02;
			flagset = 1;
			}
		RGBLED_ColorSET(1,Kck_TX_Color);
		can_Send (Kicker_ID , 4 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,Kck_TX_Color);
		delay_ms (1000);
	}
	else if(TabNum == KCK_ED)
	{
		data.D0 = 0xDE;
		if (flagKCK)
			{
			data.D1 = 0x01;
			flagKCK = 0;
			}
		else
			{
			data.D1 = 0x00;
			flagKCK = 1;
			}
		RGBLED_ColorSET(1,Kck_TX_Color);
		can_Send (Kicker_ID , 2 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,Kck_TX_Color);
		delay_ms (1000);
	}
	else if(TabNum == PWR_BEEP)
	{
		data.D0 = BEEP;
		RGBLED_ColorSET(1,Pwr_TX_Color);
		can_Send (Power_ID , 1 , &data);
		delay_ms(100);
		RGBLED_ColorCLR(1,Pwr_TX_Color);
	 	delay_ms (500);
	}
//	else if (TabNum == 0)
//		break;

}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void can_Send (int ID , int Data_Length , DATA *Data) 
{

	int j;
	CAN_TxMsg[1].id = ID;                  
  	for (j = 0; j < 8; j++) CAN_TxMsg[0].data[j] = 0;
  	CAN_TxMsg[1].len = Data_Length;
  	CAN_TxMsg[1].format = STANDARD_FORMAT;
  	CAN_TxMsg[1].type = DATA_FRAME;
	 
    if (CAN_TxRdy[1]) 
	{                          
    	CAN_TxRdy[1] = 0;
		CAN_TxMsg[1].data[0] = Data->D0;
		CAN_TxMsg[1].data[1] = Data->D1;
		CAN_TxMsg[1].data[2] = Data->D2;
		CAN_TxMsg[1].data[3] = Data->D3;
		CAN_TxMsg[1].data[4] = Data->D4;
		CAN_TxMsg[1].data[5] = Data->D5;
		CAN_TxMsg[1].data[6] = Data->D6;
		CAN_TxMsg[1].data[7] = Data->D7;
      	CAN_wrMsg (2, &CAN_TxMsg[1]);           
	}
    delay_ms (10);
}

////////////////////////////////////////////////////////////////////////////
//////////////////////////// CAN Reciever //////////////////////////////////
///////////////////////////////////////////////////////////////////////////;

void Can_Rx (void)
{
static char flagK,flagP1,flagP2;
char RxID;
char data_rx[8];
int i;


	if (CAN_RxRdy[0]) 
	{                           
      	CAN_RxRdy[0] = 0;
	  //	val_Rx = CAN_RxMsg[0].data[0];
	  	RxID = CAN_RxMsg[0].id;
		for(i=0;i<8;i++)
		data_rx[i] = CAN_RxMsg[0].data[i];
		RGBLED_ColorCLR(1,NoCAN_TX_Color);
		RGBLED_ColorCLR(2,NoCAN_RX_Color);
	}
//	else
//	{
//	 	if (CounterFlag>1000)
//		{
//			RGBLED_ColorSET(1,NoCAN_TX_Color);
//			RGBLED_ColorSET(2,NoCAN_RX_Color);
//			
//		}
//		if (CounterFlag>2000)
//		{
//			RGBLED_ColorCLR(1,NoCAN_TX_Color);
//			RGBLED_ColorCLR(2,NoCAN_RX_Color);	
//		}
//		CounterFlag = 0;
//
//	}
//		if (Handeling_L_Rx_ID)
//		{
//
//		}
//		else if (Handeling_R_Rx_ID)
//		{
//
//		}
		if (RxID == Kicker_Rx_ID)
		{
			if(CAN_RxMsg[0].data[0] == 0xCE)
			{
			 	delay_ms(1000);
				if (flagK)
					{
					flagK = 0;
					RGBLED_ColorSET(2,Kck_RX_Color);
					}
				else
					{
					flagK = 1;	
					RGBLED_ColorCLR(2,Kck_RX_Color);	
					}
				GLCD_Initalize();
			}
			else if(data_rx[0] == 0xAF)
			{				
				Rx_Data.Cap_Vol = (data_rx[1] <<8) + data_rx[2];      
				Rx_Data.Input_Vol = data_rx[3];
				Rx_Data.Kicker_Status = data_rx[4];
				Rx_Data.Shoot_Status = data_rx[5];
				Rx_Data.Fuse_Status = data_rx[6];
				if (flagK)
					{
					flagK = 0;
					RGBLED_ColorSET(2,Kck_RX_Color);
					}
				else
					{
					flagK = 1;	
					RGBLED_ColorCLR(2,Kck_RX_Color);	
					}		
			}

		}
		else if (RxID == Power_Rx_ID1)
		{
		 	if(data_rx[0] == 0x12)
			{	
			
				Rx_Data.BT48V_Cell1 = (data_rx[1] <<8) + data_rx[2];
				Rx_Data.BT48V_Cell2 = (data_rx[3] <<8) + data_rx[4];
				Rx_Data.BT48V = (data_rx[5] <<8) + data_rx[6];      
				
				if (flagP1)
					{
					flagP1 = 0;
					RGBLED_ColorSET(2,Pwr_RX_Color);
					}
				else
					{
					flagP1 = 1;	
					RGBLED_ColorCLR(2,Pwr_RX_Color);	
					}		
			}
		}


		else if (RxID == Power_Rx_ID2)
		{
		 	if(data_rx[0] == 0x15)
			{	
			
				Rx_Data.General_Key = data_rx[1];
				Rx_Data.Vision_Reset = data_rx[2];
				Rx_Data.IR1 = data_rx[3];      
				Rx_Data.IR2 = data_rx[4];
				
				if (flagP2)
					{
					flagP2 = 0;
					RGBLED_ColorSET(2,Pwr_RX_Color);
					}
				else
					{
					flagP2 = 1;	
					RGBLED_ColorCLR(2,Pwr_RX_Color);	
					}		
			}
		}
	
}

/////////////////////////////////////////////////////////////////////////////////

//if (CAN_RxRdy[0]) {                           /* rc message on CAN Controller #1 */
//      CAN_RxRdy[0] = 0;
//	  val_Rx = CAN_RxMsg[0].data[0];
//	  rxid = CAN_RxMsg[0].id;
//   }
//   if (val_Rx == 206){
//   	delay_ms(1000);
//	RGBLED_ColorSET(2,Kck_RX_Color);
//	delay_ms(100);
//	RGBLED_ColorCLR(2,Kck_RX_Color);
//	GLCD_Initalize();
//	delay_ms(10);
//   }


