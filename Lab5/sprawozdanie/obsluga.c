#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "funkcje.h"

#define MAX 2048        /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024    /* Dlugosc buforow pomocniczych */
#define W_OK 0                   /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1    /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY   -2
#define B_BRAKWARTOSCI  -3
#define B_BRAKPLIKU   -4



/************************************************************************************
 * Funkcja wczytuje obraz z podanego pliku do tablicy                               *                                              *
 *                                                                                  *
 * \param[out] piksele  tablica, do ktorej zostanie zapisany obraz                  *
 * \param[out] wym_x  szerokosc obrazka                                             *
 * \param[out] wym_y  wysokosc obrazka                                              *
 * \param[out] szarosci  liczba odcieni szarosci                                    *
 * \return liczba wczytanych pikseli                                                *
 ************************************************************************************/
int czytaj(t_opcje *opcje, struct_obrazka *obrazek)
{
    char nazwa[DL_LINII]; /*bufor do czytania nazwy pliku*/
    char bufor[DL_LINII]; /*bufor pomocniczy do czytania komentarzy i naglowka*/
    int znak; /*zmienna pomocnicza do komentarzy*/
    int koniec=0; /*zmienna pomocna w szukaniu konca danych*/
    int i,j,k; /*zmienne pomocnicze petli*/
    
    /*Warunek poprawnego uchwytu do pliku*/
    if (opcje->plik_we==NULL)
    {
        fprintf(stderr,"BLAD: Niepoprawny uchwyt do pliku!\n");
        return 0;
    }
    else
    {
        /*Sprawdzenie numeru magicznego*/
        if(fgets(bufor,DL_LINII,opcje->plik_we)==NULL) 
        koniec=1; 
        else
        {if(bufor[0]!='P'||bufor[1]!='2'&& bufor[1]!='3'||koniec) 
        {
            fprintf(stderr,"BLAD: Ten plik nie jest formatu PGM ani PPM (nie jest obslugiwany)\n");
            return 0;
        }
        else
        {/*Zapisanie formatu pliku w zaleznosci od nr magicznego*/
            if(bufor[1]=='2')
            obrazek->nr_magiczny=2;
            printf("nr magiczny 2");
            
            if(bufor[1]=='3')
            obrazek->nr_magiczny=3;
            printf("nr magiczny 3");
            
        }
        
    }

    /*Pomijanie zbednych komentarzy*/
    do
    {
        if((znak=fgetc(opcje->plik_we))=='#') /*Sprawdzenie czy linia jest komentarzem (znak "#")*/
        {
            if(fgets(bufor,DL_LINII,opcje->plik_we)==NULL)
            koniec=1;
            else
            {
                ungetc(znak,opcje->plik_we);
            }
        }
    } while (znak=='#'|| !koniec); /*Rob dopoki sa komentarze i nie nastapil koniec danych*/
    
    /*Wczytanie wymiarow obrazka */
    if(fscanf(opcje->plik_we,"%d %d %d",&obrazek->wym_x,&obrazek->wym_y,&obrazek->szarosci)!=3)
    {
        fprintf(stderr,"BLAD: Brak jednego z parametrow: wysokosc, szerokosc, ilosc stopni szarosci!\n");
        return 0;
    }
    
/*Przydzielanie dynamiczne pamieci w zaleznosci od formatu pliku*/
    if(obrazek->nr_magiczny==2)/*obrazek pgm*/
    {
        obrazek->piksele=(int**)malloc(obrazek->wym_y*sizeof(int*));
        for (i=0;i<obrazek->wym_y;i++)
        obrazek->piksele[i]=(int*)malloc(obrazek->wym_x*sizeof(int*));
        
    if(obrazek->piksele==NULL) /*Sprawdzenie powodzenia przydzielania pamieci*/
    {
        fprintf(stderr,"BLAD: Niepowodzenie przy przydzielaniu pamieci!\n");
        return 0;
    }
    }

    if(obrazek->nr_magiczny==3)/*obrazek ppm*/
    {
        obrazek->piksele=(int**)malloc(obrazek->wym_y*sizeof(int*));
        for(i=0;i<obrazek->wym_y;i++)
        obrazek->piksele[i]=(int*)malloc(obrazek->wym_x*3*sizeof(int*));
        
    if(obrazek->piksele==NULL) /*Sprawdzenie powodzenia przydzielania pamieci*/
    {
        fprintf(stderr,"BLAD: Niepowodzenie przy przydzielaniu pamieci!\n");
        return 0;
    }
    }

    /*Zapelnienie przydzielonej pamieci wczytywanym obrazem*/
    if(obrazek->nr_magiczny==2)/*obrazek pgm*/
    {
        for(j=0;j<obrazek->wym_y;j++)
        {
            for(k=0;k<obrazek->wym_x;k++)
            {
                if(fscanf(opcje->plik_we,"%d",&obrazek->piksele[j][k])!=1)
                {
                    fprintf(stderr,"BLAD: Niepoprawne wymiary obrazka\n");
                    return 0;
                }
            }
        }
    }

    if(obrazek->nr_magiczny==3)/*obrazek ppm*/
    {
        for(j=0;j<obrazek->wym_y;j++)
        {
            for(k=0;k<obrazek->wym_x*3;k++)
            {
                if(fscanf(opcje->plik_we,"%d",&obrazek->piksele[j][k])!=1)
                {
                    fprintf(stderr,"BLAD: Niepoprawne wymiary obrazka\n");
                    return 0;
                }
            }
        }
    }

return (obrazek->wym_x)*(obrazek->wym_y);/*Poprawnie wykonano operacje wczytywania, zwracamy liczbe wczytanych pikseli*/
}
}




/************************************************************************************
 * Funkcja zapisuje obraz z tablicy do podanego pliku                               *                                              *
 *                                                                                  *
 * \param[in] piksele  tablica, do ktorej zostanie zapisany obraz                  *
 * \param[in] wym_x  szerokosc obrazka                                             *
 * \param[in] wym_y  wysokosc obrazka                                              *
 * \param[in] szarosci  liczba odcieni szarosci                                    *
 * \return liczba wczytanych pikseli                                                *
 ************************************************************************************/
int zapisz(t_opcje *opcje,struct_obrazka *obrazek)
{
    char word [DL_LINII]; /*bufor do wydawania polecen terminalowi*/
    int i,j;

    /*zapisanie na poczatku pliku nr_magicznego, wymiarow, szarosci i ewentualnych komentarzy*/
    fprintf(opcje->plik_wy, "P%d\n", obrazek->nr_magiczny);
    fprintf(opcje->plik_wy, "# Plik formatowany poprzez program PRZETWARZANIE\n");
    fprintf(opcje->plik_wy, "%d %d\n", obrazek->wym_x, obrazek->wym_y);

    /*zapis kolenych pikseli*/
    if(obrazek->nr_magiczny==2) /*dla formatu .pgm*/
    {
        for(i=0; i<obrazek->wym_y; i++)
        {
            for(j=0; j<obrazek->wym_x; j++)
            {
                fprintf(opcje->plik_wy, "%d", obrazek->piksele[i][j]);
            }       
        }
    }

    if(obrazek->nr_magiczny==3) /*dla formatu .ppm*/
    {
        for(i=0; i<obrazek->wym_y; i++)
        {
            for(j=0; j<obrazek->wym_x*3; j++)
            {
                fprintf(opcje->plik_wy, "%d", obrazek->piksele[i][j]);
            }       
        }
    }


}

/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(t_opcje *opcje) 
{
char word [DL_LINII]; /*bufor do wydawania polecen terminalowi*/
    strcpy(word,"display ");  /* konstrukcja polecenia postaci */
    strcat(word,opcje->plik_we);  
    strcat(word," &");
    system(word);             /* wykonanie polecenia        */
  
}