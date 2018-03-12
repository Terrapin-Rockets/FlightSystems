//#include<Wire.h>
//#include<math.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>
//#include <SD.h>
//#include <SPI.h>
//#include <SFE_LSM9DS0.h>
//#include <stdint.h>
//#include "SparkFunBME280.h"

//#define LSM9DS0_XM  0x1D // Would be 0x1E if SDO_XM is LOW
//#define LSM9DS0_G   0x6B // Would be 0x6A if SDO_G is LOW
// [SPI or I2C Mode declaration],[gyro I2C address],[xm I2C add.]
//LSM9DS0 dof(MODE_I2C, LSM9DS0_G, LSM9DS0_XM);
//BME280 mySensor;

TinyGPS gps;
SoftwareSerial xbee =  SoftwareSerial(0, 1);
SoftwareSerial gpsPort(9, 10);

int count;
static void smartdelay(unsigned long ms);
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
static void print_str(const char *str, int len);


void setup(){
  Serial.begin(9600); 
  
//  uint16_t status = dof.begin();
//  Serial.print("LSM9DS0 WHO_AM_I's returned: 0x");
//  Serial.println(status, HEX);
//  Serial.println("Should be 0x49D4");
//  Serial.println();

  Serial.print("Testing TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
  Serial.println("Sats HDOP Latitude  Longitude  Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum");
  Serial.println("          (deg)     (deg)      Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail");
  Serial.println("-------------------------------------------------------------------------------------------------------------------------------------");


//  mySensor.settings.runMode = 3; //Normal mode
//  mySensor.settings.tStandby = 0;
//  mySensor.settings.filter = 0;
//  mySensor.settings.tempOverSample = 1;
//  mySensor.settings.pressOverSample = 1;
//  mySensor.settings.humidOverSample = 1;
//  delay(10);  //Make sure sensor had enough time to turn on. BME280 requires 2ms to start up.
//  mySensor.begin()
  
  

  
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  xbee.begin(9600);


  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  gpsPort.begin(9600);


//  if (!SD.begin(BUILTIN_SDCARD)) {
//    Serial.println("Card failed, or not present");
//    return;
//  }

  
  unsigned long time;
  count = 0;
  
}


void loop(){

 

//  dof.readAccel();
//  dof.readGyro();
//  dof.readMag();
//
//  
//  Serial.print(dof.calcGyro(dof.gx), 2);
//  xbee.print(", ");
//  Serial.print(dof.calcGyro(dof.gy), 2);
//  Serial.print(", ");
//  Serial.println(dof.calcGyro(dof.gz), 2);
//  Serial.print(dof.gx);
//  Serial.print(", ");
//  Serial.print(dof.gy);
//  Serial.print(", ");
//  Serial.println(dof.gz);
//
//  Serial.print(dof.calcAccel(dof.ax), 2);
//  Serial.print(", ");
//  Serial.print(dof.calcAccel(dof.ay), 2);
//  Serial.print(", ");
//  Serial.println(dof.calcAccel(dof.az), 2);
//  Serial.print(dof.ax);
//  Serial.print(", ");
//  Serial.print(dof.ay);
//  Serial.print(", ");
//  Serial.println(dof.az);
//
//  Serial.print(dof.calcMag(dof.mx), 2);
//  Serial.print(", ");
//  Serial.print(dof.calcMag(dof.my), 2);
//  Serial.print(", ");
//  Serial.println(dof.calcMag(dof.mz), 2);
//  Serial.print(dof.mx);
//  Serial.print(", ");
//  Serial.print(dof.my);
//  Serial.print(", ");
//  Serial.println(dof.mz);
//
//
//
//
//
//  Serial.print("Temperature: ");
//  Serial.print(mySensor.readTempC(), 2);
//  Serial.println(" degrees C");
//
//  Serial.print("Temperature: ");
//  Serial.print(mySensor.readTempF(), 2);
//  Serial.println(" degrees F");
//
//  Serial.print("Pressure: ");
//  Serial.print(mySensor.readFloatPressure(), 2);
//  Serial.println(" Pa");
//
//  Serial.print("Altitude: ");
//  Serial.print(mySensor.readFloatAltitudeMeters(), 2);
//  Serial.println("m");
//
//  Serial.print("Altitude: ");
//  Serial.print(mySensor.readFloatAltitudeFeet(), 2);
//  Serial.println("ft"); 
//
//  Serial.print("%RH: ");
//  Serial.print(mySensor.readFloatHumidity(), 2);
//  Serial.println(" %");




  count += 1;
  if(count == 10){
    count = 1;
  
//    xbee.println("Blank");
//    xbee.println(AcX);
//    xbee.println(AcY);
//    xbee.println(AcZ);
//    xbee.println(GyX/100);
//    xbee.println(GyY/100);
//    xbee.println(GyZ/100);
//  
//    Serial.print(AcX);
//    Serial.print(", ");
//    Serial.print(AcY);
//    Serial.print(", ");
//    Serial.print(AcZ);
//    Serial.print(", ");
//    Serial.print(GyX/100);
//    Serial.print(", ");
//    Serial.print(GyY/100);
//    Serial.print(", ");
//    Serial.println(GyZ/100);

  }
   
//  int sensor1 = scale1.getGram();
//  int sensor2 = analogRead(A4);
//
//  String dataString = "";
//  dataString += String(sensor1);
//  dataString += ","; 
//  dataString += String(sensor2);
//  dataString += ","; 
//  dataString += String(millis());
//  
//  File dataFile = SD.open("Flight_Log001.txt", FILE_WRITE);
//  
//  if (dataFile) {
//    dataFile.println(BUILTIN_SDCARD);
//    dataFile.close();
//  }
//  xbee.print('test\n');
  float flat, flon;
  unsigned long age, chars = 0;
  unsigned short sentences = 0, failed = 0;
  static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;
  
  print_int(gps.satellites(), TinyGPS::GPS_INVALID_SATELLITES, 5);
  print_int(gps.hdop(), TinyGPS::GPS_INVALID_HDOP, 5);
  gps.f_get_position(&flat, &flon, &age);
  print_float(flat, TinyGPS::GPS_INVALID_F_ANGLE, 10, 6);
  print_float(flon, TinyGPS::GPS_INVALID_F_ANGLE, 11, 6);
  print_int(age, TinyGPS::GPS_INVALID_AGE, 5);
  print_date(gps);
  print_float(gps.f_altitude(), TinyGPS::GPS_INVALID_F_ALTITUDE, 7, 2);
  print_float(gps.f_course(), TinyGPS::GPS_INVALID_F_ANGLE, 7, 2);
  print_float(gps.f_speed_kmph(), TinyGPS::GPS_INVALID_F_SPEED, 6, 2);
  print_str(gps.f_course() == TinyGPS::GPS_INVALID_F_ANGLE ? "*** " : TinyGPS::cardinal(gps.f_course()), 6);
  print_int(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0xFFFFFFFF : (unsigned long)TinyGPS::distance_between(flat, flon, LONDON_LAT, LONDON_LON) / 1000, 0xFFFFFFFF, 9);
  print_float(flat == TinyGPS::GPS_INVALID_F_ANGLE ? TinyGPS::GPS_INVALID_F_ANGLE : TinyGPS::course_to(flat, flon, LONDON_LAT, LONDON_LON), TinyGPS::GPS_INVALID_F_ANGLE, 7, 2);
  print_str(flat == TinyGPS::GPS_INVALID_F_ANGLE ? "*** " : TinyGPS::cardinal(TinyGPS::course_to(flat, flon, LONDON_LAT, LONDON_LON)), 6);

  gps.stats(&chars, &sentences, &failed);
  print_int(chars, 0xFFFFFFFF, 6);
  print_int(sentences, 0xFFFFFFFF, 10);
  print_int(failed, 0xFFFFFFFF, 9);
  xbee.println();
  
  smartdelay(1000);
}

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do {
    while (gpsPort.available())
      gps.encode(gpsPort.read());
  } while (millis() - start < ms);
}

static void print_float(float val, float invalid, int len, int prec)
{
  if (val == invalid) {
    while (len-- > 1)
      xbee.print('*');
    xbee.print(' ');
  } else {
    xbee.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      xbee.print(' ');
  }
  smartdelay(0);
}

static void print_int(unsigned long val, unsigned long invalid, int len)
{
  char sz[32];
  if (val == invalid) {
    strcpy(sz, "*******");
  } else {
    sprintf(sz, "%ld", val);
  }
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i) {
    sz[i] = ' ';
  }
  if (len > 0) {
    sz[len-1] = ' ';
  }
  xbee.print(sz);
  smartdelay(0);
}

static void print_date(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned long age;
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  if (age == TinyGPS::GPS_INVALID_AGE) {
    xbee.print("********** ******** ");
  } else {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d %02d:%02d:%02d ",
        month, day, year, hour, minute, second);
    xbee.print(sz);
  }
  print_int(age, TinyGPS::GPS_INVALID_AGE, 5);
  smartdelay(0);
}

static void print_str(const char *str, int len)


{
  int slen = strlen(str);
  for (int i=0; i<len; ++i) {
    xbee.print(i<slen ? str[i] : ' ');
  }
  smartdelay(0);
}
