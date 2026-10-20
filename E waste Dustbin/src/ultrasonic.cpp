#include <Arduino.h>
#include "pindef.h"
#include "ultrasonic.h"

void ultrasonicInit() {
    pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
    pinMode(ULTRASONIC_ECHO_PIN, INPUT);
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    Serial.println("Ultrasonic ready");
}

void ultrasonicRead() {
    // 10 us pulse on TRIG
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

    long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH, 30000);   // 30 ms timeout (~5 m)

    if (duration == 0) {
        Serial.println("Distance: out of range");
        return;
    }

    float distance = duration * 0.0343 / 2;   // cm

    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
}
