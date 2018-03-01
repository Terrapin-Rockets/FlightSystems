#include<Wire.h>
#include<math.h>
#include <SoftwareSerial.h>
#include <SD.h>
#include <SPI.h>
#include <SFE_LSM9DS0.h>
#include <stdint.h>
#include "SparkFunBME280.h"

#define LSM9DS0_XM  0x1D // Would be 0x1E if SDO_XM is LOW
#define LSM9DS0_G   0x6B // Would be 0x6A if SDO_G is LOW
// [SPI or I2C Mode declaration],[gyro I2C address],[xm I2C add.]
LSM9DS0 dof(MODE_I2C, LSM9DS0_G, LSM9DS0_XM);
BME280 mySensor;

SoftwareSerial xbee =  SoftwareSerial(2, 3);
SoftwareSerial GPS =  SoftwareSerial(4, 5);

int count;

void setup(){
  Serial.begin(9600); 
  
  uint16_t status = dof.begin();
  Serial.print("LSM9DS0 WHO_AM_I's returned: 0x");
  Serial.println(status, HEX);
  Serial.println("Should be 0x49D4");
  Serial.println();



  mySensor.settings.runMode = 3; //Normal mode
  mySensor.settings.tStandby = 0;
  mySensor.settings.filter = 0;
  mySensor.settings.tempOverSample = 1;
  mySensor.settings.pressOverSample = 1;
  mySensor.settings.humidOverSample = 1;
  delay(10);  //Make sure sensor had enough time to turn on. BME280 requires 2ms to start up.
  mySensor.begin()
  
  

  
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  xbee.begin(9600);


  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  GPS.begin(9600);


  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("Card failed, or not present");
    return;
  }

  
  unsigned long time;
  count = 0;
  
}


void loop(){

 

  dof.readAccel();
  dof.readGyro();
  dof.readMag();

  
  Serial.print(dof.calcGyro(dof.gx), 2);
  Serial.print(", ");
  Serial.print(dof.calcGyro(dof.gy), 2);
  Serial.print(", ");
  Serial.println(dof.calcGyro(dof.gz), 2);
  Serial.print(dof.gx);
  Serial.print(", ");
  Serial.print(dof.gy);
  Serial.print(", ");
  Serial.println(dof.gz);

  Serial.print(dof.calcAccel(dof.ax), 2);
  Serial.print(", ");
  Serial.print(dof.calcAccel(dof.ay), 2);
  Serial.print(", ");
  Serial.println(dof.calcAccel(dof.az), 2);
  Serial.print(dof.ax);
  Serial.print(", ");
  Serial.print(dof.ay);
  Serial.print(", ");
  Serial.println(dof.az);

  Serial.print(dof.calcMag(dof.mx), 2);
  Serial.print(", ");
  Serial.print(dof.calcMag(dof.my), 2);
  Serial.print(", ");
  Serial.println(dof.calcMag(dof.mz), 2);
  Serial.print(dof.mx);
  Serial.print(", ");
  Serial.print(dof.my);
  Serial.print(", ");
  Serial.println(dof.mz);





  Serial.print("Temperature: ");
  Serial.print(mySensor.readTempC(), 2);
  Serial.println(" degrees C");

  Serial.print("Temperature: ");
  Serial.print(mySensor.readTempF(), 2);
  Serial.println(" degrees F");

  Serial.print("Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 2);
  Serial.println(" Pa");

  Serial.print("Altitude: ");
  Serial.print(mySensor.readFloatAltitudeMeters(), 2);
  Serial.println("m");

  Serial.print("Altitude: ");
  Serial.print(mySensor.readFloatAltitudeFeet(), 2);
  Serial.println("ft"); 

  Serial.print("%RH: ");
  Serial.print(mySensor.readFloatHumidity(), 2);
  Serial.println(" %");




  count += 1;
  if(count == 10){
    count = 1;
  
    xbee.println("Blank");
    xbee.println(AcX);
    xbee.println(AcY);
    xbee.println(AcZ);
    xbee.println(GyX/100);
    xbee.println(GyY/100);
    xbee.println(GyZ/100);
  
    Serial.print(AcX);
    Serial.print(", ");
    Serial.print(AcY);
    Serial.print(", ");
    Serial.print(AcZ);
    Serial.print(", ");
    Serial.print(GyX/100);
    Serial.print(", ");
    Serial.print(GyY/100);
    Serial.print(", ");
    Serial.println(GyZ/100);

  }
   
  int sensor1 = scale1.getGram();
  int sensor2 = analogRead(A4);

  String dataString = "";
  dataString += String(sensor1);
  dataString += ","; 
  dataString += String(sensor2);
  dataString += ","; 
  dataString += String(millis());
      
  File dataFile = SD.open("Flight_Log001.txt", FILE_WRITE);
  
  if (dataFile) {
    dataFile.println(BUILTIN_SDCARD);
    dataFile.close();
  }
 

  delay(10);
}

