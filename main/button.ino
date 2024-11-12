int buttonRead() {
  int val = 0;
  while(true) {
    int t = 0;
    if (digitalRead(button) == 0) {
      digitalWrite(led, 1);
      while(!digitalRead(button)) {
        delay(1); t++;
      }
      digitalWrite(led, 0);
    }
    if (t > 10) {
      t = 0, val++;
      while(digitalRead(button)) {
        delay(1); t++;
        if (t > 1000) return val;
      }
      continue;
    }else break;
  }
  return val;
}