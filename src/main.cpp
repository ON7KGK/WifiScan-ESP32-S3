#include <Arduino.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000); // Attendre que le moniteur série soit prêt
  Serial.println("Scanning for Wi-Fi networks...");

  // Démarrer le Wi-Fi en mode station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Scanner les réseaux Wi-Fi disponibles
  int n = WiFi.scanNetworks();
  Serial.println("Scan done");
  if (n == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Afficher les informations de chaque réseau
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");
}

void loop() {
  // Rien à faire ici
}
