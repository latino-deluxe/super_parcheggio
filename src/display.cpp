#include "vars.h"
#include "classesD.h"

void displayInit() {
  lcd.init();
  lcd.backlight();
}

void displayTEST() {
  lcd.setCursor(0,0);
  lcd.print("Parcheggi");

  lcd.setCursor(0,1);
  lcd.print("occupati :");

  lcd.setCursor(10,1);
  for(i=1; i<=5; i++) {
    lcd.print(i);
    delay(100);
  }
  if(i>5){
    delay(300);
    i=0;
  }
  lcd.clear();
}

void displayP() {
  lcd.setCursor(0,0);
  lcd.print("Parcheggi");
  lcd.setCursor(0,1);
  lcd.print("occupati :");
  lcd.setCursor(10,1);
  lcd.print(posti);
  // lcd.clear();
}
