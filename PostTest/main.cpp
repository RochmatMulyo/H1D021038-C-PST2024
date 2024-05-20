#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D4;
int SCL_pin = D3;
int red = D5;
int green = D7;

//inisialisasi pin LED dan LCD nya
void setup() {
 Wire.begin(SDA_pin, SCL_pin);
 lcd.init();
 lcd.backlight();
 pinMode (red, OUTPUT);
 pinMode (green, OUTPUT);

}

//buat program untuk menyalakan LED bergantian setiap 5 detik
void loop() {
digitalWrite(green, HIGH);
digitalWrite(red, LOW);
delay (5000);
digitalWrite(green, LOW);
digitalWrite(red, HIGH);
delay (5000);
//jika yang menyala LED merah, LCD akan menampilkan teks LED Merah
//Jika yang menyala LED hijau, LCD akan menampilkan teks LED Hijau
 if (red == HIGH){
    lcd.setCursor(0,0);
    lcd.print(" LED Merah");
    delay(5000);
 }else{
    lcd.setCursor(0,0);
    lcd.print("LED Hijau");
    delay(5000);
 }
 


}