#include "vars.h"

void isSunnyToday() {                         //controllo se è buio
  FR1 = analogRead(FTR1);                     //leggo i fotoresistori
  if(FR1 > 650) analogWrite(LIGHTSPIN, 750);//scrivo il valore sulle resistenze
  else analogWrite(LIGHTSPIN, 0);
}
