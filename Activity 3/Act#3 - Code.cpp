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
  int lightMapped = map(light, 0, 1035, 0, 255);
  

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | Brightness: ");
  Serial.println(lightMapped);
  
  
  if (temp >= TEMP_THRESHOLD && lightMapped >= LIGHT_THRESHOLD) {
    Serial.println("Fire Detected");
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
  
  } else {
    digitalWrite(LED_PIN, LOW);
    delay(1000);
  }
}

float getTemp() {
  int readTemp = analogRead(THERMISTOR_PIN);
  float resistance = (1023.0 / readTemp - 1.0) * SERIES_RESISTOR;
  float temp = 1.0 / ((log(resistance / SERIES_RESISTOR) / BETA) + (1.0 / ROOM_TEMP));
  return temp - 273.15;  
}