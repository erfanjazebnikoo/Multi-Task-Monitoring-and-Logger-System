//Using  : The source code is intended to be used at selected operation mode of AD7843.
//Description : 

#ifndef _TC_AD7843_H_
#define _TC_AD7843_H_

void TCInit(void); //initial touch screen controller
unsigned short TCGetX(void); //call this after TCRead() to get X value
unsigned short TCGetY(void); //call this after TCRead() to get Y value
unsigned short TCIsPenOn(void); //TC_PEN_PIN is 0 when the screen is pressed
void TCRead(void); //read analog voltage

#endif
