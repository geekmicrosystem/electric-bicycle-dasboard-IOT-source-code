void interupt() {
  currentState1 = digitalRead(b_plus);
  currentState2 = digitalRead(b_min);

  int kondisi = handle_button();
  switch (kondisi) {
    case 1:
      EEPROM.write(0, 0);
      EEPROM.commit();
      OdoNow = 0;
      z = 0;
      Serial.println("Odo Reset");
      z = EEPROM.read(0);
      Serial.print("Odo: ");
      Serial.println(z, 2);
      break;
    case 2:
      EEPROM.writeFloat(10, keliling);
      EEPROM.write(15, y);
      EEPROM.commit();
      Serial.println(OdoNow);
      Serial.println(keliling);
      Serial.println(y);
      Serial.println("ESP32 going to Deep Sleep");
      tft.initR(INITR_BLACKTAB);
      tft.fillScreen(ST7735_BLACK);
      esp_deep_sleep_start();
      break;
  }

  if (currentState1 == HIGH && lastState1 == LOW) {
    c5 = 0;
    if (currentState1 == HIGH && lastState1 == LOW) {
      delay(10);
      counter++; p_mode = true;
    } else if (currentState1 == LOW && lastState1 == HIGH) {
      delay(10);
    }

    switch (counter) {
      case 1:
        m_count = 1; Serial.print("Mode: "); Serial.println(m_count); Serial2.print(m_count);
        break;

      case 2:
        m_count = 2; Serial.print("Mode: "); Serial.println(m_count); Serial2.print(m_count);
        break;

      case 3:
        m_count = 3; Serial.print("Mode: "); Serial.println(m_count); Serial2.print(m_count);
        counter = 0;
        break;
    }

    if (p_mode) {
      p_mode = false;
      dis_mode();
    }
  }

  if (currentState2 == HIGH && lastState2 == LOW) {
    counter2 ++; Serial.print(counter2);
    c5, c1 = 0;
    delay(1);
  } else if (currentState2 == LOW && lastState2 == HIGH) {
    delay(10);
  }
}
