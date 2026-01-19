Laboratory Activity 3: Fire Sensor Simulation Using Arduino
Overview

This laboratory activity demonstrates a simple fire detection simulation using an Arduino. A thermistor monitors temperature, and a photoresistor measures light intensity. The system evaluates the sensor readings against predefined limits and triggers a visual alert if potential fire conditions are detected._
_____________________________________________________________________________________________________________________________________________________________________________________________
Objectives

- Gain familiarity with basic sensor components used in IoT systems

- Integrate multiple sensors in an Arduino circuit

- Implement threshold-based decision logic for fire detection
_____________________________________________________________________________________________________________________________________________________________________________________________

Hardware Used:

- Arduino Uno

- Thermistor

- Photoresistor

-Red LED

- Resistors

- Breadboard and jumper wires

Pin Configuration

- Thermistor → Analog Pin A0

- Photoresistor → Analog Pin A2

- Alert LED → Digital Pin 12
_____________________________________________________________________________________________________________________________________________________________________________________________

Implementation Details

- The system continuously reads temperature data from the thermistor and light intensity data from the photoresistor

- Temperature is calculated in degrees Celsius based on the thermistor’s resistance

- Light intensity is compared against a set threshold to detect unusual conditions

- If temperature ≥ 50 °C and light intensity ≥ 220, the system turns on a fast-blinking red LED to indicate a potential fire

- Temperature calculations are encapsulated in a separate function for readability and code organization

- A buzzer is connected in parallel with the alert LED, blinking simultaneously without additional control logic
_____________________________________________________________________________________________________________________________________________________________________________________________

Key Concepts Demonstrated

- Multi-sensor integration in an embedded system

- Analog signal reading and interpretation

- Threshold-based conditional logic

- Functional decomposition and code organization

- Use of constants and macros for configuration management
  _____________________________________________________________________________________________________________________________________________________________________________________________

Technical Notes

- Photoresistor readings are evaluated as a digital condition using a threshold, rather than as direct digital input

- Thermistor calculations use standard beta parameter values suitable for simulation and educational purposes

- The buzzer shares the same output pin as the alert LED, turning on and off in sync with the LED blinking pattern
