int pins[] = {12, 11, 10, 9, 8};
int numPins = sizeof(pins) / sizeof(pins[0]); // Correct way to get array length
int maxBrightness = 255;
int minBrightness = 0;

void setup() {
  for (int a = 0; a < numPins; a++) {
    pinMode(pins[a], OUTPUT);
  }
}

void loop() {
 
  for (int a = 0; a < numPins; a++) {
    for (int brightness = minBrightness; brightness <= maxBrightness; brightness += 5) {
      analogWrite(pins[a], brightness);
      delay(20);
    }
    delay(1000);
  }
  
  delay(500);
  
 
  for (int a = 0; a < numPins; a++) {
    for (int brightness = maxBrightness; brightness >= minBrightness; brightness -= 5) {
      analogWrite(pins[a], brightness);
      delay(20);
    }
    delay(1000);
  }
  
  delay(500);
}
