#define LDR_PIN A2
#define LED_PIN 8
const int LIGHT_THRESHOLD = 220;
String currentCommand = "";
bool thresholdMet = false;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available()) {

    currentCommand = Serial.readStringUntil('\n');
    Serial.println("Analyzing...");
    delay(3000); 
    currentCommand.trim();
    currentCommand.toLowerCase();

    if (currentCommand == "stop") {
      thresholdMet = false;      
      digitalWrite(LED_PIN, LOW); 
      Serial.println("Stopped");
      delay(2000);
    } else {
      Serial.print("Unknown: '");
      Serial.print(currentCommand);
      Serial.println("'");
      delay(2000);
    }
    currentCommand = "";

  } else {

    int light = analogRead(LDR_PIN);
    int lightMapped = map(light, 0, 1023, 0, 255);

    Serial.print("Brightness: ");
    Serial.println(lightMapped);
    delay(500);

    if (lightMapped >= LIGHT_THRESHOLD) {
      thresholdMet = true;
    } 

    if (thresholdMet) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW); 
      delay(100);
    }
  }
}
