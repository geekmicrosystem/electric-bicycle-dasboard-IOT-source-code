void display1() {
  bar_kosong();
  String SpeedString = String(Speed, 1);
  SpeedString.toCharArray(SpeedChar, 10);
  tft.fillRect(10, 50, 110, 14, ST7735_BLACK);
  tft.setFont(&DejaVu_Sans_Bold_11);
  tft.setTextSize(1);
  if (y == 1) {
    testdrawtext("SPEED (MPH)", ST7735_WHITE, 15, 60);
  } else {
    testdrawtext("SPEED (Km/H)", ST7735_WHITE, 15, 60);
  }
  tft.setFont(&DSEG7_Classic_Bold_35);
  tft.fillRect(5, 65, 113, 38, ST7735_BLACK);
  tft.setTextSize(2);
  if (Speed >= 10) {
    tft.setTextSize(1);
    testdrawtext(SpeedChar, ST7735_WHITE, 15, 100);
    tft.setFont();
  } if (Speed < 10) {
    tft.setTextSize(1);
    testdrawtext(SpeedChar, ST7735_WHITE, 30, 100);
    tft.setFont();
  }

  if (Speed < 4 && Speed >= 1) {
    bar1();
  }
  if (Speed >= 4) {
    bar2();
  }
  if (Speed >= 6) {
    bar3();
  }
  if (Speed >= 8) {
    bar4();
  }
  if (Speed >= 10) {
    bar5();
  }
  if (Speed >= 12) {
    bar6();
  }
  if (Speed >= 14) {
    bar7();
  }
  if (Speed >= 16) {
    bar8();
  }
  if (Speed >= 17) {
    bar9();
  }
  if (Speed >= 18) {
    bar10();
  }
  if (Speed >= 19) {
    bar11();
  }
  if (Speed >= 20) {
    bar12();
  }
  if (Speed >= 21) {
    bar13();
  }
  if (Speed >= 22) {
    bar14();
  }
  if (Speed >= 23) {
    bar15();
  }
  if (Speed >= 24) {
    bar16();
  }
  if (Speed >= 25) {
    bar17();
  }
  if (Speed > 26 ) {
    bar18();
  }
  if (Speed < 1 ) {
    bar_kosong();
  }

  if (Speed != previousSpeed)
  {
    previousSpeed = Speed;
    if (Speed > maxSpeed)
    {
      maxSpeed = Speed;
      dtostrf(maxSpeed, 5, 1, charMaxSpeed);
      tft.fillRect(3, 139, 42, 35, ST7735_BLACK);
      tft.setFont(&FreeSansOblique9pt7b);
      tft.setTextSize(1);
      testdrawtext(charMaxSpeed, ST7735_WHITE, 3, 154);
      //      testdrawtext("Km/H", ST7735_WHITE, 35, 145);
    }
    if (Speed  < minSpeed)
    {
      minSpeed = Speed;
      dtostrf(minSpeed, 5, 1, charMinSpeed);
      tft.fillRect(58, 139, 70, 35, ST7735_BLACK);
      tft.setFont(&FreeSansOblique9pt7b);
      tft.setTextSize(1);
      testdrawtext(charMinSpeed, ST7735_WHITE, 80, 154);
    }
  }
}
