#include <Arduino.h>
#include "pindef.h"
#include "ir.h"

void irInit() {
    pinMode(IR1_PIN, INPUT);
    pinMode(IR2_PIN, INPUT);
    Serial.println("IR sensors ready");
}

void irRead() {
    // IR module gives LOW when object detected, so invert: 1 = detected, 0 = clear
    int ir1 = !digitalRead(IR1_PIN);
    int ir2 = !digitalRead(IR2_PIN);

    Serial.print("IR1: ");
    Serial.print(ir1);
    Serial.print("   IR2: ");
    Serial.println(ir2);
}
