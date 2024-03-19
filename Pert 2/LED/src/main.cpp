#include <Arduino.h>

// put function declarations here:

int red = D5;
int green = D7;
int yellow = D6;

void setup() {
  // put your setup code here, to run once:

  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (yellow, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(100);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(100);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}