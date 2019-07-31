#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

byte coeur[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};
byte smile[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};
byte smiles[8] = {
  0b11111,
  0b11111,
  0b10101,
  0b11111,
  0b11111,
  0b01110,
  0b10001,
  0b11111
};
byte smiless[8] = {
  0b00000,
  0b11111,
  0b11111,
  0b10101,
  0b11111,
  0b11111,
  0b01110,
  0b00000
};

void setup()
{
  lcd.init();

  lcd.createChar(1, coeur);
  lcd.createChar(2, smiles);
  lcd.createChar(3, smiless);
  
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("JAMES KANA");
  lcd.setCursor(2,1);
  lcd.print("I");
  lcd.setCursor(5,1);
  lcd.write(1);
  lcd.setCursor(7,1);
  lcd.print("you!");
  lcd.setCursor(12, 1);
  lcd.write(2);
  
}




void loop()
{
   lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("JAMES KANA");
  lcd.setCursor(2,1);
  lcd.print("I");
  lcd.setCursor(5,1);
  lcd.write(1);
  lcd.setCursor(7,1);
  lcd.print("you!");
  lcd.setCursor(12, 1);
  lcd.write(2);
  delay(500);
  lcd.setCursor(12, 1);
  lcd.write(3);
  delay(500);
  lcd.noDisplay();
  delay(500);
  lcd.display();

}
