#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "config.h"
// ========================================================================================
// config.h contains 3 variables
// 
// const char* WLAN_SSID = "xxx"; // The name of your wlan
// const char* WLAN_PASS = "xxx"; // The password of your wlan
// byte WLAN_IP[] = {0, 0, 0, 0}; // Your IP as array of 4 bytes
// 
// which I do not want to show the world, so you got to make your own config.h ;)
// ========================================================================================

const int WIFI_PORT = 2000;

WiFiClient client;

void setup() {
  Serial.begin(9600);

  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.print(WLAN_SSID);
  
  // Connect to WPA/WPA2 network:
  bool state = WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  
  IPAddress myAddress = WiFi.localIP();
  Serial.print("IP: ");
  Serial.println(myAddress);
}

int i = 0;
void loop() {
  if (!client.connected()) {
    Serial.println("Trying to connect to server ...");
    client.connect(WLAN_IP, WIFI_PORT);
    Serial.println("Connection completed");
  }
  
  client.println(i++);
  delay(500);
}
