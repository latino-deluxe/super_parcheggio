#include "vars.h"

void isSunnyToday() {                         //controllo se è buio
  FR1 = analogRead(FTR1);                     //leggo i fotoresistori
  if(FR1 > 350) analogWrite(LIGHTSPIN, 750);  //se supero il valore di riferimento do potenza ai lampioni
  else analogWrite(LIGHTSPIN, 0);             //altrimenti lampioni spenti
}
