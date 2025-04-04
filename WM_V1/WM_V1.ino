/* ESP & Blynk includes */
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <BlynkTimer.h>

/* Wi-Fi information for wireless connection */
char auth[] = "YourBlynkAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

/* Pin defines */
#define MOISTURE_SENSOR_PIN A0
#define RELAY_PIN 6
#define WATER_LEVEL_PIN 4
/* Threshold defines */
#define DRY_VALUE 4095  // Adjust this value based on sensor's readings when dry
#define WET_VALUE 5     // Adjust this value based on sensor's readings when fully wet

int moistureThreshold = 500;
unsigned long pumpRunTime = 5000;

/* Function prototypes */
void checkSoilMoisture();
void waterPlant();

void setup() {
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(WATER_LEVEL_PIN, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(60000L, checkSoilMoisture);
  delay (1000);
}

void loop() {
  Blynk.run();
  timer.run();

  // int sensorValue = analogRead(MOISTURE_SENSOR_PIN);

  // // Map the sensor value to a percentage (0-100)
  // int percentage = map(sensorValue, DRY_VALUE, WET_VALUE, 0, 100);

  // // Ensure the percentage is within the valid range
  // percentage = constrain(percentage, 0, 100);

  // // Print the sensor value and percentage
  // Serial.print("Sensor Value: ");
  // Serial.print(sensorValue);
  // Serial.print(", Moisture Level: ");
  // Serial.print(percentage);
  // Serial.println("%");


//   // Relay Test
//   digitalWrite(RELAY_PIN, HIGH);
//   delay(2000);
//   digitalWrite(RELAY_PIN, LOW);
//   delay(2000);
}

void checkSoilMoisture() {
  int moistureValue = analogRead(SOIL_MOISTURE_PIN);
  if (moistureValue < moistureThreshold) {
    waterPlant();
  }
}

void waterPlant() {
  if (digitalRead(WATER_LEVEL_PIN) == HIGH) {
    digitalWrite(RELAY_PIN, LOW);
    delay(pumpRunTime);
    digitalWrite(RELAY_PIN, HIGH);
  }
}

BLYNK_WRITE(V1) {
  if (param.asInt() == 1) {
    waterPlant();
  }
}

BLYNK_WRITE(V2) {
  timer.setInterval(param.asInt() * 1000L, checkSoilMoisture);
}

BLYNK_WRITE(V3) {
  moistureThreshold = param.asInt();
}