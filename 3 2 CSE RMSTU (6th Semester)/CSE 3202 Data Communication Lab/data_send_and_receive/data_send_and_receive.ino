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

int counter = 0;
unsigned long lastSendTime = 0;
#define SEND_INTERVAL 3000

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Team B (Abid)] LoRa init FAILED!");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team B (Abid)] Arduino Send+Receive Ready");
}

void loop() {
  // --- Receive ---
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Team B (Abid)] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }

  // --- Send every 3 seconds ---
  if (millis() - lastSendTime > SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;
    String message = "Hey from TeamB (Abid) | Packet #" + String(counter);
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("[Team B (Abid)] Sent: " + message);
  }
}