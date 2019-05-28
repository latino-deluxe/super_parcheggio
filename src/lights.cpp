#include "vars.h"

void isSunnyToday() {                         //controllo se è buio
  FR1 = analogRead(FTR1);                     //leggo i fotoresistori
  analogWrite(LIGHTSPIN, FR1);                //scrivo il valore sulle resistenze
}
