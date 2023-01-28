#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "funkcje.h"
#define MAX_DLUGOSC 100

int main()
{

    int arg;
    char wejscie[MAX_DLUGOSC];

    struct Stack stos_obj;
    struct Stack *stos = &stos_obj;
    printf("++++++++++++++++++++++++++\n");
    printf("+     Kalkulator RPN     +\n");
    printf("++++++++++++++++++++++++++\n");
    printf("+          OPCJE         +\n");
    printf("+ P- usunięcie ostatnio wprowadzonej liczby+\n");
    printf("+ c- usunięcie wszystkich elementów +\n");
    printf("+ r- zamiana miejscami dwóch ostatnich+\n");
    printf("+d- zduplikowanie ostatniego elementu+\n");
    printf("+p- pokazanie ostatniego elementu+\n");
    do
    {
        if (scanf("%s", wejscie) == 1)

            init(stos);
        arg = 7;
        push(stos, arg);
        arg = 14;
        push(stos, arg);
        print(stos);
        arg = 7;
        pop(stos, &arg);
        print(stos);
        printf("Zdjeta wartosc: %d\n", arg);
    } while (wejscie != 'q');

    return 0;
}