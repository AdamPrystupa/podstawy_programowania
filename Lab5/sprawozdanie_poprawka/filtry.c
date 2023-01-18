#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "funkcje.h"

#define MAX 4096              /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 2048         /* Dlugosc buforow pomocniczych */
#define W_OK 0                /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1 /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY -2
#define B_BRAKWARTOSCI -3
#define B_BRAKPLIKU -4

/************************************************************************
 * Funkcja negatywu      	       	       	                            *
 * \param[in] piksele tablica, z ktorej zostanie wczytany obraz		    *
 * \param[in] wym_x szerokosc obrazka						            *
 * \param[in] wym_y wysokosc obrazka						            *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] piksele tablica, w ktorej zostanie zapisany zmodyfikowany*
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int negatyw(struct_obrazka *obrazek, t_opcje *opcje)
{

    if (obrazek->nr_magiczny == 2) /*sprawdzamy format obrazka*/
        negatyw2(obrazek, opcje);

    if (obrazek->nr_magiczny == 3) /*dla formatu .ppm wym_x jest 3 razy dłuższy*/
    {
        if (opcje->r == 1)
            negatyw3r(obrazek, opcje);
        if (opcje->g == 1)
            negatyw3g(obrazek, opcje);
        if (opcje->b == 1)
            negatyw3b(obrazek, opcje);
        else
            negatyw3(obrazek, opcje);
    }
    return 0;
}

/************************************************************************
 * Funkcja progowania                                 	       	       	*
 * \param[in] piksele tablica, z ktorej zostanie wczytany obraz		    *
 * \param[in] wym_x szerokosc obrazka						            *
 * \param[in] wym_y wysokosc obrazka						            *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] piksele tablica, w ktorej zostanie zapisany zmodyfikowany*
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int progowanie(struct_obrazka *obrazek, t_opcje *opcje)
{
    int max_szarosc = obrazek->szarosci;
    float prog_proc = opcje->w_progu;
    float prog;

    prog = max_szarosc * (prog_proc / 100);

    if (prog >= 0 && prog <= max_szarosc)
    {
        if (obrazek->nr_magiczny == 2) /*sprawdzamy format obrazka*/
            progowanie2(obrazek, opcje, prog, max_szarosc);

        if (obrazek->nr_magiczny == 3) /*wilkosc wym_x wieksza 3 razy*/
        {
            if (opcje->r == 1)
                progowanie3r(obrazek, opcje, prog, max_szarosc);
            if (opcje->g == 1)
                progowanie3g(obrazek, opcje, prog, max_szarosc);
            if (opcje->b == 1)
                progowanie3b(obrazek, opcje, prog, max_szarosc);
            else
                progowanie3(obrazek, opcje, prog, max_szarosc);
        }
    }
    else
        fprintf(stderr, "BLAD: Niewlasciwa wartosc progu!\n");
    return 0;
}

/************************************************************************
 * Funkcja konturowania                               	       	       	*
 * \param[in] piksele tablica, z ktorej zostanie zapisany obraz		    *
 * \param[in] wym_x szerokosc obrazka						            *
 * \param[in] wym_y wysokosc obrazka						            *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] piksele tablica, w ktorej zostanie zapisany zmodyfikowany*
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int konturowanie(struct_obrazka *obrazek, t_opcje *opcje)
{

    if (obrazek->nr_magiczny == 2) /*sprawdzamy format obrazka*/
        konturowanie2(obrazek);

    if (obrazek->nr_magiczny == 3) /*jesli format (.ppm) wym_x trzy razy wiekszy*/
    {
        if (opcje->r == 1)
            konturowanie3r(obrazek);
        if (opcje->g == 1)
            konturowanie3g(obrazek);
        if (opcje->b == 1)
            konturowanie3b(obrazek);
        else
            konturowanie3(obrazek);
    }
    return 0;
}

/************************************************************************************
 * Funkcja konwersji kolorowego obrazka do obrazka w odcieniach szarosci            *
 * \param[in]  nr_magiczny zmienna, pamietajaca stary format pliku                *
 * \param[in]  piksele tablica, z ktorej zostanie pobrany obraz zrodlowy            *
 * \param[in]  wym_x szerokosc obrazka                                             *
 * \param[in]  wym_y wysokosc obrazka                                              *
 * \param[in]  szarosci liczba odcieni szarosci                                   *
 * \param[out] nr_magiczny zmienna, pamietajaca nowy format pliku                 *
 * \param[out] piksele tablica, do ktorej zostanie zapisany kontur obrazu           *
 * \return liczba wczytanych pikseli                                                *
 ************************************************************************************/
int konwersja(struct_obrazka *obrazek)
{
    int i, j, pom = 0;

    obrazek->nr_magiczny = 2; /*zmiana nr_magicznego z P3 na P2/

     /*obliczanie poziomu szarosci jednego punktu na podstawie wartosci trzech kolorowych*/
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 0; j < obrazek->wym_x; j++)
        {
            obrazek->piksele[i][j] = ((obrazek->piksele[i][pom] + obrazek->piksele[i][pom + 1] + obrazek->piksele[i][pom + 2]) / 3);
            pom = pom + 3;
        }
        pom = 0; /*zabieg zapewniajacy dzialanie w każdym wierszu tablicy*/
    }
    pom = 0; /*zabieg zapewniajacy dzialanie wielokrotne funkcji*/
    return 0;
}