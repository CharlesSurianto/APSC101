/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo; // create servo object to control a servo

int val = 1500, min = 544, max = 2400;
unsigned long lm = 0, t = 1000;

void setup()
{
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    myservo.attach(6);
    Serial.begin(9600);
}

void loop()
{
    unsigned long m = micros();
    if (m - lm >= t)
    {
        if (!digitalRead(2) && val > min)
        {
            val--;
        }
        if (!digitalRead(3) && val < max)
        {
            val++;
        }
        lm = m;
    }
    Serial.println(myservo.readMicroseconds());
    myservo.writeMicroseconds(val);
}
