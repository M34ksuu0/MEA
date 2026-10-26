
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

const unsigned long czasZielonego = 5000;

// Kolejka kierunków
int kolejka[4];
int poczatek = 0;
int koniec = 0;
int liczbaWKolejce = 0;

int aktywnyKierunek = -1;
unsigned long czasStartu = 0;

bool poprzedniRuch[4] = {false, false, false, false};

// Flagi ustawiane przez przerwania
volatile bool wykrytoPir2 = false;
volatile bool wykrytoPir4 = false;

const int pinyZielone[4] = {
  zielone1, zielone2, zielone3, zielone4
};

const int pinyCzerwone[4] = {
  czerwone1, czerwone2, czerwone3, czerwone4
};

const int pinyPIR[4] = {
  pir1, pir2, pir3, pir4
};

// Funkcje przerwań — muszą być krótkie
void przerwaniePir2() {
  wykrytoPir2 = true;
}

void przerwaniePir4() {
  wykrytoPir4 = true;
}

void ustawCzerwone() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pinyZielone[i], LOW);
    digitalWrite(pinyCzerwone[i], HIGH);
  }
}

bool jestWKolejceLubAktywny(int kierunek) {
  if (aktywnyKierunek == kierunek) {
    return true;
  }

  for (int i = 0; i < liczbaWKolejce; i++) {
    int indeks = (poczatek + i) % 4;

    if (kolejka[indeks] == kierunek) {
      return true;
    }
  }

  return false;
}

void dodajDoKolejki(int kierunek) {
  if (jestWKolejceLubAktywny(kierunek)) {
    return;
  }

  if (liczbaWKolejce < 4) {
    kolejka[koniec] = kierunek;
    koniec = (koniec + 1) % 4;
    liczbaWKolejce++;

    Serial.print("Dodano do kolejki kierunek: ");
    Serial.println(kierunek + 1);
  }
}

void rozpocznijKierunek(int kierunek) {
  aktywnyKierunek = kierunek;
  czasStartu = millis();

  ustawCzerwone();

  digitalWrite(pinyCzerwone[kierunek], LOW);
  digitalWrite(pinyZielone[kierunek], HIGH);

  Serial.print("Zielone dla kierunku: ");
  Serial.println(kierunek + 1);
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(pinyZielone[i], OUTPUT);
    pinMode(pinyCzerwone[i], OUTPUT);
    pinMode(pinyPIR[i], INPUT);
  }

  ustawCzerwone();

  // Sprzętowe przerwania na Arduino UNO
  attachInterrupt(
    digitalPinToInterrupt(pir2),
    przerwaniePir2,
    RISING
  );

  attachInterrupt(
    digitalPinToInterrupt(pir4),
    przerwaniePir4,
    RISING
  );
}

void loop() {
  // Odczyt i wyzerowanie flag atomowo
  bool ruchPir2;
  bool ruchPir4;

  noInterrupts();
  ruchPir2 = wykrytoPir2;
  ruchPir4 = wykrytoPir4;
  wykrytoPir2 = false;
  wykrytoPir4 = false;
  interrupts();

  // Kierunek 2: czujnik na pinie 3
  if (ruchPir2) {
    dodajDoKolejki(1);
  }

  // Kierunek 4: czujnik na pinie 2
  if (ruchPir4) {
    dodajDoKolejki(3);
  }

  // Pozostałe czujniki — zwykłe odczyty
  for (int i = 0; i < 4; i++) {
    if (i == 1 || i == 3) {
      continue;
    }

    bool ruch = digitalRead(pinyPIR[i]) == HIGH;

    if (ruch && !poprzedniRuch[i]) {
      dodajDoKolejki(i);
    }

    poprzedniRuch[i] = ruch;
  }

  // Zakończenie zielonego światła
  if (aktywnyKierunek != -1 &&
      millis() - czasStartu >= czasZielonego) {

    digitalWrite(pinyZielone[aktywnyKierunek], LOW);
    digitalWrite(pinyCzerwone[aktywnyKierunek], HIGH);

    Serial.print("Koniec zielonego kierunku: ");
    Serial.println(aktywnyKierunek + 1);

    aktywnyKierunek = -1;
  }

  // Uruchomienie następnego kierunku
  if (aktywnyKierunek == -1 && liczbaWKolejce > 0) {
    int nastepny = kolejka[poczatek];

    poczatek = (poczatek + 1) % 4;
    liczbaWKolejce--;

    rozpocznijKierunek(nastepny);
  }
}
