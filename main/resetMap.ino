void resetMap() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j] = '.';
    }
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      edge[i][j] = 0;
    }
  }
}