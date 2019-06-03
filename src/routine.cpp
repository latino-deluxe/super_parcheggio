#include "lights.h"
#include "parkingbar.h"
#include "display.h"
#include "vars.h"


void routine() {
  int p;
  isSunnyToday();
  updatePosti();
  p = posti + 1;
  if(posti < 0) posti = 0;
  if(posti > 4) posti = 4;
  if(p > 0) parkingBar1();
  parkingBar2();
  delay(200);
  displayP();
}