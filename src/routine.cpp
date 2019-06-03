#include "lights.h"
#include "parkingbar.h"
#include "display.h"
#include "vars.h"


void routine() {
  int p;                                      //funzione locale per limitare le sbarre
  isSunnyToday();                             //controllo se c'è luce, accendo lampioni
  updatePosti();                              //leggo pulsanti, aggiorno variabile posti
  p = posti + 1;                              //tengo la variabile locale avanti di uno rispetto ai posti
  if(posti < 0) posti = 0;                    //limito i posti
  if(posti > 4) posti = 4;                    //limito i posti
  if(p > 0) parkingBar1();                    //se i posti vanno a zero alzo la sbarra, poi non la alzo più fino a incremento
  parkingBar2();                              //routine sbarra d'uscita                                 
  displayP();                                 //refresh dello schermo
}