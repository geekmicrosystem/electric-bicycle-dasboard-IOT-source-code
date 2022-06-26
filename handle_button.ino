int handle_button() {
  int kondisi;
  int button_now_pressed = !digitalRead(b_sleep); // pin low -> pressed

  if (!button_now_pressed && button_was_pressed) {
    if (button_pressed_counter < 200) {
      kondisi = 1; Serial.print("kondisi: "); Serial.println(kondisi);
    }
    else {
      kondisi = 2; Serial.print("kondisi: "); Serial.println(kondisi);
    }
  }
  else {
    kondisi = 0;
  }

  if (button_now_pressed) {
    ++button_pressed_counter; Serial.print(button_pressed_counter);
  }
  else {
    button_pressed_counter = 0;
  }

  button_was_pressed = button_now_pressed;
  return kondisi;
}
