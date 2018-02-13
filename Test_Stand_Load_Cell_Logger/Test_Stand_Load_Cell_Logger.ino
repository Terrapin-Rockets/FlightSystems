


/* sample for digital weight scale of hx711, display with a HD44780 liquid crtstal monitor
 *
 * hardware design: syyyd
 * available at http://syyyd.taobao.com
 *
 * library design: Weihong Guan (@aguegu)
 * http://aguegu.net
 *
 * library host on
 * https://github.com/aguegu/Arduino
 */

// Hx711.DOUT - pin #A1
// Hx711.SCK - pin #A0

#include "hx711.h"
#include <SD.h>

Hx711 scale(A1, A0);

void setup() {
  Serial.begin(9600);
  pinMode(1, INPUT);

  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:

    
}

void loop() {
  File dataFile = SD.open("LoadCellData001.txt", FILE_WRITE);
  Serial.println("Ready to Start Logging ");
  while(digitalRead(1) = LOW){
    wait(10)
  }

  Serial.println("Logging Data");
  
  boolean testing = true
  while(testing){
    String dataString = "";
    int sensor = scale.getGram();
    dataString += String(sensor);
      
//    Serial.print(scale.getGram(), 1);
//    Serial.println(" g");

    dataFile.println(dataString);
    if(digitalRead(1) = LOW){
      testing = false
    }
  }
  dataFile.close();

  while(testing == false){
    delay(2000)
    Serial.println("Waiting to Terminate");
  }
  
}
