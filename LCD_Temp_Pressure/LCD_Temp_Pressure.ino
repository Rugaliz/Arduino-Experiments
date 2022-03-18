#include <LiquidCrystal_I2C.h>

// enter the I2C address and the dimensions of your LCD here
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Temp & Pressure");
  
  lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
  lcd.print("Made by Rugaliz");
  Serial.begin(9600);
  while ( !Serial ) delay(100);   // wait for native usb
  Serial.println(F("BMP280 test"));
  unsigned status;
  //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  status = bmp.begin();
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }
}

void loop() {
    delay(3000);
    lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
    lcd.print("Temp = " + String(bmp.readTemperature()) + " ");
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
    lcd.print("P = " + String(bmp.readPressure()) + " Pa");
    
}
