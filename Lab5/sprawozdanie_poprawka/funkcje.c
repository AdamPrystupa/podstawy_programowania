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

char nazwa[DL_LINII]; /*bufor do czytania nazwy pliku*/
char bufor[DL_LINII]; /*bufor pomocniczy do czytania komentarzy i naglowka*/
int znak;             /*zmienna pomocnicza do komentarzy*/
int koniec = 0;       /*zmienna pomocna w szukaniu konca danych*/
int i, j, k;          /*zmienne pomocnicze petli*/
int max_szarosc;
float prog_proc;
float prog;

/************************************************************************************
 * Funkcja sprawdza numer magiczny obrazu                                           *
 ************************************************************************************/

int sprawdz_numer(t_opcje *opcje, struct_obrazka *obrazek)
{
    if (fgets(bufor, DL_LINII, opcje->plik_we) == NULL)
    {
        fprintf(stderr, "BLAD: Plik jest pusty\n");
        return (koniec = 1);
    }
    else
    {
        if (bufor[0] != 'P' || bufor[1] != '2' && bufor[1] != '3')
        {
            fprintf(stderr, "BLAD: Ten plik nie jest formatu PGM ani PPM (nie jest obslugiwany)\n");
            return (koniec = 1);
        }
        else
        { /*Zapisanie formatu pliku w zaleznosci od nr magicznego*/
            if (bufor[1] == '2')
            {
                obrazek->nr_magiczny = 2;
            }

            if (bufor[1] == '3')
            {
                obrazek->nr_magiczny = 3;
            }
        }
    }
    return 0;
}

/************************************************************************************
 * Funkcja pomija komentarze                                                        *
 ************************************************************************************/

int pomin_komentarze(t_opcje *opcje)
{
    do
    {
        if ((znak = fgetc(opcje->plik_we)) == '#')
        {                                                       /* Czy linia rozpoczyna sie od znaku '#'? */
            if (fgets(bufor, DL_LINII, opcje->plik_we) == NULL) /* Przeczytaj ja do bufora                */
                koniec = 1;                                     /* Zapamietaj ewentualny koniec danych */
        }
        else
        {
            ungetc(znak, opcje->plik_we); /* Gdy przeczytany znak z poczatku linii */
        }                                 /* nie jest '#' zwroc go                 */
    } while (znak == '#' && !koniec);     /* Powtarzaj dopoki sa linie komentarza */
                                          /* i nie nastapil koniec danych         */
    return 0;
}

/************************************************************************************
 * Funkcja wczytuje wymiary obrazu                                                  *
 ************************************************************************************/

int wczytaj_wymiary(t_opcje *opcje, struct_obrazka *obrazek)
{
    if (fscanf(opcje->plik_we, "%d %d %d", &obrazek->wym_x, &obrazek->wym_y, &obrazek->szarosci) != 3)
    {
        fprintf(stderr, "BLAD: Brak jednego z parametrow: wysokosc, szerokosc, ilosc stopni szarosci!\n");
        return 1;
    }
    return 0;
}

/************************************************************************************
 * Funkcja przydziela pamiec dla obrazkow                                           *
 ************************************************************************************/

int przydziel_pamiec(struct_obrazka *obrazek)
{
    if (obrazek->nr_magiczny == 2) /*obrazek pgm*/
    {
        obrazek->piksele = (int **)malloc(obrazek->wym_y * sizeof(int *));
        for (i = 0; i < obrazek->wym_y; i++)
            obrazek->piksele[i] = (int *)malloc(obrazek->wym_x * sizeof(int));

        if (obrazek->piksele == NULL) /*Sprawdzenie powodzenia przydzielania pamieci*/
        {
            fprintf(stderr, "BLAD: Niepowodzenie przy przydzielaniu pamieci!\n");
            return 1;
        }
    }
    if (obrazek->nr_magiczny == 3) /*obrazek ppm*/
    {
        obrazek->piksele = (int **)malloc(obrazek->wym_y * sizeof(int *));
        for (i = 0; i < obrazek->wym_y; i++)
            obrazek->piksele[i] = (int *)malloc(obrazek->wym_x * 3 * sizeof(int));

        if (obrazek->piksele == NULL) /*Sprawdzenie powodzenia przydzielania pamieci*/
        {
            fprintf(stderr, "BLAD: Niepowodzenie przy przydzielaniu pamieci!\n");
            return 1;
        }
    }
}

/************************************************************************************
 * Funkcja zapelnia przydzielona pamiec wartosciami                                 *
 ************************************************************************************/

int zapelnij_piksele(t_opcje *opcje, struct_obrazka *obrazek)
{
    if (obrazek->nr_magiczny == 2) /*obrazek pgm*/
    {

        for (j = 0; j < obrazek->wym_y; j++)
        {
            for (k = 0; k < obrazek->wym_x; k++)
            {
                if (fscanf(opcje->plik_we, "%d", &obrazek->piksele[j][k]) != 1)
                {
                    fprintf(stderr, "BLAD: Niepoprawne wymiary obrazka\n");
                    return 1;
                }
            }
        }
    }

    if (obrazek->nr_magiczny == 3) /*obrazek ppm*/
    {

        for (j = 0; j < obrazek->wym_y; j++)
        {
            for (k = 0; k < obrazek->wym_x * 3; k++)
            {
                if (fscanf(opcje->plik_we, "%d", &obrazek->piksele[j][k]) != 1)
                {
                    fprintf(stderr, "BLAD: Niepoprawne wymiary obrazka\n");
                    return 1;
                }
            }
        }
    }

    return 0;
}

/************************************************************************************
 * Negatyw dla obrazkow pgm                                                          *
 ************************************************************************************/

int negatyw2(struct_obrazka *obrazek, t_opcje *opcje)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 0; j < obrazek->wym_x; j++)
            obrazek->piksele[i][j] = obrazek->szarosci - obrazek->piksele[i][j];
    }
    return 0;
}

/************************************************************************************
 * Negatyw dla obrazkow ppm kolor czerwony                                           *
 ************************************************************************************/

int negatyw3r(struct_obrazka *obrazek, t_opcje *opcje)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 0; j < obrazek->wym_x * 3; j += 3)
        {

            obrazek->piksele[i][j] = obrazek->szarosci - obrazek->piksele[i][j];
        }
    }
    return 0;
}

/************************************************************************************
 * Negatyw dla obrazkow ppm kolor zielony                                          *
 ************************************************************************************/
int negatyw3g(struct_obrazka *obrazek, t_opcje *opcje)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 1; j < obrazek->wym_x * 3; j += 3)
        {
            obrazek->piksele[i][j] = obrazek->szarosci - obrazek->piksele[i][j];
        }
    }
    return 0;
}

/************************************************************************************
 * Negatyw dla obrazkow ppm kolor zielony                                          *
 ************************************************************************************/
int negatyw3b(struct_obrazka *obrazek, t_opcje *opcje)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 2; j < obrazek->wym_x * 3; j += 3)
        {
            obrazek->piksele[i][j] = obrazek->szarosci - obrazek->piksele[i][j];
        }
    }
    return 0;
}

/************************************************************************************
 * Negatyw dla obrazkow ppm po konwersji do szarosci                                 *
 ************************************************************************************/
int negatyw3(struct_obrazka *obrazek, t_opcje *opcje)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 0; j < obrazek->wym_x * 3; j++)
        {
            obrazek->piksele[i][j] = obrazek->szarosci - obrazek->piksele[i][j];
        }
    }
    return 0;
}

/************************************************************************************
 * Progowanie dla obrazkow ppm po konwersji do szarosci                              *
 ************************************************************************************/
int progowanie2(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc)
{

    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 0; j < obrazek->wym_x; j++)
        {
            if (obrazek->piksele[i][j] <= prog)
                obrazek->piksele[i][j] = 0;
            else
                obrazek->piksele[i][j] = max_szarosc;
        }
    }
    return 0;
}

/************************************************************************************
 * Progowanie dla obrazkow ppm w kolorze czerwonym                             *
 ************************************************************************************/
int progowanie3r(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 0; j < obrazek->wym_x * 3; j += 3)
        {
            if (obrazek->piksele[i][j] <= prog)
                obrazek->piksele[i][j] = 0;
            else
                obrazek->piksele[i][j] = max_szarosc;
        }
    }
    return 0;
}

/************************************************************************************
 * Progowanie dla obrazkow ppm w kolorze zielonym                             *
 ************************************************************************************/
int progowanie3g(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 1; j < obrazek->wym_x * 3; j += 3)
        {
            if (obrazek->piksele[i][j] <= prog)
                obrazek->piksele[i][j] = 0;
            else
                obrazek->piksele[i][j] = max_szarosc;
        }
    }
    return 0;
}
/************************************************************************************
 * Progowanie dla obrazkow ppm w kolorze niebiesim                              *
 ************************************************************************************/
int progowanie3b(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc)

{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 2; j < obrazek->wym_x * 3; j += 3)
        {
            if (obrazek->piksele[i][j] <= prog)
                obrazek->piksele[i][j] = 0;
            else
                obrazek->piksele[i][j] = max_szarosc;
        }
    }
    return 0;
}
/************************************************************************************
 * Progowanie dla obrazkow ppm po konwersji do szarosci                              *
 ************************************************************************************/
int progowanie3(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc)
{
    for (i = 0; i < obrazek->wym_y; i++)
    {
        for (j = 0; j < obrazek->wym_x * 3; j++)
        {
            if (obrazek->piksele[i][j] <= prog)
                obrazek->piksele[i][j] = 0;
            else
                obrazek->piksele[i][j] = max_szarosc;
        }
    }
    return 0;
}

/************************************************************************************
 * Konturowanie dla obrazkow ppm po konwersji do szarosci                              *
 ************************************************************************************/
int konturowanie2(struct_obrazka *obrazek)
{
    for (i = 0; i < obrazek->wym_y - 1; i++)
    {
        for (j = 0; j < obrazek->wym_x; j++)
            obrazek->piksele[i][j] = (abs(obrazek->piksele[i + 1][j] - obrazek->piksele[i][j]) + abs(obrazek->piksele[i][j + 1] - obrazek->piksele[i][j]));
    }
    return 0;
}

/************************************************************************************
 * Konturowanie dla obrazkow ppm po konwersji do szarosci                              *
 ************************************************************************************/
int konturowanie3r(struct_obrazka *obrazek)

{
    for (i = 0; i < obrazek->wym_y - 1; i++)
    {
        for (j = 0; j < obrazek->wym_x * 3; j += 3)
            obrazek->piksele[i][j] = (abs(obrazek->piksele[i + 1][j] - obrazek->piksele[i][j]) + abs(obrazek->piksele[i][j + 1] - obrazek->piksele[i][j]));
    }
    return 0;
}
/************************************************************************************
 * Konturowanie dla obrazkow ppm po konwersji do szarosci                              *
 ************************************************************************************/
int konturowanie3g(struct_obrazka *obrazek)

{
    for (i = 0; i < obrazek->wym_y - 1; i++)
    {
        for (j = 1; j < obrazek->wym_x * 3; j += 3)
            obrazek->piksele[i][j] = (abs(obrazek->piksele[i + 1][j] - obrazek->piksele[i][j]) + abs(obrazek->piksele[i][j + 1] - obrazek->piksele[i][j]));
    }
    return 0;
}
/************************************************************************************
 * Konturowanie dla obrazkow ppm po konwersji do szarosci                              *
 ************************************************************************************/
int konturowanie3b(struct_obrazka *obrazek)
{
    for (i = 0; i < obrazek->wym_y - 1; i++)
    {
        for (j = 2; j < obrazek->wym_x * 3; j += 3)
            obrazek->piksele[i][j] = (abs(obrazek->piksele[i + 1][j] - obrazek->piksele[i][j]) + abs(obrazek->piksele[i][j + 1] - obrazek->piksele[i][j]));
    }
    return 0;
}
/************************************************************************************
 * Konturowanie dla obrazkow ppm po konwersji do szarosci                              *
 ************************************************************************************/
int konturowanie3(struct_obrazka *obrazek)
{
    for (i = 0; i < obrazek->wym_y - 1; i++)
    {
        for (j = 0; j < obrazek->wym_x * 3; j += 3)
            obrazek->piksele[i][j] = (abs(obrazek->piksele[i + 1][j] - obrazek->piksele[i][j]) + abs(obrazek->piksele[i][j + 1] - obrazek->piksele[i][j]));
    }
    return 0;
}