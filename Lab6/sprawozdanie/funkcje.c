#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "funkcje.h"

/********************************************************/
/*   Funkcja wkładnaia elementu na stos                 */
/********************************************************/
void push(struct Stack *stos, int element)
{
    struct Pojemnik *nowy_pojemnik = (struct Pojemnik *)malloc(sizeof(struct Pojemnik));
    nowy_pojemnik->dane = element;
    nowy_pojemnik->nastepny = stos->head;
    stos->head = nowy_pojemnik;
}

/********************************************************/
/*   Funkcja usuwania elementu ze stosu                 */
/********************************************************/
void pop(struct Stack *stos, int *element)
{
    if (stos->head == NULL)
    {
        printf("Blad: stos jest pusty\n");
        return;
    }
    struct Pojemnik *pom = stos->head;
    *element = pom->dane;
    stos->head = pom->nastepny;
    free(pom);
}

/********************************************************/
/*   Funkcja sprawdza czy stos jest pusty               */
/********************************************************/
int empty(struct Stack *stos)
{
    if (stos->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/********************************************************/
/*   Funkcja usuwa wszystkie elementy stosu             */
/********************************************************/
void wyczysc(struct Stack *stos)
{
    struct Pojemnik *pom = stos->head;
    while (pom != NULL)
    {
        stos->head = pom->nastepny;
        free(pom);
        pom = stos->head;
    }
}

/********************************************************/
/*   Funkcja wyswietla cały stos                        */
/********************************************************/
void fullprint(struct Stack *stos)
{
    struct Pojemnik *pom = stos->head;

    while (pom != NULL)
    {
        printf("%d ", pom->dane);
        pom = pom->nastepny;
    }
    printf("\n");
}

/********************************************************/
/*   Funkcja duplikuje ostatni element                  */
/********************************************************/
void duplikuj(struct Stack *stos)
{

    int element = stos->head->dane;
    push(stos, element);
}

/********************************************************/
/*   Funkcja zamienia dwa ostatnie elementy             */
/********************************************************/
void zamiana(struct Stack *stos)
{

    int pom1 = stos->head->dane;
    pop(stos, &pom1);
    int pom2 = stos->head->dane;
    pop(stos, &pom2);
    push(stos, pom1);
    push(stos, pom2);
}

/********************************************************/
/*   Funkcja wyswietla szczyt stosu                     */
/********************************************************/
void print(struct Stack *stos)
{
    struct Pojemnik *pom = stos->head;
    if (pom != NULL)
    {
        printf("%d ", pom->dane);
        printf("\n");
    }
}

/********************************************************/
/*   Funkcja inicjuje stos                              */
/********************************************************/
void init(struct Stack *stos)
{
    stos->head = NULL;
}

/********************************************************/
/*   Funkcja wczytuje liczbe dodatnia lub ujemna        */
/********************************************************/
int czytaj_liczbe(char *wejscie, int *liczba)
{

    if ((isdigit(wejscie[0]) != 0) || wejscie[0] == '-' && (isdigit(wejscie[1]) != 0)) /*sprawdzamy czy wejscie jest liczbą dodatnią lub ujemną*/
    {
        *liczba = atoi(wejscie);
    }
    return 0;
}

/********************************************************/
/*   Funkcja dodaje dwie ostatnie liczby na stosie      */
/********************************************************/
void dodaj(struct Stack *stos)
{

    int pom1 = stos->head->dane;
    pop(stos, &pom1);
    int pom2 = stos->head->dane;
    pop(stos, &pom2);
    int pom3 = pom1 + pom2;
    push(stos, pom3);
}

/********************************************************/
/*   Funkcja odejmuje dwie ostatnie liczby na stosie    */
/********************************************************/
void odejmij(struct Stack *stos)
{

    int pom1 = stos->head->dane;
    pop(stos, &pom1);
    int pom2 = stos->head->dane;
    pop(stos, &pom2);
    int pom3 = pom1 - pom2;
    push(stos, pom3);
}

/********************************************************/
/*   Funkcja mnozy dwie ostatnie liczby na stosie       */
/********************************************************/
void pomnoz(struct Stack *stos)
{

    int pom1 = stos->head->dane;
    pop(stos, &pom1);
    int pom2 = stos->head->dane;
    pop(stos, &pom2);
    int pom3 = pom1 * pom2;
    push(stos, pom3);
}

/********************************************************/
/*   Funkcja dzieli dwie ostatnie liczby na stosie      */
/********************************************************/
void podziel(struct Stack *stos)
{

    int pom1 = stos->head->dane;
    pop(stos, &pom1);
    int pom2 = stos->head->dane;
    pop(stos, &pom2);
    int pom3 = pom1 / pom2;
    push(stos, pom3);
}
/********************************************************/
/*   Funkcja wyswietla menu                             */
/********************************************************/
void menu()
{
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                Kalkulator RPN                    +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                     OPCJE                        +\n");
    printf("+---------------------------------------------------\n");
    printf("+    P - usunięcie ostatnio wprowadzonej liczby    +\n");
    printf("+    c - usunięcie wszystkich elementów            +\n");
    printf("+    r - zamiana miejscami dwóch ostatnich         +\n");
    printf("+    d - zduplikowanie ostatniego elementu         +\n");
    printf("+    p - pokazanie ostatniego elementu             +\n");
    printf("+    f - pokaz cala zawartosc stosu                +\n");
    printf("+    q - zamknij kalkulator                        +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

/********************************************************/
/*   Funkcja wyswietla zapytanie o wejscie              */
/********************************************************/
void zapytanie()
{
    printf("\n");
    printf("Podaj liczbe, znak lub opcje: ");
}

/********************************************************/
/*   Switch: case P:                                    */
/********************************************************/
void caseP(struct Stack *stos, int *liczba)
{
    pop(stos, liczba);
    system("clear");
    menu();
    printf("Liczba usunieta ze stosu: %d\n", *liczba);
}
/********************************************************/
/*   Switch: case c:                                    */
/********************************************************/
void casec(struct Stack *stos)
{
    wyczysc(stos);
    system("clear");
    menu();
    printf("Stos zostal wyczyszczony\n");
}
/********************************************************/
/*   Switch: case r:                                    */
/********************************************************/
void caser(struct Stack *stos)
{
    if (stos->head == NULL || stos->head->nastepny == NULL)
    {
        system("clear");
        menu();
        printf("Blad: stos jest pusty\n");
    }
    else
    {
        zamiana(stos);
        system("clear");
        menu();
        printf("Dwie ostatnie liczby zostały zamienione\n");
    }
}
/********************************************************/
/*   Switch: case d:                                    */
/********************************************************/
void cased(struct Stack *stos, int *liczba)
{
    if (stos->head == NULL)
    {
        system("clear");
        menu();
        printf("Blad: stos jest pusty\n");
    }
    else
    {
        duplikuj(stos);
        system("clear");
        menu();
        printf("Zduplikowano ostatnia liczbe\n");
    }
}

/********************************************************/
/*   Switch: case p:                                    */
/********************************************************/
void casep(struct Stack *stos)
{
    if (stos->head == NULL)
    {
        system("clear");
        menu();
        printf("Blad: stos jest pusty\n");
    }
    else
    {
        system("clear");
        menu();
        printf("Ostatni element stosu: ");
        print(stos);
    }
}

/********************************************************/
/*   Switch: case f:                                    */
/********************************************************/
void casef(struct Stack *stos)
{
    if (stos->head == NULL)
    {
        system("clear");
        menu();
        printf("Blad: stos jest pusty\n");
    }
    else
    {
        system("clear");
        menu();
        printf("Zawartosc stosu: ");
        fullprint(stos);
    }
}

/********************************************************/
/*   Switch: case +:                                    */
/********************************************************/
void caseplus(struct Stack *stos)
{
    if (stos->head == NULL || stos->head->nastepny == NULL)
    {
        system("clear");
        menu();
        printf("Blad: brak wystarczajacej ilosci elementow do wykonania\n");
    }
    else
    {
        dodaj(stos);
        system("clear");
        menu();
        printf("Wykonano operacje dodwania dwoch ostatnich liczby\n");
    }
}
/********************************************************/
/*   Switch: case -:                                    */
/********************************************************/
void caseminus(struct Stack *stos)
{
    if (stos->head == NULL || stos->head->nastepny == NULL)
    {
        system("clear");
        menu();
        printf("Blad: brak wystarczajacej ilosci elementow do wykonania\n");
    }
    else
    {
        odejmij(stos);
        system("clear");
        menu();
        printf("Wykonano operacje odejmowania dwoch ostatnich liczby\n");
    }
}
/********************************************************/
/*   Switch: case *:                                    */
/********************************************************/
void caseiloczyn(struct Stack *stos)
{
    if (stos->head == NULL || stos->head->nastepny == NULL)
    {
        system("clear");
        menu();
        printf("Blad: brak wystarczajacej ilosci elementow do wykonania\n");
    }
    else
    {
        pomnoz(stos);
        system("clear");
        menu();
        printf("Wykonano operacje mnożenia dwoch ostatnich liczby\n");
    }
}
/********************************************************/
/*   Switch: case /:                                    */
/********************************************************/
void caseiloraz(struct Stack *stos)
{
    if (stos->head == NULL || stos->head->nastepny == NULL)
    {
        system("clear");
        menu();
        printf("Blad: brak wystarczajacej ilosci elementow do wykonania\n");
    }
    else
    {
        podziel(stos);
        system("clear");
        menu();
        printf("Wykonano operacje dzielenia calkowitego dwoch ostatnich liczby\n");
    }
}
