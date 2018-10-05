#include "app_config.h"

#ifndef SPI_BUF_CNT_TYPE
#define SPI_BUF_CNT_TYPE	unsigned char
#endif	

spi_status_t volatile spi_status[MAX_SPI] = {SPI_IDLE,SPI_IDLE};

const unsigned long spi_base[MAX_SPI] = {SSP0_BASE_ADDR,SSP1_BASE_ADDR};
unsigned char spi_int_enable[MAX_SPI];

SPI_BUF_CNT_TYPE spi_cnt[MAX_SPI];
SPI_BUF_CNT_TYPE spi_ri[MAX_SPI];
SPI_BUF_CNT_TYPE spi_wi[MAX_SPI];

void SPIMasterEnable(unsigned char dev,	//set SPI master mode
	unsigned int clk_pol,unsigned int clk_phase,
	unsigned int clk_div,unsigned int order,
	unsigned int int_mask,unsigned int data_size)
{
	unsigned int buf = clk_div << 8;
	buf |= clk_pol | clk_phase | data_size;
	(*(volatile unsigned long *)(spi_base[dev] + SSP_CR0)) = buf;
	(*(volatile unsigned long *)(spi_base[dev] + SSP_CPSR)) = 2;
	(*(volatile unsigned long *)(spi_base[dev] + SSP_IMSC)) = int_mask;

	spi_int_enable[dev] = 0;

	if (int_mask)
	{
		spi_int_enable[dev] = 1;
		//this feature is not supported in this version
	}

	(*(volatile unsigned long *)(spi_base[dev] + SSP_CR1)) |= SPI_ENABLE;
}

void SPIMasterDisable(unsigned char dev) //disable SPI
{
	(*(volatile unsigned long *)(spi_base[dev] + SSP_CR1)) &= ~SPI_ENABLE;
}

void SPIMasterTransfer(unsigned char dev, int len, unsigned short *buf) //transfer data from buf and also put received data in buf
{
	spi_status[dev] = SPI_BUSY;
	spi_cnt[dev] = len;
	spi_wi[dev] = 0;
	spi_ri[dev] = 0;

	if (spi_int_enable[dev])
	{
		//this feature is not supported in this version
	}

	if (!spi_int_enable[dev])
	{
		while (spi_wi[dev] != spi_cnt[dev])
		{
			if (((*(volatile unsigned long *)(spi_base[dev] + SSP_SR)) & SPI_TNF) && (spi_ri[dev] < len))
			{
				(*(volatile unsigned long *)(spi_base[dev] + SSP_DR)) = buf[spi_ri[dev]];
				spi_ri[dev]++;
			}

			if ((*(volatile unsigned long *)(spi_base[dev] + SSP_SR)) & SPI_RNE)
			{
				buf[spi_wi[dev]] = (*(volatile unsigned long *)(spi_base[dev] + SSP_DR));
				spi_wi[dev]++;
			}
		}
		spi_status[dev] = SPI_IDLE;
	}
}

void SPIMasterTransfer2(unsigned char dev,int len, unsigned char *buf) //transfer data from buf and also put received data in buf
{
	spi_status[dev] = SPI_BUSY;
	spi_cnt[dev] = len;
	spi_wi[dev] = 0;
	spi_ri[dev] = 0;

	if (spi_int_enable[dev])
	{
		//this feature is not supported in this version
	}

	if (!spi_int_enable[dev])
	{
		while (spi_wi[dev] != spi_cnt[dev])
		{
			if (((*(volatile unsigned long *)(spi_base[dev] + SSP_SR)) & SPI_TNF) && (spi_ri[dev] < len))
			{
				(*(volatile unsigned long *)(spi_base[dev] + SSP_DR)) = buf[spi_ri[dev]];
				spi_ri[dev]++;
			}

			if ((*(volatile unsigned long *)(spi_base[dev] + SSP_SR)) & SPI_RNE)
			{
				buf[spi_wi[dev]] = (*(volatile unsigned long *)(spi_base[dev] + SSP_DR));
				spi_wi[dev]++;
			}
		}
		spi_status[dev] = SPI_IDLE;
	}
}

unsigned char SPIIsBusy(unsigned char dev) //return 1 if SPI is busy, supposed to be used with interrupt mode
{
	if (spi_status[dev] == SPI_IDLE) //spi_status MUST be volatile variable!!!
		return (0);
	else
		return (1);
}
