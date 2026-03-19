#include <Arduino.h>

const int LED_PIN = PC10; 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(115200); 
  
  // Wait for the USB Serial port to be opened by the host computer
  while (!Serial) {
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  }

  Serial.println("USB Serial initialized successfully!");
  Serial.println("STM32G0B1 is alive.");
}

void loop() {
  Serial.println("Blinking LED...");
  digitalWrite(LED_PIN, HIGH);
  delay(1000); 
  
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}