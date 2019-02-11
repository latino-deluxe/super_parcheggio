#include "vars.h"

void isSunnyToday() {
  FR1 = analogRead(FTR1);
  FR2 = analogRead(FTR2);
  FRM = ((FR1 + FR2) / 2) / 2;
  analogWrite(LIGHTSPIN, FRM);
}
