/******************************************************************************/
/* RTA_Config.c: Real-Time Agent Configuaration V2.12                          */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2006-07 Keil - An ARM Company. All rights reserved.          */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

// <<< Use Configuration Wizard in Context Menu >>>

// <e0>Real-Time Agent
// <i>Enable Real-Time Agent to obtain run-time debug information.
#ifndef __RTA_ENABLED
 #define __RTA_ENABLED          1
#endif

#define RTA_HW_LPC21xx        1
#define RTA_HW_LPC23xx        2
#define RTA_HW_STR91x         3
#define RTA_HW_AT91SAM7Sx     4
#define RTA_HW_AT91SAM7Xx     5
#define RTA_HW_LPC22xx        6
#define RTA_HW_AT91SAM9261    7
#define RTA_HW_AT91SAM9263    8
#define RTA_HW_POLLED         99
#define RTA_HW_CUSTOM         100
// <o0>Hardware Type  <i>Select the target MCU you are using.
//   <1=> NXP (Philips) LPC21xx
//   <2=> NXP (Philips) LPC23xx
//   <3=> STMicroelectronics STR91x
//   <4=> Atmel AT91SAM7Sx
//   <5=> Atmel AT91SAM7Xx
//   <6=> NXP (Philips) LPC22xx
//   <7=> Atmel AT91SAM9261
//   <8=> Atmel AT91SAM9263
//   <99=> Polled Mode (any hardware)
//   <100=> Custom
//   (for custom hardware you need to set macros in the hardware section)
//
#ifndef __RTA_HW_TYPE
 #define __RTA_HW_TYPE          2
#endif

// <o0>Output Buffer Size (bytes) <i>If you are experiencing buffer overruns, increase the buffer size.
// <i>Default: 256
//    <256=>256
//    <512=>512
//    <1024=>1024
//    <2048=>2048
#ifndef __RTA_OUT_SIZE_BYTES
 #define __RTA_OUT_SIZE_BYTES  256
#endif
#define __RTA_OUT_SIZE         (__RTA_OUT_SIZE_BYTES / 4)

// <o>  Invalid Memory Pattern <0x0-0xFFFFFFFF>
// <i>  This pattern is shown at inaccessible locations in the memory window at run-time.
// <i>  Default: 0xCCCCCCCC
#ifndef __RTA_NO_MEM_FLAG
 #define __RTA_NO_MEM_FLAG     0xCCCCCCCC
#endif

// <e0>Enable Real-Time Agent Terminal
//   <o1.0>Echo Characters Automatically<i>Echoes back characters typed in the serial window
//          <i>Default: Off
//   <o2.0>Block on Write<i>Waits for serial buffer to have available space to send data.
//          <i>This option must be disabled to run without the debugger.
//          <i>Default: On
//  </e>
#ifndef __RTA_TERM_SUPPORT
 #define __RTA_TERM_SUPPORT   1
#endif

/* Echo characters back to the serial window automatically */
#ifndef __RTA_TERM_ECHO
 #define __RTA_TERM_ECHO       0
#endif

/* Blocking writes - write  blocks when output buffer full*/
#ifndef __RTA_TERM_W_BLOCKING
 #define __RTA_TERM_W_BLOCKING 1
#endif

// </e>

// <e0>I/O Retargeting
// <i>Enable I/O retargeting
#ifndef __IO_RETARGET_ENABLED
 #define __IO_RETARGET_ENABLED  1
#endif

/* Possible stream sources/destinations */
#define __IO_RETARGET_STREAM_NONE           0
#define __IO_RETARGET_STREAM_RTA            1
#define __IO_RETARGET_STREAM_NOT_USED       2
#define __IO_RETARGET_STREAM_COM_1          3

// <o0>STDIO Routing (for printf(), scanf(), etc) <i>Select the route for standard input/output, and standard error
//   <0=> None
//   <1=> Real-Time Agent
//   <3=> COM Port
#ifndef __IO_RETARGET_STDIO_ROUTE
 #define __IO_RETARGET_STDIO_ROUTE          1
#endif


// <o0.0>External file operations (eg RTL Flash File System)
// <i>Enable if __fopen(), __fclose(), __write(), __read(), __setfpos(), __flushbuf() and __get_flen() are defined
#ifndef __IO_RETARGET_FOPEN_ETC_ENABLED
 #define __IO_RETARGET_FOPEN_ETC_ENABLED    0
#endif

// </e>

// <<< end of configuration section >>>

/* Terminal Emulator input buffer size (must be a power of 2)
     This should be modified based on the amount of
     data being sent, and the speed of the JTAG. A faster
     JTAG and/or greater amount of data would require a 
     larger buffer size. */
#ifndef __RTA_TERM_IN_SIZE
 #define __RTA_TERM_IN_SIZE    16
#endif

// RTX task switch monitoring should not be enabled unless RTX is included, in which case this file need not be used
#ifndef __RTA_TERM_IN_SIZE
  #define __RTA_RTX_TASK_SWITCHING     0
#endif

/* Real-Time Agent code */
#include <RT_Agent.c>




