#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <time.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int rollPin = 6;
const int downDice = 7;
const int upDice = 8;
int switchState = 0;
int prevSwitchState = 0;
int reply;
int numberDiceToRoll = 10;

int upDicePressed = 0;
int downDicePressed = 0;

int numberOfDice();
int diceRoll();

int ones = 0;
int twos = 0;
int threes = 0;
int fours = 0;
int fives = 0;
int sixes = 0;

String onesPrint = "1:";
String twosPrint = "2:";
String threesPrint = "3:";
String foursPrint = "4:";
String fivesPrint = "5:";
String sixesPrint = "6:";

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(rollPin, INPUT_PULLUP);
  pinMode(downDice, INPUT_PULLUP);
  pinMode(upDice, INPUT_PULLUP);
  // int numberOfDice = 10;
  lcd.print("Please roll");
  lcd.setCursor(0, 1);
  lcd.print("the dice");
}

void loop()
{
  // put your main code here, to run repeatedly:
  switchState = digitalRead(rollPin);
  srand(time(NULL));
  if (switchState != prevSwitchState)
  {

    numberOfDice();

    String numberOfDicePrint = "Number of Dice: ";

    lcd.clear();
    lcd.print(numberOfDicePrint);
    lcd.setCursor(0, 1);
    lcd.print(numberDiceToRoll);

    prevSwitchState = switchState;
  }
  switchState = digitalRead(rollPin);
  if (switchState != prevSwitchState)
  {
    for (int i = 0; i < numberDiceToRoll; i++)
    {
      int result = diceRoll();

      switch (result)
      {
      case 1:
        ones++;
        break;
      case 2:
        twos++;
        break;
      case 3:
        threes++;
        break;
      case 4:
        fours++;
        break;
      case 5:
        fives++;
        break;
      case 6:
        sixes++;
        break;
      }
    }

    prevSwitchState = switchState;
  }

  switchState = digitalRead(rollPin);
  if (switchState != prevSwitchState)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(onesPrint + ones);
    lcd.setCursor(5, 0);
    lcd.print(twosPrint + twos);
    lcd.setCursor(10, 0);
    lcd.print(threesPrint + threes);
    lcd.setCursor(0, 1);
    lcd.print(foursPrint + fours);
    lcd.setCursor(5, 1);
    lcd.print(fivesPrint + fives);
    lcd.setCursor(10, 1);
    lcd.print(sixesPrint + sixes);

    prevSwitchState = switchState;
  }
}

int numberOfDice()
{
  if (upDicePressed == 1)
  {
    numberDiceToRoll++;
  }
  if (downDicePressed == 1)
  {
    numberDiceToRoll--;
  }

  return numberDiceToRoll;
}

int diceRoll()
{
  int result = random(6) + 1;

  return result;
}