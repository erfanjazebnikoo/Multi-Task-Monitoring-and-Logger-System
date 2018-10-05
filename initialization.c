#include "initialization.h"

//////////////////////////////////////////////////////////////////////////////

void IO_Init (void) {

PINSEL0 |= 0x80000000;						//SCLK0
PINSEL1 |= 0x00000028;						//MISO0 MOSI0
Orb(TC_CS_DPRT,TC_CS_PIN);
SCS |= 0x00000001;
Orb(GLCD_BCKL_PORT,GLCD_BCKL_PIN);
Setb(GLCD_BCKL_SET,GLCD_BCKL_PIN);

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
//  CAN_wrFilter (1, 45, STANDARD_FORMAT);          /* Enable reception of messages */

  CAN_start (1);                                  /* start CAN Controller #2 */
  CAN_start (2);                                  /* start CAN Controller #2 */

  CAN_waitReady (1);                              /* wait til tx mbx is empty */
  CAN_waitReady (2);                              /* wait til tx mbx is empty */
}

/////////////////////////////////////////////////////////////////////////////////

void main_init (void) {
int i;

IO_Init();

GLCD_Initalize();

#ifdef RT_AGENT
  RTA_Init();                                     /* Initialize Real-Time Agent  */
#endif
  //card_Init ();
  can_Init ();

Setb(TC_CS_PRTS,TC_CS_PIN);

TCInit();
for(i=0;i<100;i++);





}
