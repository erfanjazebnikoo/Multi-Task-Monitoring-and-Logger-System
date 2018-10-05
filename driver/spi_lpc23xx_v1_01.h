//Using  : Use for interfacing with SPI of LPC23xx
//Description : please predefine device index of interface, 
//	for example #define RTC		0 --> using SPI port 0 with Real-time clock
//
//Important Note *********************************************
//if your buffer size is more than 254 please define SPI_BUF_CNT_TYPE
//as unsigned short or unsigned long

#ifndef _SPI_H_
#define _SPI_H_

#define MAX_SPI				2

#define SSP_CR0				0x00
#define SSP_CR1				0x04
#define SSP_DR				0x08
#define SSP_SR				0x0C
#define SSP_CPSR			0x10
#define SSP_IMSC			0x14
#define SSP_RIS				0x18
#define SSP_MIS				0x1C
#define SSP_ICR				0x20
#define SSP_DMACR			0x24

#define SPI_ENABLE			0x02

#define SPI_MSB_FIRST		0x0000

#define SPI_MASTER			0x0000
#define SPI_SLAVE			0x0040
							  
#define SPI_FAL_FIRST		0x0040
#define SPI_RIS_FIRST		0x0000

#define SPI_SET_FIRST		0x0080
#define SPI_SAM_FIRST		0x0000

#define SPI_TNF				0x02
#define SPI_RNE				0x04

typedef enum 
{
	SPI_IDLE,
	SPI_BUSY
} spi_status_t;

void SPIMasterEnable(unsigned char dev,	//set SPI master mode
	unsigned int clk_pol,unsigned int clk_phase,
	unsigned int clk_div,unsigned int order,
	unsigned int int_mask,unsigned int data_size);
void SPIMasterDisable(unsigned char dev); //disable SPI
void SPIMasterTransfer(unsigned char dev,int len, unsigned short *buf); //transfer data from buf and also put received data in buf
void SPIMasterTransfer2(unsigned char dev,int len, unsigned char *buf); //transfer data from buf and also put received data in buf
unsigned char SPIIsBusy(unsigned char dev); //return 1 if SPI is busy, supposed to be used with interrupt mode

#endif

