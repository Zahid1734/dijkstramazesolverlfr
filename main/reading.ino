void reading() {
  pos = 0;
  tot = 0;
  for (int i = 0; i < 6; i++) {
    int black = 1;
    int x = analogRead(sensor[i]);
    if (x <= mid[i]) {
      black = 0;
    }
    data[i] = black;
    pos += black * base[i];
    tot += black;
  }
}

void callibration() {
  for (int i = 0; i < 6; i++) {
    mx[i] = 0; mn[i] = 1023;
  }
  delay(1000);
  drive(-100, 100);
  digitalWrite(led, 1);
  for (int i = 0; i < 10000; i++) {
    for (int i = 0; i < 6; i++) {
      int x = analogRead(sensor[i]);
      mx[i] = max(x, mx[i]);
      mn[i] = min(x, mn[i]);
    }
   
  }
  drive(0, 0);
  digitalWrite(led, 0);
  for (int i = 0; i < 6; i++) {
    mid[i] = (mx[i] + mn[i]) / 2;
    EEPROM.write(i, mid[i] / 4);  delay(15); // delay is given to write the input correctly to the EEPROM
    EEPROM.write(i + 6, mx[i] / 4); delay(15);
    EEPROM.write(i + 12, mn[i] / 4); delay(15);
  }
}