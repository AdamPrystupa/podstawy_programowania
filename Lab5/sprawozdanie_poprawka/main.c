#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main(int argc, char **argv)
{
    struct_obrazka obrazek;
    t_opcje opcje;
    int kod_bledu;

    kod_bledu = przetwarzaj_opcje(argc, argv, &opcje);

    if (kod_bledu)
        printf("Blad nr %d\n", kod_bledu);
    else if (czytaj(&opcje, &obrazek) != 0)
        fprintf(stderr, "BLAD: Wczytywanie nie udalo sie!");

    if (opcje.nie_kolorowy == 1)
    {
        if (konwersja(&obrazek) != 0)
            fprintf(stderr, "BLAD: Konwersja do szarosci sie nie powiodla!");
    }

    if (opcje.konturowanie == 1)
    {
        if (konturowanie(&obrazek, &opcje) != 0)
            fprintf(stderr, "BLAD: Konturowanie nie powiodlo sie!");
    }

    if (opcje.negatyw == 1)
    {
        if (negatyw(&obrazek, &opcje) != 0)
            fprintf(stderr, "BLAD: Negatywowanie nie powiodlo sie!");
    }

    if (opcje.progowanie == 1)
    {
        if (progowanie(&obrazek, &opcje) != 0)
            fprintf(stderr, "BLAD: Progowanie nie powiodlo sie!");
    }

    zapisz(&opcje, &obrazek);
    if (opcje.wyswietlenie == 1)
        wyswietl(&opcje);

    return kod_bledu;
}
