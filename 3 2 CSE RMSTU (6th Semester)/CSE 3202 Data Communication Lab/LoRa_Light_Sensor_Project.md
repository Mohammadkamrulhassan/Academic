# Data Communication Lab Project
## Wireless Light-Intensity Telemetry over LoRa
### Arduino UNO + Ra-01 LoRa SX1278 (433MHz) + TSL2561 Light Sensor + Logic Level Converter

---

## 1. What This Project Actually Is

Your team's project is different from the basic 3-team "send a counter" demo. You're building a **sensor telemetry link**:

> A physical quantity (light intensity) is measured at one location → digitized → packaged into a radio packet → transmitted wirelessly over LoRa → received at a different location → displayed.

This demonstrates the full **Data Communication pipeline**: source → encoder → transmitter → channel → receiver → decoder → sink. That mapping is exactly what your course wants you to show.

| DCN Concept | What plays that role here |
|---|---|
| Data Source | TSL2561 sensing ambient light |
| Source Encoder | Arduino reading raw sensor registers → converting to Lux |
| Line/Logic Adaptation | Logic Level Converter (3.3V ↔ 5V domains) |
| Transmitter | Ra-01 LoRa module (modulates data onto 433MHz carrier using CSS) |
| Channel | Open air, 433MHz radio wave |
| Receiver | A second Ra-01 LoRa module |
| Sink | Serial Monitor / display showing received Lux value |

---

## 2. Components — What Each One Does and Why It's There

### 2.1 Arduino UNO (ATmega328P)
The **controller/brain** on both ends (transmitter side and receiver side — you need two Arduino+LoRa setups, OR one Arduino is TX-only with sensor, and the other Arduino is RX-only just printing data).

- Runs at **5V logic**.
- Talks to the TSL2561 over **I2C** (2 wires: SDA, SCL).
- Talks to the LoRa module over **SPI** (4 wires: SCK, MISO, MOSI, NSS/CS) plus 2 control lines (RST, DIO0).
- Job: read sensor → format data → hand it to LoRa module → LoRa module radiates it.

### 2.2 Ra-01 LoRa SX1278 433MHz (AI-Thinker)
The **radio transceiver chip**. This is what actually converts your digital data into a 433MHz radio wave and back.

- Uses **Chirp Spread Spectrum (CSS)** modulation — not simple AM/FM. It spreads each bit of data across a wide range of frequencies (a "chirp"), which is why LoRa survives noise and interference so well at long range despite low power.
- Communicates with the Arduino over **SPI**, not I2C. Arduino tells it "here's a packet, send it" and LoRa handles the RF part autonomously.
- Operates strictly at **3.3V logic** — this chip has **no built-in 5V tolerance** on its SPI lines. Feeding it 5V directly from the Arduino's SPI pins risks damaging it.
- This module has **no level conversion onboard**, which is exactly why your team has a 4th component.

### 2.3 TSL2561 Luminosity Sensor
The **data source** — a real-world physical sensor.

- Has two photodiodes internally: one sensitive to **visible + infrared light**, one sensitive to **infrared only**. Subtracting gives you the human-eye-equivalent "visible" channel.
- Communicates over **I2C** (address `0x39` by default, when the ADDR pin is left floating).
- Outputs **raw 16-bit channel values**, which the library converts into a calibrated **Lux** value using TAOS's published formula (you don't need to do this math by hand — the Adafruit_TSL2561 library does it).
- Important wiring fact: TSL2561's I2C lines (SDA/SCL) are **open-drain** with onboard pull-ups, and the chip is commonly wired directly to a 5V Arduino's I2C bus in hobbyist projects without a separate converter — many guides connect it straight to A4/A5 on a 5V Uno. **However**, since you already have an 8-channel bidirectional logic converter on the board for the LoRa module, the cleanest/safest lab practice (and what a strict viva examiner will want to see) is running TSL2561 on its own 3.3V rail or through 2 spare channels of the same converter, so nothing in your sensing chain ever sees raw 5V on a 3.3V-rated line.

### 2.4 Logic Level Converter (8-channel bidirectional, e.g. TXS0108E or similar bi-directional MOSFET-based converter)
The **voltage translator**. This is the part that makes 5V-world (Arduino) and 3.3V-world (LoRa, and optionally TSL2561) safe to connect together.

- Has two sides:
  - **HV side (B0–B7)** — high voltage, connects to Arduino's 5V signal pins.
  - **LV side (A0–A7)** — low voltage, connects to the 3.3V LoRa module pins.
- Has two power inputs:
  - **VCCA** → 3.3V (powers the low-voltage side logic threshold)
  - **VCCB** → 5V (powers the high-voltage side logic threshold)
- Each channel (A0↔B0, A1↔B1, …) is a bidirectional pass-through: a signal can go Arduino→LoRa or LoRa→Arduino through the **same** pair of pins, which is essential because SPI is bidirectional (MOSI goes Arduino→LoRa, MISO goes LoRa→Arduino, SCK and NSS go Arduino→LoRa).
- **Why it exists conceptually**: this is a hardware analogy to "protocol/format conversion" in data communication — just like a modem/converter translates between two different signaling standards, this chip translates between two different voltage signaling standards so two otherwise-incompatible digital systems can exchange data without damage or data corruption.

---

## 3. Why You Need the Converter — the Core Electrical Logic

```
Arduino UNO (operates at 5V logic)
   |
   |  SPI signals at 5V (SCK, MOSI, NSS, RST, DIO0)
   ↓
[ Logic Level Converter ]
   B-side (5V) <---- translation ----> A-side (3.3V)
   ↓
   |  Same SPI signals, now safely at 3.3V
   ↓
Ra-01 LoRa SX1278 (operates at 3.3V logic, NOT 5V tolerant)
```

If you skip the converter and wire Arduino's 5V SPI pins straight into the Ra-01:
- The LoRa module's input pins see 5V where they expect max ~3.6V.
- This can permanently damage the SX1278 chip (overvoltage on GPIO).
- Even if it "seems to work" initially, you get unreliable communication, overheating, or early failure — bad for a lab demo you need working for the whole semester.

The converter's job is purely **signal-level translation**, not data translation. The actual bits/data being sent are unchanged — only the voltage **representing** a logical `1` or `0` is shifted from ~5V/0V down to ~3.3V/0V and back.

---

## 4. Wiring Logic (Conceptual, No Code)

### 4.1 Power Domains
- Arduino 5V pin → powers Arduino itself, and VCCB of the converter, and VCCB-side logic.
- Arduino 3.3V pin → powers VCCA of the converter, AND powers the Ra-01 directly (Ra-01's 3V3 pin connects straight to Arduino 3.3V — power doesn't go through the converter, **only signal lines do**).
- Common GND ties everything together (Arduino, converter, LoRa, sensor) — without a shared ground reference, none of the voltage-level logic means anything to the receiving side.

### 4.2 Signal Path (LoRa side, through the converter)
Six SPI/control signals cross the voltage boundary, each through one converter channel:

| Signal | Direction | Purpose |
|---|---|---|
| SCK (clock) | Arduino → LoRa | Synchronizes every bit transfer |
| MOSI (Master Out Slave In) | Arduino → LoRa | Arduino sends command/data bytes to LoRa chip |
| MISO (Master In Slave Out) | LoRa → Arduino | LoRa chip sends back status/data bytes |
| NSS/CS (chip select) | Arduino → LoRa | Arduino "wakes up" the LoRa chip to start a transaction |
| RST (reset) | Arduino → LoRa | Arduino can hard-reset the LoRa chip |
| DIO0 (interrupt) | LoRa → Arduino | LoRa chip signals "packet received" or "transmit done" |

### 4.3 Signal Path (Sensor side)
- SDA, SCL (I2C) run between Arduino and TSL2561.
- This is a **separate bus** from the LoRa SPI bus — they don't interfere because I2C and SPI use different, dedicated pins on the Arduino (I2C: A4/A5; SPI: D10–D13).

---

## 5. End-to-End Working Procedure (Logical Flow, No Code)

### Transmitter Node (Sensor Side)
1. **Sense**: TSL2561 continuously measures incoming light using its two photodiodes (visible+IR channel, IR-only channel).
2. **Digitize & Read**: Arduino polls the TSL2561 over I2C, pulls the two raw 16-bit channel readings.
3. **Compute**: Arduino (via library) runs the TAOS lux-conversion formula on those two raw values → produces a single human-readable **Lux number**.
4. **Package**: Arduino formats this Lux value into a short text/byte packet (e.g., `"LUX:482"`), the same way Team A/B/C format `"MSG from TeamX | Packet #N"` in the base project.
5. **Hand-off to radio**: Arduino pushes this packet across the SPI bus, through the level converter, into the Ra-01's transmit buffer.
6. **Radiate**: Ra-01 modulates the packet using LoRa's chirp spread spectrum scheme and transmits it as a 433MHz radio wave through the antenna.

### Receiver Node (Display Side)
7. **Listen**: A second Ra-01 (on a separate Arduino, or the same one in a different role) constantly listens on the same frequency (433MHz) and same sync word — this is the "agreed channel" both sides must share, exactly like the 3-team demo.
8. **Capture**: When a matching packet arrives, the receiving Ra-01 raises its DIO0 interrupt line, telling its Arduino "data's here."
9. **Pull data**: Receiving Arduino reads the packet back across SPI (through its own level converter) into memory.
10. **Decode & Display**: Arduino parses out the Lux value and prints it (Serial Monitor, LCD, or any sink you choose) — along with **RSSI** (signal strength) as a bonus metric showing the channel quality, same as the base project does.

### Why This Matters as a "Data Communication" Demo
- You're showing **source coding** (raw photodiode counts → meaningful Lux number).
- You're showing **physical layer signaling translation** (level converter = literal "translate one electrical standard into another," a hands-on analog to physical-layer encoding/decoding concepts from your syllabus).
- You're showing **wireless modulation** (LoRa CSS) as opposed to the simple digital signaling (NRZ, Manchester, etc.) you study on paper.
- You're showing a complete **transmitter–channel–receiver** model with a real measurable channel-quality metric (RSSI) — which ties directly into the "signal quality / noise / attenuation" theory portion of Data Communication.

---

## 6. Component Responsibility Summary Table

| Component | Role | Voltage Domain | Bus/Interface | What breaks if wrong |
|---|---|---|---|---|
| Arduino UNO | Controller, runs logic for both sensing and radio control | 5V | I2C (sensor) + SPI (radio) | Nothing — it's the reference voltage |
| TSL2561 | Light sensor, generates raw data | 3.3–5V tolerant (per datasheet, but board pull-ups assume 3.3V logic) | I2C | Wrong address pin wiring → I2C read fails; wrong VCC → readings wrong or chip damage |
| Logic Level Converter | Translates voltage domains for the LoRa SPI bus | Has both 3.3V (VCCA) and 5V (VCCB) sides simultaneously | Pass-through, both SPI directions | Reversed VCCA/VCCB → permanent chip damage; missing GND → erratic/no communication |
| Ra-01 LoRa SX1278 | Radio transceiver, modulates/demodulates 433MHz CSS signal | 3.3V only — strictly | SPI | Direct 5V on signal pins → chip damage; wrong sync word/frequency → no communication with other node; no antenna → may damage PA or get near-zero range |

---

## 7. Key Settings That Must Match Between Transmitter and Receiver
(Same principle as the base 3-team project — both nodes must agree on the "channel contract"):

| Setting | Required Value | Why |
|---|---|---|
| Frequency | 433 MHz | Both radios must listen/transmit on the exact same carrier |
| Sync Word | Same custom byte (e.g. `0x12`) | Acts like a "private channel" filter — ignores other LoRa traffic on the same frequency |
| Spreading Factor / Bandwidth | Same on both ends | These define how the chirp is shaped — mismatched values mean the receiver literally cannot decode the chirps |

---

## 8. Safety Checklist Before Powering On
- TSL2561 ADDR pin: leave floating for default address `0x39` (unless you deliberately need a second sensor on the bus).
- Ra-01 VCC → 3.3V **only**, never 5V — direct from Arduino's 3.3V pin, not through the converter.
- Converter VCCA = 3.3V, VCCB = 5V — **never swapped**.
- Antenna attached to Ra-01 before powering on (transmitting without an antenna can damage the power amplifier).
- All grounds (Arduino, converter A-side, converter B-side, Ra-01, TSL2561) tied to one common ground net.

---

*Project: Data Communication Lab — Wireless Light Intensity Telemetry*
*Built on: Arduino UNO + Ra-01 LoRa SX1278 (433MHz) + TSL2561 Luminosity Sensor + 8CH Bi-Directional Logic Level Converter*
