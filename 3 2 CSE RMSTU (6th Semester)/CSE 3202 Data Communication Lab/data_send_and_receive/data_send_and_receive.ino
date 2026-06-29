#include <SPI.h>
#include <LoRa.h>

// ---- Pin Config ----
#define SS   10
#define RST  9
#define DIO0 8

// ---- LoRa Config ----
#define FREQUENCY   433E6
#define SYNC_WORD   0x12
#define BAUD_RATE   9600

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Abid-B] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Abid-B] Arduino Receiver Ready");
  Serial.println("Listening for Team A (Maruf) and Team C (Joyanta)...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Abid-B] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}