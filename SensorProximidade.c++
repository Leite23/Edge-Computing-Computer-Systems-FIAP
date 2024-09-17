int trigger = 7;
int echo = 4;
int dist = 0;
int greenLed = 13;
int yellowLed = 12;
int redLed = 8;
int led = 0;

void setup()
{
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
    pinMode(redLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
}

void loop()
{
    digitalWrite(trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    dist = pulseIn(echo, HIGH);
    dist = dist / 58;
    Serial.println(dist);

    if (dist < 10)
    {
        if (led != redLed)
        {
            digitalWrite(led, LOW);
        }
        digitalWrite(redLed, HIGH);
        Serial.println(dist);
        led = redLed;
    }
    else if (dist > 10 && dist < 20)
    {
        if (led != yellowLed)
        {
            digitalWrite(led, LOW);
        }
        digitalWrite(yellowLed, HIGH);
        Serial.println(dist);
        led = yellowLed;
    }
    else if (dist > 20 && dist < 30)
    {
        if (led != greenLed)
        {
            digitalWrite(led, LOW);
        }
        digitalWrite(greenLed, HIGH);
        Serial.println(dist);
        led = greenLed;
    }
    else
    {
        digitalWrite(led, LOW);
    }
}