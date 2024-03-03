#include <Arduino.h>
#include "ControllerWiFi.h"
#include "OTA.h"

#define version 0.02

void setup() {
  Serial.begin(115200);
    Serial.println("Booting");
    
    WiFiSetup();

    OTASetup();
}

void loop() {
    ArduinoOTA.handle();
}

