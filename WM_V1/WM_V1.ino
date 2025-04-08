/* ESP & Blynk includes */
#include <ESP8266WiFi.h>

/* Pin defines */
#define MOISTURE_SENSOR_PIN A0
#define RELAY_PIN 6
/* Threshold defines */
#define DRY_VALUE 4095  // Adjust this value based on sensor's readings when dry
#define WET_VALUE 5     // Adjust this value based on sensor's readings when fully wet

int moistureThreshold = 500;  // Moisture threshold above which watering occurs
int pumpRunTime = 2000;       // To control pump duration
int soilMoisture = 0;         // To store the soil moisture value
bool relayState = false;      // To store the relay state

/* Function prototypes */
void checkSoilMoisture();
void waterPlant();

void setup() {
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  checkSoilMoisture();
  waterPlant();
  printData();
}

void checkSoilMoisture() {
  soilMoisture = analogRead(MOISTURE_SENSOR_PIN);
}

void waterPlant() {
  if (soilMoisture >= moistureThreshold) {
    digitalWrite(RELAY_PIN, HIGH);
    relayState = true;
    delay(pumpRunTime);
    digitalWrite(RELAY_PIN, LOW);
    relayState = false;
  } else {
    digitalWrite(RELAY_PIN, LOW);
    relayState = false;
  }
}

void printData() {
  Serial.print("Moisture Level: ");
  Serial.print(soilMoisture);
  Serial.print(", Relay State: ");
  Serial.println(relayState);
}