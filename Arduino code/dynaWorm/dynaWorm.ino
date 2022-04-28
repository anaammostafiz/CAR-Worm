/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <DynamixelShield.h>

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DEBUG_SERIAL soft_serial
#elif defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
  #define DEBUG_SERIAL SerialUSB    
#else
  #define DEBUG_SERIAL Serial
#endif

// wheel 1 Dynamixels
const uint8_t DXL_ID_1 = 1;
const uint8_t DXL_ID_2 = 2;
const uint8_t DXL_ID_3 = 3;
const uint8_t DXL_ID_4 = 4;
// wheel 2 Dynamixels
const uint8_t DXL_ID_5 = 5;
const uint8_t DXL_ID_6 = 6;
const uint8_t DXL_ID_7 = 7;
const uint8_t DXL_ID_8 = 8;
const float DXL_PROTOCOL_VERSION = 2.0;

DynamixelShield dxl;

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  
  // For Uno, Nano, Mini, and Mega, use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);

  // Set Port baudrate. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID_1);
  dxl.ping(DXL_ID_2);
  dxl.ping(DXL_ID_3);
  dxl.ping(DXL_ID_4);
  dxl.ping(DXL_ID_5);
  dxl.ping(DXL_ID_6);
  dxl.ping(DXL_ID_7);
  dxl.ping(DXL_ID_8);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID_1);
  dxl.setOperatingMode(DXL_ID_1, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_1);
  dxl.torqueOff(DXL_ID_2);
  dxl.setOperatingMode(DXL_ID_2, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_2);
  dxl.torqueOff(DXL_ID_3);
  dxl.setOperatingMode(DXL_ID_3, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_3);
  dxl.torqueOff(DXL_ID_4);
  dxl.setOperatingMode(DXL_ID_4, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_4);
  dxl.torqueOff(DXL_ID_5);
  dxl.setOperatingMode(DXL_ID_5, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_5);
  dxl.torqueOff(DXL_ID_6);
  dxl.setOperatingMode(DXL_ID_6, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_6);
  dxl.torqueOff(DXL_ID_7);
  dxl.setOperatingMode(DXL_ID_7, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_7);
  dxl.torqueOff(DXL_ID_8);
  dxl.setOperatingMode(DXL_ID_8, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_8);

  dxl.setGoalPosition(DXL_ID_1,25);
  dxl.setGoalPosition(DXL_ID_2,1535);
  dxl.setGoalPosition(DXL_ID_3,2500);
  dxl.setGoalPosition(DXL_ID_4,3140);
  dxl.setGoalPosition(DXL_ID_5,1200);
  dxl.setGoalPosition(DXL_ID_6,1100);
  dxl.setGoalPosition(DXL_ID_7,3850);
  dxl.setGoalPosition(DXL_ID_8,1180);
  delay(2000);
}

void loop() {
  
  // Please refer to e-Manual(http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/) for available range of value. 
  // Set Goal Position in RAW value

  // expand and contract segments in worm-like wave
  dxl.setGoalPosition(DXL_ID_7,3850);
  dxl.setGoalPosition(DXL_ID_8,1180);
  dxl.setGoalPosition(DXL_ID_1, -2475);
  dxl.setGoalPosition(DXL_ID_2, -965);
  delay(1000);
  dxl.setGoalPosition(DXL_ID_1, 25);
  dxl.setGoalPosition(DXL_ID_2, 1535);
  dxl.setGoalPosition(DXL_ID_3, 0);
  dxl.setGoalPosition(DXL_ID_4, 640);
  delay(1000);
  dxl.setGoalPosition(DXL_ID_3, 2500);
  dxl.setGoalPosition(DXL_ID_4, 3140);
  dxl.setGoalPosition(DXL_ID_5, -1300);
  dxl.setGoalPosition(DXL_ID_6, -1400);
  delay(1000);
  dxl.setGoalPosition(DXL_ID_5, 1200);
  dxl.setGoalPosition(DXL_ID_6, 1100);
  dxl.setGoalPosition(DXL_ID_7, 1350);
  dxl.setGoalPosition(DXL_ID_8, -1320);
  delay(1000);
  
}
