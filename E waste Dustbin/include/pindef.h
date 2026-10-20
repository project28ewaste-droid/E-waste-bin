#pragma once

// ===== Sensor ON / OFF =====
// 1 = ON  (init + output)
// 0 = OFF (skipped, no output)

#define USE_PROXIMITY   0
#define USE_OLED        0
#define USE_GAS         0
#define USE_LOADCELL    0
#define USE_RAIN        0
#define USE_SERVO       0
#define USE_TEMP        0
#define USE_BUZZER      0
#define USE_IR          0
#define USE_ULTRASONIC  0

// ===== Pin Definitions =====

#define PROXIMITY_PIN   27

// I2C bus - shared by OLED (0x3C) and PCA9685 servo driver (0x40)
#define I2C_SDA_PIN     21
#define I2C_SCL_PIN     22

// Gas sensor (MQ series, analog out) - use ADC1 pins only (32-39)
#define GAS_PIN         34
#define GAS_THRESHOLD   2000    // 0-4095, tune after testing in clean air

// Load cell (HX711)
#define LOADCELL_DT_PIN     16
#define LOADCELL_SCK_PIN    17
#define LOADCELL_CAL_FACTOR 420.0   // new = old x shown weight / actual weight
#define LOADCELL_ZERO_G     5       // below +/- this (g) show 0

// Rain sensor (digital out DO) - sensitivity set by module's blue pot
#define RAIN_PIN        13

// Servo driver PCA9685 - channel numbers (0-15)
#define SERVO360_1_CH   0       // 360 deg continuous
#define SERVO360_2_CH   7       // 360 deg continuous
#define SERVO180_CH     12      // 180 deg
#define SERVO360_STOP_US 1500   // tune if a 360 servo creeps when it should stop

// Temperature sensor DS18B20 (one-wire, needs 4.7k pull-up DATA->3.3V)
#define TEMP_PIN        4

// Buzzer (active buzzer, HIGH = ON)
#define BUZZER_PIN      15

// IR sensors x2 (digital out, LOW = object detected)
#define IR1_PIN         25
#define IR2_PIN         26

// Ultrasonic HC-SR04 (ECHO is 5V -> use divider 1k/2k to ESP32)
#define ULTRASONIC_TRIG_PIN  18
#define ULTRASONIC_ECHO_PIN  19

// Add next sensor pins here
