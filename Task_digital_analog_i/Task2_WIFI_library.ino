#include <WiFiNINA.h>  // WiFiNINA library

void setup() {
  Serial.begin(9600);  // Start serial at 9600 baud
}

void loop() {
  if (WiFi.status() == WL_NO_MODULE) {   // Check if the WiFi module is present
    Serial.println("WiFi module not found!");
  }

  Serial.println("Scanning available networks...");  // Status message before a scan

  uint8_t numNetworks = WiFi.scanNetworks();  // Performs a WiFi scan + returns number of networks

  for (uint8_t i = 0; i < numNetworks; i++) {  
    Serial.print("Network: ");
    Serial.print(WiFi.SSID(i));           // SSID
    Serial.print("  Signal Strength: ");
    Serial.print(WiFi.RSSI(i));           // RSSI in dBm (=signal strength)
    Serial.print(" dBm  Encryption: ");
    Serial.println(WiFi.encryptionType(i)); // Encryption type code (e.g., WPA/WPA2)
  }

  Serial.print("Total networks: ");     
  Serial.println(numNetworks);           // Prints the count returned form scanning

  // 30s gaps between scans
  delay(10000);
  delay(10000);
  delay(10000);
}
