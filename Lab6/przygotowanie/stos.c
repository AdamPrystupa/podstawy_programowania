#include <stdio.h>
#include <stdlib.h>

struct Pojemnik
{
    int dane;
    struct Pojemnik *nastepny;
};

struct Stack
{
    struct Pojemnik *head;
};

void push(struct Stack *stos, int element)
{
    struct Pojemnik *nowy_pojemnik = (struct Pojemnik *)malloc(sizeof(struct Pojemnik));
    nowy_pojemnik->dane = element;
    nowy_pojemnik->nastepny = stos->head;
    stos->head = nowy_pojemnik;
}

int pop(struct Stack *stos)
{
    if (stos->head == NULL)
    {
        printf("Error: Stos jest pusty!\n");
        return -1;
    }
    struct Pojemnik *pom = stos->head;
    int element = pom->dane;
    stos->head = pom->nastepny;
    free(pom);
    return element;
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