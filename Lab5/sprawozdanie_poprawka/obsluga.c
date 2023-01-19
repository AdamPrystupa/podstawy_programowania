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

/************************************************************************************
 * Funkcja wczytuje obraz z podanego pliku do tablicy                               *                                              *
 *                                                                                  *
 * \param[out] piksele  tablica, do ktorej zostanie zapisany obraz                  *
 * \param[out] wym_x  szerokosc obrazka                                             *
 * \param[out] wym_y  wysokosc obrazka                                              *
 * \param[out] szarosci  liczba odcieni szarosci                                    *
 * \return liczba wczytanych pikseli                                                *
 ************************************************************************************/
int czytaj(t_opcje *opcje, struct_obrazka *obrazek)
{

    /*Warunek poprawnego uchwytu do pliku*/
    if (opcje->plik_we == NULL)
    {
        fprintf(stderr, "BLAD: Niepoprawny uchwyt do pliku!\n");
        return 1;
    }

    /*Sprawdzenie numeru magicznego*/
    sprawdz_numer(opcje, obrazek);

    /*Pomijanie zbednych komentarzy*/
    pomin_komentarze(opcje);

    /*Wczytanie wymiarow obrazka */
    wczytaj_wymiary(opcje, obrazek);

    /*Przydzielanie dynamiczne pamieci w zaleznosci od formatu pliku*/
    przydziel_pamiec(obrazek);

    /*Zapelnienie pamieci przez obraz*/
    zapelnij_piksele(opcje, obrazek);

    return 0;
}

/************************************************************************************
 * Funkcja zapisuje obraz z tablicy do podanego pliku                               *                                              *
 *                                                                                  *
 * \param[in] piksele  tablica, do ktorej zostanie zapisany obraz                  *
 * \param[in] wym_x  szerokosc obrazka                                             *
 * \param[in] wym_y  wysokosc obrazka                                              *
 * \param[in] szarosci  liczba odcieni szarosci                                    *
 * \return 0 gdy wykonana poprawnie                                                *
 ************************************************************************************/
int zapisz(t_opcje *opcje, struct_obrazka *obrazek)
{
    char word[DL_LINII]; /*bufor do wydawania polecen terminalowi*/
    int i, j;

    /*zapisanie na poczatku pliku nr_magicznego, wymiarow, szarosci i ewentualnych komentarzy*/
    fprintf(opcje->plik_wy, "P%d\n", obrazek->nr_magiczny);
    // printf("P% d\n ", obrazek->nr_magiczny);
    fprintf(opcje->plik_wy, "# Plik formatowany poprzez program PRZETWARZANIE\n");
    fprintf(opcje->plik_wy, "%d %d\n", obrazek->wym_x, obrazek->wym_y);
    // printf("% d %d\n ", obrazek->wym_x, obrazek->wym_y);
    fprintf(opcje->plik_wy, "%d\n", obrazek->szarosci);

    /*zapis kolenych pikseli*/
    if (obrazek->nr_magiczny == 2) /*dla formatu .pgm*/
    {
        for (i = 0; i < obrazek->wym_y; i++)
        {
            for (j = 0; j < obrazek->wym_x; j++)
            {
                fprintf(opcje->plik_wy, "%d ", obrazek->piksele[i][j]);
            }
            fprintf(opcje->plik_wy, "\n");
        }
    }

    if (obrazek->nr_magiczny == 3) /*dla formatu .ppm*/
    {
        for (i = 0; i < obrazek->wym_y; i++)
        {
            for (j = 0; j < obrazek->wym_x * 3; j++)
            {
                fprintf(opcje->plik_wy, "%d ", obrazek->piksele[i][j]);
            }
            fprintf(opcje->plik_wy, "\n");
        }
    }
    return 0;
}

/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(t_opcje *opcje)
{
    char word[DL_LINII];      /*bufor do wydawania polecen terminalowi*/
    strcpy(word, "display "); /* konstrukcja polecenia postaci */
    strcat(word, (char *)opcje->do_wyswietlania);
    strcat(word, " &");
    system(word); /* wykonanie polecenia        */
}