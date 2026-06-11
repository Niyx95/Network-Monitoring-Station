.#Network Monitor Station

## Overview
ESP-32 based network monitor with LCD display
LED alerts, Grafana dashboard on Raspberry Pi5

## Hardware
- Raspberry Pi5
- ESP32-S (AI-Thinker)
- 16x2 I2C display
- Samsung 980 Pro m.2 SSD
- Waveshare PCIe bridge

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

###Phase4 - Pi Setup
- debugging M2 (not showing up)
- set static ipv4
- installed Grafana and InfluxDB
- More debugging (M2)

## Issues:
- Samsung 980 Pro not detected
- Samsung 970 Evo not detected
- contacted Waveshare to get guidance 

## Technologies
- C++ / Arduino IDE
- Raspberry Pi OS
- Grafana + influxDB
- MQTT / HTTP
- Python 
