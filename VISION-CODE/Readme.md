<h1 align="center">🤖 AI-Based Robotic Arm using YOLO & Arduino</h1>

<p align="center">
  An intelligent robotic arm system that combines <b>Computer Vision</b>, <b>Embedded Systems</b>, and <b>Automation</b> to detect objects in real time and perform robotic movement.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Python-3.x-blue?style=for-the-badge&logo=python">
  <img src="https://img.shields.io/badge/OpenCV-Computer%20Vision-green?style=for-the-badge&logo=opencv">
  <img src="https://img.shields.io/badge/YOLOv8-Object%20Detection-red?style=for-the-badge">
  <img src="https://img.shields.io/badge/Arduino-Uno-teal?style=for-the-badge&logo=arduino">
  <img src="https://img.shields.io/badge/Status-Working-success?style=for-the-badge">
</p>

---

## 📌 Project Overview

This project demonstrates how a robotic arm can be integrated with an AI-based vision system to detect objects and respond accordingly.  
A webcam captures the live workspace, YOLO detects the object, and Python sends commands to Arduino. The robotic arm then performs movement based on the detected object position.

This project is built as a **second-year mini project** to explore the practical integration of:
- Artificial Intelligence
- Computer Vision
- Arduino-based motor control
- Robotics and automation

---

## 🚀 Key Features

- 🎯 Real-time object detection using **YOLOv8**
- 📷 Live webcam feed processing with **OpenCV**
- 🔌 Serial communication between **Python and Arduino**
- 🤖 Robotic arm movement using **servo motors**
- ↔️ Base rotation according to object position
- ✊ Pick action when object comes to center
- 🧠 Simple AI + hardware integration

---

## 🛠️ Tech Stack

### Software
- Python
- OpenCV
- YOLOv8 (Ultralytics)
- PySerial
- Arduino IDE

### Hardware
- Arduino Uno
- PCA9685 Servo Driver
- MG996R Servo Motors
- SG90 Servo Motor
- 3D Printed Robotic Arm
- Webcam
- 5A Power Adapter

---

## 📂 Project Structure

```text
AI_Robotic_Arm/
│
├── Arduino_Codes/
│   ├── Center_Alignment/
│   ├── Calibration/
│   ├── Motor_Testing/
│   └── Final_Code/
│
├── Vision_Code/
│   ├── 1_Install_Setup/
│   ├── 2_Camera_Test/
│   ├── 3_YOLO_Model_Test/
│   ├── 4_YOLO_Camera_Detection/
│   ├── 5_Serial_Test/
│   └── 6_Vision_With_Serial_Control/
│
├── 3D_Design/
├── Report/
├── PPT/
├── Images/
└── README.md
Feel free to fork, improve, and contribute to this project.

🔥 This looks professional + GitHub-ready + marks-friendly
