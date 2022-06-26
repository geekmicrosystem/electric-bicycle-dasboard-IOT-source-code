void testdrawtext(char *text, uint16_t color, uint16_t x, uint16_t y) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
