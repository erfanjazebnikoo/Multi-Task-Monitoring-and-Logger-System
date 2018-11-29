# Multi task monitoring and logger system
Touchscreen graphical data monitor, debugger and Logger for [CAN protocol][can] based on an [ARM-microprocessor][arm] which designed for an autonomous [middle size robot][middle].

### Features
- Display live data in the [CAN protocol][can] attached to the system in a 128*64  [graphical LCD][ks0108]
- Store the information received for later review on the [MMC memory card][mmc]
- [Touch control][ads7843] with an easy interface for manual settings of circuits or related systems
- Using the [ARM Microprocessor][arm] that makes processing faster
- Monitor several messages via RGB Leds

![N|Solid](http://erfanjazebnikoo.com/downloads/Multi-Task-Monitoring-and-Logger-System-Data-LQ.jpg)
![N|Solid](http://erfanjazebnikoo.com/downloads/Multi-Task-Monitoring-and-Logger-System-Board-LQ.jpg)
 
 ---------
 
## Software
Multi-task monitoring and logger system programmed by [Keil uVision][keil] with C programming language. In the driver section, I implemented and defined [CAN protocol][can], Graphical LCD, SPI, Interrupts and memory card in this system. In the util section which includes all the details of the monitoring system, we have initialization, tab, logger, network, RGB Led and Main files.

- [initialization.h][initialization]: defined all driver files and pin configuration so every other file can use this library for accessing to whole system parameters.
- [tab.h][tab]: contains commands that display the taskbar and get the touchscreen information.
- [logger.h][logger]: to make a text file every minute and save data on the memory card and Information on the [CAN bus][can] is stored on it
- [network.h][network]: read or write on [CAN bus][can], along with this activity, the RGB LED file displays these reading and writing functions via RGB Leds.

---------

## Hardware
To build this device, firstly, Its electronic circuits designed in [Altium Designer][altium] software. The circuit of this device consists of 3 different parts. It launched after assembling and taking various tests. A system consisting of two electronic circuits and a graphical LCD that put together.

### 1-  Main board
Processor, touch screen control and display input circuits. This system reads the [CAN bus][can] data and displays information on the graphical LCD. All data are saved in an external memory to use when needed. Additionally, There is also a touch controller that the user can enter any manual command.

| Unit | Description |
| ------ | ------ |
| Proccessor | [LPC2368 NXP ARM7][lpc2368] |
| 4-wire Touch Controller | [Texas Instruments ADS7843 ][ads7843] |
| CAN controller interface|[NXP PCA82C250][PCA82C250]|
| Graphical LCD|[KS0108][ks0108]|
| Clock frequency|12.000000 MHz|
| RTC frequency|32.768 KHz|

[![N|Solid](http://erfanjazebnikoo.com/downloads/Multi-Task-Monitoring-and-Logger-System-Main-Board-LQ.jpg)](http://erfanjazebnikoo.com/downloads/Multi-Task-Monitoring-and-Logger-System-Main-Board.jpg)

### 2- I/O board
Storage circuit and system inputs. This board designed for all input connection like CAN, power, memory card and programmer. All of data 

| Unit | Description |
| ------ | ------ |
| Storage | [MMC Memory card][mmc]|
| Programmer | [ULINK2][ulink]|


[![N|Solid](http://erfanjazebnikoo.com/downloads/Multi-Task-Monitoring-and-Logger-System-IO-Board-LQ.jpg)](http://erfanjazebnikoo.com/downloads/Multi-Task-Monitoring-and-Logger-System-IO-Board.jpg)

### 3- Pin configuration
NXP LPC2368 has four different ports.

#### Port 0:

| Pin | Connection |
| ------ | ------ |
| 0 | CAN 1 RXD |
| 1 | CAN 1 TXD |
| 2 | GLCD R/W |
| 3 | GLCD D/I |
| 6 | GLCD Reset |
| 15 | Touch Driver SCK0 |
| 16 | Touch Driver SSEL0 |
| 17 | Touch Driver DOUT |
| 18 | Touch Driver DIN |
| 19 | MMC Driver CLK |
| 20 | MMC Driver CMD |
| 21 | MMC Driver PWR |
| 22 | MMC Driver DATA0 |

#### Port 1:

| Pin | Connection |
| ------ | ------ |
| 0 | GLCD DB0 |
| 1 | GLCD DB1 |
| 4 | GLCD DB2 |
| 8 | GLCD DB3 |
| 9 | GLCD DB4 |
| 10 | GLCD DB5 |
| 14 | GLCD DB6 |
| 15  | GLCD DB7 |
| 16 | GLCD CSA |
| 17 | GLCD CSB |
| 18 | RGB LED 1 Blue |
| 19 | RGB LED 1 Red |
| 20 | RGB LED 1 Green |
| 21 | RGB LED 2 Blue |
| 22 | RGB LED 2 Red |
| 23 | RGB LED 2 Green |
| 29 | Lock Button |

#### Port 2:

| Pin | Connection |
| ------ | ------ |
| 0 | GLCD BackLight control |
| 6 | Touch Driver Busy|
| 7 | CAN 2 RXD |
| 8 | CAN 2 TXD |
| 10 | Touch Driver PENIRQ |
| 11 | MMC Driver DATA1 |
| 12 | MMC Driver DATA2 |
| 13 | MMC Driver DATA3 |

#### Port 4:

| Pin | Connection |
| ------ | ------ |
| 29 | GLCD Enable |

[lpc2368]: <https://www.nxp.com/docs/en/data-sheet/LPC2364_65_66_67_68.pdf>
[ads7843]: <http://www.ti.com/lit/ds/symlink/ads7843.pdf>
[PCA82C250]: <https://www.nxp.com/docs/en/data-sheet/PCA82C250.pdf>
[ks0108]: <https://www.adafruit.com/product/188>
[mmc]: <https://en.wikipedia.org/wiki/MultiMediaCard>
[ulink]: <http://www2.keil.com/mdk5/ulink>
[keil]:<http://www2.keil.com/mdk5/uvision/>
[altium]:<https://www.altium.com/>
[initialization]:<https://github.com/erfanjazebnikoo/Multi-Task-Monitoring-and-Logger-System/blob/master/initialization.h>
[tab]:<https://github.com/erfanjazebnikoo/Multi-Task-Monitoring-and-Logger-System/blob/master/util/tab.h>
[logger]:<https://github.com/erfanjazebnikoo/Multi-Task-Monitoring-and-Logger-System/blob/master/util/logger.h>
[network]:<https://github.com/erfanjazebnikoo/Multi-Task-Monitoring-and-Logger-System/blob/master/util/network.h>
[can]:<https://en.wikipedia.org/wiki/CAN_bus>
[arm]:<https://en.wikipedia.org/wiki/ARM_architecture>
[middle]:<https://www.robocup.org/leagues/6>

