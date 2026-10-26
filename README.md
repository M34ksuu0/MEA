# 🚦 Inteligentna sygnalizacja świetlna z czujnikami PIR
📌 Opis projektu

Projekt przedstawia inteligentną sygnalizację świetlną dla czterech kierunków ruchu, sterowaną za pomocą Arduino UNO oraz czujników ruchu PIR.

System wykrywa ruch w poszczególnych kierunkach i dodaje zgłoszenia do kolejki. Każdy kierunek otrzymuje zielone światło na określony czas, a pozostałe kierunki mają światło czerwone.

## ⚙️ Funkcje projektu

🚦 Obsługa czterech kierunków ruchu.

🟢 Automatyczne sterowanie światłami zielonymi i czerwonymi.

👁️ Wykrywanie ruchu za pomocą czujników PIR.

📋 Kolejkowanie kierunków, w których wykryto ruch.

⏱️ Czas zielonego światła wynoszący 5 sekund.

⚡ Obsługa przerwań sprzętowych dla dwóch czujników PIR.

🖥️ Wyświetlanie informacji w monitorze portu szeregowego.

## 🧰 Wykorzystane komponenty

Arduino UNO

4 czujniki ruchu PIR

4 zielone diody LED

4 czerwone diody LED

Rezystory do diod LED

Płytka stykowa

Przewody połączeniowe

## 🔌 Schemat połączeń

Diody LED

Kierunek	Zielona LED	Czerwona LED

Kierunek 1	Pin 11	Pin 6

Kierunek 2	Pin 10	Pin 9

Kierunek 3	Pin 13	Pin 12

Kierunek 4	Pin 7	Pin 8

Czujniki PIR

Czujnik	Pin Arduino	Kierunek

PIR 1	4	Kierunek 1

PIR 2	3	Kierunek 2

PIR 3	5	Kierunek 3

PIR 4	2	Kierunek 4

## 🧠 Zasada działania

Po uruchomieniu wszystkie kierunki otrzymują czerwone światło.

System monitoruje sygnały z czterech czujników PIR.

Po wykryciu ruchu odpowiedni kierunek zostaje dodany do kolejki.

Jeśli kierunek nie jest aktywny ani obecny w kolejce, zostaje zapisany jako nowe zgłoszenie.

Gdy żaden kierunek nie ma zielonego światła, system uruchamia kolejny kierunek z kolejki.

Wybrany kierunek otrzymuje zielone światło na 5 sekund.

Po upływie tego czasu zielone światło zostaje wyłączone, a czerwone włączone.

System przechodzi do kolejnego zgłoszonego kierunku.

## ⏱️ Parametry systemu

Liczba kierunków: 4

Czas zielonego światła: 5000 ms (5 sekund)

Maksymalna liczba zgłoszeń w kolejce: 4

Przerwania sprzętowe: PIR 2 i PIR 4

Komunikacja szeregowa: 9600 baud
