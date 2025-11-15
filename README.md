# IoT-Based Warehouse Security System
An IoT-based intrusion detection & alert system using NodeMCU ESP8266, PIR sensor, IR sensor, GSM SIM800L and buzzer.

## 🚀 Features
- Detects human movement using PIR sensor
- Detects object interruption using IR sensor
- Sends SMS alerts using GSM SIM800L (real-time)
- Activates buzzer on intrusion
- Low-cost warehouse & shop security system

## 🛠️ Components Used
- NodeMCU ESP8266
- PIR Motion Sensor (HC-SR501)
- IR Sensor
- GSM SIM800L Module
- Buzzer
- Jumper wires
- 5V/9V power supply

## 📡 System Architecture
1. Sensors detect motion or object interruption
2. NodeMCU receives sensor signal
3. Buzzer is activated
4. GSM module sends SMS alert to owner

## 🧾 Arduino Code
(See `code/warehouse_security.ino`)

## 📷 Circuit Diagram
(Add circuit_diagram.png inside docs folder)

## 📌 Future Enhancements
- Firebase integration for cloud alerts
- Adding camera module for image capture
- Mobile app notifications
- Web dashboard for alert logs
