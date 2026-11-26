
#include <Wire.h>

#define SDA_PIN 21
#define SCL_PIN 22

void setup() {
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);

  delay(1000);
  Serial.println("=== SORTIFY: I2C SCANNER ===");
}

void loop() {
  byte error;
  int devicesFound = 0;

  Serial.println("\nScanning I2C devices...");

  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address: 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);

      devicesFound++;
    }
  }

  if (devicesFound == 0) {
    Serial.println("No I2C devices found.");
  } else {
    Serial.print("Total devices found: ");
    Serial.println(devicesFound);
  }

  delay(3000);
}
