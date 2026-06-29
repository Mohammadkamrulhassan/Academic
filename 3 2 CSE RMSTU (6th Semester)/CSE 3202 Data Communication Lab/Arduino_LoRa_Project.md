# Data Communication Project

## LoRa SX1278 433MHz — 3 Team Full Communication + Environmental Sensors
### Course: Data Communication | Arduino UNO & ESP32

---

# Team Overview

| Team | Hardware | LoRa Module | Level Converter | Sensor | Role |
|---|---|---|---|---|---|
| **Team A (Maruf)** | ESP32 NodeMCU 30P | Ra-01 SX1278 433MHz | Not needed | MP-135/MP503 Air Quality (analog) | Send & Receive |
| **Team B (Abid)** | Arduino UNO | Ra-01 SX1278 433MHz | 8CH Bi-Directional | TSL2561 Luminosity/IR (I2C) | Send & Receive |
| **Team C (Joyanta)** | Arduino UNO | Ra-01 SX1278 433MHz | 8CH Bi-Directional | AHT20+BMP280 Temp/Humidity/Pressure (I2C) | Send & Receive |

---

# Can All 3 Teams Communicate With Each Other?

## YES — Here is Why

All 3 teams use:
- Same **frequency**: 433 MHz
- Same **sync word**: 0x12
- Same **LoRa library**: Sandeep Mistry

LoRa works like a **radio broadcast**. Anyone tuned to the same frequency and sync word can hear everyone else.

```
         Team A (ESP32)
        /              \
       sends           receives
      /                    \
Team C/Joyanta (Arduino) ←→ Team B/Abid (Arduino)
       \                    /
       receives           sends
        \              /
         all connected!
```

Every team can SEND to all others and RECEIVE from all others at the same time.

---

# Full Configuration Table — All Teams

| Parameter | Value | Note |
|---|---|---|
| Frequency | **433 MHz (433E6)** | Must be same on all |
| Sync Word | **0x12** | Must be same on all |
| Bandwidth | **125 kHz** (default) | Do not change |
| Spreading Factor | **7** (default) | Do not change |
| Coding Rate | **4/5** (default) | Do not change |
| TX Power | **17 dBm** (default) | Can adjust if needed |
| Library | **LoRa by Sandeep Mistry** | All teams use this |
| Serial Baud — Arduino | **9600** | Team B (Abid) & Team C (Joyanta) |
| Serial Baud — ESP32 | **115200** | Team A (Maruf) only |
| SPI Mode | **Mode 0** (handled by library) | Auto |

---

# Why Level Converter? (Team B/Abid & Team C/Joyanta Only)

```
Arduino UNO  →  5V logic
Ra-01 LoRa   →  3.3V logic  ← DAMAGED by 5V!

Level Converter = Translator

Arduino (5V) [B side] ════ [A side] Ra-01 (3.3V)
    VCCB=5V                           VCCA=3.3V
     B0  ←── translates ──→  A0
     B1  ←── translates ──→  A1  ...
```

| Pin | Meaning | Connect To |
|---|---|---|
| VCCA | Power for 3.3V side | Arduino 3.3V |
| VCCB | Power for 5V side | Arduino 5V |
| A0–A7 | 3.3V signal pins | Ra-01 pins |
| B0–B7 | 5V signal pins | Arduino pins |
| GND | Common ground | Arduino GND |

---

---

# TEAM A (MARUF) — ESP32 NodeMCU 30P

## Wiring (No Level Converter Needed)

| ESP32 Pin | Ra-01 Pin |
|---|---|
| 3.3V | 3V3 |
| GND | GND |
| GPIO5 (D5) | NSS |
| GPIO18 (D18) | SCK |
| GPIO19 (D19) | MISO |
| GPIO23 (D23) | MOSI |
| GPIO14 (D14) | RST |
| GPIO2 (D2) | DIO0 |

```
[ESP32 NodeMCU 30P]
    ├── 3.3V ──────────→ 3V3  (Ra-01)
    ├── GND  ──────────→ GND  (Ra-01)
    ├── D5   ──────────→ NSS  (Ra-01)
    ├── D18  ──────────→ SCK  (Ra-01)
    ├── D19  ──────────→ MISO (Ra-01)
    ├── D23  ──────────→ MOSI (Ra-01)
    ├── D14  ──────────→ RST  (Ra-01)
    └── D2   ──────────→ DIO0 (Ra-01)
```

## Configuration
```
Frequency  : 433E6
Sync Word  : 0x12
Baud Rate  : 115200
Board      : ESP32 Dev Module
SS  pin    : 5
RST pin    : 14
DIO0 pin   : 2
```

---

## SENSOR ADD-ON — MP-135 / MP503 Air Quality Sensor (Team A / Maruf)

### Sensor Facts
- **Type:** Analog only (no I2C/digital data line) — outputs a voltage on the **AO** pin proportional to gas concentration
- **Power:** 5V (some breakout boards tolerate 3.3V–5V, but 5V gives correct reference range — check your board's VCC label)
- **Pins on module:** `VCC`, `GND`, `AO` (analog out), `DO` (digital threshold out — not used here)
- **Preheat:** sensor needs ~20–60s after power-on before readings stabilize

### Wiring (ESP32)

| MP503 Pin | ESP32 Pin | Note |
|---|---|---|
| VCC | 5V (VIN) | Use the 5V pin, not 3.3V |
| GND | GND | Common ground |
| AO | GPIO34 (ADC1_CH6) | Analog read — input-only pin, ADC1 (safe, doesn't conflict with WiFi/LoRa) |
| DO | Not connected | Digital threshold pin, unused in this project |

```
[ESP32 NodeMCU 30P]                [MP503 Module]
    ├── 5V   ──────────────────→ VCC
    ├── GND  ──────────────────→ GND
    └── D34  ──────────────────→ AO
                                  DO ── (not connected)
```

**Why GPIO34?** It's an ADC1 input-only pin. ADC2 pins share hardware with WiFi and can give unreliable readings if WiFi is ever active — ADC1 avoids that entirely, and GPIO34 isn't used anywhere else in the LoRa wiring.

### Combined Pin Map — Team A (Maruf)

| Function | ESP32 Pin |
|---|---|
| LoRa NSS | GPIO5 |
| LoRa SCK | GPIO18 |
| LoRa MISO | GPIO19 |
| LoRa MOSI | GPIO23 |
| LoRa RST | GPIO14 |
| LoRa DIO0 | GPIO2 |
| MP503 AO | GPIO34 |
| MP503 VCC | 5V |
| MP503 GND | GND |

---

## Team A (Maruf) — Sender Code (ESP32)

```cpp
#include <SPI.h>
#include <LoRa.h>

// ---- Pin Config ----
#define SS   5
#define RST  14
#define DIO0 2

// ---- LoRa Config ----
#define FREQUENCY   433E6
#define SYNC_WORD   0x12
#define BAUD_RATE   115200

// ---- MP503 Air Quality Sensor ----
#define MP503_AO_PIN 34   // ADC1_CH6, input-only pin
#define PREHEAT_TIME 20000  // 20s warm-up before first reliable reading

int counter = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Maruf-A] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Maruf-A] ESP32 Sender Ready");
  Serial.println("Sending to Team B (Abid) and Team C (Joyanta)...");

  Serial.println("[Maruf-A] Preheating MP503 sensor (20s)...");
  delay(PREHEAT_TIME);
  Serial.println("[Maruf-A] MP503 ready.");
}

void loop() {
  counter++;

  int airRaw = analogRead(MP503_AO_PIN);          // 0-4095 (ESP32 ADC is 12-bit)
  float airVoltage = airRaw * (3.3 / 4095.0);      // convert to volts

  String message = "Maruf-A | Packet #" + String(counter) +
                    " | AirQuality_Raw=" + String(airRaw) +
                    " | AirQuality_V=" + String(airVoltage, 2);

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println("[Maruf-A] Sent: " + message);
  delay(3000);
}
```

## Team A (Maruf) — Receiver Code (ESP32)

```cpp
#include <SPI.h>
#include <LoRa.h>

// ---- Pin Config ----
#define SS   5
#define RST  14
#define DIO0 2

// ---- LoRa Config ----
#define FREQUENCY   433E6
#define SYNC_WORD   0x12
#define BAUD_RATE   115200

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Maruf-A] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Maruf-A] ESP32 Receiver Ready");
  Serial.println("Listening for Team B (Abid) and Team C (Joyanta)...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Maruf-A] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

## Team A (Maruf) — Sender + Receiver Together (ESP32)

```cpp
#include <SPI.h>
#include <LoRa.h>

// ---- Pin Config ----
#define SS   5
#define RST  14
#define DIO0 2

// ---- LoRa Config ----
#define FREQUENCY   433E6
#define SYNC_WORD   0x12
#define BAUD_RATE   115200

// ---- MP503 Air Quality Sensor ----
#define MP503_AO_PIN  34
#define PREHEAT_TIME  20000

int counter = 0;
unsigned long lastSendTime = 0;
bool sensorReady = false;
#define SEND_INTERVAL 3000

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Maruf-A] LoRa init FAILED!");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Maruf-A] ESP32 Send+Receive Ready");

  Serial.println("[Maruf-A] Preheating MP503 sensor (20s)...");
  delay(PREHEAT_TIME);

  // Check sensor connection by reading initial value
  int testRead = analogRead(MP503_AO_PIN);
  if (testRead == 0 || testRead == 4095) {
    Serial.println("[Maruf-A] MP503 NOT FOUND or disconnected! Running without sensor.");
    sensorReady = false;
  } else {
    Serial.println("[Maruf-A] MP503 ready.");
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
    Serial.print("[Maruf-A] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }

  // --- Send every 3 seconds ---
  if (millis() - lastSendTime > SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;

    String message;

    if (sensorReady) {
      int airRaw = analogRead(MP503_AO_PIN);
      float airVoltage = airRaw * (3.3 / 4095.0);
      message = "Maruf-A | Packet #" + String(counter) +
                " | AirQuality_Raw=" + String(airRaw) +
                " | AirQuality_V=" + String(airVoltage, 2);
    } else {
      message = "Maruf-A | Packet #" + String(counter) +
                " | AirQuality_Raw=N/A | AirQuality_V=N/A";
    }

    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("[Maruf-A] Sent: " + message);
  }
}
```

---

---

# TEAM B (ABID) — Arduino UNO + Level Converter

## Wiring

### Power Wiring

| Arduino | To | Note |
|---|---|---|
| 3.3V | Level Converter VCCA | A side power |
| 3.3V | Ra-01 3V3 | Ra-01 power direct |
| 5V | Level Converter VCCB | B side power |
| GND | Converter GND (A side) | Common ground |
| GND | Converter GND (B side) | Common ground |
| GND | Ra-01 GND | Common ground |

### Signal Wiring

| Arduino | Converter B | Converter A | Ra-01 |
|---|---|---|---|
| D13 SCK | B0 | A0 | SCK |
| D12 MISO | B1 | A1 | MISO |
| D11 MOSI | B2 | A2 | MOSI |
| D10 NSS | B3 | A3 | NSS |
| D9 RST | B4 | A4 | RST |
| D8 DIO0 | B5 | A5 | DIO0 |

```
LAPTOP USB → [Arduino UNO]
    ├── 3.3V ──┬──→ VCCA (Converter)
    │          └──→ 3V3  (Ra-01)
    ├── 5V  ──────→ VCCB (Converter)
    ├── GND ──┬──→ GND-A + GND-B (Converter)
    │         └──→ GND (Ra-01)
    ├── D13 ──→ [B0═A0] ──→ SCK
    ├── D12 ──→ [B1═A1] ──→ MISO
    ├── D11 ──→ [B2═A2] ──→ MOSI
    ├── D10 ──→ [B3═A3] ──→ NSS
    ├── D9  ──→ [B4═A4] ──→ RST
    └── D8  ──→ [B5═A5] ──→ DIO0
```

### Ra-01 Pin Layout
```
┌─────────────────┐
│  MISO  │  DIO0  │
│  SCK   │  MOSI  │
│  RST   │  NSS   │
│  GND   │  3V3   │
└────────┴────────┘
       [antenna]
```

## Configuration
```
Frequency  : 433E6
Sync Word  : 0x12
Baud Rate  : 9600
SS  pin    : 10
RST pin    : 9
DIO0 pin   : 8
```

---

## SENSOR ADD-ON — TSL2561 Luminosity/IR Sensor (Team B / Abid)

### Sensor Facts
- **Type:** I2C digital sensor (no analog wiring needed)
- **Power:** 3.3V or 5V (module has onboard regulator — check your breakout's silkscreen, most accept both)
- **I2C Address:** `0x39` default (some boards: `0x29` or `0x49` depending on ADDR pin strap)
- **Library:** Adafruit TSL2561 + Adafruit Unified Sensor (install both via Library Manager)

### Wiring (Arduino UNO)

| TSL2561 Pin | Arduino UNO Pin | Note |
|---|---|---|
| VCC | 3.3V or 5V | Check breakout's input voltage range |
| GND | GND | Common ground |
| SDA | A4 | I2C data line |
| SCL | A5 | I2C clock line |

```
[Arduino UNO]                  [TSL2561 Module]
    ├── 3.3V/5V ─────────────→ VCC
    ├── GND     ─────────────→ GND
    ├── A4 (SDA) ────────────→ SDA
    └── A5 (SCL) ────────────→ SCL
```

**Note on shared bus:** A4/A5 are not used anywhere else in Team B's LoRa wiring (which uses D8–D13), so there's no pin conflict. If you add more I2C sensors later, they can share the same SDA/SCL lines (each I2C device needs a unique address).

### Combined Pin Map — Team B (Abid)

| Function | Arduino Pin |
|---|---|
| LoRa SCK | D13 (via converter) |
| LoRa MISO | D12 (via converter) |
| LoRa MOSI | D11 (via converter) |
| LoRa NSS | D10 (via converter) |
| LoRa RST | D9 (via converter) |
| LoRa DIO0 | D8 (via converter) |
| TSL2561 SDA | A4 (direct, no converter — 3.3V/5V tolerant) |
| TSL2561 SCL | A5 (direct, no converter) |

### Arduino Library Setup (Team B only)
1. Arduino IDE → Tools → Manage Libraries
2. Search **"Adafruit TSL2561"** → Install
3. It will prompt to also install **"Adafruit Unified Sensor"** → accept

---

## Team B (Abid) — Sender Code (Arduino)

```cpp
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

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Abid-B] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Abid-B] Arduino Sender Ready");
  Serial.println("Sending to Team A (Maruf) and Team C (Joyanta)...");

  if (!tsl.begin()) {
    Serial.println("[Abid-B] TSL2561 NOT FOUND! Check I2C wiring.");
    while (1);
  }
  tsl.enableAutoRange(true);
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);
  Serial.println("[Abid-B] TSL2561 ready.");
}

void loop() {
  counter++;

  uint16_t broadband, ir;
  tsl.getLuminosity(&broadband, &ir);
  uint32_t lux = tsl.calculateLux(broadband, ir);

  String message = "Abid-B | Packet #" + String(counter) +
                    " | Lux=" + String(lux);

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println("[Abid-B] Sent: " + message);
  delay(3000);
}
```

## Team B (Abid) — Receiver Code (Arduino)

```cpp
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
```

## Team B (Abid) — Sender + Receiver Together (Arduino)

```cpp
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
```

---

---

# TEAM C (JOYANTA) — Arduino UNO + Level Converter

## Wiring

Exact same as Team B (Abid) — refer to Team B wiring section.

## Configuration
```
Frequency  : 433E6
Sync Word  : 0x12
Baud Rate  : 9600
SS  pin    : 10
RST pin    : 9
DIO0 pin   : 8
```

---

## SENSOR ADD-ON — AHT20 + BMP280 (Team C / Joyanta)

### Sensor Facts
- **Type:** I2C digital sensor — actually two chips on one breakout (AHT20 for temp/humidity, BMP280 for temp/pressure)
- **Power:** 3.3V or 5V (most breakouts have onboard regulator — confirm via silkscreen)
- **I2C Addresses:** AHT20 = `0x38`, BMP280 = `0x76` (or `0x77` if address pin strapped high) — no conflict, both share the same SDA/SCL bus
- **Library:** Adafruit AHTX0 (for AHT20) + Adafruit BMP280 (for BMP280), both via Library Manager

### Wiring (Arduino UNO)

| Module Pin | Arduino UNO Pin | Note |
|---|---|---|
| VCC | 3.3V or 5V | Check breakout's input voltage range |
| GND | GND | Common ground |
| SDA | A4 | I2C data line (shared bus) |
| SCL | A5 | I2C clock line (shared bus) |

```
[Arduino UNO]                  [AHT20+BMP280 Module]
    ├── 3.3V/5V ─────────────→ VCC
    ├── GND     ─────────────→ GND
    ├── A4 (SDA) ────────────→ SDA
    └── A5 (SCL) ────────────→ SCL
```

**Note:** Same I2C bus pattern as Team B — A4/A5 don't conflict with the LoRa SPI wiring (D8–D13), so wiring is a direct drop-in addition.

### Combined Pin Map — Team C (Joyanta)

| Function | Arduino Pin |
|---|---|
| LoRa SCK | D13 (via converter) |
| LoRa MISO | D12 (via converter) |
| LoRa MOSI | D11 (via converter) |
| LoRa NSS | D10 (via converter) |
| LoRa RST | D9 (via converter) |
| LoRa DIO0 | D8 (via converter) |
| AHT20/BMP280 SDA | A4 (direct, no converter) |
| AHT20/BMP280 SCL | A5 (direct, no converter) |

### Arduino Library Setup (Team C only)
1. Arduino IDE → Tools → Manage Libraries
2. Search **"Adafruit AHTX0"** → Install
3. Search **"Adafruit BMP280"** → Install (accept the **Adafruit BusIO** dependency prompt if shown)

---

## Team C (Joyanta) — Sender Code (Arduino)

```cpp
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>

// ---- Pin Config ----
#define SS   10
#define RST  9
#define DIO0 8

// ---- LoRa Config ----
#define FREQUENCY   433E6
#define SYNC_WORD   0x12
#define BAUD_RATE   9600

// ---- AHT20 + BMP280 Sensors ----
Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp;

int counter = 0;
bool ahtReady = false;
bool bmpReady = false;

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Joyanta-C] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Joyanta-C] Arduino Sender Ready");
  Serial.println("Sending to Team A (Maruf) and Team B (Abid)...");

  if (!aht.begin()) {
    Serial.println("[Joyanta-C] AHT20 NOT FOUND! Running without it.");
    ahtReady = false;
  } else {
    Serial.println("[Joyanta-C] AHT20 ready.");
    ahtReady = true;
  }

  if (!bmp.begin(0x76)) {
    Serial.println("[Joyanta-C] BMP280 NOT FOUND! Running without it.");
    bmpReady = false;
  } else {
    Serial.println("[Joyanta-C] BMP280 ready.");
    bmpReady = true;
  }
}

void loop() {
  counter++;

  String tempStr = "N/A";
  String humStr  = "N/A";
  String presStr = "N/A";

  if (ahtReady) {
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp);
    tempStr = String(temp.temperature, 1) + "C";
    humStr  = String(humidity.relative_humidity, 1) + "%";
  }

  if (bmpReady) {
    float pressure = bmp.readPressure() / 100.0F;
    presStr = String(pressure, 1) + "hPa";
  }

  String message = "Joyanta-C | Packet #" + String(counter) +
                    " | Temp=" + tempStr +
                    " | Hum=" + humStr +
                    " | Pres=" + presStr;

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println("[Joyanta-C] Sent: " + message);
  delay(3000);
}
```

## Team C (Joyanta) — Receiver Code (Arduino)

```cpp
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
    Serial.println("[Joyanta-C] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Joyanta-C] Arduino Receiver Ready");
  Serial.println("Listening for Team A (Maruf) and Team B (Abid)...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Joyanta-C] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

## Team C (Joyanta) — Sender + Receiver Together (Arduino)

```cpp
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>

// ---- Pin Config ----
#define SS   10
#define RST  9
#define DIO0 8

// ---- LoRa Config ----
#define FREQUENCY   433E6
#define SYNC_WORD   0x12
#define BAUD_RATE   9600

// ---- AHT20 + BMP280 Sensors ----
Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp;

int counter = 0;
unsigned long lastSendTime = 0;
bool ahtReady = false;
bool bmpReady = false;
#define SEND_INTERVAL 3000

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Joyanta-C] LoRa init FAILED!");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Joyanta-C] Arduino Send+Receive Ready");

  if (!aht.begin()) {
    Serial.println("[Joyanta-C] AHT20 NOT FOUND! Running without it.");
    ahtReady = false;
  } else {
    Serial.println("[Joyanta-C] AHT20 ready.");
    ahtReady = true;
  }

  if (!bmp.begin(0x76)) {
    Serial.println("[Joyanta-C] BMP280 NOT FOUND! Running without it.");
    bmpReady = false;
  } else {
    Serial.println("[Joyanta-C] BMP280 ready.");
    bmpReady = true;
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
    Serial.print("[Joyanta-C] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }

  // --- Send every 3 seconds ---
  if (millis() - lastSendTime > SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;

    String tempStr = "N/A";
    String humStr  = "N/A";
    String presStr = "N/A";

    if (ahtReady) {
      sensors_event_t humidity, temp;
      aht.getEvent(&humidity, &temp);
      tempStr = String(temp.temperature, 1) + "C";
      humStr  = String(humidity.relative_humidity, 1) + "%";
    }

    if (bmpReady) {
      float pressure = bmp.readPressure() / 100.0F;
      presStr = String(pressure, 1) + "hPa";
    }

    String message = "Joyanta-C | Packet #" + String(counter) +
                      " | Temp=" + tempStr +
                      " | Hum=" + humStr +
                      " | Pres=" + presStr;

    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("[Joyanta-C] Sent: " + message);
  }
}
```

---

---

# Expected Serial Monitor Output

## Team A (Maruf) Serial Monitor (115200 baud)
```
[Maruf-A] ESP32 Send+Receive Ready
[Maruf-A] Preheating MP503 sensor (20s)...
[Maruf-A] MP503 ready.
[Maruf-A] Sent: Maruf-A | Packet #1 | AirQuality_Raw=512 | AirQuality_V=0.41
[Maruf-A] Received: Abid-B | Packet #1 | Lux=320  | RSSI: -52 dBm
[Maruf-A] Received: Joyanta-C | Packet #1 | Temp=29.4C | Hum=68.2% | Pres=1008.3hPa  | RSSI: -55 dBm
[Maruf-A] Sent: Maruf-A | Packet #2 | AirQuality_Raw=515 | AirQuality_V=0.42
```

## Team B (Abid) Serial Monitor (9600 baud)
```
[Abid-B] Arduino Send+Receive Ready
[Abid-B] TSL2561 ready.
[Abid-B] Sent: Abid-B | Packet #1 | Lux=320
[Abid-B] Received: Maruf-A | Packet #1 | AirQuality_Raw=512 | AirQuality_V=0.41  | RSSI: -48 dBm
[Abid-B] Received: Joyanta-C | Packet #1 | Temp=29.4C | Hum=68.2% | Pres=1008.3hPa  | RSSI: -50 dBm
[Abid-B] Sent: Abid-B | Packet #2 | Lux=318
```

## Team C (Joyanta) Serial Monitor (9600 baud)
```
[Joyanta-C] Arduino Send+Receive Ready
[Joyanta-C] AHT20 + BMP280 ready.
[Joyanta-C] Sent: Joyanta-C | Packet #1 | Temp=29.4C | Hum=68.2% | Pres=1008.3hPa
[Joyanta-C] Received: Maruf-A | Packet #1 | AirQuality_Raw=512 | AirQuality_V=0.41  | RSSI: -49 dBm
[Joyanta-C] Received: Abid-B | Packet #1 | Lux=320  | RSSI: -51 dBm
[Joyanta-C] Sent: Joyanta-C | Packet #2 | Temp=29.5C | Hum=68.0% | Pres=1008.2hPa
```

---

# RSSI Signal Strength Reference

| RSSI Value | Signal Quality |
|---|---|
| -30 to -50 dBm | Excellent |
| -50 to -70 dBm | Good |
| -70 to -90 dBm | Fair |
| -90 to -120 dBm | Weak |

---

# Safety Checklist (Team B/Abid & Team C/Joyanta)

- ✅ Antenna attached to Ra-01 before powering on
- ✅ Ra-01 VCC connected to 3.3V only (NOT 5V)
- ✅ VCCA = 3.3V and VCCB = 5V (NOT reversed)
- ✅ All GNDs connected together
- ✅ USB cable connected to laptop

# Safety Checklist — New Sensors (All Teams)

- ✅ MP503 (Team A/Maruf): VCC → 5V, NOT 3.3V — module needs full 5V for the heater element
- ✅ MP503 (Team A/Maruf): allow the 20s preheat in code to finish before trusting readings
- ✅ TSL2561 (Team B/Abid) and AHT20+BMP280 (Team C/Joyanta): double-check VCC voltage rating printed on your specific breakout before connecting (most are 3.3V/5V tolerant, but confirm)
- ✅ I2C wiring (Team B/Abid & Team C/Joyanta): SDA→A4, SCL→A5 — do not swap these two
- ✅ All sensor GNDs join the same common ground as the LoRa module and Arduino/ESP32

---

# Software Setup

### All Teams
1. Install **Arduino IDE** from arduino.cc
2. Library Manager → Search **"LoRa"** → Install **LoRa by Sandeep Mistry**

### Team A (Maruf) Only (ESP32 board setup)
1. Arduino IDE → File → Preferences
2. Additional Board URLs → add:
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Tools → Board Manager → Search **ESP32** → Install
4. Tools → Board → Select **ESP32 Dev Module**
5. No extra library needed for MP503 — it's a plain analog read using `analogRead()`

### Team B (Abid) Only — TSL2561 libraries
1. Library Manager → Search **"Adafruit TSL2561"** → Install
2. Accept the prompt to also install **Adafruit Unified Sensor**

### Team C (Joyanta) Only — AHT20 + BMP280 libraries
1. Library Manager → Search **"Adafruit AHTX0"** → Install
2. Library Manager → Search **"Adafruit BMP280"** → Install
3. Accept the prompt to also install **Adafruit BusIO** (and Adafruit Unified Sensor if prompted)

---

*Project: Data Communication Course — LoRa Radio Wave Transmission*
*Team A (Maruf): ESP32 + MP-135/MP503 Air Quality Sensor*
*Team B (Abid): Arduino UNO + TSL2561 Luminosity/IR Sensor*
*Team C (Joyanta): Arduino UNO + AHT20+BMP280 Temp/Humidity/Pressure Sensor*
*All teams communicate on 433MHz | Sync Word 0x12*
