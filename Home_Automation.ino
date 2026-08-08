/*
  Project Name : IoT-Based Home Automation Using Digital Logic

  Author : Amruth Kumar Ronanki

  Description:
  IoT-based home automation system using ESP32, Blynk,
  DHT22, PIR sensor, LDR sensor, relay modules, LED
  and I2C LCD.

  Features:
  - Remote appliance control using Blynk
  - Four relay-controlled appliances
  - Outdoor light control using LDR
  - Motion detection using PIR sensor
  - Temperature and humidity monitoring
  - LCD status display
  - Wi-Fi connectivity through ESP32
  - Automatic lighting control
*/

#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHTesp.h"

// --------------------------------------------------
// LCD
// --------------------------------------------------

LiquidCrystal_I2C lcd(0x27, 20, 4);

// --------------------------------------------------
// Wi-Fi
// --------------------------------------------------

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// --------------------------------------------------
// Blynk Timer
// --------------------------------------------------

BlynkTimer timer;

// --------------------------------------------------
// Variables
// --------------------------------------------------

int val = 0;

int va1 = 0;
int va2 = 0;
int va3 = 0;
int va4 = 0;
int va5 = 0;

int ge = 0;
int k = 0;

float tmp = 0;
float hum = 0;

// --------------------------------------------------
// Pin Definitions
// --------------------------------------------------

// Relay outputs
const int RELAY1 = 5;
const int RELAY2 = 18;
const int RELAY3 = 19;
const int RELAY4 = 4;

// LDR digital output
const int LDR_PIN = 23;

// Outdoor light
const int OUTDOOR_LIGHT = 2;

// PIR sensor
const int PIR_PIN = 27;

// Motion indicator LED
const int LED_PIN = 33;

// DHT22
const int DHT_PIN = 15;

// --------------------------------------------------
// DHT Sensor
// --------------------------------------------------

DHTesp temps;

// --------------------------------------------------
// Custom LCD Characters
// --------------------------------------------------

byte lockChar[] = {
  B01110,
  B10001,
  B10001,
  B11111,
  B11011,
  B11011,
  B11111,
  B00000
};

// Temperature symbol
byte t1[] = {
  B00000,
  B00001,
  B00010,
  B00100,
  B00100,
  B00100,
  B00100,
  B00111
};

byte t2[] = {
  B00111,
  B00111,
  B00111,
  B01111,
  B11111,
  B11111,
  B01111,
  B00011
};

byte t3[] = {
  B00000,
  B10000,
  B01011,
  B00100,
  B00111,
  B00100,
  B00111,
  B11100
};

byte t4[] = {
  B11111,
  B11100,
  B11100,
  B11110,
  B11111,
  B11111,
  B11110,
  B11000
};

// Humidity symbol
byte hum1[] = {
  B00000,
  B00001,
  B00011,
  B00011,
  B00111,
  B01111,
  B01111,
  B11111
};

byte hum2[] = {
  B11111,
  B11111,
  B11111,
  B01111,
  B00011,
  B00000,
  B00000,
  B00000
};

byte hum3[] = {
  B00000,
  B10000,
  B11000,
  B11000,
  B11100,
  B11110,
  B11110,
  B11111
};

byte hum4[] = {
  B11111,
  B11111,
  B11111,
  B11110,
  B11100,
  B00000,
  B00000,
  B00000
};

// Degree symbol
byte degreeSymbol[] = {
  B00011,
  B00011,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

// --------------------------------------------------
// Blynk Virtual Pin Controls
// --------------------------------------------------

// Appliance 1
BLYNK_WRITE(V0)
{
  va1 = param.asInt();
  digitalWrite(RELAY1, va1);
}

// Appliance 2
BLYNK_WRITE(V1)
{
  va2 = param.asInt();
  digitalWrite(RELAY2, va2);
}

// Appliance 3
BLYNK_WRITE(V2)
{
  va3 = param.asInt();
  digitalWrite(RELAY3, va3);
}

// Appliance 4
BLYNK_WRITE(V3)
{
  va4 = param.asInt();
  digitalWrite(RELAY4, va4);
}

// Outdoor light
BLYNK_WRITE(V4)
{
  va5 = param.asInt();
  digitalWrite(OUTDOOR_LIGHT, va5);
}

// PIR control
BLYNK_WRITE(V7)
{
  int pirState = param.asInt();

  if (pirState == 0)
  {
    digitalWrite(LED_PIN, LOW);
    k = 1;
    ge = 0;
  }
  else
  {
    digitalWrite(LED_PIN, HIGH);
    k = 0;
    ge = 1;
  }
}

// --------------------------------------------------
// Send Sensor Data to Blynk
// --------------------------------------------------

void sendSensorData()
{
  Blynk.virtualWrite(V5, tmp);
  Blynk.virtualWrite(V6, hum);
}

// --------------------------------------------------
// Setup
// --------------------------------------------------

void setup()
{
  Serial.begin(115200);

  // Start Blynk
  Blynk.begin(auth, ssid, pass);

  // Relay pins
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // LDR
  pinMode(LDR_PIN, INPUT);

  // Outdoor light
  pinMode(OUTDOOR_LIGHT, OUTPUT);

  // PIR
  pinMode(PIR_PIN, INPUT_PULLUP);

  // LED
  pinMode(LED_PIN, OUTPUT);

  // DHT22
  temps.setup(DHT_PIN, DHTesp::DHT22);

  // LCD
  lcd.init();
  lcd.backlight();

  // Initial relay state
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);

  digitalWrite(OUTDOOR_LIGHT, LOW);
  digitalWrite(LED_PIN, LOW);

  // Startup screen
  lcd.setCursor(0, 0);
  lcd.print("IoT HOME AUTOMATION");

  lcd.setCursor(0, 1);
  lcd.print("ESP32 Controller");

  lcd.setCursor(0, 2);
  lcd.print("--------------------");

  lcd.setCursor(0, 3);
  lcd.print("System Starting...");

  delay(3000);

  lcd.clear();

  // Create lock character
  lcd.createChar(6, lockChar);

  lcd.setCursor(19, 0);
  lcd.write(6);

  lcd.setCursor(2, 1);
  lcd.print("HOME AUTOMATION");

  lcd.setCursor(5, 2);
  lcd.print("USING IoT");

  lcd.setCursor(3, 3);
  lcd.print("SYSTEM READY");

  delay(3000);

  lcd.clear();

  // Send sensor data every second
  timer.setInterval(1000L, sendSensorData);
}

// --------------------------------------------------
// Loop
// --------------------------------------------------

void loop()
{
  Blynk.run();
  timer.run();

  // ------------------------------------------------
  // LDR based outdoor light
  // ------------------------------------------------

  val = digitalRead(LDR_PIN);

  if (val == HIGH)
  {
    digitalWrite(OUTDOOR_LIGHT, va5);
  }
  else
  {
    digitalWrite(OUTDOOR_LIGHT, LOW);
  }

  // ------------------------------------------------
  // Read DHT22
  // ------------------------------------------------

  TempAndHumidity data = temps.getTempAndHumidity();

  tmp = data.temperature;
  hum = data.humidity;

  // ------------------------------------------------
  // PIR motion detection
  // ------------------------------------------------

  int pirValue = digitalRead(PIR_PIN);

  if (pirValue == HIGH)
  {
    digitalWrite(LED_PIN, HIGH);
    k = 1;
    ge = 1;
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    k = 0;
    ge = 0;
  }

  // ------------------------------------------------
  // Display relay status
  // ------------------------------------------------

  lcd.clear();

  lcd.setCursor(19, 0);
  lcd.write(6);

  lcd.setCursor(0, 1);
  lcd.print("SW_1=");
  lcd.print(va1 ? "ON " : "OFF");

  lcd.setCursor(11, 1);
  lcd.print("SW_2=");
  lcd.print(va2 ? "ON " : "OFF");

  lcd.setCursor(0, 2);
  lcd.print("SW_3=");
  lcd.print(va3 ? "ON " : "OFF");

  lcd.setCursor(11, 2);
  lcd.print("SW_4=");
  lcd.print(va4 ? "ON " : "OFF");

  lcd.setCursor(0, 3);
  lcd.print("OD_L=");
  lcd.print(va5 ? "ON " : "OFF");

  lcd.setCursor(11, 3);
  lcd.print("WR_L=");
  lcd.print(ge ? "ON " : "OFF");

  delay(1500);

  // ------------------------------------------------
  // Temperature Display
  // ------------------------------------------------

  lcd.clear();

  lcd.createChar(1, t1);
  lcd.createChar(2, t2);
  lcd.createChar(3, t3);
  lcd.createChar(4, t4);
  lcd.createChar(5, degreeSymbol);

  lcd.setCursor(19, 0);
  lcd.write(6);

  lcd.setCursor(1, 1);
  lcd.write(1);

  lcd.setCursor(1, 2);
  lcd.write(2);

  lcd.setCursor(2, 1);
  lcd.write(3);

  lcd.setCursor(2, 2);
  lcd.write(4);

  lcd.setCursor(4, 1);
  lcd.print("Temperature:");

  lcd.setCursor(7, 2);
  lcd.print(tmp);

  lcd.setCursor(12, 2);
  lcd.write(5);

  lcd.setCursor(13, 2);
  lcd.print("C");

  delay(750);

  // ------------------------------------------------
  // Humidity Display
  // ------------------------------------------------

  lcd.clear();

  lcd.createChar(1, hum1);
  lcd.createChar(2, hum2);
  lcd.createChar(3, hum3);
  lcd.createChar(4, hum4);

  lcd.setCursor(19, 0);
  lcd.write(6);

  lcd.setCursor(3, 1);
  lcd.write(1);

  lcd.setCursor(3, 2);
  lcd.write(2);

  lcd.setCursor(4, 1);
  lcd.write(3);

  lcd.setCursor(4, 2);
  lcd.write(4);

  lcd.setCursor(6, 1);
  lcd.print("Humidity:");

  lcd.setCursor(7, 2);
  lcd.print(hum);

  lcd.setCursor(13, 2);
  lcd.print("%");

  delay(750);
}
