#include <stdio.h>
#define ROZMIAR_TAB 10
int tablica[ROZMIAR_TAB][ROZMIAR_TAB];


int wypelnij(int *tab, int x, int y)
    
    {
        for (int i=0; i<x; i++)
        {
            for (int j=0; j<y; j++)
            *(tab++)=i*j;
                
        }
    }
    
    
int wypisz(int *tab, int x, int y)
    
    {
        for (int i=0; i<x; i++)
        {
            for (int j=0; j<y; j++)
            printf("%d ",*(tab++));
            printf("\n");
        }
    }
    
    
int zmien_znaki(int *tab, int x, int y)
    
    {
        for (int i=0; i<x; i++)
        {
            for (int j=0; j<y; j++)
            *(tab++)*=(-1);
        }
    }
    
    
int main()
{
    int *obraz;
    obraz=&tablica[0][0];
    int x=4, y=5;
    wypelnij(obraz,x,y);
    printf("Zawartość oryginalna: \n");
    wypisz(obraz,x,y);
    zmien_znaki(obraz,x,y);
    printf("Zawartość po zmianie znaku: \n");
    wypisz(obraz,x,y);

    return 0;
}
