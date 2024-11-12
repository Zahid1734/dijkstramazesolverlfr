
void showMenu() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("1.Solve");
  display.println("2.Modify Obstacles");
  display.println("3.Show Map");
  display.println("4.Follow");
  display.println("5.Callibration");
  display.println("6.Show Reading");
  display.println("7.Test Motor");
  display.println("8.Change Obs Num");
  display.display();
  takeInput();
  switch(x) {
    case 1:
      solve();
      break;
    case 2:
      obstacle();
      break;
    case 3:
      showString();
      break;
    case 4:
      lineFollow();
      break;
    case 5:
      callibration();
      break;
    case 6:
      sensorReading();
      break;
    case 7:
      testMotor();
      break;
    case 8:
      increaseObstacle();
  }
}