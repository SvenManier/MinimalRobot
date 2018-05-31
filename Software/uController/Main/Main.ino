#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "settings.h"
#include "connectionInfo.h"
// ========================================================================================
// connectionInfo.h contains 3 variables
// 
// const char* WLAN_SSID = "xxx"; // The name of your wlan
// const char* WLAN_PASS = "xxx"; // The password of your wlan
// byte WLAN_IP[] = {0, 0, 0, 0}; // Your IP as array of 4 bytes
// 
// which I do not want to show the world, so you got to make your own connectionInfo.h ;)
// ========================================================================================

const int WIFI_PORT = 2000;

WiFiClient client;

void setup() {
  systemInit();
}

void loop() {
  if (!client.connected()) {
    Serial.println("Trying to connect to server ...");
    client.connect(WLAN_IP, WIFI_PORT);
    Serial.println("Connection completed");
  }
  
  client.println(i++);
  delay(500);
}

// ==========================
// ===== ENGINE CONTROL =====
// ==========================

void rechtsrum(int[] engine, unsigned int motorSpeed){
  // 1
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);

  // 2
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);

  // 3
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);

  // 4
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);

  // 5
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delayMicroseconds(motorSpeed);

  // 6
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delayMicroseconds(motorSpeed);

  // 7
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delayMicroseconds(motorSpeed);

  // 8
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delayMicroseconds(motorSpeed);
}

void linksrum(unsigned int motorSpeed)
{ // 1
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delayMicroseconds(motorSpeed);

  // 2
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delayMicroseconds(motorSpeed);

  // 3
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delayMicroseconds(motorSpeed);

  // 4
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delayMicroseconds(motorSpeed);

  // 5
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delayMicroseconds(motorSpeed);

  // 6
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delayMicroseconds(motorSpeed);

  // 7
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delayMicroseconds(motorSpeed);

  // 8
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delayMicroseconds(motorSpeed);
}

void stop(){
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
}

// =================================
// ===== SYSTEM INITIALIZATION =====
// =================================

/**
 * Initializes the system
 */
void systemInit() {
  connectWithWifi();
  initializePinModes();
}

/**
 * Connects to WiFi
 */
void connectWithWiFi() {
  bool state = WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

/**
 * Initializes the pin modes
 */
void initializePinModes() {
  setPinModeForArray(LEFT_ENGINE, 4, OUTPUT);
  setPinModeForArray(RIGHT_ENGINE, 4, OUTPUT);
}

/**
 * Initializes an array of pins
 */
void setPinModeForArray(int[] pinArray, int length, int pinMode) {
  for (int i = 0; i < length; i++) {
    setPinMode(pinArray[i], pinMode);
  }
}

