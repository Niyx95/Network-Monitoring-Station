.#Network Monitor Station

## Overview
ESP-32 based network monitor with LCD display
LED alerts, Grafana dashboard on Raspberry Pi5
Built to develop hands-on skills in embedded systems,
networking, and Linux infrastructure.

## Hardware
- Raspberry Pi5
- ESP32-S (AI-Thinker)
- 16x2 I2C display
- Samsung 980 Pro m.2 SSD
- Waveshare PCIe bridge

## Technologies
- C++ / Arduino IDE
- Raspberry Pi OS
- Grafana + influxDB
- MQTT / HTTP
- Python

## Progress Log
### Phase1 - Connect ESP32 to Wifi
- Installed Arduino IDE on my fedora machine
- Fixed permissions 
- Initial Try to blink a light with LED lights
- ESP32 connected to WIFI, prints IP to Serial Console

### Phase2 - install library and get display to work
- Wired 16x2 I2C LCD to ESP32
- Fixed contrast via potentiometer
- LCD shows Wifi status and IP address

### Phase3 - Network Pinging and LED alerts
- Wired 2 LED (Green on GPIO17, Red on 16)
- Tested both LED
- tested first logs with lcd screen

### Phase4 - Pi Setup
- set static ipv4
- installed Grafana and InfluxDB
- created dashboard on grafana 
- Configured MQTT Broker
- All services enabled

### Phase5 - MQTT - ESP32 - Python
- ESP32 publishes ping to the MQTT
- mosquitto broker recives message on Pi

## Issues & Solutions
| Issue | Solution |
|-------|----------|
| Samsung 980 Pro not detected on Waveshare bridge | Contacted Waveshare support — hardware issue confirmed, ribbon cable was off |
| MQTT stuck in infinite loop | Diagnosed missing client.connect() call — fixed |
| LCD showing blank screen | Adjusted contrast potentiometer on I2C module |

## About
Built during a 2-month learning sprint in Italy, June 2025.
Part of a personal portfolio demonstrating Linux sysadmin,
networking, and IoT skills.
