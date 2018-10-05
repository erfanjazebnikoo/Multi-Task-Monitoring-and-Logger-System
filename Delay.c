/*****************************************************************************
*File: Delay.c
******************************************************************************/
//presentation Header file
#ifndef _DELAY_INCLUDED_
#define _DELAY_INCLUDED_
//presentation variable
unsigned long crystal=21900000;  // for other crystal change 18432000
unsigned long ddx;
unsigned long ddy;


/////////////////////////////////////////////////////////////////////////////////
// sub delay_us 
void delay_us(unsigned long dda){
do{
unsigned long ddd=0;
ddx=crystal/50000000;	 //
for (ddd=0;ddd<ddx;ddd++);	 //start the VALUE off d is 0 ,  increase  d , 
//if d > x goto next line ,else (d<x) increase d
ddy++;   // increase y 
} while(ddy<dda);  //if y > a goto next line ,else (y<a) goto "do{"
ddy=0;
}
////////////////////////////////////////////////////////////////////////////////
//in mine program , you write "delay_s(4);" . in this Header "a" is 4 & do-while 
//loop repeat 4 ---time = (x*5)/ crystal
// sub delay_ms
void delay_ms(unsigned long ddb){
do{
unsigned long dde=0;
ddx=crystal/5000;	
for (dde=0;dde<ddx;dde++);
ddy++;
} while(ddy<ddb);
ddy=0;
}
// sub delay_s
void delay_s(unsigned long ddc){
do{
unsigned long ddf=0;
ddx=crystal/5;
for (ddf=0;ddf<ddx;ddf++);
ddy++;
} while(ddy<ddc);
ddy=0;
}
#endif
