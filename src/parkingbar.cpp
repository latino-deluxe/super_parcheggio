#include "vars.h"
#include "classesS.h"

void initServo() {                                      //inizializzo pin servo
  mariottide.attach(12);
  billyballo.attach(13);
}

void checkButton() {                                    //controllo del bottone d'entrata
  VP1 = digitalRead(PU1);  
}

void checkIR() {                                        //controllo i sensori infrarossi
  VIR1 = digitalRead(IR1);
  VIR2 = digitalRead(IR2);
  VIR3 = digitalRead(IR3);
}

void UP1() {
  for(int u = 180; u>=90; u--) {
    mariottide.write(u);
    delay(25);
  }
  AAAAA = true;
}

void UP2() {
  for(int u = 1; u<=90; u++) {
    billyballo.write(u);
    delay(25);
  }
}

void DOWN1() {
  for(int d = 90; d<=180; d++) {
    mariottide.write(d);
    delay(25);
  }
  AAAAA = false;
}

void DOWN2() {
  for(int d = 90; d>=1; d--) {
    billyballo.write(d);
    delay(25);
  }
}


void parkingBar1() {                                    //gestisco la sbarra di entrata
  checkButton();                                        //controllo pulsante
  checkIR();                                            //controllo infrarossi
  if((VP1 == 1) || (VP1 == 1) && (VIR1 == 0)) UP1();
  if(VIR1) mariottide.write(90);
  if((VIR1 == 0) && (VP1 == 0)) {
    if(AAAAA) DOWN1();
    else mariottide.write(180);
  }
}

void parkingBar2() {                                    //gestisco la sbarra di uscita
  checkIR();                                            //controllo degli infrarossi
  // if((VIR2 ==1) || (VIR2 == 1) && (VIR3 == 0)) UP2();
  // if(VIR3) billyballo.write(90);
  // if((VIR3 == 0) && (VIR2 == 0)) billyballo.write(1);
  if(VIR2) UP2();
  else billyballo.write(1);
}

void testIR() {                                         //funzione di test IR
  int TIR1;
  int TIR2;
  int TIR3;
  TIR1 = digitalRead(IR1);                              //leggo e visualizzo in seriale
  TIR2 = digitalRead(IR2);
  TIR3 = digitalRead(IR3);
  Serial.print("IR1 = ");
  Serial.print(TIR1);
  Serial.print("  IR2 = ");
  Serial.print(TIR2);
  Serial.print("  IR3 = ");
  Serial.println(TIR3);
}


void simCars() {                                        //funzione di simulazione delle macchine
  posti--;
  return;
}

void checkPosti() {                                     //controlo e limito la variabile dei posti
  if(posti <= 0)  posti = 0;                            //se va sottozero limito a zero
  if(posti == -1) posti++;                              //perchè si prende il limite a -1???
  if(posti >= 4) posti = 4;                             //se aumenta oltre 4 imposto 4
}

void testSbarra() {
//   for(int i=0; i<=90; i++) {
//      billyballo.write(i);
//      delay(15);
//  }
//   for(int i=90; i>=0; i--) {      //uscita 90 0
//    billyballo.write(i);
//    delay(15);
//  }
 for(int i=180; i>=100; i--) {     //entrata 180 90
  mariottide.write(i);
  delay(15);
}
 for(int i=100; i<=180; i++) {
    mariottide.write(i);
    delay(15);
}
}
