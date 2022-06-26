void display2() {
  String TripString = String(TripNow, 1);
  TripString.toCharArray(TripChar, 10);
  tft.fillRect(10, 50, 110, 14, ST7735_BLACK);
  tft.setFont(&DejaVu_Sans_Bold_11);
  tft.setTextSize(1);
  if (y == 1) {
    testdrawtext("Trip (Mil)", ST7735_WHITE, 32, 60);
  } else {
    testdrawtext("Trip (Km)", ST7735_WHITE, 32, 60);
  }
  if (TripNow < 100) {
    tft.fillRect(5, 65, 113, 38, ST7735_BLACK);
    tft.setFont(&DSEG7_Classic_Bold_35);
    tft.setTextSize(1);
    if (TripNow >= 10) {
      tft.setTextSize(1);
      testdrawtext(TripChar, ST7735_WHITE, 15, 100);
      tft.setFont();
    } if (TripNow < 10) {
      tft.setTextSize(1);
      testdrawtext(TripChar, ST7735_WHITE, 30, 100);
      tft.setFont();
    }
  } if (TripNow >= 100) {
    tft.setFont(&DSEG7_Classic_Bold_26);
    tft.setTextSize(1);
    tft.fillRect(5, 65, 113, 38, ST7735_BLACK);
    tft.setTextSize(1);
    testdrawtext(TripChar, ST7735_WHITE, 15, 100);
    tft.setFont();
  }
}
