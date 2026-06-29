#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

// ---- Pin Config ----
#define SS   10
#define RST  9
#define DIO0 8

// ---- LoRa Config ----
#define FREQUENCY   433E6
#define SYNC_WORD   0x12
#define BAUD_RATE   9600

// ---- TSL2561 Sensor ----
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

int counter = 0;
unsigned long lastSendTime = 0;
bool sensorReady = false;
#define SEND_INTERVAL 3000

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Abid-B] LoRa init FAILED!");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Abid-B] Arduino Send+Receive Ready");

  if (!tsl.begin()) {
    Serial.println("[Abid-B] TSL2561 NOT FOUND! Running without sensor.");
    sensorReady = false;
  } else {
    tsl.enableAutoRange(true);
    tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);
    Serial.println("[Abid-B] TSL2561 ready.");
    sensorReady = true;
  }
}

void loop() {
  // --- Receive ---
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

  // --- Send every 3 seconds ---
  if (millis() - lastSendTime > SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;

    uint32_t lux = 0;
    if (sensorReady) {
      uint16_t broadband, ir;
      tsl.getLuminosity(&broadband, &ir);
      lux = tsl.calculateLux(broadband, ir);
    }

    String message = "Abid-B | Packet #" + String(counter) +
                      " | Lux=" + (sensorReady ? String(lux) : "N/A");

    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("[Abid-B] Sent: " + message);
  }
}