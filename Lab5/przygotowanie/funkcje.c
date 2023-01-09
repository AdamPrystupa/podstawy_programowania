#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "funkcje.h"

#define MAX 1024        /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 2048     /* Dlugosc buforow pomocniczych */
#define odczekaj 1      /*Czas wyświetlania komunikatu w sekundach*/


/************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy       	          	    *
 *										                                                  *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM			    *
 * \param[out] obraz_pgm tablica, do ktorej zostanie zapisany obraz		  *
 * \param[out] wymx szerokosc obrazka						                        *
 * \param[out] wymy wysokosc obrazka						                        *
 * \param[out] szarosci liczba odcieni szarosci					                *
 * \return liczba wczytanych pikseli						                        *
 ************************************************************************/

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci) {
  char buf[DL_LINII];      /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;                /* zmienna pomocnicza do czytania komentarzy */
  int koniec=0;            /* czy napotkano koniec danych w pliku */
  int i,j;

  /*Sprawdzenie czy podano prawid�owy uchwyt pliku */
  if (plik_we==NULL) {
    printf("Blad: Nie podano uchwytu do pliku\n");
    return(0);
  }

  /* Sprawdzenie "numeru magicznego" - powinien by� P2 */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych! */

  if ( (buf[0]!='P') || (buf[1]!='2') || koniec) {  /* Czy jest magiczne "P2"? */
    printf("Blad: To nie jest plik PGM\n");
    return(0);
  }

  /* Pominiecie komentarzy */
  do {
    if ((znak=fgetc(plik_we))=='#') {         /* Czy linia rozpoczyna sie od znaku '#'? */
      if (fgets(buf,DL_LINII,plik_we)==NULL)  /* Przeczytaj ja do bufora                */
	koniec=1;                   /* Zapamietaj ewentualny koniec danych */
    }  else {
      ungetc(znak,plik_we);                   /* Gdy przeczytany znak z poczatku linii */
    }                                         /* nie jest '#' zwroc go                 */
  } while (znak=='#' && !koniec);   /* Powtarzaj dopoki sa linie komentarza */
                                    /* i nie nastapil koniec danych         */

  /* Pobranie wymiarow obrazu i liczby odcieni szarosci */
  if (fscanf(plik_we,"%d %d %d",wymx,wymy,szarosci)!=3) {
    printf("Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
    return(0);
  }
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
  for (i=0;i<*wymy;i++) {
    for (j=0;j<*wymx;j++) {
      if (fscanf(plik_we,"%d",&(obraz_pgm[i][j]))!=1) {
	printf("Blad: Niewlasciwe wymiary obrazu\n");
	return(0);
      }
    }
  }
  return *wymx**wymy;   /* Czytanie zakonczone sukcesem    */
}                       /* Zwroc liczbe wczytanych pikseli */


/* Wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
  
}

/************************************************************************
 * Funkcja zapisuje obraz PGM z tablicy do pliku      	       	       	*
 *										                                                  *
 * \param[in] plik_wyj uchwyt do pliku w którym zapisany zostanie obraz *
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		        *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                          *
 * \param[in] szarosci liczba odcieni szarosci					                *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int zapisz(FILE *plik_wyj,int obraz[][MAX],int *wymx,int *wymy, int *szarosci,char nazwa_zapisu[])
{
  int i,j;

  /* Wypisanie "numeru magicznego" */
    fprintf(plik_wyj,"P2\n");
    fprintf(plik_wyj,"%i ",*wymx);
    fprintf(plik_wyj,"%i\n",*wymy);
    fprintf(plik_wyj,"%i\n",*szarosci);
    
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
    for (i=0;i<*wymy;i++) 
    {
      for (j=0;j<*wymx;j++) 
      {
      fprintf(plik_wyj,"%i ",(obraz[i][j])); 
      }
      fprintf(plik_wyj,"\n");
    }
  return 1;   /* Zapis zakonczończony sukcesem    */
}                       

/************************************************************************
 * Funkcja negatywu      	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		        *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                          *
 * \param[in] szarosci liczba odcieni szarosci					                *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int negatyw(int obraz[][MAX],int *wymx,int *wymy, int *szarosci)

  {
    int max_szarosc=*szarosci;
    int i,j;

    for (i=0;i<*wymy;i++) 
    {
      for (j=0;j<*wymx;j++) 
      {
       obraz[i][j]=(max_szarosc-obraz[i][j]);
      }
    }

  return 1;   /* Zapis zakonczończony sukcesem    */
  }

/************************************************************************
 * Funkcja progowania                                 	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		        *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                          *
 * \param[in] szarosci liczba odcieni szarosci					                *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int progowanie(int obraz[][MAX],int *wymx,int *wymy, int *szarosci)

  {
    int max_szarosc=*szarosci;
    int i,j;
    float prog,prog_procent;

    printf("Podaj wartość progu: ");
    scanf("%f",&prog_procent); 

    prog=max_szarosc*(prog_procent/100);

    if(prog>=0&&prog<=max_szarosc)
    { 
      for (i=0;i<*wymy;i++) 
      {
        for (j=0;j<*wymx;j++) 
        {
          if(obraz[i][j]<=prog)
            obraz[i][j]=0;
          else
            obraz[i][j]=max_szarosc;
        }
      }
    }
    else
      printf("Niewłaściwa wartośc progu!\n");
  return 1;   /* Zapis zakonczończony sukcesem    */
  }

/************************************************************************
 * Funkcja konturowania                               	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		        *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                          *
 * \param[in] szarosci liczba odcieni szarosci					                *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int konturowanie(int obraz[][MAX],int *wymx,int *wymy, int *szarosci)

  {
    int i,j;

    for (i=0;i<*wymy;i++) 
    {
      for (j=0;j<*wymx;j++) 
      {
       obraz[i][j]=(abs(obraz[i+1][j]-obraz[i][j])+abs(obraz[i][j+1]-obraz[i][j]));
      }
    }

  return 1;   /* Zapis zakonczończony sukcesem    */
  }

/************************************************************************
 * Funkcja rozmycia poziomego                          	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		        *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                          *
 * \param[in] szarosci liczba odcieni szarosci					                *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int rozmycie_poziome(int obraz[][MAX],int *wymx,int *wymy, int *szarosci)

  {
    int i,j;
    int promien;
    
    printf("Wybierz promień rozmycia (1 lub 2): ");
    scanf("%d",&promien);

    if(promien=1)
    {
      for (i=0;i<*wymy;i++) 
    {
      for (j=1;j<*wymx-1;j++) 
      {
       obraz[i][j]=((obraz[i][j-1]+obraz[i][j]+obraz[i][j+1])/3);
      }
    }
   }

   if(promien=2)
    {
      for (i=0;i<*wymy;i++) 
    {
      for (j=2;j<*wymx-2;j++) 
      {
       obraz[i][j]=((obraz[i][j-2]+obraz[i][j-1]+obraz[i][j]+obraz[i][j+1]+obraz[i][j+2])/5);
      }
    }
   }
   

  return 1;   /* Zapis zakonczończony sukcesem    */
  }


/************************************************************************
 * Funkcja rozmycia pionowego                          	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		        *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                          *
 * \param[in] szarosci liczba odcieni szarosci					                *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int rozmycie_pionowe(int obraz[][MAX],int *wymx,int *wymy, int *szarosci)

  {
    int i,j;
    int promien;
    
    printf("Wybierz promień rozmycia (1 lub 2): ");
    scanf("%d",&promien);

    if(promien=1)
    {
      for (i=0;i<*wymy;i++) 
    {
      for (j=0;j<*wymx;j++) 
      {
       obraz[i][j]=((obraz[i-1][j]+obraz[i][j]+obraz[i+1][j])/3);
      }
    }
   }

   if(promien=2)
    {
      for (i=0;i<*wymy;i++) 
    {
      for (j=0;j<*wymx;j++) 
      {
       obraz[i][j]=((obraz[i-2][j]+obraz[i-1][j]+obraz[i][j]+obraz[i+1][j]+obraz[i+2][j])/5);
      }
    }
   }
   

  return 1;   /* Zapis zakonczończony sukcesem    */
  }

/************************************************************************
 * Funkcja rozciągania histogramu                      	       	       	*
 * \param[in] obraz tablica, z ktorej zostanie zapisany obraz		        *
 * \param[in] wymx szerokosc obrazka						                        *
 * \param[in] wymy wysokosc obrazka						                          *
 * \param[in] szarosci liczba odcieni szarosci					                *
 * \return wartość oznaczająca poprawny przebieg operacji(1)            *
 ************************************************************************/

int rozciaganie_histogramu(int obraz[][MAX],int *wymx,int *wymy, int *szarosci)
{
    int szarosc=*szarosci;
    int max_jasnosc=obraz[0][0], min_jasnosc=obraz[0][0];
    int i,j;

    for (i=0;i<*wymy;i++) 
    {
      for (j=0;j<*wymx;j++) 
      {
       if (obraz[i][j]>max_jasnosc)
       max_jasnosc=obraz[i][j];
       if (obraz[i][j]<min_jasnosc)
       min_jasnosc=obraz[i][j];
      } 
    }

    printf("%d\n",szarosc);

    for (i=0;i<*wymy;i++) 
    {
      for (j=0;j<*wymx;j++) 
      {
       obraz[i][j]=((obraz[i][j]-min_jasnosc)*(szarosc/(max_jasnosc-min_jasnosc)));
      }
    }

  return 1;   /* Zapis zakonczończony sukcesem    */
  }

/************************************************************************
 * Funkcja sprawdzania poprawności rozszerzenia pliku  	       	       	*
 * \param[in] nazwa nazwa pliku do sprawdzenia              		        *
 * \return wartość oznaczająca poprawny przebieg operacji(poprawnosc=1  *
 ************************************************************************/


int poprawnosc_pliku(char nazwa[100])
{
    int dlugosc;
    dlugosc=strlen(nazwa);
    int poprawnosc=1;
    if(nazwa[dlugosc-4]!='.' || nazwa[dlugosc-3]!='p' || nazwa[dlugosc-2]!='g' || nazwa[dlugosc-1]!='m')
    poprawnosc=0;


    return poprawnosc;
}
