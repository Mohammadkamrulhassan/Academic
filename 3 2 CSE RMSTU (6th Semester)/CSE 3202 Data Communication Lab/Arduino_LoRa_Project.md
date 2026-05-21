# Data Communication Project
## LoRa SX1278 433MHz — 3 Team Full Communication
### Course: Data Communication | Arduino UNO & ESP32

---

# Team Overview

| Team | Hardware | LoRa Module | Level Converter | Role |
|---|---|---|---|---|
| **Team A** | ESP32 NodeMCU 30P | Ra-01 SX1278 433MHz | Not needed | Send & Receive |
| **Team B** | Arduino UNO | Ra-01 SX1278 433MHz | 8CH Bi-Directional | Send & Receive |
| **Team C** | Arduino UNO | Ra-01 SX1278 433MHz | 8CH Bi-Directional | Send & Receive |

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
Team C (Arduino) ←→ Team B (Arduino)
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
| Serial Baud — Arduino | **9600** | Team B & C |
| Serial Baud — ESP32 | **115200** | Team A only |
| SPI Mode | **Mode 0** (handled by library) | Auto |

---

# Why Level Converter? (Team B & C Only)

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

# TEAM A — ESP32 NodeMCU 30P

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

## Team A — Sender Code (ESP32)

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

int counter = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Team A] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team A] ESP32 Sender Ready");
  Serial.println("Sending to Team B and Team C...");
}

void loop() {
  counter++;

  String message = "Hello from TeamA | Packet #" + String(counter);

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println("[Team A] Sent: " + message);
  delay(3000);
}
```

## Team A — Receiver Code (ESP32)

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
    Serial.println("[Team A] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team A] ESP32 Receiver Ready");
  Serial.println("Listening for Team B and Team C...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Team A] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

## Team A — Sender + Receiver Together (ESP32)

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

int counter = 0;
unsigned long lastSendTime = 0;
#define SEND_INTERVAL 3000

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Team A] LoRa init FAILED!");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team A] ESP32 Send+Receive Ready");
}

void loop() {
  // --- Receive ---
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Team A] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }

  // --- Send every 3 seconds ---
  if (millis() - lastSendTime > SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;
    String message = "Hello from TeamA | Packet #" + String(counter);
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("[Team A] Sent: " + message);
  }
}
```

---

---

# TEAM B — Arduino UNO + Level Converter

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

## Team B — Sender Code (Arduino)

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

  String message = "Hello from TeamB | Packet #" + String(counter);

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println("[Team B] Sent: " + message);
  delay(3000);
}
```

## Team B — Receiver Code (Arduino)

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
    Serial.println("[Team B] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team B] Arduino Receiver Ready");
  Serial.println("Listening for Team A and Team C...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Team B] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

## Team B — Sender + Receiver Together (Arduino)

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

int counter = 0;
unsigned long lastSendTime = 0;
#define SEND_INTERVAL 3000

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Team B] LoRa init FAILED!");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team B] Arduino Send+Receive Ready");
}

void loop() {
  // --- Receive ---
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Team B] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }

  // --- Send every 3 seconds ---
  if (millis() - lastSendTime > SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;
    String message = "Hello from TeamB | Packet #" + String(counter);
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("[Team B] Sent: " + message);
  }
}
```

---

---

# TEAM C — Arduino UNO + Level Converter

## Wiring

Exact same as Team B — refer to Team B wiring section.

## Configuration
```
Frequency  : 433E6
Sync Word  : 0x12
Baud Rate  : 9600
SS  pin    : 10
RST pin    : 9
DIO0 pin   : 8
```

## Team C — Sender Code (Arduino)

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

int counter = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Team C] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team C] Arduino Sender Ready");
  Serial.println("Sending to Team A and Team B...");
}

void loop() {
  counter++;

  String message = "Hello from TeamC | Packet #" + String(counter);

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println("[Team C] Sent: " + message);
  delay(3000);
}
```

## Team C — Receiver Code (Arduino)

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
    Serial.println("[Team C] LoRa init FAILED! Check wiring.");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team C] Arduino Receiver Ready");
  Serial.println("Listening for Team A and Team B...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Team C] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

## Team C — Sender + Receiver Together (Arduino)

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

int counter = 0;
unsigned long lastSendTime = 0;
#define SEND_INTERVAL 3000

void setup() {
  Serial.begin(BAUD_RATE);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(FREQUENCY)) {
    Serial.println("[Team C] LoRa init FAILED!");
    while (1);
  }

  LoRa.setSyncWord(SYNC_WORD);
  Serial.println("[Team C] Arduino Send+Receive Ready");
}

void loop() {
  // --- Receive ---
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.print("[Team C] Received: ");
    Serial.print(received);
    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }

  // --- Send every 3 seconds ---
  if (millis() - lastSendTime > SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;
    String message = "Hello from TeamC | Packet #" + String(counter);
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    Serial.println("[Team C] Sent: " + message);
  }
}
```

---

---

# Expected Serial Monitor Output

## Team A Serial Monitor (115200 baud)
```
[Team A] ESP32 Send+Receive Ready
[Team A] Sent: Hello from TeamA | Packet #1
[Team A] Received: Hello from TeamB | Packet #1  | RSSI: -52 dBm
[Team A] Received: Hello from TeamC | Packet #1  | RSSI: -55 dBm
[Team A] Sent: Hello from TeamA | Packet #2
```

## Team B Serial Monitor (9600 baud)
```
[Team B] Arduino Send+Receive Ready
[Team B] Sent: Hello from TeamB | Packet #1
[Team B] Received: Hello from TeamA | Packet #1  | RSSI: -48 dBm
[Team B] Received: Hello from TeamC | Packet #1  | RSSI: -50 dBm
[Team B] Sent: Hello from TeamB | Packet #2
```

## Team C Serial Monitor (9600 baud)
```
[Team C] Arduino Send+Receive Ready
[Team C] Sent: Hello from TeamC | Packet #1
[Team C] Received: Hello from TeamA | Packet #1  | RSSI: -49 dBm
[Team C] Received: Hello from TeamB | Packet #1  | RSSI: -51 dBm
[Team C] Sent: Hello from TeamC | Packet #2
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

# Safety Checklist (Team B & C)

- ✅ Antenna attached to Ra-01 before powering on
- ✅ Ra-01 VCC connected to 3.3V only (NOT 5V)
- ✅ VCCA = 3.3V and VCCB = 5V (NOT reversed)
- ✅ All GNDs connected together
- ✅ USB cable connected to laptop

---

# Software Setup

### All Teams
1. Install **Arduino IDE** from arduino.cc
2. Library Manager → Search **"LoRa"** → Install **LoRa by Sandeep Mistry**

### Team A Only (ESP32 board setup)
1. Arduino IDE → File → Preferences
2. Additional Board URLs → add:
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Tools → Board Manager → Search **ESP32** → Install
4. Tools → Board → Select **ESP32 Dev Module**

---

*Project: Data Communication Course — LoRa Radio Wave Transmission*
*Team A: ESP32 | Team B: Arduino UNO | Team C: Arduino UNO*
*All teams communicate on 433MHz | Sync Word 0x12*
