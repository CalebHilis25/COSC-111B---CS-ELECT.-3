Laboratory Activity 1: Working with Digital Signals
______________________________________________________Overview______________________________________________________

This laboratory activity demonstrates digital output control using an Arduino Uno by implementing a running light circuit. 
LEDs are turned ON and OFF sequentially to illustrate how digital signals and timing operate in embedded systems._
__________________________________________________________________________________________________________________________

Objectives

 - Understand the use of Arduino as a basic device for IoT projects

- Learn how to control digital output pins using Arduino

**Hardware Used
- Arduino Uno
- 5 LEDs
- Resistors
- Breadboard
- Jumper wires
__________________________________________________________________________________________________________________________

Implementation Details
- LEDs are connected to digital pins 8 through 12
- LEDs turn ON sequentially from pin 12 down to pin 8
- After all LEDs are ON, they turn OFF in the same order
- A 1-second delay is applied between each step for clear visibility
- The setup() function initializes all LED pins as OUTPUT
- The loop() function contains:
- One loop to turn LEDs ON sequentially
- One loop to turn LEDs OFF sequentially
