#include "rgbled.h"


void RGBLED_ColorSET (int  LED_Num, int LED_Color)
{

	if (LED_Num == 1)
	{
	 	if (LED_Color == Blue)
			Clrb(RGBLED_CLR,RGBLED1_B);
		if (LED_Color == Green)
			Clrb(RGBLED_CLR,RGBLED1_G);
		if (LED_Color == Red)
			Clrb(RGBLED_CLR,RGBLED1_R);
		if (LED_Color == Cyan)
		{
			Clrb(RGBLED_CLR,RGBLED1_B);
			Clrb(RGBLED_CLR,RGBLED1_G);
		}
		if (LED_Color == Yellow)
		{
			Clrb(RGBLED_CLR,RGBLED1_G);
			Clrb(RGBLED_CLR,RGBLED1_R);
		}
		if (LED_Color == Magenta)
		{
			Clrb(RGBLED_CLR,RGBLED1_B);
			Clrb(RGBLED_CLR,RGBLED1_R);
		}
		if (LED_Color == White)
		{
			Clrb(RGBLED_CLR,RGBLED1_B);
			Clrb(RGBLED_CLR,RGBLED1_G);
			Clrb(RGBLED_CLR,RGBLED1_R);
		}
	}
	
	else if (LED_Num == 2)
	{
	 	if (LED_Color == Blue)
			Clrb(RGBLED_CLR,RGBLED2_B);
		if (LED_Color == Green)
			Clrb(RGBLED_CLR,RGBLED2_G);
		if (LED_Color == Red)
			Clrb(RGBLED_CLR,RGBLED2_R);
		if (LED_Color == Cyan)
		{
			Clrb(RGBLED_CLR,RGBLED2_B);
			Clrb(RGBLED_CLR,RGBLED2_G);
		}
		if (LED_Color == Yellow)
		{
			Clrb(RGBLED_CLR,RGBLED2_G);
			Clrb(RGBLED_CLR,RGBLED2_R);
		}
		if (LED_Color == Magenta)
		{
			Clrb(RGBLED_CLR,RGBLED2_B);
			Clrb(RGBLED_CLR,RGBLED2_R);
		}
		if (LED_Color == White)
		{
			Clrb(RGBLED_CLR,RGBLED2_B);
			Clrb(RGBLED_CLR,RGBLED2_G);
			Clrb(RGBLED_CLR,RGBLED2_R);
		}
	} 

}

void RGBLED_ColorCLR (int  LED_Num, int LED_Color)
{

	if (LED_Num == 1)
	{
	 	if (LED_Color == Blue)
			Setb(RGBLED_SET,RGBLED1_B);
		if (LED_Color == Green)
			Setb(RGBLED_SET,RGBLED1_G);
		if (LED_Color == Red)
			Setb(RGBLED_SET,RGBLED1_R);
		if (LED_Color == Cyan)
		{
			Setb(RGBLED_SET,RGBLED1_B);
			Setb(RGBLED_SET,RGBLED1_G);
		}
		if (LED_Color == Yellow)
		{
			Setb(RGBLED_SET,RGBLED1_G);
			Setb(RGBLED_SET,RGBLED1_R);
		}
		if (LED_Color == Magenta)
		{
			Setb(RGBLED_SET,RGBLED1_B);
			Setb(RGBLED_SET,RGBLED1_R);
		}
		if (LED_Color == White)
		{
			Setb(RGBLED_SET,RGBLED1_B);
			Setb(RGBLED_SET,RGBLED1_G);
			Setb(RGBLED_SET,RGBLED1_R);
		}
	}
	
	else if (LED_Num == 2)
	{
	 	if (LED_Color == Blue)
			Setb(RGBLED_SET,RGBLED2_B);
		if (LED_Color == Green)
			Setb(RGBLED_SET,RGBLED2_G);
		if (LED_Color == Red)
			Setb(RGBLED_SET,RGBLED2_R);
		if (LED_Color == Cyan)
		{
			Setb(RGBLED_SET,RGBLED2_B);
			Setb(RGBLED_SET,RGBLED2_G);
		}
		if (LED_Color == Yellow)
		{
			Setb(RGBLED_SET,RGBLED2_G);
			Setb(RGBLED_SET,RGBLED2_R);
		}
		if (LED_Color == Magenta)
		{
			Setb(RGBLED_SET,RGBLED2_B);
			Setb(RGBLED_SET,RGBLED2_R);
		}
		if (LED_Color == White)
		{
			Setb(RGBLED_SET,RGBLED2_B);
			Setb(RGBLED_SET,RGBLED2_G);
			Setb(RGBLED_SET,RGBLED2_R);
		}
	} 

}
