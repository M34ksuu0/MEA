# Inteligentna sygnalizacja świetlna z czujnikami PIR
Opis projektu

Projekt przedstawia system sygnalizacji świetlnej oparty na platformie Arduino, który steruje czterema zestawami świateł na podstawie zaprogramowanej sekwencji oraz odczytów z czterech czujników ruchu PIR.

W normalnym trybie światła zmieniają się kolejno zgodnie z ustalonym czasem. Gdy którykolwiek czujnik wykryje ruch, sterowanie przechodzi w tryb reagowania na czujniki. Zielone światło zostaje włączone dla kierunków, na których wykryto ruch, a pozostałe kierunki otrzymują światło czerwone.

Po ustaniu ruchu system wraca do normalnej sekwencji, rozpoczynając ją od początku.

Funkcje
Obsługa czterech zestawów świateł.
Wykorzystanie czterech czujników ruchu PIR.
Automatyczna sekwencja zmiany świateł.
Konfigurowalny czas świecenia światła czerwonego i zielonego.
Priorytet odczytów z czujników PIR nad normalną sekwencją.
Ustawienie wszystkich świateł na czerwono po zakończeniu wykrywania ruchu.
Automatyczny powrót do normalnego trybu pracy.
Wykorzystanie funkcji millis() do odmierzania czasu bez stosowania blokującego delay().
Wykorzystane komponenty
Arduino, np. Arduino Uno
4 czujniki ruchu PIR
4 zielone diody LED
4 czerwone diody LED
Rezystory ograniczające prąd diod LED
Płytka stykowa
Przewody połączeniowe
Podłączenie pinów
Sygnalizacja świetlna
Kierunek	Zielone światło	Czerwone światło
1	D11	D6
2	D10	D9
3	D13	D12
4	D7	D8
Czujniki ruchu PIR
Czujnik	Pin Arduino
PIR 1	D4
PIR 2	D3
PIR 3	D5
PIR 4	D2

Uwaga: Diody LED należy podłączyć przez odpowiednie rezystory ograniczające prąd. Czujniki PIR należy podłączyć zgodnie z ich specyfikacją, uwzględniając zasilanie, masę i wyjście sygnałowe.

Zasada działania
1. Tryb normalny

System rozpoczyna działanie od ustawienia wszystkich świateł na czerwono. Następnie kolejno włącza zielone światło dla każdego kierunku.

Etap	Działanie	Czas
1	Wszystkie światła czerwone	2 sekundy
2	Zielone światło – kierunek 1	5 sekund
3	Wszystkie światła czerwone	2 sekundy
4	Zielone światło – kierunek 2	5 sekund
5	Wszystkie światła czerwone	2 sekundy
6	Zielone światło – kierunek 3	5 sekund
7	Wszystkie światła czerwone	2 sekundy
8	Zielone światło – kierunek 4	5 sekund

Po zakończeniu cyklu sekwencja rozpoczyna się ponownie.

2. Tryb wykrywania ruchu

Gdy co najmniej jeden czujnik PIR wykryje ruch:

Zielone światło włącza się dla kierunków, których czujniki wykrywają ruch.
Czerwone światło włącza się dla pozostałych kierunków.
Normalna sekwencja świateł zostaje wstrzymana.

Jeżeli kilka czujników wykryje ruch jednocześnie, zielone światło zostanie włączone dla wszystkich odpowiadających im kierunków.

3. Powrót do normalnego trybu

Po ustaniu ruchu system ustawia wszystkie światła na czerwono. Następnie rozpoczyna normalną sekwencję od początku, zachowując dwusekundowy czas oczekiwania przed włączeniem pierwszego zielonego światła.

Konfiguracja czasu

Czasy działania można zmienić za pomocą dwóch stałych zdefiniowanych w kodzie:

    const unsigned long CZERWONE_CZAS = 2000;
    const unsigned long ZIELONE_CZAS = 5000;

CZERWONE_CZAS – czas oczekiwania przed kolejnym zielonym światłem, w milisekundach.
ZIELONE_CZAS – czas świecenia zielonego światła w normalnej sekwencji, w milisekundach.

Przykładowo wartość 2000 oznacza 2 sekundy, a 5000 oznacza 5 sekund.

Wykorzystane technologie
Arduino IDE
Język C/C++
Czujniki ruchu PIR
Sterowanie cyfrowymi wejściami i wyjściami Arduino
Funkcja millis() do kontroli czasu
Funkcja digitalRead() do odczytu czujników
Funkcja digitalWrite() do sterowania światłami
Uruchomienie projektu
Podłącz komponenty do odpowiednich pinów Arduino zgodnie z tabelami.
Otwórz kod projektu w Arduino IDE.
Wybierz odpowiednią płytkę Arduino oraz port komunikacyjny.
Wgraj program na płytkę.
Sprawdź działanie świateł w normalnym trybie.
Przetestuj działanie czujników PIR i reakcję systemu na wykrycie ruchu.
Możliwe rozszerzenia
Dodanie sygnalizacji żółtym światłem.
Zastosowanie wyświetlacza pokazującego czas do zmiany świateł.
Dodanie przycisków do ręcznego sterowania sygnalizacją.
Zmiana czasu świecenia świateł w zależności od natężenia ruchu.
Dodanie sygnalizacji dźwiękowej.
Rozbudowa projektu o dodatkowe czujniki.
Autor

Projekt edukacyjny przedstawiający zastosowanie Arduino i czujników PIR do sterowania sygnalizacją świetlną.

Licencja

Projekt może być wykorzystywany do nauki programowania Arduino i eksperymentów z elektroniką.

Ważne: Projekt ma charakter edukacyjny i nie jest przeznaczony do sterowania rzeczywistą sygnalizacją drogową.
