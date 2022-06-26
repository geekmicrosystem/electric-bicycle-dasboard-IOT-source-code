void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_SRV_OPEN_EVT) {
    Serial.println("Client Connected");
  } else {
    tft.fillRect(25, 2, 20, 15, ST7735_BLACK);
  }
}
