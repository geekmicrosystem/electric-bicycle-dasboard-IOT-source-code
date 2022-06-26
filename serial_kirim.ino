void s_kirim() {
  if (Serial.available() > 0) {
    inChar = (char)Serial.read();
    dataln += inChar;
    if (inChar == '#') {
      parsing = true;
    }
    if (parsing) {
      parsingData();
      dataln = "";
      ind_batteray();
      msg = "*";
      msg = Speed;
      msg = msg + ",";
      msg = msg + TripNow;
      msg = msg + ",";
      msg = msg + OdoNow;
      msg = msg + ",";
      msg = msg + cadence;
      msg = msg + ",";
      msg = msg + maxSpeed;
      msg = msg + ",";
      msg = msg + minSpeed;
      msg = msg + ",";
      msg = msg + a;
      msg = msg + ",";
      msg = msg + b;
      msg = msg + ",";
      msg = msg + torsi;
      msg = msg + ",";
      msg = msg + d;
      msg = msg + ",";
      msg = msg + e;
      msg = msg + ",";
      msg = msg + f;
      msg = msg + ",";
      msg = msg + m_count;
      msg = msg + ",";
      msg = msg + y;
      msg = msg + ",";
      char message[100];      msg.toCharArray(message, 100);
      ESP_BT.print(message);
      parsing = false;
      switch (counter2) {
        case 1:
          display1(); //Serial.println(counter2);
          break;

        case 2:
          display2(); //Serial.println(counter2);
          break;

        case 3:
          display3(); //Serial.println(counter2);
          break;

        default:
          counter2 = 1;
          break;
      }
    }
    d = 0;
  }
}

void setting() {
  if (ESP_BT.available()) {
    char onChar = ESP_BT.read();
    Serial.print(onChar);
    databt += onChar;
    if (onChar == '#') {
      parsing2 = true;
    }
    if (parsing2) {
      parsingData2();
      databt = "";
      parsing2 = false;
    }
  }
}
