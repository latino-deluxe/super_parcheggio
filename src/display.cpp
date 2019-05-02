#include "vars.h"
#include "classesD.h"

void displayInit() {                                    //inizializzo il display I2C
  lcd.init();
  lcd.backlight();
}

void displayTEST() {                                    //funzione di test per il display
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

void displayP() {                                       //routine di refresh del display
  lcd.setCursor(0,0);
  lcd.print("Parcheggi");
  lcd.setCursor(0,1);
  lcd.print("liberi :");
  lcd.setCursor(10,1);
  lcd.print(posti);                                     //mostro i posti disponibili
  // lcd.clear();
}
