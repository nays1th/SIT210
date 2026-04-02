
# Task 1.1P - Switching ON Lights

## System Description
This project is a simple smart lighting system for an elderly care home scenario. When the switch is activated, the porch light turns on for 30 seconds and the hallway light turns on for 60 seconds.

## Components Used
- Arduino Nano 33 IoT
- 2 LEDs
- 2 resistors
- 1 switch
- Breadboard
- Jumper wires

## Code Overview
The program is divided into smaller functions to make it easier to read and manage.

- setup() sets the pin modes for the switch and LEDs.
- loop() keeps the system running by checking the switch and controlling the lights.
- checkSwitch() detects when the switch has been pressed.
- controlLights() controls how long each light stays on.
- millis() is used for timing so both lights can run at the same time without stopping the whole program.
- INPUT_PULLUP is used for the switch so the wiring is simpler and the input is more stable.
