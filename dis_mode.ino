void dis_mode() {
  if (m_count == 1) {
    tft.fillRect(60, 18, 65, 28, ST7735_BLACK);
    tft.setFont(&FreeSansOblique9pt7b);
    tft.setTextSize(1);
    testdrawtext("ECO", ST7735_WHITE, 65, 40);
  }
  if (m_count == 2) {
    tft.fillRect(60, 18, 65, 28, ST7735_BLACK);
    tft.setFont(&FreeSansOblique9pt7b);
    tft.setTextSize(1);
    testdrawtext("TRAIL", ST7735_WHITE, 60, 40);
  }
  if (m_count == 3) {
    tft.fillRect(60, 18, 65, 28, ST7735_BLACK);
    tft.setFont(&FreeSansOblique9pt7b);
    tft.setTextSize(1);
    testdrawtext("BOOST", ST7735_WHITE, 60, 40);
  }
}
