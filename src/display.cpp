#include "vars.h"
#include "classesD.h"

void displayInit() {                                    //inizializzo il display I2C
  lcd.init();                                           //fa partire la comunicazione
  lcd.backlight();                                      //accende la backlight dell'LCD
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
if(posti > 0) {
  delay(200);                                           //delay di refresh
  lcd.clear();                                          //pulisco il buffer dello schermo
  lcd.setCursor(0,0);                                   //imposto il cursore a prima riga prima colonna
  lcd.print("Parcheggi");
  lcd.setCursor(0,1);                                   //imposto il cursore a seconda riga prima colonna
  lcd.print("liberi :");
  lcd.setCursor(11,1);                                  //imposto il cursore a seconda riga undicesima colonna
  lcd.print(posti);                                     //mostro i posti disponibili
}
if(posti == 0) {
  delay(200);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Parcheggio");
  lcd.setCursor(2, 1);
  lcd.print("al completo");
}
}

void refresh(){
  lcd.clear();                                          //pulisco il buffer dello schermo
}
