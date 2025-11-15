#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define PIR_PIN D5          // PIR Motion Sensor
#define IR_PIN D6           // IR Sensor
#define BUZZER_PIN D7       // Buzzer

SoftwareSerial gsm(4, 5);   // GSM SIM800L Tx=4, Rx=5

void setup() {
  Serial.begin(115200);
  gsm.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Warehouse Security System Started");
  sendSMS("System Activated - Warehouse Monitoring Started");
}

void loop() {
  int pirValue = digitalRead(PIR_PIN);
  int irValue = digitalRead(IR_PIN);

  if (pirValue == HIGH || irValue == LOW) {
    Serial.println("⚠ ALERT! Unauthorized entry detected!");

    digitalWrite(BUZZER_PIN, HIGH);
    sendSMS("⚠ ALERT: Intrusion detected in warehouse!");
    delay(5000);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500);
}

void sendSMS(String message) {
  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.println("AT+CMGS=\"+91XXXXXXXXXX\""); // PUT YOUR NUMBER
  delay(1000);

  gsm.print(message);
  delay(1000);

  gsm.write(26); // send Ctrl+Z
  delay(3000);
}
