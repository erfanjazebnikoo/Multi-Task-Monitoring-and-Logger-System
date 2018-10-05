#include "initialization.h"

unsigned int val_Tx = 0, val_Rx = 0;            /* Globals used for display */
unsigned int rxid;
char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//char Touch_X[40],Touch_Y[40];
int x,y,i=0;
int j=0;
int Touch_X,Touch_Y;
int Lock_State;


//int m,n,p,beep;
//int Lock_State,i=0;
//int h;
char a[20];
//static int k = 8;
//static int flag;



  FILE *f;
  BOOL append=0;
  char Temp[40];
  U32 TimeTemp;
  char fname[40];
/*------------------------------------------------------------------------------
  convert one byte to string in hexadecimal notation
 *------------------------------------------------------------------------------*/
void Hex_Str (unsigned char hex, char *str) {
  *str++ = '0';
  *str++ = 'x';
  *str++ = hex_chars[hex >>  4];
  *str++ = hex_chars[hex & 0xF];
}

/*----------------------------------------------------------------------------
 *        Main: 
 *---------------------------------------------------------------------------*/
int main (void) {
char k[30],z[30];
main_init();


GLCD_ClearScreen();


GLCD_Bitmap(my_pic,1,0,126,64);
GLCD_GoTo(0,6);
GLCD_WriteString("Multi-Task-Monitoring");
GLCD_GoTo(0,7);
GLCD_WriteString("  and-Logger-System  ");
delay_ms(1500);
GLCD_GoTo(0,6);
GLCD_WriteString("  Erfan Jazeb Nikoo  ");
GLCD_GoTo(0,7);
GLCD_WriteString("    2010 - 2011      ");
delay_ms(1500);
GLCD_ClearScreen();
while(1){


//for(y=0;y<64;y++){
//	for(x=0;x<128;x++)
//		GLCD_SetPixel(x,y,0);
//}



//
//  CAN_TxMsg[1].id = 1;                           /* initialise message to send */
//  for (j = 0; j < 8; j++) CAN_TxMsg[0].data[j] = 0;
//  CAN_TxMsg[1].len = 1;
//  CAN_TxMsg[1].format = STANDARD_FORMAT;
//  CAN_TxMsg[1].type = DATA_FRAME;
//	
//
//	val_Tx=7;
//     if (CAN_TxRdy[1]) {                           /* tx message on CAN Controller #2 */
//      CAN_TxRdy[1] = 0;
//
//      CAN_TxMsg[1].data[0] = val_Tx;             /* data[0] field = ADC value */
//      CAN_wrMsg (2, &CAN_TxMsg[1]);               /* transmit message */
//    }
//
//	delay_ms(50);
//
//  CAN_TxMsg[1].id = 2;                           /* initialise message to send */
//  for (j = 0; j < 8; j++) CAN_TxMsg[0].data[j] = 0;
//  CAN_TxMsg[1].len = 1;
//  CAN_TxMsg[1].format = STANDARD_FORMAT;
//  CAN_TxMsg[1].type = DATA_FRAME;
//	
//
//	val_Tx=20;
//     if (CAN_TxRdy[1]) {                           /* tx message on CAN Controller #2 */
//      CAN_TxRdy[1] = 0;
//
//      CAN_TxMsg[1].data[0] = val_Tx;             /* data[0] field = ADC value */
//      CAN_wrMsg (2, &CAN_TxMsg[1]);               /* transmit message */
//    }
//
//    delay_ms (10); 

//CAN_TxMsg[1].id = 35;                           /* initialise message to send */
//  for (j = 0; j < 8; j++) CAN_TxMsg[0].data[j] = 0;
//  CAN_TxMsg[1].len = 1;
//  CAN_TxMsg[1].format = STANDARD_FORMAT;
//  CAN_TxMsg[1].type = DATA_FRAME;
//	
//
//	val_Tx=24;
//     if (CAN_TxRdy[1]) {                           /* tx message on CAN Controller #2 */
//      CAN_TxRdy[1] = 0;
//
//      CAN_TxMsg[1].data[0] = val_Tx;             /* data[0] field = ADC value */
//      CAN_wrMsg (2, &CAN_TxMsg[1]);               /* transmit message */
//    }
//
//    delay_ms (500);

//	val_Tx=23;
//     if (CAN_TxRdy[1]) {                           /* tx message on CAN Controller #2 */
//      CAN_TxRdy[1] = 0;
//
//      CAN_TxMsg[1].data[0] = val_Tx;             /* data[0] field = ADC value */
//      CAN_wrMsg (2, &CAN_TxMsg[1]);               /* transmit message */
//    }
//
//    delay_ms (500);

Lock(0);

 
		

Multi_Tasking();








//Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
//GLCD_GoTo(0,4);
//GLCD_WriteString("|    Calibration    |");
//GLCD_GoTo(0,5);
//GLCD_WriteString("|-------------------|");
//GLCD_GoTo(0,6);
//GLCD_WriteString("| Monitoring System |");
//
////if(TCIsPenOn())
////Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
////else
////Clrb(GLCD_BCKL_CLR,GLCD_BCKL_PIN);
//if(TCIsPenOn()){
//TCRead();
//	x = TCGetX()/(26.8)-12; 
//	y = TCGetY()/(46.4)-12;	
//}
//else{
//	x = 0;
//	y = 0;
//}
//
//sprintf(Touch_X,"X: %04d",x);
//sprintf(Touch_Y,"Y: %04d",y);
//
//GLCD_GoTo(0,0);
//GLCD_WriteString(Touch_X);
//GLCD_GoTo(0,2);
//GLCD_WriteString(Touch_Y);

 }
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
