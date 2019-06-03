#include "vars.h"
#include "classesS.h"
#include "display.h"

void initServo() {                                      //inizializzo pin servo
  mariottide.attach(12);                                //servo d'entrata sul pin 12
  billyballo.attach(13);                                //servo d'uscita sul pin 13
  delay(15);
  mariottide.write(180);                                //posizioni di partenza
  billyballo.write(1);
}

void checkButton() {                                    //controllo del bottone d'entrata
  VP1 = digitalRead(PU1);                               
  VP2 = digitalRead(PU2);
}

void checkIR() {                                        //controllo i sensori infrarossi
  VIR1 = digitalRead(IR1);
  VIR2 = digitalRead(IR2);
}

void updatePosti() {                                    //aggiorno e regolo i posti
  checkButton();      
  if(VP1 == 0) posti--;
  if(VP2 == 0) posti++;
  if(posti < 0) posti == 0;
  if(posti > 4) posti == 4;
}

void UP1() {                                            //funzione di salita servo d'entrata
  for(int u = 180; u>=90; u--) {
    mariottide.write(u);
    delay(25);
  }
  AAAAA = true;                                         //aggiorno flag d'entrata
}

void UP2() {                                            //funzione di salita servo d'uscita
  for(int i=0; i<=90; i++) {      
     billyballo.write(i);
     delay(25);
 }
 BBBBB = true;                                          //aggiorno flag d'uscita
}

void DOWN1() {                                          //funzione discesa servo d'entrata
  for(int d = 90; d<=180; d++) {
    mariottide.write(d);
    delay(25);
  }
  AAAAA = false;                                        //aggiorno flag d'entrata
}

void DOWN2() {                                          //funzione discesa servo d'uscita
  for(int i=90; i>=0; i--) {     
   billyballo.write(i);
   delay(25);
 }
  BBBBB = false;                                        //aggiorno flag d'uscita
}


void parkingBar1() {                                    //gestisco la sbarra di entrata
  checkButton();                                        //controllo pulsante
  checkIR();                                            //controllo infrarossi
  if((VP1 == 0) || (VP1 == 0) && (VIR1 == 0)) UP1();    //alzo la sbarra per far entrare la macchina
  if(VIR1) mariottide.write(90);                        //tengo alta la sbarra se la macchina è in transito
  if((VIR1 == 0) && (VP1 == 1)) {                       //se la macchina è passata
    if(AAAAA) DOWN1();                                  //controllo flag d'entrata, impostata da salita
    else mariottide.write(180);                         //altrimenti posizione fissa
  }
}

void parkingBar2() {                                    //gestisco la sbarra di uscita
  checkButton();                                        //controllo pulsante
  checkIR();                                            //controllo infrarossi
  if((VP2 == 0) || (VP2 == 0) && (VIR2 == 0)) UP2();    //alzo la sbarra per far uscire la macchina
  if(VIR2) billyballo.write(90);                        //tengo alta la sbarra se la macchina è in transito
  if((VIR2 == 0) && (VP2 == 1)) {                       //se la macchina è passata
    if(BBBBB) DOWN2();                                  //controllo flag d'uscita, impostata da salita
    else billyballo.write(0);                           //altrimenti posizone fissa
  }
}

void testIR() {                                         //funzione di test IR
  int TIR1;
  int TIR2;
  TIR1 = digitalRead(IR1);                              //leggo e visualizzo in seriale
  TIR2 = digitalRead(IR2);
  Serial.print("IR1 = ");
  Serial.print(TIR1);
  Serial.print("  IR2 = ");
  Serial.println(TIR2);
}


void simCars() {                                        //funzione di simulazione delle macchine
  posti--;
  return;
}

void checkPosti() {                                     //controlo e limito la variabile dei posti
  if(posti <= 0) entrata == false;
  else entrata== true;
}

void testSbarra() {
  for(int i=0; i<=90; i++) {      //salita
     billyballo.write(i);
     delay(15);
 }
 delay(1500);
  for(int i=90; i>=0; i--) {      //discesa
   billyballo.write(i);
   delay(15);
 }
 for(int i=180; i>=100; i--) {     //salita
  mariottide.write(i);
  delay(15);
}
 for(int i=100; i<=180; i++) {      //discesa
    mariottide.write(i);
    delay(15);
}
}
