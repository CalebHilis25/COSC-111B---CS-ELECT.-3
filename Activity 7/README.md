Laboratory Activity #7: Controlling Arduino Using FastAPI

Overview

This project demonstrates bi-directional control of an Arduino using Python and FastAPI. The system allows controlling LEDs on the Arduino both via Serial commands and HTTP requests through a FastAPI server.

Three LEDs represent the output (**Red, Green, Blue**) and can be toggled using:

- Arduino Serial Monitor inputs

- FastAPI HTTP requests

- Push buttons on the Arduino can also send signals to the Python FastAPI server, demonstrating real-time two-way communication.
________________________________________________________________________________________________________________________________________________________

Objectives

- Implement Arduino Serial communication.

- Use Python to interface with Arduino via Serial.

- Control Arduino LEDs through an HTTP-based API using FastAPI.

- Enable bi-directional communication between Arduino and Python.
________________________________________________________________________________________________________________________________________________________

Hardware Used

- Arduino MCU

- 3 × LEDs (Red, Green, Blue recommended)

- 3 × Push Buttons

- Breadboard, Jumper Wires, Resistors

- Laptop with Python, pyserial, and FastAPI installed
________________________________________________________________________________________________________________________________________________________

Pin Configuration
_Component	Pin_
- Red LED	7
- Green LED	6
- Blue LED	5
- Button 1	12
- Button 2	11
- Button 3	10
- Implementation Details
________________________________________________________________________________________________________________________________________________________
  
Arduino Logic

_Inbound Signals:_

- "1" → Toggle Red LED

- "2" → Toggle Green LED

- "3" → Toggle Blue LED

Inputs are case-insensitive.

_Outbound Signals:_

Button presses send corresponding characters to Python (R, G, B).
________________________________________________________________________________________________________________________________________________________

FastAPI API Endpoints

- /led/<color> → Toggle a single LED

- color = "red" → Sends "1" to Arduino

- color = "green" → Sends "2" to Arduino

- color = "blue" → Sends "3" to Arduino

- /led/on → Turns all LEDs ON

- /led/off → Turns all LEDs OFF

_All HTTP requests interact with Arduino via the Serial connection in real-time._
________________________________________________________________________________________________________________________________________________________

Key Concepts Demonstrated

- Bi-directional Serial communication between Arduino and Python

- Controlling Arduino hardware through an HTTP interface

Integration of hardware control with a web-based API (FastAPI)

Real-time response handling (<1 second)

Case-insensitive command processing
