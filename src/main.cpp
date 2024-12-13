#define DEBUG   0

#define PIN1    26
#define PIN2    33
#define PIN3    32
#define PIN4    25

#define COMMAND1    "A"
#define COMMAND2    "B"
#define COMMAND3    "C"
#define COMMAND4    "D"

#define DEBOUNCE_DELAY 500

#include <Arduino.h>

uint8_t pins[4] = {PIN1, PIN2, PIN3, PIN4};
String commands[4] = {COMMAND1, COMMAND2, COMMAND3, COMMAND4};

uint32_t lastUpdateMillis = 0;

void readPins(){
  for (int i = 0; i < 4; i++) {
    if (digitalRead(pins[i]) == LOW) {
      if (millis() - lastUpdateMillis < DEBOUNCE_DELAY) { return; }
      Serial.println();
      Serial.println(commands[i]);
      if (DEBUG) { Serial.println("Pin " + String(i) + " pressed, sending command: " + commands[i]);} 
      lastUpdateMillis = millis();
    }
  }
}

void io_init() {
  for (int i = 0; i < 4; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void setup() {
  Serial.begin(9600);
  io_init();
}

void loop(){
  readPins();
}