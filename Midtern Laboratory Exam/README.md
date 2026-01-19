COSC 111B - MIDTERM EXAMINATION

_This project implements a Smart Lighting System using an Arduino Uno. The system adjusts LED indicators based on ambient light conditions measured via a photoresistor.

The system operates in Manual and Automatic modes:

Automatic Mode: Simulates responses to environmental conditions (Cloudy, Normal, Bright Sunlight) and lights up LEDs accordingly.

Manual Mode: Allows the user to set thresholds and control the system via the Serial Monitor.

_Three LEDs represent the light intensity: Green for low light, Yellow for medium light, and Red for high light. Only one LED is active at a time._
____________________________________________________________________________________________________________

Objectives

- Understand Arduino analog input and digital output.

- Implement sensor-based decision logic using thresholds.

- Learn Serial communication for interactive control.

- Simulate environmental conditions and automatic response.
____________________________________________________________________________________________________________
Hardware Used

- -Arduino Uno

- 1 × Photoresistor (LDR)

- 3 × LEDs (Green, Yellow, Red)

- Resistors

- Breadboard

- Jumper wires
____________________________________________________________________________________________________________

Pin Configuration
- Component	Pin
- Photoresistor	A0
- Green LED	11
- Yellow LED	12
- Red LED	13
____________________________________________________________________________________________________________
  
Implementation Details
- LED Control Logic

Automatic Mode:

Cloudy: Low ≤ 40 → Green LED

Normal: 41 ≤ Medium ≤ 70 → Yellow LED

Bright Sunlight: 71 ≤ High ≤ 100 → Red LED

Manual Mode:

- User sets low/high thresholds via Serial commands.

- Only one LED is active depending on the current light intensity.

Serial Commands

- MODE AUTO → Switch to Automatic Mode

- MODE MANUAL → Switch to Manual Mode

- SET LOW xx → Set the low threshold (_Manual Mode only_)

- SET HIGH xx → Set the high threshold (_Manual Mode only_)

_Invalid commands return: Error: Wrong command_

- Display on Serial Monitor


Every second, the system outputs:
____________________________________________________________________________________________________________
- Light Intensity: xx%                                                                                                                                                                                                                                               
- Active LED: Green/Yellow/Red 

- Current Mode: Manual/Automatic

- Environment: Cloudy/Normal/Bright Sunlight (only in Automatic Mode)
________________________________________________________________________________________________________

Key Concepts Demonstrated

- Analog input reading with analogRead()

- LED control using digitalWrite()

- Threshold-based conditional logic

- Mode switching via Serial commands

- Dynamic environmental simulation

- Real-time data display
