#include "vars.h"
#include "classesD.h"

void displayInit() {                                    //inizializzo il display I2C
  lcd.init();
  lcd.backlight();
}

void displayTEST() {                                    //funzione di test per il display
  
  for(i=1; i<=15; i++) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Parcheggi");

    lcd.setCursor(0,1);
    lcd.print("occupati :");

    lcd.setCursor(11,1);
    lcd.print(i);
    delay(300);
  }
  if(i>15){
    delay(300);
    i=0;
  }
  
}

void displayP() {                                       //routine di refresh del display
  lcd.clear();                                          //pulisco il buffer per riscrivere il display
  lcd.setCursor(0,0);
  lcd.print("Parcheggi");
  lcd.setCursor(0,1);
  lcd.print("liberi :");
  lcd.setCursor(11,1);
  lcd.print(posti);                                     //mostro i posti disponibili
}
