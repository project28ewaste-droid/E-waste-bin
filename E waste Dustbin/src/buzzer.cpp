#include <Arduino.h>
#include "pindef.h"
#include "buzzer.h"

void buzzerInit() {
    pinMode(BUZZER_PIN, OUTPUT);
    buzzerOff();
    Serial.println("Buzzer ready");
}

void buzzerOn() {
    digitalWrite(BUZZER_PIN, HIGH);
}

void buzzerOff() {
    digitalWrite(BUZZER_PIN, LOW);
}

void buzzerBeep(int times) {
    for (int i = 0; i < times; i++) {
        buzzerOn();
        delay(100);
        buzzerOff();
        delay(100);
    }
    Serial.println("Buzzer: beep");
}
