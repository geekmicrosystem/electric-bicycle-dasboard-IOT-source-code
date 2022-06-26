void parsingData() {
  int j = 0;
  dt[j] = "";
  
  for (i = 1; i < dataln.length(); i++) {
    //pengecekan tiap karakter dengan karakter (#) dan (,)
    if ((dataln[i] == '#') || (dataln[i] == ','))
    {
      j++;
      dt[j] = "";
    }
    else
    {
      dt[j] = dt[j] + dataln[i];
    }
  }

  a = dt[0].toInt();
  b = dt[1].toInt();
  c = dt[2].toFloat();
  d = dt[3].toInt();
  e = dt[4].toFloat();
  f = dt[5].toFloat();

  rpm = d / 360;
  cadence = b / 1920;
  batt = ((f*0.00489)*16.03);
  if (y == 1) {
    Speed = rpm * keliling * 2.237 / 60; //Sudah MPH
  } else {
    Speed = rpm * keliling * 3.6 / 60; //Sudah KM/H
  }
  Trip = d / 6 * keliling / 1000 / 3600;
  TripNow  = TripNow + Trip;
  OdoNow = OdoNow + Trip;
  torsi = c / 3.3 * 80;

  EEPROM.writeFloat(0, OdoNow);
  EEPROM.commit();
}

void parsingData2() {
  int k = 0;
  db[k] = "";

  for (l = 1; l < databt.length(); l++) {
    //pengecekan tiap karakter dengan karakter (#) dan (,)
    if ((databt[l] == '#') || (databt[l] == ','))
    {
      k++;
      db[k] = "";
    }
    else
    {
      db[k] = db[k] + databt[l];
    }
  }

  x = db[0].toFloat();
  y = db[1].toInt();
  keliling = x;
  Serial.print("X : "); Serial.println(x);
  Serial.print("Y : "); Serial.println(y);
}
