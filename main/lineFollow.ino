void lineFollow() {
  for (int i = 0; i < f.length(); i++) {
    char now = f[i];
    if (now == 'R' || now == 'L') {
      changedirection(now);
      FF();
    }
    else FF();
  }
  m = millis();
  while(millis() - m < stoptime) ;
  brake();
}

void changedirection(char dirr) {
  (dirr == 'L' ? drive((int)(-nodespeed * lbase), (int)(nodespeed * rbase)) : drive((int)(nodespeed * lbase), (int)(-nodespeed * rbase)));
  reading();
  while(tot > 0) reading();
  reading();
  while(data[2] + data[3] < 2) reading();
  m = millis();
  while(millis() - m < 5);
  nodebalance(dirr);
  
}

void FF() {
  while(true) {
    reading();
    if (tot < 3) {
      if (pos == B001100) {
        drive(10 * lbase, 10 * rbase);
      }
      // car is tilted towards right
      else if (pos == B000100) {
        drive(7 * lbase, 10 * rbase);
      }
      else if (pos == B000110) {
        drive(4 * lbase, 10 * rbase);
      }
      else if (pos == B000010) {
        drive(0 * lbase, 10 * rbase);
      }
      else if (pos == B000011) {
        drive(-2 * lbase, 10 * rbase);
      }
      else if (pos == B000001) {
        drive(-5 * lbase, 10 * rbase);
      }
      
      //car is tilted towards left
      else if (pos == B001000) {
        drive(10 * lbase, 7 * rbase);
      }
      else if (pos == B011000) {
        drive(10 * lbase,4 * rbase);
      }
      else if (pos == B010000) {
        drive(10 * lbase, 0 * rbase);
      }
      else if (pos == B110000){
          drive(10 * lbase, -2 * rbase);
      }
      else if (pos == B100000) {
        drive(10 * lbase, -5 * rbase);
      }
      
    }
    else {
      m = millis();
      while(millis() - m < nodedelay);
      brake();
      return ;
    }
  }
}

void nodebalance(char ch) {
  (ch == 'L' ? drive((int)(balancespeed * lbase), (int)(-balancespeed * rbase)) : drive((int)(-balancespeed * lbase), (int)(balancespeed * rbase)));
  m = millis();
  while(millis() - m <= balancetime) ; 
  brake();
}

