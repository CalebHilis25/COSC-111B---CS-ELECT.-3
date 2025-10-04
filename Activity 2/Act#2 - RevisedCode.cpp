int leds[] = {12, 11, 10, 9, 8};  
int led = 0;
int brightness = 0;

void setup() {
  
  led = 0;
  while (led < 5) {
    pinMode(leds[led], OUTPUT);
    led++;
  }
}

void loop() {
  
  led = 0;
  while (led < 5) {
    brightness = 0;
    while (brightness <= 255) {
      analogWrite(leds[led], brightness);
      brightness++;
      delay(3);
    }
    delay(1000);
    led++;  
  }

  led = 0;
  while (led < 5) {
    brightness = 255;
    while (brightness >= 0) {
      analogWrite(leds[led], brightness);
      brightness--;
      delay(3);
    }
    delay(1000);
    led++;  
  }
}
