void drive(int a, int b) {
  if (a > 0) {
    digitalWrite(motor[0], 1);
    digitalWrite(motor[1], 0);
  }
  else if (a < 0) {
    a = -a;
    digitalWrite(motor[0], 0);
    digitalWrite(motor[1], 1);
  }
  else {
    digitalWrite(motor[0], 0);
    digitalWrite(motor[1], 0);
  }
  
  if (b > 0) {
    digitalWrite(motor[2], 1);
    digitalWrite(motor[3], 0);
  }
  else if (b < 0) {
    b = -b;
    digitalWrite(motor[2], 0);
    digitalWrite(motor[3], 1);
  }
  else {
    digitalWrite(motor[2], 0);
    digitalWrite(motor[3], 0);
  }
  
  analogWrite(speedl, a);
  analogWrite(speedr, b);
}
