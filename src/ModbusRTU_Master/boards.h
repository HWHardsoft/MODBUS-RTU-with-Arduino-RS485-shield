#ifndef MODBUS_BOARDS_H
#define MODBUS_BOARDS_H

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
  // The ATmega328P and ATmega168 only have one HardwareSerial port, and on Arduino boards it is usually connected to a USB/UART bridge.
  // So, for these boards, we will use SoftwareSerial with the lbrary, leaving the HardwareSerial port available to send debugging messages.
  #define SOFTWARE_SERIAL
  #include <SoftwareSerial.h>
  const int8_t rxPin = 2;
  const int8_t txPin = 3;
  SoftwareSerial mySerial(rxPin, txPin);
  #define MODBUS_SERIAL mySerial
#elif defined(ARDUINO_NANO_ESP32)
  // On the Arduino Nano ESP32, the HardwareSerial port on pins 0 and 1 is Serial0
  #define MODBUS_SERIAL Serial0
#elif defined(ARDUINO_ARCH_STM32)
  // On ST Nucleo-64 Boards, the HardwareSerial port on pins 0 and 1 is Serial2.
  #define MODBUS_SERIAL Serial2
#else
  // On the majority of Arduino boards, the HardwareSerial port on pins 0 and 1 is Serial1
  // On the Arduino Mega and Adruino Due, Serial1 is on pins 18 and 19.
  #define MODBUS_SERIAL Serial1
#endif


 
#endif

