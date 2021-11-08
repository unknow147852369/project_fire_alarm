/////////////////////////////////////
#include "DHT.h"
#include <LiquidCrystal.h>
/////////////////////////////////////////////////////////
#include <LiquidCrystal_I2C.h>  
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int speaker = 7;                 // loa,den ket noi Pin 7      
int led = 8;                       // out ket noi Pin 9

const int DHTPIN = 6;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
   dht.begin(); 
  pinMode(speaker, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Cam bien nhiet:");
}
void loop() {
  //////////////////////////
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ
  lcd.begin(16, 2);
  ///////////////////////
  if (t > 45)
  {
    lcd.print("Nhiet do: ");
    lcd.print(t);
    ////////xuống hàng///////
    lcd.setCursor(0, 1);
    ///////////////////////
    lcd.print("WARNING");
    digitalWrite(led, HIGH);
    digitalWrite(speaker, HIGH);
  }
  else
  {
    //////////////////
    lcd.print("Nhiet do: ");
    lcd.print(t);
    // In ra dong chu
    lcd.setCursor(0, 1);
    lcd.print("Do am   : ");
    lcd.print(h);
    /////////////////////
    digitalWrite(led, LOW);
    digitalWrite(speaker, LOW);
  }
}
