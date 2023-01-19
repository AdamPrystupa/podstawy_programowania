#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 4096              /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 2048         /* Dlugosc buforow pomocniczych */
#define W_OK 0                /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1 /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY -2
#define B_BRAKWARTOSCI -3
#define B_BRAKPLIKU -4

typedef struct
{
  int nr_magiczny;
  int wym_x, wym_y, szarosci;
  int **piksele;
} struct_obrazka;

/* strukura do zapamietywania opcji podanych w wywolaniu programu */
typedef struct
{
  FILE *plik_we, *plik_wy;                                                    /* uchwyty do pliku wej. i wyj. */
  int negatyw, progowanie, konturowanie, wyswietlenie, r, g, b, nie_kolorowy; /* opcje */
  int w_progu;                                                                /* wartosc progu dla opcji progowanie */
  char *do_wyswietlania;                                                      /*pomocnicza ulatwiajaca wyswietlanie obrazkas*/
} t_opcje;

int czytaj(t_opcje *opcje, struct_obrazka *obrazek);
void wyswietl(t_opcje *opcje);
int zapisz(t_opcje *opcje, struct_obrazka *obrazek);
int negatyw(struct_obrazka *obrazek, t_opcje *opcje);
int progowanie(struct_obrazka *obrazek, t_opcje *opcje);
int konturowanie(struct_obrazka *obrazek, t_opcje *opcje);
int przetwarzaj_opcje(int argc, char **argv, t_opcje *wybor);
int konwersja(struct_obrazka *obrazek);
int sprawdz_numer(t_opcje *opcje, struct_obrazka *obrazek);
int pomin_komentarze(t_opcje *opcje);
int wczytaj_wymiary(t_opcje *opcje, struct_obrazka *obrazek);
int przydziel_pamiec(struct_obrazka *obrazek);
int zapelnij_piksele(t_opcje *opcje, struct_obrazka *obrazek);
int negatyw2(struct_obrazka *obrazek, t_opcje *opcje);
int negatyw3r(struct_obrazka *obrazek, t_opcje *opcje);
int negatyw3g(struct_obrazka *obrazek, t_opcje *opcje);
int negatyw3b(struct_obrazka *obrazek, t_opcje *opcje);
int negatyw3(struct_obrazka *obrazek, t_opcje *opcje);
int progowanie2(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc);
int progowanie3r(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc);
int progowanie3g(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc);
int progowanie3b(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc);
int progowanie3(struct_obrazka *obrazek, t_opcje *opcje, float prog, int max_szarosc);
int konturowanie2(struct_obrazka *obrazek);
int konturowanie3r(struct_obrazka *obrazek);
int konturowanie3g(struct_obrazka *obrazek);
int konturowanie3b(struct_obrazka *obrazek);
int konturowanie3(struct_obrazka *obrazek);
int zapis_temp2(t_opcje *opcje, struct_obrazka *obrazek);
int zapis_temp3(t_opcje *opcje, struct_obrazka *obrazek);