Overview
========
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
This demo explains how built in HWVAD( HW voice activity detector) in LPC5411x can be used to
wake up the device from sleep mode
Hardware requirements
=====================
- Micro USB cable
- LPCLPCXpresso54114 board
- MAO board 
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
1.  Connect a micro USB cable between the PC host and the CMSIS DAP USB port (J7) on the board
2.  Open a serial terminal with the following settings (See Appendix A in Getting started guide for description how to determine serial port number):
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.

Running the demo
================
1.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

The following lines are printed to the serial terminal when the demo program is executed.

Configure DMIC

2. This example wakes up microcontroller on any voice activity.
   Speak on DMIC,you can see blinking Red LED(D2). Also serial message "Going into sleep" and "Just woke up" will be transmitted.

Toolchain supported
===================
- IAR embedded Workbench  8.32.1
- Keil MDK  5.26
- MCUXpresso 10.3.0
- GCC ARM Embedded  7.3.1

