#include <Arduino.h>
#include "pindef.h"
#include "proximity.h"
#include "oled.h"
#include "gas.h"
#include "loadcell.h"
#include "rain.h"
#include "servo.h"
#include "temp.h"
#include "buzzer.h"
#include "ir.h"
#include "ultrasonic.h"

void setup() {
    Serial.begin(115200);

#if USE_PROXIMITY
    proximityInit();
#endif

#if USE_OLED
    oledInit();
#endif

#if USE_GAS
    gasInit();
#endif

#if USE_LOADCELL
    loadcellInit();
#endif

#if USE_RAIN
    rainInit();
#endif

#if USE_SERVO
    servoInit();
#endif

#if USE_TEMP
    tempInit();
#endif

#if USE_BUZZER
    buzzerInit();
#endif

#if USE_IR
    irInit();
#endif

#if USE_ULTRASONIC
    ultrasonicInit();
#endif
}

void loop() {
#if USE_PROXIMITY
    proximityRead();
#endif

#if USE_OLED
    oledShow("OLED Test", "Hello Rakshana");
#endif

#if USE_GAS
    gasRead();
#endif

#if USE_LOADCELL
    loadcellRead();
#endif

#if USE_RAIN
    rainRead();
#endif

#if USE_SERVO
    servoTest();
#endif

#if USE_TEMP
    tempRead();
#endif

#if USE_BUZZER
    buzzerBeep(1);
#endif

#if USE_IR
    irRead();
#endif

#if USE_ULTRASONIC
    ultrasonicRead();
#endif

    delay(500);
}
