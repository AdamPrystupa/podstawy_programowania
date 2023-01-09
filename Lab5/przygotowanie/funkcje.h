#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1024        /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 2048     /* Dlugosc buforow pomocniczych */
#define odczekaj 1      /*Czas wyświetlania komunikatu w sekundach*/

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci);
void wyswietl(char *n_pliku);
int zapisz(FILE *plik_wyj,int obraz[][MAX],int *wymx,int *wymy, int *szarosci,char nazwa_zapisu[]);
int negatyw(int obraz[][MAX],int *wymx,int *wymy, int *szarosci);
int progowanie(int obraz[][MAX],int *wymx,int *wymy, int *szarosci);
int konturowanie(int obraz[][MAX],int *wymx,int *wymy, int *szarosci);
int rozmycie_poziome(int obraz[][MAX],int *wymx,int *wymy, int *szarosci);
int rozmycie_pionowe(int obraz[][MAX],int *wymx,int *wymy, int *szarosci);
int rozciaganie_histogramu(int obraz[][MAX],int *wymx,int *wymy, int *szarosci);
int poprawnosc_pliku(char nazwa[100]);
