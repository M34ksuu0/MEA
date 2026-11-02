
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

unsigned long previousMillis = 0;
const long interval = 400;

int pozycja = 0;

String reklama = "    EASY BOOST'A               ^LEVEL UP^";

void LCD_Write() {
  lcd_1.setCursor(0, 0);

  for (int i = 0; i < 16; i++) {
    lcd_1.print(reklama[(pozycja + i) % reklama.length()]);
  }
}

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);

  lcd_1.setCursor(0, 1);
  lcd_1.print("   KUP i PIJ!   ");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    LCD_Write();

    pozycja++;

    if (pozycja >= reklama.length()) {
      pozycja = 0;
    }
  }
}
