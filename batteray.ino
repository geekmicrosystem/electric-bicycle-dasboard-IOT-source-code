void ind_batteray() {
  String BattString = String(batt, 1);
  BattString = BattString + "V";
  BattString.toCharArray(charBatteray, 10);
  tft.fillRect(26, 0, 43, 12, ST7735_BLACK);
  tft.setFont(&Aclonica_Regular_12);
  tft.setTextSize(1);
  testdrawtext(charBatteray, ST7735_WHITE, 26, 10);
  tft.drawRect(0, 0 , 24, 44, ST7735_WHITE);
  tft.fillRect(2, 2 , 20, 40, ST7735_BLACK);
  if (batt > 39.2) {
    tft.fillRect(2, 2 , 20, 7, ST7735_CYAN);
    tft.fillRect(2, 11 , 20, 6, ST7735_GREEN);
    tft.fillRect(2, 19 , 20, 6, ST7735_YELLOW);
    tft.fillRect(2, 27 , 20, 6, ST7735_ORANGE);
    tft.fillRect(2, 35 , 20, 6, ST7735_RED);
  }
  else if (batt > 37.5 && batt <= 39.2) {
    tft.fillRect(2, 11 , 20, 6, ST7735_GREEN);
    tft.fillRect(2, 19 , 20, 6, ST7735_YELLOW);
    tft.fillRect(2, 27 , 20, 6, ST7735_ORANGE);
    tft.fillRect(2, 35 , 20, 6, ST7735_RED);
  }
  else if (batt > 36.5 && batt <= 37.5) {
    tft.fillRect(2, 19 , 20, 6, ST7735_YELLOW);
    tft.fillRect(2, 27 , 20, 6, ST7735_ORANGE);
    tft.fillRect(2, 35 , 20, 6, ST7735_RED);
  }
  else if (batt > 35.5 && batt <= 36.5) {
    tft.fillRect(2, 27 , 20, 6, ST7735_ORANGE);
    tft.fillRect(2, 35 , 20, 6, ST7735_RED);
  }
  else if (batt <= 35.5) {
    tft.fillRect(2, 35 , 20, 6, ST7735_RED);
  }
}
