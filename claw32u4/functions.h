// necessary functions

Servo servo;

void printRawData()
{
    Serial.print(distance);
    Serial.print("\t");
    Serial.print(threshold);
    Serial.print("\t");
    Serial.print(currentPos);
    Serial.print("\t");
    Serial.print(desiredPos);
    Serial.print("\n");
}

void updateReading()
{
    // some coding magic
    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    unsigned long duration = pulseIn(echoPin, HIGH, timeout);
    if (duration > 0)
        distance = readingSF * ((double)duration * 0.0172) + (1 - readingSF) * distance;
}

void updateServo()
{
    if (desiredPos > currentPos)
        currentPos++;
    if (desiredPos < currentPos)
        currentPos--;
    servo.writeMicroseconds(currentPos);
}

void open()
{
    if (debuggingLevel == 1)
        Serial.println("opening...");
    servoInterval = openInterval;
    threshold = openThreshold;
    desiredPos = openPos;
    wait = openWait;
    isOpen = 1;
}

void close()
{
    if (debuggingLevel == 1)
        Serial.println("closing...");
    servoInterval = closeInterval;
    threshold = closeThreshold;
    desiredPos = closePos;
    wait = closeWait;
    isOpen = 0;
}

void clawIsLowered()
{
    digitalWrite(proxLedPin, 1);
    isNear = true;
    tNear = tms;
    if (debuggingLevel == 1)
        Serial.println("claw lowered");
}

void clawIsRaised()
{
    digitalWrite(proxLedPin, 0);
    isNear = false;
    isArmed = true;
    if (debuggingLevel == 1)
        Serial.println("claw lifted");
}

void triggerClaw()
{
    if (isOpen)
        close();
    else
        open();
    isArmed = false;
    if (debuggingLevel == 1)
        Serial.println("claw disarmed");
}
