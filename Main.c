#include "initialization.h"

int test =0;
int test2 =0;
unsigned int val_Tx = 0, val_Rx = 0;            /* Globals used for display */
unsigned int rxid;
char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//char Touch_X[40],Touch_Y[40];
unsigned int x,y,i=0;
int j=0;
int Touch_X,Touch_Y;
int Lock_State;
int InterruptFlag=0;
int CounterFlag = 0;
char k[30];



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

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Interrupt /////////////////////////////////////////
//void Tab_Interrupt(void) __irq {
//static U8 fflag;
////Multi_Tasking(InterruptFlag);
//if(InterruptFlag < 20)
//InterruptFlag++;
////GLCD_GoTo(0,6);
////sprintf(k,"adad: %06d",test);
////GLCD_WriteString(k);
////test++;
//T0IR = 0x01;
//VICVectAddr = 0;		/* Acknowledge Interrupt */
//}

/////////////////////////////////////////////////////////////////////////////////

void FlagCounter(void) __irq {

CounterFlag++;
T1IR = 0x01;
VICVectAddr = 0;		/* Acknowledge Interrupt */

}

/*----------------------------------------------------------------------------
 *        Main: 
 *---------------------------------------------------------------------------*/
int main (void) {
char RxID;
main_init();


GLCD_ClearScreen();
						
Welcome();

for(;;){

Lock(0);
//
Can_Rx();
Multi_Tasking();
Can_Tx (SendToCan());

//
//
//
//
////Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
////GLCD_GoTo(0,4);
////GLCD_WriteString("|    Calibration    |");
////GLCD_GoTo(0,5);
////GLCD_WriteString("|-------------------|");
////GLCD_GoTo(0,6);
////GLCD_WriteString("| Monitoring System |");
////
//////if(TCIsPenOn())
//////Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
//////else
//////Clrb(GLCD_BCKL_CLR,GLCD_BCKL_PIN);
////if(TCIsPenOn()){
////TCRead();
////	x = TCGetX()/(26.8)-12; 
////	y = TCGetY()/(46.4)-12;	
////}
////else{
////	x = 0;
////	y = 0;
////}
////
////sprintf(Touch_X,"X: %04d",x);
////sprintf(Touch_Y,"Y: %04d",y);
////
////GLCD_GoTo(0,0);
////GLCD_WriteString(Touch_X);
////GLCD_GoTo(0,2);
////GLCD_WriteString(Touch_Y);
//
 }
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
