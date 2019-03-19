#include "vars.h"

void isSunnyToday() {                         //controllo se è buio
  FR1 = analogRead(FTR1);                     //leggo i fotoresistori
  FR2 = analogRead(FTR2);
  FRM = ((FR1 + FR2) / 2) / 2;                //faccio una media tra i due
  analogWrite(LIGHTSPIN, FRM);                //scrivo il valore sulle resistenze
}
