Laboratory Activity 5: Arduino Serial Communication with Python
Overview

This laboratory activity demonstrates how to use Arduino’s Serial connection in combination with Python to control multiple LEDs. Students will implement a program on Arduino to receive serial commands and a Python script to interact with the Arduino in real time._
__________________________________________________________________________________________________________________________
Objectives

- Understand and implement Arduino Serial communication

- Utilize Python as a tool to send and receive serial commands

- Create a circuit where LEDs can be controlled via Arduino and Python
__________________________________________________________________________________________________________________________

Instructions

Using the laboratory guide, implement the following requirements:

Components Required

- Arduino MCU

- 3 LEDs (Red, Green, Blue recommended)

Standard components: _wires, breadboard, resistors_

- Laptop with Python and pyserial installed

Pin Assignments

- Red LED → Pin 8

- Green LED → Pin 9

- Blue LED → Pin 10

Arduino Sketch Requirements

Serial input should control LEDs as follows:

- R/r → Toggle Red LED ON/OFF         

- G/g → Toggle Green LED ON/OFF

- B/b → Toggle Blue LED ON/OFF

- A/a → Turn all LEDs ON

- O/o → Turn all LEDs OFF

- Any other input → Return an error message

- Inputs should be case-insensitive
__________________________________________________________________________________________________________________________

Python Script Requirements

Create a non-terminating script displaying options:
- [R] Red ON/OFF
- [G] Green ON/OFF
- [B] Blue ON/OFF
- [A] All ON
- [O] All OFF
- (X) Exit

- Commands should execute the same logic as the Arduino sketch

- Input should be case-insensitive

- Entering X/x should terminate the Python program
__________________________________________________________________________________________________________________________

Key Concepts Demonstrated

- Arduino Serial communication and input handling

- Python interaction with Arduino via pyserial

- Controlling multiple outputs through serial commands

- Conditional logic and case-insensitive input processing

- Integration of hardware and software for real-time control
__________________________________________________________________________________________________________________________

Technical Notes

- Ensure Arduino continuously reads Serial input without blocking LED control

- Python script should remain active until the user chooses to exit

- LED toggling and all-on/all-off commands should correctly synchronize between Arduino and Python
