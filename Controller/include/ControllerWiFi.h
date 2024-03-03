#include <WiFi.h>

// Check if c.h exists
#if defined(__has_include) && __has_include("conf_config.h")
#include "conf_config.h"
#endif

#ifndef conf_config_h
    #define SSID "ssid"
    #define PASSWORD "password"
#endif

const char* ssid = SSID;
const char* password = PASSWORD;

void WiFiSetup()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) 
    {
        Serial.println("Connection Failed! Rebooting...");
        delay(5000);
        ESP.restart();
    }
    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}