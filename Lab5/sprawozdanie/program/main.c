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

    if (opcje.wyswietlenie == 1)
    {
        if (opcje.plik_wy == stdout) /*W przypadku kiedy użytkownik chce wyswietlic plik ale go nie zapisywać*/
        {
            if (obrazek.nr_magiczny == 2)
                zapis_temp2(&opcje, &obrazek);

            if (obrazek.nr_magiczny == 3)
                zapis_temp3(&opcje, &obrazek);
        }
        else
        {
            zapisz(&opcje, &obrazek); /*Musi tu byc, zeby dalo sie wyswietlic nieedytowany plik*/
            wyswietl(&opcje);
        }
    }
    if (opcje.wyswietlenie == 0)
    {
        zapisz(&opcje, &obrazek);
    }

    // free(obrazek.piksele);
    return kod_bledu;
}
