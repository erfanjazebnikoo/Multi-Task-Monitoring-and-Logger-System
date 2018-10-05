#include "initialization.h"

int z=0;
static int key =1;


//////////////////////////////////////////////////////////////////////////////

void IO_Init (void) {

PINSEL0 |= 0x80000000;						//SCLK0
PINSEL1 |= 0x00000028;						//MISO0 MOSI0
Orb(TC_CS_DPRT,TC_CS_PIN);
SCS |= 0x00000001;
Orb(GLCD_BCKL_PORT,GLCD_BCKL_PIN);
//
Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);

}
//////////////////////////////////////////////////////////////////////////////

void RGBLED_init (void) {

Orb(RGBLED_PORT,RGBLED1_B);
delay_ms(10);
Orb(RGBLED_PORT,RGBLED1_G);
delay_ms(10);
Orb(RGBLED_PORT,RGBLED1_R);
delay_ms(10);
Orb(RGBLED_PORT,RGBLED2_B);
delay_ms(10);
Orb(RGBLED_PORT,RGBLED2_G);
delay_ms(10);
Orb(RGBLED_PORT,RGBLED2_R);
delay_ms(10);

Setb(RGBLED_SET,RGBLED1_B);
delay_ms(10);
Setb(RGBLED_SET,RGBLED1_G);
delay_ms(10);
Setb(RGBLED_SET,RGBLED1_R);
delay_ms(10);
Setb(RGBLED_SET,RGBLED2_B);
delay_ms(10);
Setb(RGBLED_SET,RGBLED2_G);
delay_ms(10);
Setb(RGBLED_SET,RGBLED2_R);
delay_ms(10);

}

//////////////////////////////////////////////////////////////////////////////

//void card_Init (void) {
//   U32 i; 
//
// while (finit() != 0)
//		for(i=0;i<=0x00FFFFFF;i++);
// }

/////////////////////////////////////////////////////////////////////////////

void can_Init (void) {

  CAN_setup (1);                                  /* setup CAN Controller #1 */
  CAN_setup (2);                                  /* setup CAN Controller #2 */
 // CAN_wrFilter (1, 0x30, STANDARD_FORMAT);          /* Enable reception of messages */

  CAN_start (1);                                  /* start CAN Controller #2 */
  CAN_start (2);                                  /* start CAN Controller #2 */

  CAN_waitReady (1);                              /* wait til tx mbx is empty */
  CAN_waitReady (2);                              /* wait til tx mbx is empty */
}

/////////////////////////////////////////////////////////////////////////////////

int Touch_Lock(void){
static U32 KeyPushCounter,KeyMem,KeyLastState;
if (!(FIO1PIN & (1<<29)))
KeyMem = 1;
else
KeyMem = 0;

if (KeyMem)
	{
	KeyLastState = KeyMem; KeyPushCounter = 0;
	while ((KeyMem == KeyLastState)&&(KeyPushCounter < 150))
		{
		KeyLastState = KeyMem;
		if ((FIO1PIN & (1<<29)))
		KeyMem = 0;
		else
		KeyMem = 1;
		KeyPushCounter++;
		delay_ms(10);
		}
	if (KeyPushCounter < 150)
		return (KeyLastState);
	else
		return (KeyLastState+9);
	}
return 0;
}

/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////

int Lock_Screen(int State){

int Touch_X,Touch_Y;
int Lock_State,j=0;
if(State == 0)
{
	key = Touch_Lock();

	if(Touch_Lock()>1)
		Lock_State=key;

	if(TCIsPenOn()){
		TCRead();
	Touch_X = TCGetX()/(26.8)-12; 
	Touch_Y = TCGetY()/(46.4)-12;	
	}
else
{
	Touch_X = 0;
	Touch_Y = 0;
}

if(0<Touch_X && Touch_X<37){
	if(0<Touch_Y && Touch_Y<13){
		j++;
		if(j>100){
		j=0;
		Lock_State=0;
		} 	
}	
}
return Lock_State;
}
if (State == 1)
return 10;
}

/////////////////////////////////////////////////////////////////////////////////
void Lock(int j){
int Lock_State;
Lock_State = Lock_Screen(j);
if(Lock_State==10){
if(z==0){
GLCD_ClearScreen();
z++;
}
GLCD_Bitmap(my_pic,1,0,126,64);
GLCD_GoTo(0,7);
GLCD_WriteString("        ");
GLCD_GoTo(0,7);
GLCD_WriteString("|Unlock|");
GLCD_GoTo(0,6);
GLCD_WriteString("                     ");
GLCD_GoTo(0,6);
GLCD_WriteString("| Monitoring System |");
}
else if(Lock_State==0){
z=0;
Multi_Tasking();
}

}


/////////////////////////////////////////////////////////////////////////////////

void CfgTabInterrupt (void)
{
//Timer 0 Config
T0MR0 	= PCLK / 10; //100ms
T0TCR  |= 0x01;
T0CTCR |= 0x00;
T0MCR  |= ((1 << 0)|(1 << 1));
//Timer 1 Config
T1MR0 	= PCLK / 1000; //1ms
T1TCR  |= 0x01;
T1CTCR |= 0x00;
T1MCR  |= ((1 << 0)|(1 << 1));
}

/////////////////////////////////////////////////////////////////////////////////

void CfgInterrupts (void)
{
//install_irq( TIMER0_INT  , (void *)Tab_Interrupt , 2);
install_irq( TIMER1_INT  , (void *)FlagCounter , 1);
}

/////////////////////////////////////////////////////////////////////////////////

void Welcome (void)
{
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
}

/////////////////////////////////////////////////////////////////////////////////

void main_init (void) {

CfgTabInterrupt	();
init_VIC		();
CfgInterrupts 	();

IO_Init();
GLCD_Initalize	();
RGBLED_init		();

#ifdef RT_AGENT
  RTA_Init();                                     /* Initialize Real-Time Agent  */
#endif
  //card_Init ();
can_Init 		();

Setb(TC_CS_PRTS,TC_CS_PIN);

TCInit			();
//delay_ms(1000);
//GLCD_Initalize	();

}
