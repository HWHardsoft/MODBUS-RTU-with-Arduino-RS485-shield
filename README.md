# MODBUS-RTU-with-Arduino-RS485-shield
How to implement a MODBUS RTU master and slave for use with Zihatec RS485 shield


![Modbus Relay Demo](https://github.com/HWHardsoft/ESP32-P4-ModbusRTU/blob/main/Modbus.jpg)

## Test Setup
In this tutorial, we want to implement a Modbus RTU master and a slave that can communicate with each other. Therefore, we need two Arduino Uno R4s (the good old Rev3 will also work), two RS485 shields, and a few LEDs and buttons connected to the master and slave so that something ‘happens’. 
The RS485 uses two lines for signal transmission. These two signals are often labeled A and B on RS485 devices. Unfortunately, the use of the letters A and B is not uniformly regulated. In the RS485 Shield, "A" means R+/T+ (also known as D+) and "B" means R-/T- (also known as D-). This may also differ for other devices. For our test setup, we need to connect the two A terminals and the two B terminals of the shields via cables. 
Furthermore, an LED and push button are connected to both the master and slave via a small breadboard, for example, in accordance with the circuit diagram below. 
![Button and LED](https://github.com/HWHardsoft/ESP32-P4-ModbusRTU/blob/main/Modbus.jpg)




## Jumper setting 
Jumper setting for UNO R4:
   JP1: 5V
   JP2 - JP4: 
     0 .xx
     1 xx.
     2 ...
     3 ...
     4 ...
     5 ...
     6 ..
     7 ..
 
 
 Jumper setting for UNO R3:
   JP1: 5V
   JP2 - JP4: 
     0 ...
     1 ...
     2 .xx
     3 xx.
     4 ...
     5 ...
     6 ..
     7 .. 

## DIP Switch setting
S1: OFF-ON-ON-OFF

S2: OFF-OFF-ON-ON

S3: ON-OFF-ON-ON



## Hardware
- Arduino UNO Rev3 or R4
- [Zihatec RS485 Shield for Arduino](https://www.hwhardsoft.de/english/projects/rs485-arduino/)


## Essential Libraries
Since Arduino's own MODBUS libraries do not support either the Arduino UNO R4 or the RS485 Shield, I tested various other libraries and came across the [ModbusRTUMaster](https://github.com/CMB27/ModbusRTUMaster) and [ModbusRTUSlave](https://github.com/CMB27/ModbusRTUSlave) libraries by C. M. Bulliner. Both libraries can be installed directly via the Arduino IDE. Please install with all dependencies. 

![Library installation](https://github.com/HWHardsoft/ESP32-P4-ModbusRTU/blob/main/Modbus.jpg)


## License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
