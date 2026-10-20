#include <Arduino.h>
#include "pindef.h"
#include "proximity.h"

void proximityInit() {
    pinMode(PROXIMITY_PIN, INPUT_PULLUP);
    Serial.println("Proximity sensor ready");
}

void proximityRead() {
    int value = digitalRead(PROXIMITY_PIN);

    // Most IR / inductive sensors give LOW when object is detected
    if (value == LOW) {
        Serial.println("Proximity: Object Detected");
    } else {
        Serial.println("Proximity: No Object");
    }
}
