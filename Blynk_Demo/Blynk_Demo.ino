#define BLYNK_TEMPLATE_ID "TMPL36vXxI_07"
#define BLYNK_TEMPLATE_NAME "Node MCU"
#define BLYNK_AUTH_TOKEN "d0O7545ihpkl7vVlWAARTCuamgrc5-fb"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";

BLYNK_WRITE(V0){
  int value = param.asInt();
  digitalWrite(LED_BUILTIN, value);
  Serial.print("LED Value: ");
  Serial.println(value);
}

void setup() {
  // put your setup code here, to run once:
  Blynk.begin(auth, ssid, pass);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
