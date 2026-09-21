// C++ code
//
int dioda[] = {13,12,11,10};
unsigned long licznik2 = 0;
void setup()
{
	for(int i=0; i<=4; i++)
    {
      pinMode(dioda[i], OUTPUT);
    }
}

void loop()
{
  unsigned long licznik1 = millis();
  if(licznik1-licznik2<4000)
  {
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  }
  else if(licznik1-licznik2<8000)
  {
    digitalWrite(10, LOW);
  	digitalWrite(13, LOW);
  	digitalWrite(12, HIGH);
  	digitalWrite(11, HIGH);
    licznik1 = millis();
  }
  else
  {
    licznik2=licznik1;
  }
}