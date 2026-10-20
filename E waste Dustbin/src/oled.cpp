#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "pindef.h"
#include "oled.h"

// 1.3" OLED = SH1106 128x64, I2C
// If display shows garbage / shifted, try U8G2_SSD1306_128X64_NONAME_F_HW_I2C
U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);

void oledInit() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    display.begin();

    oledShow("E-Waste Dustbin", "Starting...");
    Serial.println("OLED ready");
}

void oledShow(const char *line1, const char *line2) {
    display.clearBuffer();
    display.setFont(u8g2_font_ncenB08_tr);
    display.drawStr(0, 20, line1);
    display.drawStr(0, 45, line2);
    display.sendBuffer();
}
