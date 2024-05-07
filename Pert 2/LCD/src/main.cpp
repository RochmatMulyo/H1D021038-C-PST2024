#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D4;
int SCL_pin = D3;


void setup() {
 Wire.begin(SDA_pin, SCL_pin);
 lcd.init();
 lcd.backlight();

}

void loop() {
 lcd.setCursor(0,0);
 lcd.print("Prak Shift Lainnya");
 lcd.scrollDisplayLeft();
 delay (1000);
 lcd.clear();

 lcd.setCursor(0,1);
 lcd.print("Selasa, 07 Mei 2024");
 lcd.scrollDisplayRight();
 delay (1000);
 lcd.clear();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}