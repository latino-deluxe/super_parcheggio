#include "lights.h"
#include "parkingbar.h"
#include "display.h"
#include "vars.h"


void routine() {
  isSunnyToday();
  checkPosti();
  if(entrata) parkingBar1();
  parkingBar2();
  displayP();
}