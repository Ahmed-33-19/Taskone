#include <LiquidCrystal_I2C.h>

// C++ code
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  lcd.init();
  lcd.backlight();

  
}

void loop()
{
  
  float temp = readtemp();
  Serial.println(temp);
  buzzer(temp);
}


float readtemp()
{
  float i =analogRead(A0);
  float volt = i * 4.89  ;
  float prevtemp = ( volt - 93.7 ) / 10.07 ;
  float temp = prevtemp - 40 ;
  return temp ;
}

void buzzer(float temp)
{
  if (temp > 50) {
    tone(12,2450,500);
    lcd.setCursor(0,0);
    lcd.print("HOUSE IS FIRE");

  }
  else 
  {
    noTone(12);
    lcd.setCursor(0,0);
    lcd.print("HOUSE IS SAFE");

  }
}



