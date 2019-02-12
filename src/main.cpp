#define MAIN

#include <Arduino.h>
#include "vars.h"
#include "lights.h"
#include "parkingbar.h"


void setup() {
  FRM = 0;
  FR1 = 0;
  FR2 = 0;
  VP1 = 0;
  VIR1 = 0;
  VIR2 = 0;
  VIR3 = 0;
  initServo();
  pinMode(FTR1, INPUT);
  pinMode(FTR2, INPUT);
  pinMode(PU1, INPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  Serial.begin(9600);
}

void loop() {
  isSunnyToday();
  parkingBar1();
  parkingBar2();
}
