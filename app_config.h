//Using  : Configuration header for application
//Description : This file is to be included in all other .c files.
//User may put anything for configuration. Other files's header also
//declared in this file.

#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_

//device registers and speific macro
#include "LPC23xx.H"
#define Orb(target,bitnum)			target |= 1 << bitnum
#define Setb(FIOnSET,bitnum)		FIOnSET = 1 << bitnum
#define Clrb(FIOnCLR,bitnum)		FIOnCLR = 1 << bitnum
#define Rdb(FIOnPIN,bitnum)			FIOnPIN & 1 << bitnum

//board's pin configuration
#include "util/hw_blue_screen.h"
#define TS_XDAT		(*(volatile unsigned char *)0x80000800)
#define TS_XINS		(*(volatile unsigned char *)0x80000000)

//pen status type definition
//typedef enum
//{
//	PST_NOTFOUND,
//	PST_DOWN,
//	PST_HOLD,
//	PST_UP
//} pstatus_t;

//all other header files
//#include "utils_custom_v1_00.h"
#include "driver/spi_lpc23xx_v1_01.h"
//#include "serial_lpc23xx_v1_00.h"
//#include "console_v1_01.h"
//#include "i2c_lpc23xx_v1_00.h"
//#include "i2c_eeprom.h"

//#include "efs/efs.h"
//#include "efs/ls.h"
//#include "efs/mkfs.h"

//#include "vs1011e_v1_00.h"
 
#include "driver/tc_ad7843_v1_00.h"
//#include "tslcd_elt240320tp_v1_20.h"
//#include "screen_obj_v1_00.h"
//#include "app_screen_obj.h"

//how to read data from program memory, depend on each compiler
#define code(codemem)				codemem

//this application use console at serial port 0
#define CONSOLE
#define CONS_SER		0
#define MAX_CMD			16
#define MAX_CMD_LEN		16

//this application use USB
//#define USB

//console's buffer sizes
#define CONS_TBUF_SIZE	2048
#define CONS_RBUF_SIZE	32

//touch screen controller is connected via SPI port 0
#define TC_SPI			0

#define SD_SPI			0
//#define VS_SPI			1
//
#define SD_SPI_CLK_DIV	1
//#define VS_SPI_CLK_DIV	8

#define SPI_BUF_CNT_TYPE	unsigned int

//i2c eeprom (AT24C64) is connected via I2C port 1
//#define EEPROM_I2C		1
//#define EEPROM_AD		0xA0

//touch screen LCD configuration
#define TS_ORN_PORTRAIT

#ifdef TS_ORN_PORTRAIT
#define TS_SIZE_X					64
#define TS_SIZE_Y					128
#define TS_VAL_ENTRY_MOD			0x0030
#define TS_INS_GRAM_ADX				TS_INS_GRAM_HOR_AD
#define TS_INS_GRAM_ADY				TS_INS_GRAM_VER_AD
#define TS_INS_START_ADX   			TS_INS_HOR_START_AD
#define TS_INS_END_ADX   			TS_INS_HOR_END_AD
#define TS_INS_START_ADY   			TS_INS_VER_START_AD
#define TS_INS_END_ADY   			TS_INS_VER_END_AD
#else
#define TS_SIZE_X					128
#define TS_SIZE_Y					64
#define TS_VAL_ENTRY_MOD			0x0028
#define TS_INS_GRAM_ADX				TS_INS_GRAM_VER_AD
#define TS_INS_GRAM_ADY				TS_INS_GRAM_HOR_AD
#define TS_INS_START_ADX   			TS_INS_VER_START_AD
#define TS_INS_END_ADX   			TS_INS_VER_END_AD
#define TS_INS_START_ADY   			TS_INS_HOR_START_AD
#define TS_INS_END_ADY   			TS_INS_HOR_END_AD
#endif

//void AppInit(void);
//void AppRun(void);
//
//void AppSDInit(void);
//void AppSDList(void);
//void AppSDChangeDir(char *new_dir);
//void AppSDGetBack(void);
//void AppSDRead(char mode, char *file_name);
//void AppSDMkDir(char *file_name);
//void AppSDOpenWrite(char mode, char *file_name);
//void AppSDWrite(int len, char *data);
//void AppPlay(char *file_name);
//void AppPlayAll(char *dir_name);
//void AppSDShowPic(char *file_name);
//void AppSDShowPic2(char *file_name);
//void AppTask1ms(void);
//void AppTask10ms(void);
//void AppTask100ms(void);
//void AppTask500ms(void);

#endif

