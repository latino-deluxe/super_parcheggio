void checkButton() {
  V1 = digitalRead(PU1);
  if(V1 == HIGH) {
    entry1 = true;
    delay(10);
  }
  else entry1 = false;
}

void checkIR() {
  VIR1 = analogRead(IR1);
  VIR2 = analogRead(IR2);
  VIR3 = analogRead(IR3);
  if(VIR1<500) entry2 = true;
  else entry2 = false;
}

void parkingBar1() {
  checkButton();
  if(entry1) for(int i=0; i<=90; i++) mariottide.write(i);

}
