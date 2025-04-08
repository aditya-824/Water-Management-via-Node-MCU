#define BLYNK_TEMPLATE_ID "TMPL36vXxI_07"
#define BLYNK_TEMPLATE_NAME "Node MCU"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define MOISTURE_SENSOR_PIN A0
#define RELAY_PIN 5

#define MAX_MOISTURE 1024
#define MIN_MOISTURE 3

char auth[] = "d0O7545ihpkl7vVlWAARTCuamgrc5-fb";
char ssid[] = "Level Up";
char pass[] = "BMG9821028005";
BlynkTimer timer;

int moistureVal = 0;
int moistureScaled = 0;
int moistureThreshold = 1000;
int pumpStatus = 0;

void transmitData();

void setup () {
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, transmitData);
}

void loop () {
  Blynk.run();
  timer.run();

  moistureVal = analogRead(MOISTURE_SENSOR_PIN);
  moistureScaled = moistureVal / 1024 * 100;

  if (moistureVal > moistureThreshold) {
    digitalWrite(RELAY_PIN, HIGH);
    pumpStatus = 1;
  }
  else {
    digitalWrite(RELAY_PIN, LOW);
    pumpStatus = 0;
  }

  Serial.print("Pump Status: ");
  Serial.print(pumpStatus);
  Serial.print(", Moisture value: ");
  Serial.print(moistureVal);
  Serial.print(", Soil Moisture %: ");
  Serial.println(moistureScaled);
}

void transmitData() {
  Blynk.virtualWrite(V0, moistureScaled);
  Blynk.virtualWrite(V1, pumpStatus);
}