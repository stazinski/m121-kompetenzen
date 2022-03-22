#include <LiquidCrystal.h>

#define LED_GREEN 6
#define LED_BLUE 7
#define LED_RED 8
#define BUTTON_INCREASE 9
#define BUTTON_DECREASE 10

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int count = 0;

void setup()
{
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(BUTTON_INCREASE, INPUT);
    pinMode(BUTTON_DECREASE, INPUT);
    lcd.begin(16, 2);
    updateScreen();
}

void loop()
{
    checkButtons();
}

void updateLEDs()
{
    if (count > 0)
    {
        digitalWrite(LED_RED, HIGH);
    }
    else
    {
        digitalWrite(LED_RED, LOW);
    }
    if (count == 0)
    {
        digitalWrite(LED_BLUE, HIGH);
    }
    else
    {
        digitalWrite(LED_BLUE, LOW);
    }
    if (count < 0)
    {
        digitalWrite(LED_GREEN, HIGH);
    }
    else
    {
        digitalWrite(LED_GREEN, LOW);
    }
}

void updateScreen()
{
    lcd.clear();
    lcd.print("Counter:");
    lcd.setCursor(0, 1);
    lcd.print(count);
}

void updateVisuals()
{
    updateScreen();
    updateLEDs();
}

void checkButtons()
{
    if (digitalRead(BUTTON_INCREASE))
    {
        count++;
        updateVisuals();
        delay(500);
    }
    if (digitalRead(BUTTON_DECREASE))
    {
        count--;
        updateVisuals();
        delay(500);
    }
}
