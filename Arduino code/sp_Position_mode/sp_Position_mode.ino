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

// main code is in void loop(){}

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

const uint8_t DXL_ID = 13;
const uint8_t DXL_ID_1 = 14;
const float DXL_PROTOCOL_VERSION = 2.0;

DynamixelShield dxl;

//This namespace is required to use Control table item names
using namespace ControlTableItem;
String input;
String contract = "c";
String expand = "e";
void setup() {
  // put your setup code here, to run once:
  
  // For Uno, Nano, Mini, and Mega, use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);
  dxl.ping(DXL_ID_1);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID);
  dxl.torqueOff(DXL_ID_1);
  dxl.setOperatingMode(DXL_ID_1, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID_1);
}

void loop() {
  
  // open the serial monitor at the top right
  // type in "c" and press enter to contract the worm to -2000
  // type in "e" and press enter to expand the worm to 0
  
  if (Serial.available() > 0) {
                // read the incoming string:
                input = Serial.readString();
                input.trim();
                if (input.equals(contract)){
                    //  Set Goal Position in RAW value
                    dxl.setGoalPosition(DXL_ID, -500);
                    dxl.setGoalPosition(DXL_ID_1, -500);
                    delay(1000);
                    //  Print present position in raw value
                    DEBUG_SERIAL.print(DXL_ID);
                    DEBUG_SERIAL.print(" Contracted to : ");
                    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID));
                    DEBUG_SERIAL.print(DXL_ID_1);
                    DEBUG_SERIAL.print(" Contracted to : ");
                    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID_1));
                    delay(1000);
                }
                if (input.equals(expand)){
                    //  Set Goal Position in RAW value
                    dxl.setGoalPosition(DXL_ID, 0);
                    dxl.setGoalPosition(DXL_ID_1, 0);
                    delay(1000);
                    //  Print present position in raw value
                    DEBUG_SERIAL.print(DXL_ID);
                    DEBUG_SERIAL.print(" Expanded to : ");
                    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID));
                    DEBUG_SERIAL.print(DXL_ID_1);
                    DEBUG_SERIAL.print(" Expanded to : ");
                    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID_1));
                    delay(1000);
                }  
        }
  // Please refer to e-Manual(http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/) for available range of value. 
}
