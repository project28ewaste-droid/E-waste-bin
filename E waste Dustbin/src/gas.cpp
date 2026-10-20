#include <Arduino.h>
#include "pindef.h"
#include "gas.h"

void gasInit() {
    pinMode(GAS_PIN, INPUT);
    analogSetPinAttenuation(GAS_PIN, ADC_11db);   // full 0-3.3V range
    Serial.println("Gas sensor ready (needs ~1 min warm-up)");
}

void gasRead() {
    int value = analogRead(GAS_PIN);

    Serial.print("Gas: ");
    Serial.print(value);

    if (value > GAS_THRESHOLD) {
        Serial.println("  -> GAS DETECTED");
    } else {
        Serial.println("  -> Normal");
    }
}
