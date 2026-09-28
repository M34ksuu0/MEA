int zielone1 = 13;
int zielone2 = 11;
int zielone3 = 10;
int zielone4 = 7;

int czerwone1 = 12;
int czerwone2 = 6;
int czerwone3 = 9;
int czerwone4 = 8;

unsigned long poprzedniCzas = 0;

int sygnal = 1;
bool przerwa = false;

void setup()
{
  pinMode(zielone1, OUTPUT);
  pinMode(zielone2, OUTPUT);
  pinMode(zielone3, OUTPUT);
  pinMode(zielone4, OUTPUT);

  pinMode(czerwone1, OUTPUT);
  pinMode(czerwone2, OUTPUT);
  pinMode(czerwone3, OUTPUT);
  pinMode(czerwone4, OUTPUT);
}

void loop()
{
  unsigned long obecnyCzas = millis();

  if (!przerwa && obecnyCzas - poprzedniCzas >= 5000)
  {
    poprzedniCzas = obecnyCzas;
    przerwa = true;
  }
  if (przerwa && obecnyCzas - poprzedniCzas >= 1000)
  {
    poprzedniCzas = obecnyCzas;
    przerwa = false;

    sygnal++;

    if (sygnal > 4)
    {
      sygnal = 1;
    }
  }

  digitalWrite(zielone1, LOW);
  digitalWrite(zielone2, LOW);
  digitalWrite(zielone3, LOW);
  digitalWrite(zielone4, LOW);

  digitalWrite(czerwone2, HIGH);
  digitalWrite(czerwone3, HIGH);
  digitalWrite(czerwone4, HIGH);

  if (!przerwa)
  {
    if (sygnal == 1)
    {
      digitalWrite(zielone1, HIGH);
      digitalWrite(czerwone1, LOW);
    }

    if (sygnal == 2)
    {
      digitalWrite(zielone2, HIGH);
      digitalWrite(czerwone2, LOW);
      digitalWrite(czerwone1, HIGH);
    }

    if (sygnal == 3)
    {
      digitalWrite(zielone3, HIGH);
      digitalWrite(czerwone3, LOW);
      digitalWrite(czerwone1, HIGH);
    }

    if (sygnal == 4)
    {
      digitalWrite(zielone4, HIGH);
      digitalWrite(czerwone4, LOW);
      digitalWrite(czerwone1, HIGH);
    }
  }
}
