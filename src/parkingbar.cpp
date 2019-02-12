#include "vars.h"
#include "classes.h"

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
  VIR1 = analogRead(IR1);
  VIR2 = analogRead(IR2);
  VIR3 = analogRead(IR3);
  if(VIR1<500) entry2 = true;
  else entry2 = false;
  if(VIR2<500) exit1 = true;
  else exit1 = false;
  if(VIR3<500) exit2 = true;
  else exit2 = false;
}

void parkingBar1() {
  checkButton();
  checkIR();
  if(entry1) for(int i=0; i<=90; i++) {
    mariottide.write(i);
    delay(5);
  }
  if(entry2) mariottide.write(90);
  if(entry2 == false) for(int i=90; i>=0; i--) {
    mariottide.write(i);
    delay(5);
  }
}

void parkingBar2() {
  checkIR();
  if(exit1) for(int i=0; i<=90; i++) {
    mariottide.write(i);
    delay(5);
  }
  if(exit2) mariottide.write(90);
  if(exit2 == false) for(int i=90; i>=0; i--) {
    mariottide.write(i);
    delay(5);
  }
}
