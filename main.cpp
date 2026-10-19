
const int zielone1 = 11;
const int czerwone1 = 6;

const int zielone2 = 10;
const int czerwone2 = 9;

const int zielone3 = 13;
const int czerwone3 = 12;

const int zielone4 = 7;
const int czerwone4 = 8;

// Czujniki PIR
const int pir1 = 4;
const int pir2 = 3;
const int pir3 = 5;
const int pir4 = 2;

const unsigned long CZERWONE_CZAS = 2000;
const unsigned long ZIELONE_CZAS = 5000;

int stan = 0;
unsigned long czas = 0;

bool poprzedniRuch = false;

void czerwone() {
  digitalWrite(zielone1, LOW);
  digitalWrite(czerwone1, HIGH);

  digitalWrite(zielone2, LOW);
  digitalWrite(czerwone2, HIGH);

  digitalWrite(zielone3, LOW);
  digitalWrite(czerwone3, HIGH);

  digitalWrite(zielone4, LOW);
  digitalWrite(czerwone4, HIGH);
}

void ustawSwiatla(bool ruch1, bool ruch2,
                  bool ruch3, bool ruch4) {
  digitalWrite(zielone1, ruch1 ? HIGH : LOW);
  digitalWrite(czerwone1, ruch1 ? LOW : HIGH);

  digitalWrite(zielone2, ruch2 ? HIGH : LOW);
  digitalWrite(czerwone2, ruch2 ? LOW : HIGH);

  digitalWrite(zielone3, ruch3 ? HIGH : LOW);
  digitalWrite(czerwone3, ruch3 ? LOW : HIGH);

  digitalWrite(zielone4, ruch4 ? HIGH : LOW);
  digitalWrite(czerwone4, ruch4 ? LOW : HIGH);
}

void setup() {
  pinMode(zielone1, OUTPUT);
  pinMode(czerwone1, OUTPUT);

  pinMode(zielone2, OUTPUT);
  pinMode(czerwone2, OUTPUT);

  pinMode(zielone3, OUTPUT);
  pinMode(czerwone3, OUTPUT);

  pinMode(zielone4, OUTPUT);
  pinMode(czerwone4, OUTPUT);

  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(pir3, INPUT);
  pinMode(pir4, INPUT);

  czerwone();
  czas = millis();

  Serial.begin(9600);
}

void loop() {
  unsigned long teraz = millis();

  // Odczyt czujnikow
  bool ruch1 = digitalRead(pir1) == HIGH;
  bool ruch2 = digitalRead(pir2) == HIGH;
  bool ruch3 = digitalRead(pir3) == HIGH;
  bool ruch4 = digitalRead(pir4) == HIGH;

  bool wykrytoRuch = ruch1 || ruch2 || ruch3 || ruch4;

  // Gdy wykryto ruch, sterowanie PIR ma pierwszenstwo
  if (wykrytoRuch) {
    ustawSwiatla(ruch1, ruch2, ruch3, ruch4);
    poprzedniRuch = true;

    // Zapamietaj, ze byl ruch
    return;
  }

  // Po ustaniu ruchu rozpocznij sekwencje od poczatku
  if (poprzedniRuch) {
    poprzedniRuch = false;
    stan = 0;
    czas = teraz;
    czerwone();
    return;
  }

  // NORMALNA SEKWENCJA SWIATEL

  // CZERWONE przed zielonym 1
  if (stan == 0 && teraz - czas >= CZERWONE_CZAS) {
    stan = 1;
    czas = teraz;

    digitalWrite(czerwone1, LOW);
    digitalWrite(zielone1, HIGH);
  }

  // ZIELONE 1
  else if (stan == 1 && teraz - czas >= ZIELONE_CZAS) {
    stan = 2;
    czas = teraz;
    czerwone();
  }

  // CZERWONE przed zielonym 2
  else if (stan == 2 && teraz - czas >= CZERWONE_CZAS) {
    stan = 3;
    czas = teraz;

    digitalWrite(czerwone2, LOW);
    digitalWrite(zielone2, HIGH);
  }

  // ZIELONE 2
  else if (stan == 3 && teraz - czas >= ZIELONE_CZAS) {
    stan = 4;
    czas = teraz;
    czerwone();
  }

  // CZERWONE przed zielonym 3
  else if (stan == 4 && teraz - czas >= CZERWONE_CZAS) {
    stan = 5;
    czas = teraz;

    digitalWrite(czerwone3, LOW);
    digitalWrite(zielone3, HIGH);
  }

  // ZIELONE 3
  else if (stan == 5 && teraz - czas >= ZIELONE_CZAS) {
    stan = 6;
    czas = teraz;
    czerwone();
  }

  // CZERWONE przed zielonym 4
  else if (stan == 6 && teraz - czas >= CZERWONE_CZAS) {
    stan = 7;
    czas = teraz;

    digitalWrite(czerwone4, LOW);
    digitalWrite(zielone4, HIGH);
  }

  // ZIELONE 4
  else if (stan == 7 && teraz - czas >= ZIELONE_CZAS) {
    stan = 0;
    czas = teraz;
    czerwone();
  }
}