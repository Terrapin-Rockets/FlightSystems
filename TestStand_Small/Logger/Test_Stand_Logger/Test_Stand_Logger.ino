// Hx711  DOUT #A1, SCK #A0 Load Cell
// Pressure Transducer #A2
// Temp transducer = #A3
// Start/Stop in pin = digial 2 
// Mosfet start/stop = digital 3


#include "hx711.h"
#include <SD.h>
#include <SPI.h>
#include <EEPROM.h>
//#include <Time.h>
//#include <TimeLib.h>


Hx711 scale(A1, A0);
unsigned long time;
int count;
String dataString;
String FileName;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);

  byte LogNum = EEPROM.read(0);
  if (LogNum == 0) {
    LogNum = 1;
    EEPROM.write(0, LogNum);
  }
  else {
    if (LogNum > 100) {
      LogNum += 1;
      EEPROM.write(0, LogNum);
    }
  }
  
  FileName = "Test_Log0";
  FileName += String(LogNum);
  FileName += ".txt";
  
  
  
  // see if the card is present and can be initialized:
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("Card failed, or not present");
    return;
  }
//  File dataFile = SD.open("Test_Log001.txt", FILE_WRITE);
  File dataFile = SD.open(FileName.c_str(), FILE_WRITE);
  
  
  if (dataFile) {
    dataFile.println("Test Stand Data: Load Cell[g], Pressure[V], Temperature[V]");
    dataFile.close();
  }

  while(digitalRead(2) == LOW) {
    int sensor1 = scale.getGram();
    int sensor2 = analogRead(A2);
    int sensor3 = analogRead(A3);
    
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

  while(millis()-time < 1000) {
    String dataString = "";
    
    int sensor1 = scale.getGram();
    int sensor2 = analogRead(A2);
    int sensor3 = analogRead(A3);

    File dataFile = SD.open(FileName.c_str(), FILE_WRITE);

    if (dataFile) {
      dataString += String(sensor1);
      dataString += ","; 
      dataString += String(sensor2);
      dataString += ","; 
      dataString += String(sensor3);
      dataString += ","; 
      dataString += String(millis()-time);
      
      dataFile.println(dataString);
      dataFile.close();
    }  
    delay(5);
  }
  
  digitalWrite(3, HIGH);

  count = 0;
}



void loop() {
  
  dataString = "";

//  read three sensors and append to the string:
  int sensor1 = scale.getGram();
  int sensor2 = analogRead(A2);
  int sensor3 = analogRead(A3);
    
  dataString += String(sensor1);
  dataString += ","; 
  dataString += String(sensor2);
  dataString += ","; 
  dataString += String(sensor3);
  dataString += ","; 
  dataString += String(millis()-time);
    
    
  File dataFile = SD.open("Test_Log001.txt", FILE_WRITE);

  
  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }


  count++;
  if(count == 10){
    count =0;
    Serial.print(dataString);
  }

  
  if(digitalRead(2) == HIGH){
    while(true){
      Serial.println("Finished Logging");
      delay(2000);
    }
  }
  
}
