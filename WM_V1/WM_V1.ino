#define MOISTURE_SENSOR_PIN A0
#define RELAY_PIN 5

#define MAX_MOISTURE 1024
#define MIN_MOISTURE 3

int moistureVal = 0;
int moistureThreshold = 1000;

void setup () {
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop () {
  moistureVal = analogRead(MOISTURE_SENSOR_PIN);
  Serial.print("Moisture value: ");
  Serial.println(moistureVal);

  if (moistureVal > moistureThreshold) {
    digitalWrite(RELAY_PIN, HIGH);
  }
  else {
    digitalWrite(RELAY_PIN, LOW);
  }
}