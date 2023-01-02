#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "funkcje.h"

#define MAX 1024        /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 2048     /* Dlugosc buforow pomocniczych */
#define W_OK 0                   /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1    /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY   -2
#define B_BRAKWARTOSCI  -3
#define B_BRAKPLIKU   -4

typedef struct 
{
    int nr_magiczny;
    int wym_x, wym_y, szarosci;
    void *piksele;
}struct_obrazka;

                       

/************************************************************************
 * Funkcja negatywu      	       	       	                            *
 * \param[in] obraz tablica, z ktorej zostanie wczytany obraz		    *
 * \param[in] wymx szerokosc obrazka						            *
 * \param[in] wymy wysokosc obrazka						                *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] obraz tablica, w ktorej zostanie zapisany zmodyfikowany  *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int negatyw(struct_obrazka *obrazek)
{
    return 1;
}

/************************************************************************
 * Funkcja progowania                                 	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie wczytany obraz		    *
 * \param[in] wymx szerokosc obrazka						            *
 * \param[in] wymy wysokosc obrazka						                *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] obraz tablica, w ktorej zostanie zapisany zmodyfikowany  *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int progowanie(struct_obrazka *obrazek)
{
    return 1;
}

/************************************************************************
 * Funkcja konturowania                               	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		    *
 * \param[in] wymx szerokosc obrazka						            *
 * \param[in] wymy wysokosc obrazka						                *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] obraz tablica, w ktorej zostanie zapisany zmodyfikowany  *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int konturowanie(struct_obrazka *obrazek)

  {
  return 1;   /* Zapis zakonczończony sukcesem    */
  }

/************************************************************************
 * Funkcja rozmycia poziomego                          	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		    *
 * \param[in] wymx szerokosc obrazka						            *
 * \param[in] wymy wysokosc obrazka						                *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] obraz tablica, w ktorej zostanie zapisany zmodyfikowany  *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int rozmycie_poziome(struct_obrazka *obrazek)

  {
    return 1;   /* Zapis zakonczończony sukcesem    */
  }


/************************************************************************
 * Funkcja rozmycia pionowego                          	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		    *
 * \param[in] wymx szerokosc obrazka						            *
 * \param[in] wymy wysokosc obrazka						                *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int rozmycie_pionowe(struct_obrazka *obrazek)

  {
    return 1;   /* Zapis zakonczończony sukcesem    */
  }

/************************************************************************
 * Funkcja rozciągania histogramu                      	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		    *
 * \param[in] wymx szerokosc obrazka						            *
 * \param[in] wymy wysokosc obrazka						                *
 * \param[in] szarosci liczba odcieni szarosci					        *
 * \param[out] obraz tablica, w ktorej zostanie zapisany zmodyfikowany  *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int rozciaganie_histogramu(struct_obrazka *obrazek)
{
 return 1;   /* Zapis zakonczończony sukcesem    */
}

