/**
 * ModbusRTU_Master.ino
 * 
 * Modbus slave (server) demo for Arduino UNO by Zihatec, 2026 
 *
 * This example demonstrates the use of a Modbus RTU master to control the outputs  
 * (coil registers) of an Modbus slave and read the Holding registers of this slave to control an LED 
 *
 * DIP switch setting:
 *  S1: OFF - ON - ON - OFF
 *  S2: OFF - OFF - ON - ON
 *  S3: ON - OFF - ON - ON
 * 
 * Jumper setting for UNO R4:
 *  JP1: 5V
 *  JP2 - JP4: 
 *  0 .xx
 *  1 xx.
 *  2 ...
 *  3 ...
 *  4 ...
 *  5 ...
 *  6 ..
 *  7 ..
 *
 * Jumper setting for UNO R3:
 *  JP1: 5V
 *  JP2 - JP4: 
 *  0 ...
 *  1 ...
 *  2 .xx
 *  3 xx.
 *  4 ...
 *  5 ...
 *  6 ..
 *  7 ..
 *
 * 
 * 
 * This example demonstrates  use the ModbusRTUSlave library (https://github.com/CMB27/ModbusRTUSlave) by  C. M. Bulliner
 * 
 * 
 */ 

#include <ModbusRTUSlave.h>
#include "boards.h"

// You can change the baud, config, and unit id values if you like.
// Just make sure they match the settings you use in ModbusRTUSlaveExample.
// Note, the config value will be ignored when using SoftwareSerial.
// SoftwareSerial only supports SERIAL_8N1.
#define MODBUS_BAUD 9600
#define MODBUS_CONFIG SERIAL_8N1
#define MODBUS_UNIT_ID 1

#define LED_PIN 12
#define BUTTON_PIN 11

ModbusRTUSlave modbus(MODBUS_SERIAL, -1);

const uint8_t numCoils = 2;
const uint8_t numDiscreteInputs = 2;
const uint8_t numHoldingRegisters = 2;
const uint8_t numInputRegisters = 2;

bool coils[numCoils];
bool discreteInputs[numDiscreteInputs];
uint16_t holdingRegisters[numHoldingRegisters];
uint16_t inputRegisters[numInputRegisters];

uint16_t counter = 0;

void setup() {
  // define gpio pins
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  
  // serial interface for debugging  
  Serial.begin(115200);

  modbus.configureCoils(coils, numCoils);
  modbus.configureDiscreteInputs(discreteInputs, numDiscreteInputs);
  modbus.configureHoldingRegisters(holdingRegisters, numHoldingRegisters);
  modbus.configureInputRegisters(inputRegisters, numInputRegisters);

  //MODBUS_SERIAL.begin(MODBUS_BAUD, MODBUS_CONFIG);
  //modbus.begin(MODBUS_UNIT_ID, MODBUS_BAUD, MODBUS_CONFIG);

  // serial interface for MODBUS
  #ifndef SOFTWARE_SERIAL
    MODBUS_SERIAL.begin(MODBUS_BAUD, MODBUS_CONFIG);
    modbus.begin(MODBUS_UNIT_ID, MODBUS_BAUD, MODBUS_CONFIG);
  #else
    MODBUS_SERIAL.begin(MODBUS_BAUD);
    modbus.begin(MODBUS_UNIT_ID, MODBUS_BAUD, MODBUS_CONFIG);
  #endif


  delay(1000);
  Serial.println("MODBUS SLAVE EXAMPLE");
}

void loop() {
  
  inputRegisters[0] = map(analogRead(A0), 0, 1023, 0, 255);
  inputRegisters[1] = map(analogRead(A1), 0, 1023, 0, 255); 
  discreteInputs[0] = !digitalRead(BUTTON_PIN);
  discreteInputs[1] = digitalRead(BUTTON_PIN);
  holdingRegisters[0] = counter++;
  holdingRegisters[1] = counter - 100;
  
  modbus.poll();

  
  digitalWrite(LED_PIN, coils[0]);

  
  
}
