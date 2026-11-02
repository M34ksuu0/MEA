📟 Animowany wyświetlacz LCD

Projekt wykorzystujący wyświetlacz LCD 16x2 oraz bibliotekę Adafruit LiquidCrystal. Program wyświetla na ekranie animowany, przewijający się napis reklamowy.

✨ Funkcje

Wyświetlanie tekstu na wyświetlaczu LCD 16x2.

Płynne przewijanie napisu w pierwszym wierszu ekranu.

Stały tekst reklamowy w drugim wierszu.

Automatyczne zapętlanie animacji.

Aktualizacja wyświetlacza co 400 ms.

Sterowanie czasem za pomocą funkcji millis()

🛠️ Wykorzystane komponenty

Arduino (np. Arduino Uno)

Wyświetlacz LCD 16x2 z modułem I2C

Biblioteka Adafruit_LiquidCrystal

Przewody połączeniowe

💻 Wykorzystane technologie

C++

Arduino IDE

Biblioteka Adafruit LiquidCrystal

⚙️ Jak działa projekt?

Program wyświetla dwa wiersze tekstu:

Pierwszy wiersz:

Tekst przesuwa się cyklicznie od prawej do lewej.

Każde przesunięcie następuje co 400 ms.

Drugi wiersz:

Pozostaje niezmienny podczas działania programu.

Do obsługi animacji wykorzystano funkcję millis(), która pozwala kontrolować odstępy czasowe bez zatrzymywania wykonywania programu.

🧠 Najważniejsze elementy kodu

Element	Opis

    LCD_Write() -> Wyświetla aktualny fragment przewijanego tekstu.
    millis() -> Kontroluje czas animacji.
    interval = 400 -> Określa odstęp między przesunięciami.
    pozycja -> Przechowuje aktualną pozycję tekstu.
    reklama -> Zawiera tekst przeznaczony do przewijania.
