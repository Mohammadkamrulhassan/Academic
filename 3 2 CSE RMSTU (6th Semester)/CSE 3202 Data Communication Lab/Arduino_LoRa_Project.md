# Data Communication Project
## LoRa SX1278 433MHz — 3 Team Wireless Communication
### Course: Data Communication | Using Arduino UNO & ESP32

---

## Team Overview

| Team | Hardware | LoRa Module | Level Converter |
|---|---|---|---|
| **Team A** | ESP32 NodeMCU 30P | Ra-01 SX1278 433MHz | Not needed (3.3V native) |
| **Team B (You)** | Arduino UNO | Ra-01 SX1278 433MHz | 8CH Bi-Directional |
| **Team C** | Arduino UNO | Ra-01 SX1278 433MHz | 8CH Bi-Directional |

### Communication Flow
```
Team A (ESP32) ──sends──→ Team B (Arduino) receives
Team B (Arduino) ──sends──→ Team C (Arduino) receives
Team C (Arduino) ──sends──→ Team A (ESP32) receives
           (circular communication demo)
```

Or simply: **All teams broadcast, all teams receive** — same frequency, different sync words per pair.

---

## Why Level Converter is Needed? (Team B & C only)

```
Arduino UNO  →  5V logic
Ra-01 LoRa   →  3.3V logic   ← will be DAMAGED by 5V signals!

Level Converter = Translator between 5V and 3.3V worlds

  Arduino (5V)  [B side] ════ [A side]  Ra-01 (3.3V)
     VCCB=5V                              VCCA=3.3V
      B0  ←── translates ──→  A0
      B1  ←── translates ──→  A1
      ...                     ...
```

### Level Converter Pin Meaning

| Pin | Meaning | Connect To |
|---|---|---|
| VCCA | Power for LOW voltage (3.3V) side | Arduino 3.3V |
| VCCB | Power for HIGH voltage (5V) side | Arduino 5V |
| A0–A7 | Low voltage signal pins (3.3V) | Ra-01 pins |
| B0–B7 | High voltage signal pins (5V) | Arduino pins |
| GND | Common ground both sides | Arduino GND |

---

---

# TEAM A — ESP32 + Ra-01 LoRa

## Components
- ESP32 NodeMCU 30P
- Ra-01 LoRa SX1278 433MHz
- Jumper wires
- USB Type-C cable

## Wiring (No Level Converter Needed)

ESP32 runs on 3.3V logic — connect Ra-01 directly.

| ESP32 Pin | Ra-01 Pin |
|---|---|
| 3.3V | 3V3 |
| GND | GND |
| D5 (GPIO5) | NSS |
| D18 (GPIO18) | SCK |
| D19 (GPIO19) | MISO |
| D23 (GPIO23) | MOSI |
| D14 (GPIO14) | RST |
| D2 (GPIO2) | DIO0 |

## Connection Diagram
```
[ESP32 NodeMCU 30P]
    │
    ├── 3.3V ──────────→ 3V3  (Ra-01)
    ├── GND  ──────────→ GND  (Ra-01)
    ├── D5   ──────────→ NSS  (Ra-01)
    ├── D18  ──────────→ SCK  (Ra-01)
    ├── D19  ──────────→ MISO (Ra-01)
    ├── D23  ──────────→ MOSI (Ra-01)
    ├── D14  ──────────→ RST  (Ra-01)
    └── D2   ──────────→ DIO0 (Ra-01)
```

## Team A — Transmitter Code (ESP32 sends to Team B & C)

```cpp
#include <SPI.h>
#include <LoRa.h>

#define SS   5
#define RST  14
#define DIO0 2

int counter = 0;

void setup() {
  Serial.begin(115200);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Team A: LoRa init failed! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(0x12);   // All teams must use same sync word
  Serial.println("Team A (ESP32) Transmitter Ready");
}

void loop() {
  counter++;

  LoRa.beginPacket();
  LoRa.print("MSG from TeamA | Packet #");
  LoRa.print(counter);
  LoRa.endPacket();

  Serial.print("Team A Sent Packet #");
  Serial.println(counter);

  delay(3000);
}
```

## Team A — Receiver Code (ESP32 receives from Team B & C)

```cpp
#include <SPI.h>
#include <LoRa.h>

#define SS   5
#define RST  14
#define DIO0 2

void setup() {
  Serial.begin(115200);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Team A: LoRa init failed!");
    while (1);
  }

  LoRa.setSyncWord(0x12);
  Serial.println("Team A (ESP32) Receiver Ready...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    Serial.print("Team A Received: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.print("  |  RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

---

---

# TEAM B — Arduino UNO + Ra-01 LoRa + Level Converter

## Components
- Arduino UNO (ATmega328P)
- Ra-01 LoRa SX1278 433MHz v4.0
- 8CH Bi-Directional Logic Level Converter
- USB-B cable from Laptop

## Wiring

### Power Wiring

| From (Arduino) | To | Note |
|---|---|---|
| 3.3V | Level Converter **VCCA** | A side power |
| 3.3V | Ra-01 **3V3** | Ra-01 power (direct) |
| 5V | Level Converter **VCCB** | B side power |
| GND | Level Converter **GND** (A side) | Common ground |
| GND | Level Converter **GND** (B side) | Common ground |
| GND | Ra-01 **GND** | Common ground |

### Signal Wiring (Through Level Converter)

| Arduino Pin | Converter B side | Converter A side | Ra-01 Pin |
|---|---|---|---|
| D13 (SCK) | B0 | A0 | SCK |
| D12 (MISO) | B1 | A1 | MISO |
| D11 (MOSI) | B2 | A2 | MOSI |
| D10 (NSS) | B3 | A3 | NSS |
| D9 (RST) | B4 | A4 | RST |
| D8 (DIO0) | B5 | A5 | DIO0 |

### Full Connection Diagram

```
LAPTOP USB
    │
    ↓
[Arduino UNO]
    │
    ├── 3.3V ──┬──────────────→ VCCA (Converter A side power)
    │          └──────────────→ 3V3  (Ra-01 direct power)
    │
    ├── 5V  ───────────────────→ VCCB (Converter B side power)
    │
    ├── GND ───┬──────────────→ GND-A (Converter A side)
    │          ├──────────────→ GND-B (Converter B side)
    │          └──────────────→ GND   (Ra-01)
    │
    ├── D13 ───→ [B0 ═══ A0] ──→ SCK  (Ra-01)
    ├── D12 ───→ [B1 ═══ A1] ──→ MISO (Ra-01)
    ├── D11 ───→ [B2 ═══ A2] ──→ MOSI (Ra-01)
    ├── D10 ───→ [B3 ═══ A3] ──→ NSS  (Ra-01)
    ├── D9  ───→ [B4 ═══ A4] ──→ RST  (Ra-01)
    └── D8  ───→ [B5 ═══ A5] ──→ DIO0 (Ra-01)
```

### Ra-01 Pin Layout Reference

```
┌─────────────────┐
│  MISO  │  DIO0  │
│  SCK   │  MOSI  │
│  RST   │  NSS   │
│  GND   │  3V3   │
└────────┴────────┘
       [antenna]
```

## Team B — Transmitter Code (Arduino sends to Team A & C)

```cpp
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
```

## Team B — Receiver Code (Arduino receives from Team A & C)

```cpp
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
```

---

---

# TEAM C — Arduino UNO + Ra-01 LoRa + Level Converter

## Components
- Arduino UNO (ATmega328P)
- Ra-01 LoRa SX1278 433MHz
- 8CH Bi-Directional Logic Level Converter
- USB-B cable from Laptop

## Wiring

Exact same wiring as Team B — refer to Team B wiring section above.

```
LAPTOP USB
    │
    ↓
[Arduino UNO]
    │
    ├── 3.3V ──┬──────────────→ VCCA (Converter A side power)
    │          └──────────────→ 3V3  (Ra-01 direct power)
    │
    ├── 5V  ───────────────────→ VCCB (Converter B side power)
    │
    ├── GND ───┬──────────────→ GND-A (Converter A side)
    │          ├──────────────→ GND-B (Converter B side)
    │          └──────────────→ GND   (Ra-01)
    │
    ├── D13 ───→ [B0 ═══ A0] ──→ SCK  (Ra-01)
    ├── D12 ───→ [B1 ═══ A1] ──→ MISO (Ra-01)
    ├── D11 ───→ [B2 ═══ A2] ──→ MOSI (Ra-01)
    ├── D10 ───→ [B3 ═══ A3] ──→ NSS  (Ra-01)
    ├── D9  ───→ [B4 ═══ A4] ──→ RST  (Ra-01)
    └── D8  ───→ [B5 ═══ A5] ──→ DIO0 (Ra-01)
```

## Team C — Transmitter Code (Arduino sends to Team A & B)

```cpp
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
    Serial.println("Team C: LoRa init failed! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(0x12);   // All teams must use same sync word
  Serial.println("Team C (Arduino) Transmitter Ready");
}

void loop() {
  counter++;

  LoRa.beginPacket();
  LoRa.print("MSG from TeamC | Packet #");
  LoRa.print(counter);
  LoRa.endPacket();

  Serial.print("Team C Sent Packet #");
  Serial.println(counter);

  delay(3000);
}
```

## Team C — Receiver Code (Arduino receives from Team A & B)

```cpp
#include <SPI.h>
#include <LoRa.h>

#define SS   10
#define RST  9
#define DIO0 8

void setup() {
  Serial.begin(9600);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Team C: LoRa init failed! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(0x12);
  Serial.println("Team C (Arduino) Receiver Ready...");
  Serial.println("Waiting for packets...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    Serial.print("Team C Received: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.print("  |  RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

---

---

# Common Settings — All 3 Teams Must Match

| Setting | Value |
|---|---|
| Frequency | 433E6 (433 MHz) |
| Sync Word | 0x12 |
| Library | LoRa by Sandeep Mistry |
| Serial Baud (Arduino) | 9600 |
| Serial Baud (ESP32) | 115200 |

---

# Safety Checklist (Team B & C)

- ✅ Antenna attached to Ra-01 before powering on
- ✅ Ra-01 VCC connected to 3.3V only (NOT 5V)
- ✅ VCCA = 3.3V and VCCB = 5V (NOT reversed)
- ✅ All GNDs connected together
- ✅ USB cable connected to laptop

---

# Software Setup (All Teams)

1. Install **Arduino IDE** from arduino.cc
2. For Team A (ESP32): Add ESP32 board in Arduino IDE
   - File → Preferences → Additional Board URLs →
   - Add: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Tools → Board Manager → Search ESP32 → Install
3. Open Library Manager → Search **"LoRa"** → Install **LoRa by Sandeep Mistry**

---

# Testing Steps

1. All 3 teams wire their components
2. Upload respective TX or RX code
3. Open Serial Monitor
   - Team A: 115200 baud
   - Team B & C: 9600 baud
4. Power on all devices
5. Expected Serial Monitor output:

```
Team B Received: MSG from TeamA | Packet #1  |  RSSI: -52 dBm
Team B Received: MSG from TeamC | Packet #1  |  RSSI: -48 dBm
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

*Project: Data Communication Course — LoRa Radio Wave Transmission*
*3 Teams: ESP32 (Team A) + Arduino UNO (Team B) + Arduino UNO (Team C)*
