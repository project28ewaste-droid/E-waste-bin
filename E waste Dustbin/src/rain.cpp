#include <Arduino.h>
#include "pindef.h"
#include "rain.h"

void rainInit() {
    pinMode(RAIN_PIN, INPUT);
    Serial.println("Rain sensor ready");
}

void rainRead() {
    // Module DO gives LOW when wet, so invert: 1 = rain, 0 = dry
    int rain = !digitalRead(RAIN_PIN);

    Serial.print("Rain: ");
    Serial.println(rain);
}
