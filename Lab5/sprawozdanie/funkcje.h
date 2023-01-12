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
    int **piksele;
}struct_obrazka;


/* strukura do zapamietywania opcji podanych w wywolaniu programu */
typedef struct {
  FILE *plik_we, *plik_wy;        /* uchwyty do pliku wej. i wyj. */
  int negatyw,progowanie,konturowanie,wyswietlenie,r,g,b,nie_kolorowy;      /* opcje */
  int w_progu;   /* wartosc progu dla opcji progowanie */ 
  char *do_wyswietlania;   /*pomocnicza ulatwiajaca wyswietlanie obrazkas*/        
} t_opcje;

int czytaj(t_opcje *opcje, struct_obrazka *obrazek);
void wyswietl(t_opcje *opcje);
int zapisz(t_opcje *opcje,struct_obrazka *obrazek);
int negatyw(struct_obrazka *obrazek);
int progowanie(struct_obrazka *obrazek, t_opcje *opcje);
int konturowanie(struct_obrazka *obrazek);
int przetwarzaj_opcje(int argc, char **argv, t_opcje *wybor);
int konwersja(struct_obrazka *obrazek);


