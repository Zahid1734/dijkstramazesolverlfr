void sensorReading() {
  do {
    display.clearDisplay();
    display.setCursor(0, 0);
    reading();
    for (int i = 0; i < 6; i++) {
      display.print(data[i]);
      display.print(' ');
    }
    display.println();
    display.display();
  } while(!buttonRead());
}