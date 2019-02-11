#define MAIN

#include <Arduino.h>
#include "vars.h"
#include "lights.h"

Servo mariottide;

void setup() {
  FRM = 0;
  FR1 = 0;
  FR2 = 0;
  mariottide.attach(9);
  pinMode(FTR1, INPUT);
  pinMode(FTR2, INPUT);
  Serial.begin(9600);
}

void loop() {
  isSunnyToday();
}
