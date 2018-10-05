#include "Network.h"

DATA data;
static char flagKCK;
static char flagset;

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

/////////////////////////////////////////////////////////////////////////////////

