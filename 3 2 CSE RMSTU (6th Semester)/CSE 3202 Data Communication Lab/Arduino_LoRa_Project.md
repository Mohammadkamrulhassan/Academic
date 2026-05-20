# Data Communication Project
## Arduino UNO + Ra-01 LoRa SX1278 + 8CH Level Converter
### Team B — Receiver Side

---

## Components

| Component | Details |
|---|---|
| Arduino UNO | ATmega328P, 5V logic |
| Ra-01 LoRa | SX1278 433MHz v4.0 |
| Level Converter | 8CH Bi-Directional (VCCA/VCCB) |
| Power | USB-B cable from Laptop |

---

## Why Level Converter is Needed?

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

| Pin | Full Name | Meaning | Connect To |
|---|---|---|---|
| VCCA | Voltage CC side A | Power for LOW voltage (3.3V) side | Arduino 3.3V |
| VCCB | Voltage CC side B | Power for HIGH voltage (5V) side | Arduino 5V |
| A0–A7 | Channel A signals | Low voltage signal pins (3.3V) | Ra-01 pins |
| B0–B7 | Channel B signals | High voltage signal pins (5V) | Arduino pins |
| GND | Ground | Common ground both sides | Arduino GND |

---

## Full Wiring Connection

### Power Source
```
Laptop USB → Arduino UNO USB-B port
```

### STEP 1 — Power Wiring

| From (Arduino) | To | Note |
|---|---|---|
| 3.3V | Level Converter **VCCA** | A side power |
| 3.3V | Ra-01 **3V3** | Ra-01 power (direct) |
| 5V | Level Converter **VCCB** | B side power |
| GND | Level Converter **GND** (A side) | Common ground |
| GND | Level Converter **GND** (B side) | Common ground |
| GND | Ra-01 **GND** | Common ground |

### STEP 2 — Signal Wiring (Through Level Converter)

| Arduino Pin | Converter B side | Converter A side | Ra-01 Pin |
|---|---|---|---|
| D13 (SCK) | B0 | A0 | SCK |
| D12 (MISO) | B1 | A1 | MISO |
| D11 (MOSI) | B2 | A2 | MOSI |
| D10 (NSS/CS) | B3 | A3 | NSS |
| D9 (RST) | B4 | A4 | RST |
| D8 (DIO0) | B5 | A5 | DIO0 |

### STEP 3 — Full Connection Diagram

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

---

## Safety Checklist Before Powering On

- ✅ Antenna attached to Ra-01 (spring coil antenna)
- ✅ Ra-01 VCC connected to 3.3V only (NOT 5V)
- ✅ VCCA = 3.3V and VCCB = 5V (NOT reversed)
- ✅ All GNDs connected together (Arduino + Converter + Ra-01)
- ✅ USB cable connected to laptop

---

## Software Setup

1. Download and install **Arduino IDE** from arduino.cc
2. Open Arduino IDE → Tools → Manage Libraries
3. Search **"LoRa"** → Install **LoRa by Sandeep Mistry**

---

## Team B — Receiver Code (Arduino)

```cpp
#include <SPI.h>
#include <LoRa.h>

// Pin definitions
#define SS   10
#define RST  9
#define DIO0 8

void setup() {
  Serial.begin(9600);
  
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {       // 433 MHz frequency
    Serial.println("LoRa init failed! Check wiring.");
    while (1);                    // Stop here if failed
  }

  LoRa.setSyncWord(0x12);         // Must match Team A exactly
  Serial.println("Team B Receiver Ready...");
  Serial.println("Waiting for data from Team A (ESP32)...");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  
  if (packetSize) {
    Serial.print("Received: ");
    
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    
    Serial.print("  |  Signal Strength (RSSI): ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");
  }
}
```

---

## Team A — Transmitter Code (ESP32) — Share with Team A

```cpp
#include <SPI.h>
#include <LoRa.h>

// ESP32 SPI pins for LoRa
#define SS   5
#define RST  14
#define DIO0 2

int counter = 0;

void setup() {
  Serial.begin(115200);
  
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {       // 433 MHz frequency
    Serial.println("LoRa init failed!");
    while (1);
  }

  LoRa.setSyncWord(0x12);         // Must match Team B exactly
  Serial.println("Team A Transmitter Ready");
}

void loop() {
  counter++;
  
  LoRa.beginPacket();
  LoRa.print("Hello from ESP32! Packet #");
  LoRa.print(counter);
  LoRa.endPacket();
  
  Serial.print("Packet sent #");
  Serial.println(counter);
  
  delay(2000);                    // Send every 2 seconds
}
```

---

## Testing Steps

1. Wire everything as shown above
2. Connect Arduino to laptop via USB-B cable
3. Upload Receiver code to Arduino
4. Open **Serial Monitor** (Tools → Serial Monitor)
5. Set baud rate to **9600**
6. Ask Team A to power on their ESP32
7. You should see messages like:

```
Team B Receiver Ready...
Waiting for data from Team A (ESP32)...
Received: Hello from ESP32! Packet #1  |  Signal Strength (RSSI): -45 dBm
Received: Hello from ESP32! Packet #2  |  Signal Strength (RSSI): -46 dBm
```

---

## RSSI Value Meaning

| RSSI Value | Signal Quality |
|---|---|
| -30 to -50 dBm | Excellent (very close) |
| -50 to -70 dBm | Good |
| -70 to -90 dBm | Fair |
| -90 to -120 dBm | Weak (far away) |

---

## Key Settings — Both Teams Must Match

| Setting | Value |
|---|---|
| Frequency | 433E6 (433 MHz) |
| Sync Word | 0x12 |
| Library | LoRa by Sandeep Mistry |

---

*Project: Data Communication Course — LoRa Radio Wave Transmission*
*Team B: Arduino UNO + Ra-01 SX1278 + 8CH Level Converter*
