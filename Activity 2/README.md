Laboratory Activity 2: Working with Analog Signals
Overview

This laboratory activity extends the previous running light experiment by introducing analog control. Instead of simply switching LEDs ON or OFF, the Arduino adjusts the intensity of each LED using Pulse Width Modulation (PWM), creating smooth fade-in and fade-out effects.
__________________________________________________________________________________________________________________________________
Objectives

- Understand the concept of analog signals and how they are represented in Arduino

- Learn how to adjust LED brightness using PWM and the analogWrite() function

Hardware Used

- Arduino Uno

- 5 LEDs

- Resistors

- Breadboard

- Jumper wires
__________________________________________________________________________________________________________________________________
Implementation Details

- Five LEDs are connected to Arduino digital pins 8 to 12
- The LED pin numbers are stored in an array to simplify control
- A loop is used to configure pin modes and manage the LED sequence
- Each LED slowly increases brightness from 0 to 255 using analogWrite()
- Once maximum brightness is reached, the LED gradually dims back to 0
- A brief delay is applied between LED transitions to make the running light effect easy to observe
__________________________________________________________________________________________________________________________________

Key Concepts Demonstrated

- Simulation of analog signals using PWM

- Brightness control of LEDs through analogWrite()

- Array usage for efficient pin management

- Loop-based logic using while statements

- Timing control and gradual signal modulation
__________________________________________________________________________________________________________________________________
Technical Note

This activity follows the laboratory requirement of using digital pins 8 to 12

The focus of this experiment is on demonstrating analog signal behavior and PWM-based brightness control rather than hardware PWM pin limitations
