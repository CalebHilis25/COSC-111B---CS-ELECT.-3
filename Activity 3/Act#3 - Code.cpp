#define THERMISTOR_PIN A0
#define LDR_PIN A2
#define LED_PIN 12   

const int TEMP_THRESHOLD = 50;  
const int LIGHT_THRESHOLD = 220;

const float SERIES_RESISTOR = 10;
const float BETA = 3950.0;
const float ROOM_TEMP = 298.15; 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float temp = getTemp();
  int light = analogRead(LDR_PIN);

  Serial.print("T: ");
  Serial.print(temp);
  Serial.print(" °C | L: ");
  Serial.println(light);

  // Fire detected: both LED and buzzer blink together
  if (temp >= TEMP_THRESHOLD && light >= LIGHT_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

float getTemp() {
  int adc = analogRead(THERMISTOR_PIN);
  float r = (1023.0 / adc - 1.0) * SERIES_RESISTOR;
  float t = 1.0 / ((log(r / SERIES_RESISTOR) / BETA) + (1.0 / ROOM_TEMP));
  return t - 273.15;  
}
