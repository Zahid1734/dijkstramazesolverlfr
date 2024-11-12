void obstacle() {
  resetMap();
  for (int i = 1; i <= obstacles; i++) {
    takecoordinate(i);
  }
}

void takecoordinate(int p) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("For Obstacle ");
  display.println(p);
  display.println("1.Node");
  display.println("2.Edge");
  display.println("3.Skip");
  display.print(":");
  display.display();
  takeInput();
  display.print(x);
  display.display();
  m = millis();
  while(millis() - m < 500) ;
  if (x == 1) {
    take_node(p);
  }else if (x == 2) {
    take_edge(p);
  }
}

void take_edge(int p) {
  int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("For Obstacle ");
  display.println(p);
  display.print("X1 coordinate : ");
  display.display();
  takeInput();
  x1 = x;
  display.println(x1);
  display.display();
  display.print("Y1 coordinate : ");
  display.display();
  takeInput();
  y1 = x;
  display.println(y1);
  display.display();
  display.println();
  display.print("X2 coordinate : ");
  display.display();
  takeInput();
  x2 = x;
  display.println(x2);
  display.display();
  display.print("Y2 coordinate : ");
  display.display();
  takeInput();
  y2 = x;
  display.println(y2);
  display.display();
  x1--; y1--; x2--; y2--;
  if(x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 && x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4) {  
    int a = mask[x1][y1];
    int b = mask[x2][y2];
    edge[a][b] = edge[b][a] = 1;
  }
  else {
    take_edge(p);
  }
}

void take_node(int p) {
  int posx = -1, posy = -1;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("For Obstacle ");
  display.println(p);
  display.print("X coordinate: ");
  display.display();
  takeInput();
  posx = x;
  display.print(posx);
  display.println();
  display.display();
  display.print("Y coordinate: ");
  display.display();
  takeInput();
  posy = x;
  display.print(posy);
  display.display();
  m = millis();
  while(millis() - m < 1000);
  if (posx < 1 || posx > 4 || posy < 1 || posy > 4) {
    display.println();
    display.println("Wrong Input!");  
    display.print("Try Again");
    display.display();
    m = millis();
    while(millis() - m < 2000);
    takecoordinate(p);
    return ;
  }
  matrix[posx - 1][posy - 1] = '*';
}

int ask(int p) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Change Obstacle ");
  display.println(p);
  display.println("1.YES");
  display.println("2.NO");
  display.println("::");
  display.display();
  takeInput();
  return x;
}

void increaseObstacle() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("1.Increase By");
  display.println("2.Decrease By");
  display.print("::");
  display.display();
  takeInput();
  int choice = x;
  display.println(x);
  delay(500);
  display.print("Change by ::");
  display.display();
  takeInput();
  display.print(x);
  display.display();
  delay(500);
  if (choice == 1) {
    obstacles += x;
  }else {
    obstacles -= x;
  }
}