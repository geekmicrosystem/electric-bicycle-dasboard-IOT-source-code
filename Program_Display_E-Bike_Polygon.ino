#include "BluetoothSerial.h" //Library Bluetooth ESP32
#include <Adafruit_ST7735.h> //Library LCD TFT 1.8 Inch ST7735
#include <Adafruit_GFX.h>
#include <Fonts\DSEG7_Classic_Bold_35.h> //Font 
#include <Fonts\DSEG7_Classic_Bold_26.h> //font
#include <Fonts\FreeSansOblique9pt7b.h> //font
#include <Fonts\DejaVu_Sans_Bold_11.h> //font
#include <Fonts\Aclonica_Regular_12.h> //font
#include <Wire.h>
#include <SPI.h>
#include "bitmap.h" //file header logo polygon yang berada di tab bitmap.h
#include "EEPROM.h" ////Library EEPROM tulis dan baca pada EEPROM

#define BUTTON_PIN_BITMASK 0x200000000 // Pin Wake up (33) pada ESP32
#define TFT_CS  5 // Pin CS LCD pada GPIO 5
#define TFT_DC  2 // Pin DC/A0 LCD pada GPIO 2
#define TFT_RST 4 // Pin RST LCD pada GPIO 4
#define TFT_SCLK 18   // Pin SCLK LCD pada GPIO18
#define TFT_MOSI 23   // Pin MOSI LCD pada GPIO23
#define LONGPRESS_LEN 100 // Panjang hitungan tekanan panjang button 100

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
RTC_DATA_ATTR int bootCount = 0;
BluetoothSerial ESP_BT; //Object ESP_BT Bluetooth

char charMinSpeed[10];
char charMaxSpeed[10];
char SpeedChar[10];
char charBatteray[10];
char TripChar[10];
char OdoChar[10];
char inChar;

float z;
float cadence = 0;
float Odo = 0;
float Trip = 0;
float Speed = 0;
float torsi = 0;
float previousSpeed = 0;
float previousTrip = 0;
float TripNow = 0;
float OdoNow = 0.0;
float batt = 0;
float maxSpeed = 0;
float minSpeed = 100;
float batteray = 0;
float c, e, f, x = 0;
float keliling = 0.0;

const int b_sleep = 33;
const int b_min = 27;
const int b_plus = 26;

int m_count = 0;
int counter = 0;
int counter2 = 0;
int c5 = 0;
int c1 = 0;
int rpm = 0;
int a, b, d , y = 0;
int i, l;
int button_pressed_counter;

String dataln;
String databt;
String dt[10];
String db[10];
String msg;

boolean parsing = false;
boolean parsing2 = false;
boolean p_mode = false;
boolean currentState1 = LOW;
boolean lastState1 = LOW;
boolean currentState2 = LOW;
boolean lastState2 = LOW;
boolean currentState3 = LOW;
boolean lastState3 = LOW;
boolean button_was_pressed;

void setup() {
  Serial.begin(9600);
  EEPROM.begin(512);
  ESP_BT.begin("Polygon Step"); //Nama Bluetooth
  Serial.println("Bluetooth Device is Ready to Pair");
  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));
  print_wakeup_reason();
  pinMode(b_plus, INPUT_PULLUP);
  pinMode(b_min, INPUT_PULLUP);
  pinMode(b_sleep, INPUT_PULLUP);
  button_was_pressed = false;
  button_pressed_counter = 0;
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);
  tft.drawRGBBitmap(4, 20, Logo, 120, 120); //tampilkan logo polygon di LCD
  delay(2000);
  tft.fillScreen(ST77XX_BLACK);
  databt = "";
  dataln = "";
  Wire.begin();
  tft.setFont(&DejaVu_Sans_Bold_11);
  tft.setTextSize(1);
  tft.drawRect(0, 46 , 125, 57, ST7735_YELLOW);
  tft.drawRect(0, 0 , 24, 42, ST7735_WHITE);
  testdrawtext("SPEED (Km/H)", ST7735_WHITE, 15, 60);
  testdrawtext("MAX", ST7735_RED, 12, 140);
  testdrawtext("MIN", ST7735_GREEN, 90, 140);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 0); //1 = High, 0 = Low

  OdoNow = EEPROM.readFloat(0);
  keliling = EEPROM.readFloat(10);
  y = EEPROM.read(15);

  if (isnan(OdoNow)) {
    OdoNow = 0;
    Serial.print("OdoNow: ");
    Serial.println(OdoNow);
  } else {
    Serial.print("OdoNow: ");
    Serial.println(OdoNow);
  }
  if (isnan(keliling)) {
    keliling = 1.57;
    Serial.print("keliling: ");
    Serial.println(keliling);
  } else {
    Serial.print("keliling: ");
    Serial.println(keliling);
  }
  if (isnan(y) || y > 1) {
    y = 0;
    Serial.print("y: ");
    Serial.println(y);
  } else {
    Serial.print("y: ");
    Serial.println(y);
  }
  barawal();
  bar_kosong();
}

void loop() {
  setting();
  s_kirim();
  interupt();
  lastState1 = currentState1;
  lastState2 = currentState2;
}
