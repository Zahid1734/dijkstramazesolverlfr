void showString() {
  display.clearDisplay();
  display.setCursor(0, 0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      display.print(matrix[i][j]);
      display.print(' ');
    }
    display.println();
  }
  display.println();
  for (int i = 0; i < s.length(); i++) display.print(s[i]);
  display.println();
  for (int i = 0; i < f.length(); i++) display.print(f[i]);
  display.println();
  display.display();
  takeInput();
}