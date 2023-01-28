/********************************************************************/
/*                                                                  */
/* ALTERNATYWNA DO PRZEDSTAWIONEJ NA WYKLADZIE WERSJA OPRACOWANIA   */
/* PARAMETROW WYWOLANIA PROGRAMU UWZGLEDNIAJACA OPCJE Z PARAMETRAMI */
/* Z ODPOWIEDNIO ZAPROPONOWANYMI STRUKTURAMI DANYCH PRZEKAZUJACYMI  */
/* WCZYTANE USTAWIENIA                                              */
/*                                    COPYRIGHT (c) 2007-2020 KCiR  */
/*                                                                  */
/* Autorzy udzielaja kazdemu prawa do kopiowania tego programu      */
/* w calosci lub czesci i wykorzystania go w dowolnym celu, pod     */
/* warunkiem zacytowania zrodla                                     */
/*                                                                  */
/********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "funkcje.h"
#define W_OK 0                /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1 /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY -2
#define B_BRAKWARTOSCI -3
#define B_BRAKPLIKU -4

/*******************************************************/
/* Funkcja inicjuje strukture wskazywana przez wybor   */
/* PRE:                                                */
/*      poprawnie zainicjowany argument wybor (!=NULL) */
/* POST:                                               */
/*      "wyzerowana" struktura wybor wybranych opcji   */
/*******************************************************/

void wyzeruj_opcje(t_opcje *wybor)
{
    wybor->plik_we = NULL;
    wybor->plik_wy = NULL;
    wybor->negatyw = 0;
    wybor->konturowanie = 0;
    wybor->progowanie = 0;
    wybor->wyswietlenie = 0;
    wybor->r = 0;
    wybor->g = 0;
    wybor->b = 0;
    wybor->nie_kolorowy = 0;
}

/************************************************************************/
/* Funkcja rozpoznaje opcje wywolania programu zapisane w tablicy argv  */
/* i zapisuje je w strukturze wybor                                     */
/* Skladnia opcji wywolania programu                                    */
/*         program {[-i nazwa] [-o nazwa] [-p liczba] [-m kolor]        */
/*         [-n] [-k] [-d] }                                             */
/* Argumenty funkcji:                                                   */
/*         argc  -  liczba argumentow wywolania wraz z nazwa programu   */
/*         argv  -  tablica argumentow wywolania                        */
/*         wybor -  struktura z informacjami o wywolanych opcjach       */
/* PRE:                                                                 */
/*      brak                                                            */
/* POST:                                                                */
/*      funkcja otwiera odpowiednie pliki, zwraca uchwyty do nich       */
/*      w strukturze wybór, do tego ustawia na 1 pola dla opcji, ktore  */
/*	poprawnie wystapily w linii wywolania programu,                     */
/*	pola opcji nie wystepujacych w wywolaniu ustawione sa na 0;         */
/*	zwraca wartosc W_OK (0), gdy wywolanie bylo poprawne                */
/*	lub kod bledu zdefiniowany stalymi B_* (<0)                         */
/* UWAGA:                                                               */
/*      funkcja nie sprawdza istnienia i praw dostepu do plikow         */
/*      w takich przypadkach zwracane uchwyty maja wartosc NULL         */
/************************************************************************/

int przetwarzaj_opcje(int argc, char **argv, t_opcje *wybor)
{
    int i, prog;
    char *nazwa_pliku_we;
    char *nazwa_pliku_wy;

    wyzeruj_opcje(wybor);
    wybor->plik_wy = stdout; /* na wypadek gdy nie podano opcji "-o" */

    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-') /* blad: to nie jest opcja - brak znaku "-" */
            return B_NIEPOPRAWNAOPCJA;
        switch (argv[i][1])
        {
        case 'i':
        { /* opcja z nazwa pliku wejsciowego */
            if (++i < argc)
            { /* wczytujemy kolejny argument jako nazwe pliku */
                nazwa_pliku_we = argv[i];
                if (strcmp(nazwa_pliku_we, "-") == 0) /* gdy nazwa jest "-"        */
                    wybor->plik_we = stdin;           /* ustwiamy wejscie na stdin */
                else                                  /* otwieramy wskazany plik   */
                    wybor->plik_we = fopen(nazwa_pliku_we, "r");
            }
            else
                return B_BRAKNAZWY; /* blad: brak nazwy pliku */
            break;
        }
        case 'm':
        { /* wybieramy kolor do obrobki*/
            if (++i < argc)
            { /* wczytujemy kolejny argument jako kolor do obrobki */
                if (argv[i][0] == 'r')
                {
                    wybor->r = 1;
                }

                if (argv[i][0] == 'g')
                {
                    wybor->g = 1;
                }
                if (argv[i][0] == 'b')
                {
                    wybor->b = 1;
                }
                if (argv[i][0] == 's')
                {
                    wybor->nie_kolorowy = 1;
                }
                break;
            }
            else                           /*w przypadku gdy podano cos innego*/
                return B_NIEPOPRAWNAOPCJA; /*blad: niepoprawny argument funkcji*/
        }

        case 'o': /*zapisujemy plik*/
        {
            if (++i < argc)
            { /* wczytujemy kolejny argument jako nazwe pliku */
                nazwa_pliku_wy = argv[i];
                wybor->do_wyswietlania = nazwa_pliku_wy;
                if (strcmp(nazwa_pliku_wy, "-") == 0) /* gdy nazwa jest "-"         */
                    wybor->plik_wy = stdout;          /* ustwiamy wyjscie na stdout */
                else                                  /* otwieramy wskazany plik    */
                    wybor->plik_wy = fopen(nazwa_pliku_wy, "w");
            }
            else
                return B_BRAKNAZWY; /* blad: brak nazwy pliku */
            break;
        }

        case 'p':
        {
            if (++i < argc)
            { /* wczytujemy kolejny argument jako wartosc progu */
                if (sscanf(argv[i], "%d", &prog) == 1)
                {
                    wybor->progowanie = 1;
                    wybor->w_progu = prog;
                }
                else
                    return B_BRAKWARTOSCI; /* blad: niepoprawna wartosc progu */
            }
            else
                return B_BRAKWARTOSCI; /* blad: brak wartosci progu */
            break;
        }
        case 'n':
        { /* mamy wykonac negatyw */
            wybor->negatyw = 1;
            break;
        }
        case 'k':
        { /* mamy wykonac konturowanie */
            wybor->konturowanie = 1;
            break;
        }
        case 'd':
        { /* mamy wyswietlic obraz */
            wybor->wyswietlenie = 1;
            break;
        }
        default: /* nierozpoznana opcja */
            return B_NIEPOPRAWNAOPCJA;
        } /* koniec switch */
        wybor->do_wyswietlania = nazwa_pliku_wy;
    } /* koniec for */

    if (wybor->plik_we != NULL) /* ok: wej. strumien danych zainicjowany */
        return W_OK;
    else
        return B_BRAKPLIKU; /* blad:  nie otwarto pliku wejsciowego  */
}
