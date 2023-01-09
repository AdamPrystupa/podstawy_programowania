#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 2048        /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024    /* Dlugosc buforow pomocniczych */
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

int czytaj(FILE *plik_we, struct_obrazka *obrazek);
void wyswietl(char *n_pliku);
int zapisz(FILE *plik_wyj,struct_obrazka *obrazek,char nazwa_zapisu[]);
int negatyw(struct_obrazka *obrazek);
int progowanie(struct_obrazka *obrazek);
int konturowanie(struct_obrazka *obrazek);
int rozmycie_poziome(struct_obrazka *obrazek);
int rozmycie_pionowe(struct_obrazka *obrazek);
int rozciaganie_histogramu(struct_obrazka *obrazek);
int przetwarzaj_opcje(int argc, char **argv, t_opcje *wybor);
