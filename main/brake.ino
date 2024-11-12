void brake() {
  drive(0, 0);
  drive(-10 * lbase , -10 * rbase);
  m = millis();
  while(millis() - m < braketime) ;
  drive(0, 0);
}