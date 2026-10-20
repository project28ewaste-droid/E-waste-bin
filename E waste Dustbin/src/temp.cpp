#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "pindef.h"
#include "temp.h"

OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

void tempInit() {
    tempSensor.begin();

    if (tempSensor.getDeviceCount() == 0) {
        Serial.println("Temp sensor: not found, check wiring / 4.7k pull-up");
        return;
    }
    Serial.println("Temp sensor ready");
}

void tempRead() {
    tempSensor.requestTemperatures();
    float tempC = tempSensor.getTempCByIndex(0);

    if (tempC == DEVICE_DISCONNECTED_C) {
        Serial.println("Temp: sensor error");
        return;
    }

    Serial.print("Temp: ");
    Serial.print(tempC, 1);
    Serial.println(" C");
}
