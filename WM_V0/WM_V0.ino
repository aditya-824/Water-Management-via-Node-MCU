#define MOISTURE_SENSOR_PIN A0
#define RELAY_PIN 

#define DRY_VALUE 4095  // Adjust this value based on sensor's readings when dry
#define WET_VALUE 5     // Adjust this value based on sensor's readings when fully wet

void setup() {
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN ,OUTPUT);
  // pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
  delay (1000);
}

void loop() {
  digitalWrite(RELAY_PIN , HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN , LOW);
  delay(1000);
  // int sensorValue = analogRead(MOISTURE_SENSOR_PIN);

  // // Map the sensor value to a percentage (0-100)
  // int percentage = map(sensorValue, DRY_VALUE, WET_VALUE, 0, 100);

  // // Ensure the percentage is within the valid range
  // percentage = constrain(percentage, 0, 100);

  // Print the sensor value and percentage
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