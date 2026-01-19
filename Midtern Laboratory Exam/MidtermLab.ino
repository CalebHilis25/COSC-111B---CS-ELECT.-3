const int LDR_PIN = A0;
const int LED_GREEN = 11;
const int LED_YELLOW = 12;
const int LED_RED = 13;

// Variables
int LDR_READING = 0;
float LDR_PERCENT = 0;

int THRESHOLD_LOW = 40;  
int THRESHOLD_HIGH = 70;

bool AUTO_MODE = false;
String ENVIRONMENT_STATUS = "Cloudy";

// ======= SETUP =======
void setup() {
  Serial.begin(9600);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  Serial.println("System Ready.");
  Serial.println("Current Mode: MANUAL");
}

// ======= MAIN LOOP =======
void loop() {

  readLDR();
  updateLEDs();
  displayStatus();
  processSerialCommands();

  delay(1000);
}

// Reads LDR value and converts to percentage
void readLDR() {
  LDR_READING = analogRead(LDR_PIN);
  LDR_PERCENT = map(LDR_READING, 0, 1023, 0, 100);
}

// ======= LED LOGIC UPDATED =======
void updateLEDs() {

  // ✅ AUTO MODE — RED LED now lights at 71–100%
  if (AUTO_MODE) {
    if (LDR_PERCENT <= 40) {
      ENVIRONMENT_STATUS = "Cloudy";
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
    else if (LDR_PERCENT <= 70) {
      ENVIRONMENT_STATUS = "Clear";
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);
    }
    else {  
      // ✅ 71% to 100%
      ENVIRONMENT_STATUS = "Clear";
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, HIGH);
    }
  }

  // ✅ MANUAL MODE (unchanged)
  else {
    if (LDR_PERCENT <= THRESHOLD_LOW) {
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
    else if (LDR_PERCENT <= THRESHOLD_HIGH) {
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);
    }
    else {
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, HIGH);
    }
  }
}

// Display monitor output every second
void displayStatus() {
  Serial.print("Light Intensity: ");
  Serial.print(LDR_PERCENT);
  Serial.println("%");

  Serial.print("Active LED: ");
  if (digitalRead(LED_GREEN)) Serial.println("Green");
  if (digitalRead(LED_YELLOW)) Serial.println("Yellow");
  if (digitalRead(LED_RED)) Serial.println("Red");

  Serial.print("Current Mode: ");
  Serial.println(AUTO_MODE ? "Automatic" : "Manual");

  if (AUTO_MODE) {
    Serial.print("Environment: ");
    Serial.println(ENVIRONMENT_STATUS);
  }

  Serial.println("-----------------------------------");
}

// ====== COMMAND PROCESSING ======
void processSerialCommands() {
  if (!Serial.available()) return;

  String COMMAND = Serial.readStringUntil('\n');
  COMMAND.trim();
  COMMAND.toUpperCase();

  // --- MODE selection ---
  if (COMMAND.equals("MODE AUTO")) {
    AUTO_MODE = true;
    Serial.println("Switched to AUTOMATIC mode.");
    return;
  }

  if (COMMAND.equals("MODE MANUAL")) {
    AUTO_MODE = false;
    Serial.println("Switched to MANUAL mode.");
    return;
  }

  // --- SET LOW ---
  if (COMMAND.startsWith("SET LOW ")) {
    if (!AUTO_MODE) {
      int VALUE = COMMAND.substring(8).toInt();
      if (VALUE >= 0 && VALUE <= 100 && VALUE < THRESHOLD_HIGH) {
        THRESHOLD_LOW = VALUE;
        Serial.print("Low threshold set to: ");
        Serial.println(THRESHOLD_LOW);
      } else {
        Serial.println("Error: Invalid LOW value");
      }
    } 
    else {
      Serial.println("Error: Wrong command (AUTO mode)");
    }
    return;
  }

  // --- SET HIGH ---
  if (COMMAND.startsWith("SET HIGH ")) {
    if (!AUTO_MODE) {
      int VALUE = COMMAND.substring(9).toInt();
      if (VALUE >= 0 && VALUE <= 100 && VALUE > THRESHOLD_LOW) {
        THRESHOLD_HIGH = VALUE;
        Serial.print("High threshold set to: ");
        Serial.println(THRESHOLD_HIGH);
      } else {
        Serial.println("Error: Invalid HIGH value");
      }
    } 
    else {
      Serial.println("Error: Wrong command (AUTO mode)");
    }
    return;
  }

  // Invalid command
  Serial.println("Error: Wrong command");
}
