/*
 * Author  : Charles Surianto
 * Date    : 14 Jan 2022
 * Purpose : APSC 101 Claw Project
 */

#include <Servo.h>

#include <globals.h>
#include <functions.h>

void setup()
{
    servo.attach(servoPin);
    pinMode(proxLedPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    open();
    if (debuggingLevel > 0)
    {
        Serial.begin(baudRate);
    }
}

void loop()
{
    bool buttonS = digitalRead(buttonPin);
    if (buttonS < buttonLS)
    {
        triggerClaw();
    }
    buttonLS = buttonS;

    if (currentPos == desiredPos)
    {
        updateReading();
    }

    tms = millis();
    tus = micros();

    if (distance < threshold && !isNear)
    {
        clawIsLowered();
    }
    if (distance > threshold && isNear)
    {
        clawIsRaised();
    }
    if (tms - tNear >= wait && isArmed && isNear)
    {
        triggerClaw();
    }

    if (tus - tServo >= servoInterval && currentPos != desiredPos)
    {
        updateServo();
        tServo = tus;
    }

    if (debuggingLevel == 2)
    {
        printRawData();
    }
}
