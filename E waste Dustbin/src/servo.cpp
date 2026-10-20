#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "pindef.h"
#include "servo.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

void servoInit() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);         // servos run at 50 Hz
    delay(10);

    servoSpin(SERVO360_1_CH, 0);
    servoSpin(SERVO360_2_CH, 0);
    servoAngle(SERVO180_CH, 0);

    Serial.println("Servo driver ready");
}

// 180 deg servo: 0 deg = 500 us, 180 deg = 2400 us
void servoAngle(int channel, int angle) {
    angle = constrain(angle, 0, 180);
    int us = map(angle, 0, 180, 500, 2400);
    pwm.writeMicroseconds(channel, us);
}

// 360 deg servo: 1500 us = stop, 1000 = full reverse, 2000 = full forward
void servoSpin(int channel, int speed) {
    speed = constrain(speed, -100, 100);
    int us = SERVO360_STOP_US + speed * 5;
    pwm.writeMicroseconds(channel, us);
}

void servoTest() {
    Serial.println("180 servo: 0 -> 90 -> 180");
    servoAngle(SERVO180_CH, 0);
    delay(1000);
    servoAngle(SERVO180_CH, 90);
    delay(1000);
    servoAngle(SERVO180_CH, 180);
    delay(1000);

    Serial.println("360 servos: forward");
    servoSpin(SERVO360_1_CH, 50);
    servoSpin(SERVO360_2_CH, 50);
    delay(2000);

    Serial.println("360 servos: stop");
    servoSpin(SERVO360_1_CH, 0);
    servoSpin(SERVO360_2_CH, 0);
    delay(1000);

    Serial.println("360 servos: reverse");
    servoSpin(SERVO360_1_CH, -50);
    servoSpin(SERVO360_2_CH, -50);
    delay(2000);

    Serial.println("360 servos: stop");
    servoSpin(SERVO360_1_CH, 0);
    servoSpin(SERVO360_2_CH, 0);
    delay(1000);
}
