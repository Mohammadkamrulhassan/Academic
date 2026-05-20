// Transmitter Code (basic)
// /*
#include <SPI.h>
#include <LoRa.h>

#define SS   10
#define RST  9
#define DIO0 8

int counter = 0;

void setup() {
  Serial.begin(9600);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Team B: LoRa init failed! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(0x12);   // All teams must use same sync word
  Serial.println("Team B (Arduino) Transmitter Ready");
}

void loop() {
  counter++;

  LoRa.beginPacket();
  LoRa.print("MSG from TeamB | Packet #"); 
  LoRa.print(counter);
  LoRa.endPacket();

  Serial.print("Team B Sent Packet #");
  Serial.println(counter);

  delay(3000);
}
// */

// Receiver C          ode (basic)
/*
#include <SPI.h>
#include <LoRa.h>

#define SS   10
#define RST  9
#define DIO0 8

void setup() {
  Serial.begin(9600);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Team B: LoRa init failed! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(0x12);
  Serial.println("Team B (Arduino) Receiver Ready...");
  Serial.println("Waiting for packets...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    Serial.print("Team B Received: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.print("  |  RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
*/
