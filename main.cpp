
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

// Aktualnie obsługiwany kierunek
int aktywnyKierunek = -1;
unsigned long czasStartu = 0;

// Zapamiętanie poprzedniego stanu PIR
bool poprzedniRuch[4] = {false, false, false, false};

const int pinyZielone[4] = {
  zielone1, zielone2, zielone3, zielone4
};

const int pinyCzerwone[4] = {
  czerwone1, czerwone2, czerwone3, czerwone4
};

const int pinyPIR[4] = {
  pir1, pir2, pir3, pir4
};

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
  // Nie dodawaj ponownie tego samego kierunku
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
}

void loop() {
  // Odczyt czujników i wykrywanie nowego sygnału
  for (int i = 0; i < 4; i++) {
    bool ruch = digitalRead(pinyPIR[i]) == HIGH;

    // Dodaj tylko przy przejściu LOW -> HIGH
    if (ruch && !poprzedniRuch[i]) {
      dodajDoKolejki(i);
    }

    poprzedniRuch[i] = ruch;
  }

  // Sprawdź, czy minęło 5 sekund zielonego
  if (aktywnyKierunek != -1 &&
      millis() - czasStartu >= czasZielonego) {

    digitalWrite(pinyZielone[aktywnyKierunek], LOW);
    digitalWrite(pinyCzerwone[aktywnyKierunek], HIGH);

    Serial.print("Koniec zielonego kierunku: ");
    Serial.println(aktywnyKierunek + 1);

    aktywnyKierunek = -1;
  }

  // Uruchom następny kierunek, jeśli żaden nie jest aktywny
  if (aktywnyKierunek == -1 && liczbaWKolejce > 0) {
    int nastepny = kolejka[poczatek];

    poczatek = (poczatek + 1) % 4;
    liczbaWKolejce--;

    rozpocznijKierunek(nastepny);
  }
}
