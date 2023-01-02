#include <stdio.h>
#define ROZMIAR_TAB 10
int tablica[ROZMIAR_TAB][ROZMIAR_TAB];

int wypelnij(int x, int y)
    
    {
        for (int i=0; i<x; i++)
        {
            for (int j=0; j<y; j++)
            tablica[i][j]=i*j;
        }
    }
    
int wypisz(int x, int y)
    
    {
        for (int i=0; i<x; i++)
        {
            for (int j=0; j<y; j++)
            printf("%d ",tablica[i][j]);
            printf("\n");
        }
    }
    
int zmien_znaki(int x, int y)
    
    {
        for (int i=0; i<x; i++)
        {
            for (int j=0; j<y; j++)
            tablica[i][j]*=(-1);
        }
    }
    
    
int main()
{
    int x=3, y=7;
    wypelnij(x,y);
    printf("Zawartość oryginalna: \n");
    wypisz(x,y);
    zmien_znaki(x,y);
    printf("Zawartość po zmianie znaku: \n");
    wypisz(x,y);

    return 0;
}

