# 🚗 Car Parking Sensor System with ATmega32

This project implements a simple **car parking sensor** using an **ATmega32 microcontroller**, **ultrasonic sensor**, **LCD display**, **LED indicators**, and a **buzzer**. It helps drivers detect nearby obstacles while parking, providing real-time distance feedback and proximity-based visual and audio alerts.

---

## 🎯 Objective

To design and build an embedded system that:
- Measures the distance between a car and an obstacle.
- Displays the distance on an LCD.
- Uses LEDs and a buzzer to alert the driver based on how close the car is to the obstacle.

---

## 🧠 Features

- **Ultrasonic Distance Measurement:** Measures distance using HC-SR04 sensor.
- **LCD Feedback:** Displays the measured distance in cm. If distance ≤ 5 cm, displays "STOP!" warning.
- **LED Indicators:**
  - 🔴 Red, 🟢 Green, 🔵 Blue LEDs light up based on proximity.
  - All OFF when distance > 20 cm.
- **Buzzer Alert:** Sounds continuously when the object is ≤ 5 cm.
- **Dynamic LED Behavior:**
  - **≤ 5 cm:** All LEDs blink + Buzzer ON + LCD shows "STOP!"
  - **6–10 cm:** All LEDs ON
  - **11–15 cm:** Red & Green ON
  - **16–20 cm:** Red ON only
  - **> 20 cm:** All LEDs & buzzer OFF

---

## 🔩 Hardware Components

- ATmega32 Microcontroller
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD Display (4-bit mode)
- 3x LEDs (Red, Green, Blue)
- Buzzer
- Breadboard + Wires

---

## 🖥️ Pin Configuration

| Component     | Pin             | ATmega32 Port |
|---------------|------------------|----------------|
| LCD RS        | PA1              |                |
| LCD E         | PA2              |                |
| LCD D4–D7     | PA3–PA6          |                |
| Red LED       | PC0              |                |
| Green LED     | PC1              |                |
| Blue LED      | PC2              |                |
| Buzzer        | PC5              |                |
| Ultrasonic TRIG | PD7             |                |
| Ultrasonic ECHO | PD6             |                |

---

## 🧱 Software Architecture

The project is structured using a layered architecture:
Application Layer
│
├── HAL (High Abstraction Layer)
│ ├── LED Driver
│ ├── Buzzer Driver
│ └── LCD Driver
│
├── MCAL (Microcontroller Abstraction Layer)
│ ├── GPIO Driver
│ ├── ICU Driver
│ └── Ultrasonic Drive

---

## 🧪 How It Works

1. The ultrasonic sensor emits a trigger pulse and waits for the echo.
2. The ATmega32 uses the **ICU module** to calculate the pulse width.
3. Distance is calculated and displayed on the LCD.
4. LEDs and buzzer are controlled based on distance thresholds.


---

## 📌 Notes

- System runs at **16 MHz** clock frequency.
- Project developed using **AVR-GCC** toolchain (or Atmel Studio).
- Follows standard drivers and structure learned in **Embedded Systems Diploma**.

---

## ✅ License

This project is for educational purposes. Feel free to use and modify it.

---

## 👨‍💻 Author

**Belal Ramadan**  
📧 belalramadan1505@gmail.com  
📍 Cairo, Egypt  

---



