/*This program is for ESP32 and serial comunication with FM receiver
Open Serial Monitor and write AT commands
Input: AT+RET
Output:
/***********************************
VOL=30
FRE=937
SN_OFF
SN_THR=05
PLAY
BANK=20s
CAMPOS_ON
PCB_NUMBE:LCD_FM_RX_ENC_V1.9
Thank you for using!
/***********************************
set freq to 99.1 Input: AT+FRE=991 Output: FRE=991 
set vol to 30 Input: AT+VOL=30 Output: VOL=30 
*/
#define RXD2 16
#define TXD2 17
#define RXD1 4
#define TXD1 2
#include <HardwareSerial.h>
String code;

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);

  //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.begin(38400);
  //Serial2.begin(38400, SERIAL_8N1, RXD2, TXD2);
  Serial1.begin(38400, SERIAL_8N1, RXD1, TXD1);
  Serial1.write("AT+RET");

  
}

void loop() { //Choose Serial1 or Serial2 as required
  //read from Serial Monitor
  //write to HardwareSerial
    while (Serial.available()){
      code = Serial.readStringUntil('\n');
      Serial1.println(code);
    }
    // read from HardwareSerial
    // write to Serial Monitor
    while (Serial1.available()) {
    Serial.print(char(Serial1.read()));
  }
    delay(1000);
  
  
}
