// Wczytanie pliku :
//      Nazwa procedury : wczytaj(sciezka_do_pliku)
//      Wejście : ścieżka do pliku(sciezka_do_pliku)
//      Wyjście : lista linii pliku(linie)

// Porównanie linii i wzorca :
//      Nazwa procedury : porownaj_do_wzorca(linia, wzorzec)
//      Wejście : linia z pliku(linia)
//      i wzorzec do wyszukania(wzorzec)
//      Wyjście : liczba niedopasowań(niedopasowania)

// Wypisanie wyniku :
//      Nazwa procedury : pokaz_wynik(numer_lini, linia, rodzaj_niedopasowania)
//      Wejście : numer linii(numer_lini),
//      linia z pliku(linia)
//      i rodzaje niedopasowań(rodzaj_niedopasowania)
//      Wyjście : brak(operacja wypisania na standardowe wyjście)

// Główna funkcja programu :
//      Nazwa funkcji : wyszukiwanie_wzorcow(sciezka_do_pliku, wzorzec)
//      Wejście : ścieżka do pliku(sciezka_do_pliku) i wzorzec do wyszukania(wzorzec)
//      Wyjście : brak(operacja wypisania na standardowe wyjście)

#define MAX_LINI 1000      // Maksymalna liczba linii w pliku
#define MAX_DL_LINI 100    // Maksymalna długość jednej linii
#define MAX_NIEDOPASOWAN 2 // Maksymalna liczba niedopasowań

char *linie[MAX_LINI];                     // Tablica linii pliku
char wzorzec[MAX_DL_LINI];                 // Wzorzec do wyszukania
int niedopasowania[MAX_LINI][MAX_DL_LINI]; // Tablica indeksów niedopasowań
int ile_niedopasowan[MAX_LINI];            // Liczba niedopasowań dla każdej linii
