/*************************************************************************************************
 *  Created By: Tauseef Ahmad
 *  Created On: 28 June, 2023
 *  
 *  YouTube Video: https://youtu.be/LrEEN4Ji-Ec
 *  My Channel: https://www.youtube.com/@AhmadLogs
 ***********************************************************************************************/

#include <SoftwareSerial.h>

#define RX 5
#define TX 4
SoftwareSerial LoRaSerial(RX, TX); // RX, TX

const int ledPin = 16;
unsigned long lastTransmitTime = 0;

void setup() {
  Serial.begin(115200); // Initialize USB Serial
  delay(1000);
  
  LoRaSerial.begin(115200); // Initialize Software Serial

  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  if(LoRaSerial.available()) {
    String incommingData = LoRaSerial.readStringUntil('\n');
    Serial.println(incommingData);
    if(incommingData.indexOf("Hello")){
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
    }
  }
}
