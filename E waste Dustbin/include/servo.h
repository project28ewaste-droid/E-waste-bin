#pragma once

void servoInit();
void servoAngle(int channel, int angle);    // 180 servo: 0 - 180 deg
void servoSpin(int channel, int speed);     // 360 servo: -100 (rev) .. 0 (stop) .. 100 (fwd)
void servoTest();
