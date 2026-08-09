# IoT-Based Home Automation Using Digital Logic

## Project Overview

This project presents an IoT-based home automation system developed using an ESP32 microcontroller.

The system allows electrical appliances to be controlled remotely through the Blynk IoT platform. Environmental conditions are monitored using a DHT22 temperature and humidity sensor, while a PIR sensor and LDR are used for automatic control functions.

An I2C LCD provides real-time information about appliance status, temperature, humidity, and lighting status.

The project was developed and simulated using Wokwi.

---

## Author

**Amruth Kumar Ronanki**

B.Tech – Electrical and Electronics Engineering

---

## Features

- IoT-based appliance control
- ESP32-based control system
- Four relay-controlled appliances
- Remote control using Blynk
- Temperature monitoring using DHT22
- Humidity monitoring using DHT22
- PIR-based motion detection
- LDR-based outdoor light control
- I2C LCD status display
- LED-based motion indication
- Wi-Fi connectivity
- Digital logic-based control
- Simulation using Wokwi

---

## Components Used

### Controller

- ESP32 DevKit V1

### Sensors

- DHT22 Temperature and Humidity Sensor
- PIR Motion Sensor
- LDR / Photoresistor Sensor

### Actuators

- 4-Channel Relay Modules
- LED

### Display

- 20x4 I2C LCD

### Other Components

- Breadboards
- Jumper wires
- Power connections

---

## Pin Configuration

| Component | ESP32 Pin |
|-----------|-----------|
| Relay 1 | GPIO 5 |
| Relay 2 | GPIO 18 |
| Relay 3 | GPIO 19 |
| Relay 4 | GPIO 4 |
| LDR | GPIO 23 |
| Outdoor Light | GPIO 2 |
| PIR Sensor | GPIO 27 |
| Motion LED | GPIO 33 |
| DHT22 | GPIO 15 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |

---

## Blynk Virtual Pins

| Virtual Pin | Function |
|-------------|----------|
| V0 | Relay 1 |
| V1 | Relay 2 |
| V2 | Relay 3 |
| V3 | Relay 4 |
| V4 | Outdoor Light |
| V5 | Temperature |
| V6 | Humidity |
| V7 | PIR / Motion Control |

---

## Working Principle

The ESP32 acts as the central controller of the home automation system.

The DHT22 sensor measures temperature and humidity. The measured values are sent to the Blynk IoT platform and displayed on the LCD.

The Blynk application provides virtual controls for the relay modules. When a user changes a control in the Blynk application, the corresponding ESP32 GPIO pin is activated or deactivated.

The PIR sensor detects motion and controls the motion-indicator LED.

The LDR is used for light-dependent control of the outdoor lighting system.

The LCD continuously displays appliance states and environmental information.

---

## System Operation

### 1. Appliance Control

The four relay modules are controlled through Blynk virtual pins V0-V3.

Each relay can be switched ON or OFF remotely.

### 2. Outdoor Light Control

The LDR detects the lighting condition.

The ESP32 reads the LDR signal and controls the outdoor light accordingly.

### 3. Motion Detection

The PIR sensor detects human movement.

When motion is detected, the ESP32 activates the indicator LED.

### 4. Temperature Monitoring

The DHT22 measures the surrounding temperature.

The temperature value is displayed on the LCD and transmitted to Blynk through virtual pin V5.

### 5. Humidity Monitoring

The DHT22 also measures humidity.

The humidity value is displayed on the LCD and transmitted to Blynk through virtual pin V6.

---

## Software Used

- Wokwi
- Arduino-compatible ESP32 programming environment
- Blynk IoT
- C/C++ for ESP32
- GitHub

---

## Libraries Used

The project uses the following libraries:

- LiquidCrystal I2C
- WiFi
- WiFiClient
- BlynkSimpleEsp32
- DHTesp

---

## Simulation

The complete circuit was designed and simulated using Wokwi.

The simulation includes:

- ESP32
- DHT22
- PIR sensor
- LDR
- Relay modules
- I2C LCD
- LED
- Breadboards

See `Circuit.png` for the circuit implementation.

---

## Project Files


IoT-Based-Home-Automation/
│
├── Home_Automation.ino
├── diagram.json
├── Circuit.png
└── README.md

## Applications

This IoT-based home automation system can be used in:

- Smart homes
- Remote appliance control
- Automatic lighting systems
- Security monitoring
- Environmental monitoring
- Energy management
- IoT-based building automation

---

## Future Improvements

The system can be further enhanced by adding:

- Energy consumption monitoring
- Automatic fan speed control
- Mobile notifications
- Voice-controlled appliances
- Overcurrent and overload protection
- Real-time power monitoring
- Additional environmental sensors
- AI-based occupancy detection

---

## Conclusion

This project demonstrates the integration of IoT, digital control, sensors, actuators, and wireless communication for home automation.

The ESP32 acts as the central controller, while Blynk provides remote monitoring and control. The integration of PIR, LDR, DHT22, relay modules, and an I2C LCD provides a practical platform for smart home automation.

The project was successfully designed and simulated using Wokwi.

---

## Author

**Amruth Kumar Ronanki**

B.Tech – Electrical and Electronics Engineering
