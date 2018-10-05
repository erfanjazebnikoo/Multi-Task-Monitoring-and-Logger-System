#include "app_config.h"


#define TC_SPI_WIDTH	15 //use 15 clock per 1 SPI cycle
#define TC_CR_Y			0x90 << (TC_SPI_WIDTH - 8) //DFR = 0, PD = 00
#define TC_CR_X			0xD0 << (TC_SPI_WIDTH - 8) //DFR = 0, PD = 00


volatile unsigned short tc_x,tc_y;
extern void delay_1ms(unsigned int n);

unsigned short TCGetX(void) //call this after TCRead() to get X value
{
	return (tc_x);
}

unsigned short TCGetY(void) //call this after TCRead() to get Y value
{
	return (tc_y);
}

unsigned short TCIsPenOn(void) //TC_PEN_PIN is 0 when the screen is pressed
{	
	if (!(TC_PEN_PINP & (1 << TC_PEN_PIN)))
		return (1); 
	return (0);
}

unsigned short spi_buf[16];

void TCInit(void)
{

	Setb(TC_CS_PRTS,TC_CS_PIN);
	TCRead(); //Wake it up
}

void TCRead(void) //read analog voltage
{
	spi_buf[0] = TC_CR_Y; //read Y first
	spi_buf[1] = TC_CR_X; //then read X
	spi_buf[2] = 0; //3rd word is not used

	SPIMasterEnable(TC_SPI,SPI_RIS_FIRST,SPI_SAM_FIRST,4,0,0,TC_SPI_WIDTH - 1); 
	//initiate SPI, depend on your controller
	//TC_SPI -> SPI device
	//SPI_RIS_FIRST -> rising edge first (CPOL)
	//SPI_SAM_FIRST -> sampling before setting (CPHASE)
	//3 -> clock divider
	//0 -> MSB first (LPC23XX have only this mode)
	//0 -> no interrupt mask set
	//TC_SPI_WIDTH - 1 -> data size = TC_SPI_WIDTH
																			 
	Orb(TC_CS_DPRT,TC_CS_PIN);	//set TC_CS to be output port
	Clrb(TC_CS_PRTC,TC_CS_PIN); //clear TC_CS to 0

	SPIMasterTransfer(TC_SPI,3,spi_buf); //transfer data for 3 cycles

	Setb(TC_CS_PRTS,TC_CS_PIN); //set TC_CS to 1

	SPIMasterDisable(TC_SPI); //disable interrupt

	tc_y = (spi_buf[0] << 6) | (spi_buf[1] >> 9); //arrange received data
	tc_x = ((spi_buf[1] & 0x3F) << 6) | (spi_buf[2] >> 9); //arrange received data
}
