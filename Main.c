#include "initialization.h"

unsigned int val_Tx = 0, val_Rx = 0;            /* Globals used for display */
unsigned int rxid;
char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char Touch_X[40],Touch_Y[40];
int x,y,i;


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

main_init();

//GLCD_ClearScreen();
//	GLCD_GoTo(31,7);
//	GLCD_WriteString(" |BCKL: OFF|");

while(1){

//Multi_Tasking();


//GLCD_GoTo(0,4);
//GLCD_WriteString("| Monitoring System |");
//
//if(TCIsPenOn())
//Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);
//else
//Clrb(GLCD_BCKL_CLR,GLCD_BCKL_PIN);
//if(TCIsPenOn()){
//TCRead();
//	x = (TCGetX() - 220) / 28;
//	y = (TCGetY() - 500) / 45;	
//}
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

 }
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/