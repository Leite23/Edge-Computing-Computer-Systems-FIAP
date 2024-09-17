int led = 13;

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    Serial.println("-------");
    writeF();
    writeI();
    writeA();
    writeP();
}

void writeS()
{
    for (int x = 0; x < 3; x++)
    {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }
}

void writeO()
{
    for (int x = 0; x < 3; x++)
    {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
    }
}

void writeF()
{
    for (int x = 0; x < 4; x++)
    {
        int intervalo = 500;
        if (x == 2)
        {
            intervalo = 1000;
        }
        digitalWrite(led, HIGH);
        delay(intervalo);
        digitalWrite(led, LOW);
        delay(intervalo);
    };
    Serial.println("F");
}

void writeI()
{
    for (int x = 0; x < 2; x++)
    {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    };
    Serial.println("I");
}

void writeA()
{
    for (int x = 0; x < 2; x++)
    {
        int intervalo = 500;
        if (x == 1)
        {
            intervalo = 1000;
        }
        digitalWrite(led, HIGH);
        delay(intervalo);
        digitalWrite(led, LOW);
        delay(intervalo);
    }
    Serial.println("A");
}

void writeP()
{
    for (int x = 0; x < 4; x++)
    {
        int intervalo = 500;
        if (x == 1 || x == 2)
        {
            intervalo = 1000;
        }
        digitalWrite(led, HIGH);
        delay(intervalo);
        digitalWrite(led, LOW);
        delay(intervalo);
    }
    Serial.println("P");
}
