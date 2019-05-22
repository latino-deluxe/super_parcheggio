#define MAIN

#include <Arduino.h>
#include "vars.h"
#include "lights.h"
#include "parkingbar.h"
#include "display.h"
#include "routine.h"


void setup() {
  //Imposto le variabili globali a zero (o al valore iniziale che desidero);
  FRM = 0;                        //variabile media dei fotoresistori
  FR1 = 0;                        //variabile dei fotoresistori
  FR2 = 0;
  VP1 = 0;                        //variabile stato pulsante 
  VIR1 = 0;                       //variabile sensori infrarossi
  VIR2 = 0;
  VIR3 = 0;     
  i = 180;                          //variabile per i cicli for
  posti = 4;                      //posti del parcheggio
  initServo();                    //Inizializzo i servo
  displayInit();                  //Inizializzo Display LCD
  pinMode(FTR1, INPUT);           //Fotoresistori
  pinMode(FTR2, INPUT);
  pinMode(PU1, INPUT);            //Pulsante entrata
  pinMode(IR1, INPUT);            //Ricevitori infrarossi
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(EM, OUTPUT);            //Emettitori infrarossi
  Serial.begin(9600);             //Inizializzo la seriale USB per debug
  //Agisco sui registri dell'ATMEGA per emetterre 36kHz sul pin 11
  TCCR2A = _BV(WGM21) | _BV(COM2A0);
  TCCR2B = _BV(CS20);
  OCR2A = 221;
}

void loop() {
  // routine();                      //Eseguo il loop di istruzioni del parcheggio finale
  parkingBar1();
}
