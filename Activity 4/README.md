Laboratory Activity 4: Arduino Serial Connection
Overview

This laboratory activity introduces the use of the Arduino Serial connection. Students will control an LED using sensor input and commands sent through the Serial Monitor, learning how to interact with the Arduino via serial communication.
_______________________________________________________________________________________________________________________________
Objectives

- Understand and implement Arduino Serial communication

- Explore and practice basic Serial functions in Arduino

- Create a simple circuit controlled through Serial commands
_______________________________________________________________________________________________________________________________

Instructions

Using the diagram and code from Laboratory Activity 3, complete the following steps:

Select one sensor to use in this activity (thermistor or photoresistor)z

Set the threshold:

- Thermistor → 50 °C

- Photoresistor → 220

When the sensor reading meets or exceeds the threshold:

- Blink the LED connected to pin 8 (delay = 100 ms)

- The LED should continue blinking even if the sensor reading drops below the threshold

- If the word "stop" is entered in the Serial Monitor, stop the blinking

Input is **case-insensitive** (e.g., _"STOP", "Stop", "stop"_)
_______________________________________________________________________________________________________________________________

Key Concepts Demonstrated

- Arduino Serial communication basics

- Reading and interpreting Serial input

- Controlling hardware based on sensor data and Serial commands

- Conditional logic and persistent actions in embedded systems
_______________________________________________________________________________________________________________________________

Technical Notes

- Use Serial Monitor to send commands to Arduino

- Ensure the threshold logic and blinking function operate independently of ongoing sensor readings

- The Serial input should be processed in a way that ignores letter casing for the "stop" command
