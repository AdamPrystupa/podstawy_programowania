#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
void pop(struct Stack* stos, int* element) {
    if (stos->head == NULL) {
        printf("Error: Stack is empty\n");
        return;
    }
    struct Pojemnik* pom = stos->head;
    *element = pom->dane;
    stos->head = pom->nastepny;
    free(pom);
}

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

void print(struct Stack *stos)
{
    struct Pojemnik *pom = stos->head;
    while (pom != NULL)
    {
        printf("%d ", pom->dane);
        pom = pom->nastepny;
    }
    printf("\n");
}

void init(struct Stack *stos)
{
    stos->head = NULL;
}
