//#include <Time.h>
//#include <TimeLib.h>




// Hx711-1  DOUT #A1, SCK #A0
// Hx711-2  DOUT #A3, SCK #A2
// Temptransducer = analog 4
// Start/Stop pin = digial 2
// Mosfet start/stop = digital 3


#include "hx711.h"
#include <SD.h>
#include <SPI.h>
#include <EEPROM.h>


Hx711 scale1(A1, A0);
Hx711 scale2(A2,A3);


void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);

//  byte LogNum = EEPROM.read(0);
//  if (LogNum == 0) {
//    LogNum = 1;
//    EEPROM.write(0, LogNum);
//  }
//  else {
//    if (LogNum > 100) {
//      LogNum += 1;
//      EEPROM.write(0, LogNum);
//    }
//  }
//  
//  String FileName = "Test_Log0";
//  FileName += String(LogNum);
//  FileName += ".txt";
  
  unsigned long time;
  
  // see if the card is present and can be initialized:
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("Card failed, or not present");
    return;
  }

  while(digitalRead(2) == LOW) {
    int sensor1 = scale1.getGram();
    int sensor2 = scale2.getGram();
    int sensor3 = analogRead(A4);

    Serial.print('Still Low Reading: ');
    Serial.print(String(sensor1));
    Serial.print(', ');
    Serial.print(String(sensor2));
    Serial.print(', ');
    Serial.println(String(sensor3));
    delay(1000);
  }
  Serial.println('Starting in');
  Serial.println('3');
  delay(1000);
  Serial.println('2');
  delay(1000);
  Serial.println('1');
  time = millis();
  
  digitalWrite(3, HIGH);
  while(digitalRead(2) == LOW) {
    String dataString = "";

//    read three sensors and append to the string:
    int sensor1 = scale1.getGram();
  //   int sensor2 = scale2.getGram();
    int sensor3 = analogRead(A4);
    
    dataString += String(sensor1);
//    dataString += ","; 
//    dataString += String(sensor2);
    dataString += ","; 
    dataString += String(sensor3);
    dataString += ","; 
    dataString += String(millis());
    
    
    File dataFile = SD.open("Test_Log001.txt", FILE_WRITE);
  
    // if the file is available, write to it:
    if (dataFile) {
      dataFile.println(BUILTIN_SDCARD);
      dataFile.close();
    }
    Serial.print(dataString);

    if(digitalRead(2)){
      break;
    }
  }
}



void loop() {

  
}
////  wait for pin to go high
////  grab time
////  start recording
//
//
//  String dataString = "";
//
//  // read three sensors and append to the string:
//    int sensor1 = scale1.getGram();
////    int sensor2 = scale2.getGram();
//    int sensor3 = analogRead(A4);
//    dataString += String(sensor);
//    if (analogPin < 2) {
//      dataString += ","; 
//    }
//  }
//
//
//  File dataFile = SD.open("datalog.txt", FILE_WRITE);
//
//  // if the file is available, write to it:
//  if (dataFile) {
//    dataFile.println(BUILTIN_SDCARD);
//    dataFile.close();
//  else {
//    Serial.println("error opening datalog.txt");
//  }
//
//  
//  Serial.print(, 1);
//  Serial.println(" g");
////  check for if pin low
////    if so stop recording
////    print to SD card
//  
//
////  delay(200);
//}
