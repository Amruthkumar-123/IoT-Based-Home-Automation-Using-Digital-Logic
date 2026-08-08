# IoT-Based Home Automation Using Digital Logic

## Project Overview

This project presents an IoT-based home automation system combining
sensor interfacing, microcontroller control, digital logic, Wi-Fi-based
remote control, and power optimization.

The system uses an ESP32 microcontroller to interface with sensors and
actuators. Environmental and motion information is obtained using
DHT22, PIR, and LDR sensors. Electrical loads are controlled through
relay modules.

A Verilog-based digital control block is additionally developed to
implement the home automation decision logic. The digital logic is
simulated and synthesized using AMD Vivado.

## Objectives

- Interface sensors and actuators using digital circuits.
- Use a microcontroller for home automation.
- Provide remote control using Wi-Fi.
- Implement basic digital/VLSI control logic using Verilog.
- Implement power-saving operation.
- Simulate and verify the complete system.

## System Components

### Hardware / Simulation Components

- ESP32
- DHT22 Temperature and Humidity Sensor
- PIR Motion Sensor
- LDR Sensor
- Relay Modules
- LEDs
- I2C LCD
- Breadboards

### Software Tools

- Wokwi
- Arduino IDE / Wokwi Arduino Environment
- Blynk IoT
- Verilog
- AMD Vivado
- MATLAB / GNU Octave

## System Architecture

DHT22, PIR and LDR sensors provide input information to the ESP32.

The ESP32 processes the sensor information and controls the connected
loads through relay modules.

Wi-Fi connectivity provides remote control through the Blynk IoT
platform.

A separate Verilog digital control block implements the automation
decision logic and power-saving control.

## Block Diagram

```text
              ┌──────────────────┐
              │      DHT22       │
              │ Temperature/Humi │
              └────────┬─────────┘
                       │
                       │
┌──────────────┐       │
│ PIR Sensor   │───────┤
└──────────────┘       │
                       ▼
┌──────────────┐   ┌───────────────┐
│ LDR Sensor   │──►│     ESP32     │
└──────────────┘   │ Microcontroller│
                   └───────┬───────┘
                           │
                  ┌────────┴────────┐
                  │                 │
                  ▼                 ▼
             ┌─────────┐      ┌──────────┐
             │ Relays  │      │ I2C LCD  │
             └────┬────┘      └──────────┘
                  │
                  ▼
             Home Loads


                 Wi-Fi
                   │
                   ▼
             ┌──────────┐
             │  Blynk   │
             │   App    │
             └──────────┘


             Verilog Digital Logic
             ┌────────────────────┐
             │ Automation Control │
             │   + Power Saving   │
             └────────────────────┘
