# Projekt przedstawia sygnalizację świetlną Arduino z 4 zestawami diod.

Działanie

    Zielone światło świeci przez 5 sekund.

    Następnie przez 1 sekundę wszystkie światła są czerwone.

    Program przełącza się na kolejne światło.

    Po czwartym świetle cykl zaczyna się od początku.

Do odmierzania czasu wykorzystano millis() zamiast delay().

Piny

Zielone: 13, 11, 10, 7

Czerwone: 12, 6, 9, 8

Technologie

    Arduino

    C++

    millis()

    digitalWrite()

