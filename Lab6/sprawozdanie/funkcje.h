#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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
void pop(struct Stack* stos, int* element);
int empty(struct Stack *stos);
void print(struct Stack *stos);
void init(struct Stack *stos);

