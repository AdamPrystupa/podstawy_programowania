#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "funkcje.h"
#define MAX_DLUGOSC 100

int main()
{
    char wejscie[MAX_DLUGOSC] = "";
    int liczba;

    struct Stack stos_obj;
    struct Stack *stos = &stos_obj;
    menu();
    init(stos);

    while (wejscie[0] != 'q')
    {
        zapytanie();
        if (fgets(wejscie, sizeof(wejscie), stdin) != NULL) /*jesli poprawnie wczytano wejscie*/

        {
            if (isdigit(wejscie[0]) != 0 || isdigit(wejscie[1]) != 0 && wejscie[0] == '-')
            {

                if (czytaj_liczbe(wejscie, &liczba) != 0)
                    printf("Wystąpil blad wycztywania liczby!!!\n");
                else
                {
                    push(stos, liczba);
                    system("clear");
                    menu();
                    printf("Ostatnia wczytana liczba: %d", liczba);
                }
                printf("\n");
            }
            else
            {

                switch (wejscie[0])
                {
                case 'P':
                {
                    caseP(stos, &liczba);
                    break;
                }
                case 'c':
                {
                    casec(stos);
                    break;
                }
                case 'r':
                {
                    caser(stos);
                    break;
                }
                case 'd':
                {
                    cased(stos, &liczba);
                    break;
                }
                case 'p':
                {
                    casep(stos);
                    break;
                }
                case 'f':
                {
                    casef(stos);
                    break;
                }

                case '+':
                {
                    caseplus(stos);
                    break;
                }
                case '-':
                {
                    caseminus(stos);
                    break;
                }
                case '*':
                {
                    caseiloczyn(stos);
                    break;
                }
                case '/':
                {

                    caseiloraz(stos);
                    break;
                }
                default:
                    if (wejscie[0] != 'q')
                    {
                        system("clear");
                        menu();
                        printf("Podano niepoprawna opcje!!!\n");
                        break;
                    }
                }
            }
        }
    }
    printf("Zakonczono dzialanie programu.\n");

    return 0;
}