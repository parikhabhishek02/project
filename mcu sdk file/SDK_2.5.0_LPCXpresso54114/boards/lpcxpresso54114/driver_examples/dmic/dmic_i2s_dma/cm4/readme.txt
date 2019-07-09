Overview
========
Demonstrates the DMIC working with I2S. Audio is converted to samples in the DMIC module.
Then, the data is placed into the memory buffer. Last, it is send to the I2S buffer and sent
to the CODEC, then the audio data will be output to Lineout of CODEC.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Hardware requirements
=====================
- Micro USB cable
- LPCXpresso54114 board
- Personal Computer
- Earphone/headset


Board settings
==============
No special board setting.


Prepare the Demo
================
This demo was written on a LPCXpresso 54114 board, PCB rev A

1.  Connect a micro USB cable between the host PC and the LPC-Link USB port (J7) on the target board.
2.  Open a serial terminal with the following settings:
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

Configure I2C

Configure WM8904 codec

Configure I2S

2. This example transfers data from DMIC to Codec. Connect headphone/earphone on audio out of the board.
   Speak on DMIC and you can listen voice on audio out.

Toolchain supported
===================
- IAR embedded Workbench  8.32.1
- Keil MDK  5.26
- MCUXpresso 10.3.0
- GCC ARM Embedded  7.3.1

