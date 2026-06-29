// #include <SPI.h>
// #include <LoRa.h>

// // ---- Pin Config ----
// #define SS   10
// #define RST  9
// #define DIO0 8

// // ---- LoRa Config ----
// #define FREQUENCY   433E6
// #define SYNC_WORD   0x12
// #define BAUD_RATE   9600

// void setup() {
//   Serial.begin(BAUD_RATE);
//   LoRa.setPins(SS, RST, DIO0);

//   if (!LoRa.begin(FREQUENCY)) {
//     Serial.println("[team Abid] LoRa init FAILED! Check wiring.");
//     while (1);
//   }

//   LoRa.setSyncWord(SYNC_WORD);
//   Serial.println("[team Abid] Arduino Receiver Ready");
//   Serial.println("Listening for Team A and Team B...");
// }

// void loop() {
//   int packetSize = LoRa.parsePacket();

//   if (packetSize) {
//     String received = "";
//     while (LoRa.available()) {
//       received += (char)LoRa.read();
//     }
//     Serial.print("[team Abid] Received: ");
//     Serial.print(received);
//     Serial.print(" | RSSI: ");
//     Serial.print(LoRa.packetRssi());
//     Serial.println(" dBm");
//   }
// }


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

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Team B] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team B] Arduino Sender Ready");
  Serial.println("Sending to Team A and Team C...");
}

void loop() {
  counter++;

  String message = "Hello from Abid | Packet #" + String(counter);

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println("[Team Abid] Sent: " + message);
  delay(3000);
}