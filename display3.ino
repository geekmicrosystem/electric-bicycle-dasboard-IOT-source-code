void display3() {
  String OdoString = String(OdoNow, 1);
  OdoString.toCharArray(OdoChar, 10);
  tft.fillRect(10, 50, 110, 14, ST7735_BLACK);
  tft.setFont(&DejaVu_Sans_Bold_11);
  tft.setTextSize(1);
  if (y == 1) {
    testdrawtext("Odo (Mil)", ST7735_WHITE, 32, 60);
  } else {
    testdrawtext("Odo (Km)", ST7735_WHITE, 32, 60);
  }
  if (OdoNow < 100) {
    tft.fillRect(5, 65, 113, 38, ST7735_BLACK);
    tft.setFont(&DSEG7_Classic_Bold_35);
    tft.setTextSize(1);
    if (OdoNow >= 10) {
      tft.setTextSize(1);
      testdrawtext(OdoChar, ST7735_WHITE, 15, 100);
      tft.setFont();
    } if (OdoNow < 10) {
      tft.setTextSize(1);
      testdrawtext(OdoChar, ST7735_WHITE, 30, 100);
      tft.setFont();
    }
  } if (OdoNow >= 100) {
    tft.setFont(&DSEG7_Classic_Bold_26);
    tft.setTextSize(1);
    tft.fillRect(10, 65, 108, 38, ST7735_BLACK);
    tft.setTextSize(1);
    testdrawtext(OdoChar, ST7735_WHITE, 15, 100);
    tft.setFont();
  }
}
