#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);//pins
int DHpin = 13; //temp/humidity input and output
byte dat[5];
byte read_data()
{
  byte i = 0;
  byte result = 0;
  for (i = 0; i < 8; i++) {
      while (digitalRead(DHpin) == LOW); // wait 50us
      delayMicroseconds(30); 
    while (digitalRead(DHpin) == HIGH); 
    }
  return result;
}

void setup() {
  lcd.begin(16, 2);//x and y length
  lcd.print("Its: ");
}

void loop() {
  lcd.setCursor(0, 1);//x,y
  int x = millis()/ 1000;
  if(x % 2 == 0) lcd.print("Heads");//even
  else lcd.print("Tails");
}
