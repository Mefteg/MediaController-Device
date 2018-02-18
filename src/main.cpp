#include <Arduino.h>

#ifndef BAUDRATE
#define BAUDRATE 9600
#endif

struct Action
{
    Action(int _pin, const char* _keyword)
    : pin(_pin)
    , keyword(_keyword)
    {

    }

    const int pin;
    const char* keyword;
};

#define ACTIONS_COUNT 4
Action ACTIONS[ACTIONS_COUNT] =
{
    Action(3, "PREVIOUS"),
    Action(4, "PLAY"),
    Action(5, "NEXT"),
    Action(6, "MODE")
};

// the setup routine runs once when you switch on the board:
void setup() {
    Serial.begin(BAUDRATE);

    for (unsigned int i=0; i<ACTIONS_COUNT; ++i)
    {
        pinMode(ACTIONS[i].pin, INPUT);
    }
}

// the loop routine runs over and over again forever:
void loop() {
    for (unsigned int i=0; i<ACTIONS_COUNT; ++i)
    {
        const Action& currentAction = ACTIONS[i];
        if (digitalRead(currentAction.pin))
        {
            Serial.println(currentAction.keyword);
        }
    }

    delay(200);
}
