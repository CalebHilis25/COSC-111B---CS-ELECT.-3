COSC 111B - FINAL EXAMINATION

Overview

This project demonstrates a bridge between Arduino hardware and a remote API using Python. A push button on the Arduino sends a signal via Serial to a Python client, which then triggers an HTTP request to control LEDs on another Arduino or IoT device.

The Arduino does not interact with the API directly; it only sends signals to the Python program. The Python client handles serial input, debouncing, and sends HTTP requests to a predefined endpoint.
_____________________________________________________________________________________________________________
Objectives

- Understand Arduino Serial communication and push button handling.

- Implement software debouncing to avoid repeated signals.

- Use Python to interface with Arduino and send HTTP requests.

- Normalize serial input to ensure case-insensitive handling.

- Build a reliable, non-terminating system for IoT control.
_____________________________________________________________________________________________________________
Hardware Used

- Arduino MCU

- 1 × Push Button

- Breadboard, Jumper wires, Resistor

- Laptop with Python and pyserial installed

in Configuration
_Component	Pin_
- Push Button	e.g., 12
- GND	GND
- VCC	5V (through resistor if needed)

_____________________________________________________________________________________________________________
Implementation Details
- Arduino Requirements

- Detect valid button presses.

- Send a single signal per press via Serial to the Python client.

- Use software debouncing to prevent repeated signals from a long press.

- The signal must indicate the group number assigned to the Arduino setup.

- No HTTP requests or LED control should occur directly on the Arduino.
_____________________________________________________________________________________________________________

Python Client Requirements

- Continuously listen to the Serial port from Arduino.

- Normalize input to avoid case-sensitivity issues.

- Upon receiving a valid signal:

- Extract the group number.

- Send an HTTP request to the endpoint:

Display feedback in the terminal:

- Group number received

- Endpoint called

- API response (success or error)

Behavior Rules

- One button press = one API request

- Long button presses must not generate repeated API calls.

- Serial input validation is required; invalid inputs should produce error messages.
_____________________________________________________________________________________________________________
Key Concepts Demonstrated

- Push button input handling on Arduino

- Software debouncing for clean signals

- Arduino-to-Python communication via Serial

- HTTP request automation with Python

- Input validation and normalized handling

- IoT system design using intermediate client software
