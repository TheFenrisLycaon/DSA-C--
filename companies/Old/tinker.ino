#define trigger 6
#define echoPin 5
#define R 11
#define G 9
#define B 10

void setup()
{
    Serial.begin(9600);

    pinMode(trigger, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
}

void loop()
{
    int duration, distance;

    digitalWrite(trigger, HIGH);
    _delay_ms(10);

    digitalWrite(trigger, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;

    if (distance > 0 && distance <= 60)
    {
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
        digitalWrite(R, HIGH);
    }

    else if (distance > 60 && distance <= 120)
    {
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, HIGH);
    }

    else if (distance > 120 && distance <= 180)
    {
        digitalWrite(R, LOW);
        digitalWrite(B, LOW);
        digitalWrite(G, HIGH);
    }

    Serial.print("Distance :: \t");
    Serial.println(distance);
    _delay_ms(10);
}