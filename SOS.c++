int trigger = 7;
int echo = 8;
int dist = 0;
int led = 4;

void setup()
{
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
    pinMode(led, OUTPUT);
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

    if (dist < 50)
    {
        digitalWrite(led, HIGH);
        Serial.println(dist);
    }
    else
    {
        digitalWrite(led, LOW);
        Serial.println(dist);
    }
}