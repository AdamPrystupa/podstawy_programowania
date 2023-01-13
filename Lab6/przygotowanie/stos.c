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

int main()
{

    int arg;
    struct Stack stos_obj;
    struct Stack *stos = &stos_obj;
    init(stos);
    arg = 7;
    push(stos, arg);
    arg = 14;
    push(stos, arg);
    print(stos);
    arg = 7;
    pop(stos, &arg);
    print(stos);
    printf("Zdjeta wartosc: %d\n",arg);
return 0;
}