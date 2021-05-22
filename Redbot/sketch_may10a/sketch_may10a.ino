#include "musicNotes.h"

const int buzzerPin = 9;
const int buttonPin = 12;

int melody[] = {

    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4};

double noteDurations[] = {

    4, 4, 4, 5.33, 16, 4, 5.33, 16, 2};

void setup()
{
  // put your setup code here, to run once:

  // pinMode(13, OUTPUT);

  // pinMode(buttonPin, INPUT_PULLUP);

  // pinMode(buzzerPin, OUTPUT);

  for (int thisNote = 0; thisNote < 9; thisNote++)
  {
    int noteDuration = 1800 / noteDurations[thisNote];

    tone(buzzerPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.1;

    delay(pauseBetweenNotes);

    noTone(buzzerPin);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:

  // digitalWrite(13, HIGH);
  // delay(500);

  // digitalWrite(13, LOW);
  // delay(500);
}
