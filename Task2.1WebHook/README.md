## Description
This project uses an Arduino Nano 33 IoT to collect temperature and light data and send it to ThingSpeak.

## Components Used
- Arduino Nano 33 IoT
- DHT11 temperature sensor
- BH1750 light sensor (GY-30)
-Breadboard and jumper wires

## How it works
The Arduino reads temperature from the DHT sensor and light intensity from the BH1750 sensor. The data is sent to ThingSpeak every 30 seconds using WiFi.

## ThingSpeak
The data is displayed on a ThingSpeak channel with two fields:
- Light
- Temperature

# Notes
A BH1750 digital sensor was used instead of an analogue light sensor for more accurate readings

