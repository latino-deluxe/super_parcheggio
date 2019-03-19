#define MAIN

#include <Arduino.h>
#include "vars.h"
#include "lights.h"
#include "parkingbar.h"
#include "display.h"


void setup() {
  displayInit();
  FRM = 0;
  FR1 = 0;
  FR2 = 0;
  VP1 = 0;
  VIR1 = 0;
  VIR2 = 0;
  VIR3 = 0;
  i = 0;
  posti = 0;
  initServo();
  pinMode(FTR1, INPUT);
  pinMode(FTR2, INPUT);
  pinMode(PU1, INPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(EM, OUTPUT);
  //REGISTRI
  TCCR2A = _BV(WGM21) | _BV(COM2A0);
  TCCR2B = _BV(CS20);
  OCR2A = 221;
  Serial.begin(9600);
}

void loop() {
  // isSunnyToday();
  // parkingBar1();
  // parkingBar2();
  // displayP();
  // simCars();
  // testSbarra();
  delay(200);
}
