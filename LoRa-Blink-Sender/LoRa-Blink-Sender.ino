#include <SoftwareSerial.h>

#define RX 3
#define TX 2
SoftwareSerial LoRaSerial(RX, TX); // RX, TX

const int ledPin = 13;
unsigned long lastTransmitTime = 0;

void setup() {
  Serial.begin(115200); // Initialize USB Serial
  delay(1000);
  
  LoRaSerial.begin(115200); // Initialize Software Serial

  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  if (millis() - lastTransmitTime >= 1000) {
    lastTransmitTime = millis();
    digitalWrite(ledPin, HIGH);
    delay(100);

    LoRaSerial.println("AT+SEND=2,5,Hello"); // Send data

    digitalWrite(ledPin, LOW); // Turn off sender LED
  }
}
