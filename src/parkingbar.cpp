#include "vars.h"
#include "classesS.h"

void initServo() {
  mariottide.attach(9);
  billyballo.attach(10);
}

void checkButton() {
  VP1 = digitalRead(PU1);
  if(VP1 == HIGH) {
    entry1 = true;
    delay(10);
  }
  else entry1 = false;
}

void checkIR() {
  VIR1 = digitalRead(IR1);
  VIR2 = digitalRead(IR2);
  VIR3 = digitalRead(IR3);
  if(VIR1 = 1) entry2 = true;
  else entry2 = false;
  if(VIR2 = 1) exit1 = true;
  else exit1 = false;
  if(VIR3 = 1) exit2 = true;
  else exit2 = false;
}

void parkingBar1() {
  checkButton();
  checkIR();
  if(entry1) for(int i=0; i<=90; i++) {
    mariottide.write(i);
    // delay(5);
  }
  if(entry2) mariottide.write(90);
  if(entry2 == false) for(int i=90; i>=0; i--) {
    mariottide.write(i);
    // delay(5);
    posti--;
  }
}

void parkingBar2() {
  checkIR();
  if(exit1) for(int i=0; i<=90; i++) {
    mariottide.write(i);
    // delay(5);
  }
  if(exit2) mariottide.write(90);
  if(exit2 == false) for(int i=90; i>=0; i--) {
    mariottide.write(i);
    // delay(5);
    posti++;
  }
}

void testIR() {
  int TIR1;
  int TIR2;
  int TIR3;
  TIR1 = digitalRead(IR1);
  TIR2 = digitalRead(IR2);
  TIR3 = digitalRead(IR3);
  Serial.print("IR1 = ");
  Serial.print(TIR1);
  Serial.print("  IR2 = ");
  Serial.print(TIR2);
  Serial.print("  IR3 = ");
  Serial.println(TIR3);
}


void simCars() {
  int s;
  s = digitalRead(12);
  if(s == HIGH) posti++;
  if(s == LOW) posti--;
}
