#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 13     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);//pins

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);//x and y length
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = (dht.readTemperature() * 9.0)/5.0 + 32.0;// Convert Celcius to Fahrenheit

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" F");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print(" %");
  delay(3000);
}
