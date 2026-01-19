Laboratory Activity 6: Bidirectional Control Using Arduino and Python

Overview

This laboratory activity demonstrates bidirectional communication between Arduino and Python. Students will use push buttons on Arduino to send signals to Python, and Python will respond with commands that control LEDs on the Arduino, enabling real-time two-way interaction.
______________________________________________________________________________________________________________________

Objectives

- Understand and implement Arduino Serial communication

- Use Python to interact with Arduino in a bidirectional manner

- Create a circuit that allows real-time two-way control between Arduino and Python
______________________________________________________________________________________________________________________

Components Required:

- Arduino MCU

- 3 LEDs (Red, Green, Blue recommended)

- 3 Push Buttons

Standard components: _wires, breadboard, resistors_

- Laptop with Python and pyserial installed

Pin Assignments

LEDs: _Red → Pin 7, Green → Pin 6, Blue → Pin 5_

Push Buttons: _Button1 → Pin 12, Button2 → Pin 11, Button3 → Pin 10_
______________________________________________________________________________________________________________________
Implementation Details

- Arduino Sketch – Outbound Signals (_Button Presses_)

- Button 1 sends 'R' once when pressed

- Button 2 sends 'G' once when pressed

- Button 3 sends 'B' once when pressed

_No LED actions occur in Arduino during button presses; only signals are sent to Python_

- Arduino Sketch – Inbound Signals (Serial Commands)

- Receiving "1" → Toggle Red LED ON/OFF

- Receiving "2" → Toggle Green LED ON/OFF

- Receiving "3" → Toggle Blue LED ON/OFF

Inputs are case-insensitive
______________________________________________________________________________________________________________________

Python Script

Non-terminating script continuously monitors signals from Arduino

When Button signals are received:

- 'R' → Python responds "1" to Arduino

- 'G' → Python responds "2" to Arduino

- 'B' → Python responds "3" to Arduino

_Response time should be less than 1 second for real-time interaction_
______________________________________________________________________________________________________________________

Key Concepts Demonstrated

- Bidirectional Serial communication between Arduino and Python

- Handling both outbound (Arduino → Python) and inbound (Python → Arduino) signals

- Controlling LEDs and sending responses in real-time

- Real-time event-driven programming and responsiveness

- Integration of hardware and software in IoT applications
______________________________________________________________________________________________________________________

Required Output

GitHub repository containing:

- Breadboard diagram

- Arduino code (.ino file)

- Python script (.py file, corresponding to Arduino code)
