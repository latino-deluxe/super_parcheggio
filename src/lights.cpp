#include "vars.h"

void isSunnyToday() {                         //controllo se è buio
  FR1 = analogRead(FTR1);                     //leggo i fotoresistori
  if(FR1 < 500) digitalWrite(LIGHTSPIN, HIGH);//scrivo il valore sulle resistenze
  else digitalWrite(LIGHTSPIN, LOW);
}
