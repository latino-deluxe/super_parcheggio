#include "vars.h"
#include "classesS.h"

void initServo() {                                      //inizializzo pin servo
  mariottide.attach(12);
  billyballo.attach(13);
}

void checkButton() {                                    //controllo del bottone d'entrata
  VP1 = digitalRead(PU1);               
  if(VP1 == HIGH) {
    entry1 = true;
    delay(10);
  }
  else entry1 = false;
}

void checkIR() {                                        //controllo i sensori infrarossi
  VIR1 = digitalRead(IR1);
  VIR2 = digitalRead(IR2);
  VIR3 = digitalRead(IR3);
  if(VIR1 = 1) entry2 = true;                           //e imposto le variabil di stato
  else entry2 = false;
  if(VIR2 = 1) exit1 = true;
  else exit1 = false;
  if(VIR3 = 1) exit2 = true;
  else exit2 = false;
}

void parkingBar1() {                                    //gestisco la sbarra di entrata
  checkButton();                                        //controllo pulsante
  checkIR();                                            //controllo infrarossi
  if(entry1) for(int i=180; i<=90; i++) {               //se sta entrando
    mariottide.write(i);                                //alzo gradualmente la sbarra
    delay(15);
  }
  if(entry2) mariottide.write(90);                      //mantengo se sta ancora entrando
  if(entry2 == false) for(int i=90; i>=180; i--) {      //se non è più in zona di pericolo
    mariottide.write(i);                                //abbasso gradualmente la sbarra
    delay(15);
    posti--;                                            //diminuisco i posti disponibili
  }
}

void parkingBar2() {                                    //gestisco la sbarra di uscita
  checkIR();                                            //controllo degli infrarossi
  if(exit1) for(int i=90; i<=0; i++) {                  //se sta uscendo
    billyballo.write(i);                                //alzo gradualmente la sbarra
    delay(15);
  }
  if(exit2) mariottide.write(90);                       //mantengo se sta ancora uscendo
  if(exit2 == false) for(int i=0; i>=90; i--) {         //se non è più in zona di pericolo
    billyballo.write(i);                                //abbasso gradualmente la sbarra
    delay(15);
    posti++;                                            //aumento i posti disponibili
  }
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
  if(posti >= 10) posti = 10;                           //se aumenta oltre 10 imposto 10
}

void testSbarra() {
  for(int i=0; i<=90; i++) {
     billyballo.write(i);
     delay(15);
 }
  for(int i=90; i>=0; i--) {      //uscita 90 0
   billyballo.write(i);
   delay(15);
 }
 for(int i=180; i>=90; i--) {     //entrata 180 90
  mariottide.write(i);
  delay(15);
}
 for(int i=90; i<=180; i++) {
    mariottide.write(i);
    delay(15);
}
}
