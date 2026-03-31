
# Task 3.1P - Trigger and Notification System

## Description
This project uses an Arduino Nano 33 IoT and a BH1750 light sensor to detect sunlight conditions. When the light level reaches a certain threshold, a trigger is activated and a notification is sent using IFTTT.

## Components
- Arduino Nano 33 IoT
- BH1750 Light Sensor
- Breadboard and jumper wires

## How It Works
The Arduino reads light intensity from the BH1750 sensor. If the light level is above a defined threshold, it triggers a webhook request to IFTTT, which sends an email notification. When the light level drops below the threshold, another notification is sent.

## Notification System
IFTTT Webhooks is used to send notifications based on sunlight detection.
