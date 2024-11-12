void solve() {
  display.clearDisplay();
  display.setCursor(30, 20);
  display.println("Solving...");
  display.display();
  m = millis();
  while(millis() - m < 1000);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      dist[i][j] = 1000;
      par[i][j] = {-1, -1};
    }
  }
  s = "R";     
  f = "";
  if (matrix[0][0] == '*') {
    noSolve();
    return ;
  }
  dist[0][0] = 0;
  st.insert({0, {0, 0}});
  par[0][0] = {0, 0};
  dijkstra();
  display.setCursor(30, 40);
  display.print("Finished!!!!!");
  display.display();
  m = millis();
  while(millis() - m < 500);
  if(dist[3][3] >= 100) {
    digitalWrite(led, HIGH);
    noSolve();
    digitalWrite(led, LOW);
  }
  
}

void dijkstra() {
  while(!st.empty()) {
    pair<int, pair<int, int>> cur = *st.begin();
    st.erase(st.begin());
    int u = cur.second.first;
    int v = cur.second.second;
    for (int i = 0; i < 4; i++) {
      int xx = u + dx[i];
      int yy = v + dy[i];
      int a = mask[u][v];
      int b = mask[xx][yy];
      if (xx >= 0 && xx < 4 && yy >= 0 && yy < 4) {
        int cost = dist[u][v] + (matrix[xx][yy] == '*' ? 100 : 1);
        if (edge[a][b]) cost = 100;
        if (dist[xx][yy] > cost) {
          pair<int, pair<int, int>> p = make_pair(dist[xx][yy], make_pair(xx, yy)); 
          auto itr = st.find(p);
          if (itr != st.end()) {
            st.erase(itr);
          }
          dist[xx][yy] = cost;
          par[xx][yy] = {u, v};
          p = make_pair(dist[xx][yy], make_pair(xx, yy));
          st.insert(p);
        }
      }
    }
  }
  if (dist[3][3] >= 100) return ;
  pair<int, int> dest = {3, 3};
  while(par[dest.first][dest.second] != dest) {
    pair<int, int> pr = par[dest.first][dest.second];
    s += call(dest, pr);
    dest = pr;
  }
  s += 'R';
  reverse(s.begin(), s.end());
  convert();
}

void convert() {
  char prev = 'R';
  for (int i = 0; i < s.length(); i++) {
    char now = s[i];
    if (prev == now) f += 'F';
    else if (prev == 'R' && now == 'D') f += 'R';
    else if (prev == 'R' && now == 'U') f += 'L';
    else if (prev == 'D' && now == 'R') f += 'L';
    else if (prev == 'D' && now == 'L') f += 'R';
    else if (prev == 'L' && now == 'U') f += 'R';
    else if (prev == 'L' && now == 'D') f += 'L';
    else if (prev == 'U' && now == 'R') f += 'R';
    else if (prev == 'U' && now == 'L') f += 'L';
    prev = now;
  }
}

void noSolve() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("No path to the end!");
  display.display();
  takeInput();
}
char call (pair<int, int> dest, pair<int, int> pr) {
  if (dest.first != pr.first) {
    if (dest.first - 1 == pr.first) return 'D';
    return 'U';
  }
  else {
    if (dest.second - 1 == pr.second) return 'R';
    return 'L';
  }
}