# ⚽🤖 ESP32 RoboSoccer Bluetooth Car

An ESP32-based Bluetooth controlled RoboSoccer car designed for fast response and stable boot behavior.

This robot uses **safe GPIO pins** that do NOT go HIGH during reboot, preventing unwanted motor movement during power-up.

---

## 📡 Bluetooth Information

- **Device Name:** `ROBOT_***`
- **Communication:** Classic Bluetooth (SPP)
- **Baud Rate:** 115200
- **Platform:** ESP32

Connect using:

- Serial Bluetooth Terminal (Android)
- Bluetooth Controller App
- Custom MIT App Inventor Controller

---

## 🔌 Hardware Used

- ESP32 Dev Board
- LM2596 Buck Converter
- L298N / L293D Motor Driver
- 4 High-Speed DC Motors
- RoboSoccer Chassis
- Li-ion / LiPo Battery Pack (7–12V)

---

## 🧩 GPIO Pin Configuration (Boot Safe)

| Motor Driver Pin | ESP32 GPIO |
| ---------------- | ---------- |
| IN1              | 27         |
| IN2              | 26         |
| IN3              | 25         |
| IN4              | 33         |

These pins are selected because they:

- Do NOT affect boot mode
- Do NOT automatically go HIGH at reset
- Provide stable motor startup behavior

---

## 🎮 Control Commands

Send single characters via Bluetooth:

| Command | Action       |
| ------- | ------------ |
| F       | Move Forward |
| B       | Move Back    |
| L       | Turn Left    |
| R       | Turn Right   |
| S       | Stop         |

---

## 🛡 Safety at Boot

Motors are automatically stopped during startup:

```cpp
stopMotor();
```

This prevents:

- Sudden jerks
- Unexpected movement
- Competition disqualification due to unsafe start

---

## ⚙ How It Works

1. ESP32 starts Bluetooth server.
2. Waits for incoming character command.
3. Reads command using `SerialBT.read()`.
4. Sets motor direction accordingly.
5. Stops when 'S' is received.

---

## 🚀 Competition Ready Features

✔ Fast response
✔ Stable boot behavior
✔ No speed control delay
✔ Lightweight logic
✔ Safe GPIO selection

---

## 🔥 Future Upgrades

- PWM Speed Control
- Diagonal movement
- Ball dribbler motor
- Solenoid kicker
- OLED status display
- Battery voltage monitoring
- ESP-NOW ultra-low latency mode

---

## 📁 Project Structure

```
ROBO_SOCCER_ESP32/
│── ROBO_SOCCER_ESP32.ino
```

---

## 👨‍💻 Developed For

RoboSoccer Competition ⚽
ESP32 Based Wireless Control System
