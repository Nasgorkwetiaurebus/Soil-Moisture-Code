
#define SENSOR_PIN 34  // AO sensor terhubung ke GPIO34 (D34)

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== SORTIFY: SENSOR TEST ===");
  Serial.println("Reading YL-69...");
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);

  Serial.print("Moisture Sensor Value: ");
  Serial.println(sensorValue);

  delay(1000);
}
