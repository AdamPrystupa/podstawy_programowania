#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct Pojemnik
{
    int dane;
    struct Pojemnik *nastepny;
};

struct Stack
{
    struct Pojemnik *head;
};

void push(struct Stack *stos, int element);
void pop(struct Stack *stos, int *element);
int empty(struct Stack *stos);
void wyczysc(struct Stack *stos);
void zamiana(struct Stack *stos);
void duplikuj(struct Stack *stos);
void fullprint(struct Stack *stos);
void print(struct Stack *stos);
void init(struct Stack *stos);
void dodaj(struct Stack *stos);
void odejmij(struct Stack *stos);
void pomnoz(struct Stack *stos);
void podziel(struct Stack *stos);
int czytaj_liczbe(char *wejscie, int *liczba);
void menu();
void zapytanie();
void caseP(struct Stack *stos, int *liczba);
void casec(struct Stack *stos);
void caser(struct Stack *stos);
void cased(struct Stack *stos, int *liczba);
void casep(struct Stack *stos);
void casef(struct Stack *stos);
void caseplus(struct Stack *stos);
void caseminus(struct Stack *stos);
void caseiloraz(struct Stack *stos);
void caseiloczyn(struct Stack *stos);
