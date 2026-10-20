#include <Arduino.h>
#include <HX711.h>
#include "pindef.h"
#include "loadcell.h"

HX711 scale;

void loadcellInit() {
    scale.begin(LOADCELL_DT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(LOADCELL_CAL_FACTOR);
    scale.tare();       // make it 0 (keep empty at startup)

    Serial.println("Load cell ready");
}

void loadcellRead() {
    float weight = scale.get_units(5);

    if (abs(weight) < LOADCELL_ZERO_G) {
        weight = 0;     // ignore small noise near zero
    }

    Serial.print("Weight: ");
    Serial.print(weight, 1);
    Serial.println(" g");
}
