#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup()
{
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Please roll");
  lcd.setCursor(0, 1);
  lcd.print("the dice");
}

void loop()
{
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState)
  {
    if (switchState == LOW)
    {
      int dice1 = random(6) + 1;
      int dice2 = random(6) + 1;
      String dice1_str = "Dice 1: ";
      String dice2_str = "Dice 2: ";
      String diceOneLine = dice1_str + dice1;
      String diceTwoLine = dice2_str + dice2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(diceOneLine);
      lcd.setCursor(0, 1);
      lcd.print(diceTwoLine);
    }
  }
  prevSwitchState = switchState;
}