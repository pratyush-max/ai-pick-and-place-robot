<h1 align="center">⚡ Arduino Control Module for AI-Based Robotic Arm</h1>

<p align="center">
  This module contains all Arduino programs used for <b>servo alignment</b>, <b>calibration</b>, <b>motor testing</b>, and <b>final robotic arm movement</b>.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-Uno-teal?style=for-the-badge&logo=arduino">
  <img src="https://img.shields.io/badge/Language-Embedded%20C-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/PCA9685-Servo%20Driver-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Working-success?style=for-the-badge">
</p>

---

## 📌 Module Overview

This folder contains all Arduino-side control codes required for operating the robotic arm.  
The robotic arm uses servo motors controlled through the **PCA9685 servo driver**, while Arduino Uno acts as the main controller for receiving commands and generating movement logic.

These codes were developed step by step during implementation:
- Center alignment of servos
- Servo range calibration
- Individual motor testing
- Final robotic arm movement
- Serial communication with Python

---

## 📂 Folder Structure

```text
Arduino_Codes/
│
├── Center_Alignment/
│   └── center_alignment.ino
│
├── Calibration/
│   └── calibration_test.ino
│
├── Motor_Testing/
│   └── motor_testing.ino
│
├── Final_Code/
│   └── final_robotic_arm.ino
│
└── README.md
