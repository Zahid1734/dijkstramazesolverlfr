void testMotor() {
  drive(255, 255);
  m = millis();
  while(millis() - m < 2000);
  drive(-100, 100);
  m = millis();
  while(millis() - m < 2000);
  drive(100, -100);
  m = millis();
  while(millis() - m < 2000);
  drive(-100, -100);
  m = millis();
  while(millis() - m < 2000);
  drive(0, 0);
}