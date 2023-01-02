#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "funkcje.h"

#define MAX 1024        /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 2048     /* Dlugosc buforow pomocniczych */
#define odczekaj 1      /*Czas wyświetlania komunikatu w sekundach*/

int main() {
  int obraz[MAX][MAX] ;
  int wymx,wymy,odcieni;
  int i,j;

  int odczytano = 0;
  FILE *plik;
  FILE *plik_zapis;
  char nazwa[100], nazwa_zapisu[100], nazwa_wyswietl[100];

      int wybor,wybor1,wybor2,wybor3;
    
    do
    {   
        system("clear");  
        printf("|*****************************************************|\n");
        printf("| Program do przetwarzania obrazów monochromatycznych.|\n");
        printf("|                 1 - Odczytaj plik                   |\n");
        printf("|                 2 - Wyświetl plik                   |\n");
        printf("|                 3 - Operacje punktowe               |\n");
        printf("|                 4 - Operacje lokalne                |\n");
        printf("|                 5 - Operacje globalne               |\n");
        printf("|                 6 - Zapisz plik                     |\n");
        printf("|                 7 - Zakończ program                 |\n");
        printf("|*****************************************************|\n");
        printf("Wybierz operację którą chcesz wykonać: ");
        scanf("%d",&wybor);
        
            switch(wybor)
            {
                case 1: /* Wczytanie zawartosci wskazanego pliku do pamieci */
                {     
                      printf("Podaj nazwe pliku w formacie .pgm: ");
                      scanf("%s",nazwa); 
                      if(poprawnosc_pliku(nazwa)!=0)
                      {
                        printf("Plik %s został poprawnie zadeklarowany.\n",nazwa);
                        
                      }
                      else
                      {
                        printf("Niepoprawne rozszerzenie pliku!\n");
                        sleep(odczekaj);
                      continue;
                      }
                        
                      plik=fopen(nazwa,"r");
                      if (plik != NULL) 
                        czytaj(plik,obraz,&wymx,&wymy,&odcieni);
                        fclose(plik); 

                  sleep(odczekaj);
                                           
                  break;
                }
                
                case 2: /*Wyświetlenie wybranego pliku*/
                {
                      printf("Podaj nazwę pliku który chcesz wyświetlić: ");
                      scanf("%s",nazwa_wyswietl);
                       if(poprawnosc_pliku(nazwa_wyswietl)!=0)
                      {
                        printf("Plik %s zostanie wyświetlony w programie obsługującym ten format.\n",nazwa_wyswietl);
                        wyswietl(nazwa_wyswietl);                       
                      }
                      else
                      {
                        printf("Niepoprawne rozszerzenie pliku!\n");
                        sleep(odczekaj);
                      continue;
                      }
                      
                      
                      
                
                sleep(odczekaj);
                break;
                }
                
                case 3: /*Menu operacji punktowych*/
                {
                    do
                    {  
                        system("clear");
                        printf("|--------------------------------|\n");
                        printf("| Operacje punktowe              |\n");
                        printf("|   1 - Negatyw                  |\n");
                        printf("|   2 - Progowanie               |\n");
                        printf("|   3 - Półprogowanie czerni  !! |\n");
                        printf("|   4 - Półprogowanie bieli   !! |\n");
                        printf("|   5 - Korekcja gamma        !! |\n");
                        printf("|   6 - Zmiana poziomów       !! |\n");
                        printf("|   7 - Zapisz plik              |\n");
                        printf("|   8 - Wyświetl obraz           |\n");
                        printf("|   9 - Powrót do menu głownego  |\n");
                        printf("|--------------------------------|\n");
                        printf("Wybierz operację którą chcesz wykonać: ");
                        scanf("%d",&wybor1);
                        
                            switch(wybor1)
                            {
                                case 1:
                                {   
                                      if(negatyw(obraz, &wymx, &wymy, &odcieni)==1)
                                      printf("Operacja przebiegła pomyślnie.\n");
                                sleep(odczekaj);
                                break;
                                }                             
                                
                                case 2:
                                {   
                                      if(progowanie(obraz, &wymx, &wymy, &odcieni)==1)
                                      printf("Operacja przebiegła pomyślnie.\n");
                                sleep(odczekaj);
                                break;
                                } 
                                
                                
                                case 3:
                                    printf("Półprogowanie czerni\n");
                                break;
                                
                                
                                case 4:
                                    printf("Półprogowanie bieli\n");
                                break;
                                
                                case 5:
                                    printf("Korekcja gamman");
                                break;

                                case 6:
                                    printf("Zmiana poziomów\n");
                                break;

                                case 7:
                                {
                                    printf("Podaj nazwe pliku do zapisu w formacie .pgm: ");
                                    scanf("%s", nazwa_zapisu);
                                    if(poprawnosc_pliku(nazwa_zapisu)!=0)
                                    {
                                      printf("Obraz został zapisany pod nazwą: %s\n",nazwa_zapisu);
                                      
                                      
                                    }
                                    else
                                    {
                                      printf("Niepoprawne rozszerzenie pliku!\n");
                                      sleep(odczekaj);
                                    continue;
                                    }
                                    plik_zapis=fopen(nazwa_zapisu,"w");
                                    if(zapisz(plik_zapis,obraz,&wymx,&wymy,&odcieni,nazwa_zapisu)==1)
                                    fclose(plik_zapis);

                                  sleep(odczekaj);
                                  break;
                                }
                                
                                case 8:
                                {
                                      printf("Podaj nazwę pliku który chcesz wyświetlić: ");
                                      scanf("%s",nazwa_wyswietl);
                                      if(poprawnosc_pliku(nazwa_wyswietl)!=0)
                                      {
                                        printf("Plik %s zostanie wyświetlony w programie obsługującym ten format.\n",nazwa_wyswietl);
                                        wyswietl(nazwa_wyswietl);                       
                                      }
                                      else
                                      {
                                        printf("Niepoprawne rozszerzenie pliku!\n");
                                        sleep(odczekaj);
                                      continue;
                                      }

                                sleep(odczekaj);
                                break;
                                }
                                
                                default:
                                {
                                  if(wybor1!=9)
                                    printf("Nie ma takiej opcji w menu!\n");
                                break;
                                }
                            }


                    }
                    while(wybor1!=9);
                break;
              }  
                
                case 4: /*Menu operacji lokalnych*/
                {
                 do
                    {   
                        system("clear");
                        printf("|--------------------------------|\n");
                        printf("| Operacje lokalne               |\n");
                        printf("|   1 - Konturowanie             |\n");
                        printf("|   2 - Rozmywanie poziome       |\n");
                        printf("|   3 - Rozmywanie pionowe  !!!! |\n");
                        printf("|   4 - Zapisz plik              |\n");
                        printf("|   5 - Wyświetl plik            |\n");
                        printf("|   6 - Powrót do menu głownego  |\n");
                        printf("|--------------------------------|\n");
                        printf("Wybierz operację którą chcesz wykonać: ");
                        scanf("%d",&wybor2);
                        
                            switch(wybor2)
                            {
                                case 1:
                                {   
                                      if(konturowanie(obraz, &wymx, &wymy, &odcieni)==1)
                                      printf("Operacja przebiegła pomyślnie.\n");

                                sleep(odczekaj);
                                break;
                                }
                                
                                
                                case 2:
                                {   
                                      if(rozmycie_poziome(obraz, &wymx, &wymy, &odcieni)==1)
                                      printf("Operacja przebiegła pomyślnie.\n");
                                sleep(odczekaj);
                                break;
                                } 
                                
                                
                                case 3:
                                {   
                                      if(rozmycie_pionowe(obraz, &wymx, &wymy, &odcieni)==1)
                                      printf("Operacja przebiegła pomyślnie.\n");
                                sleep(odczekaj);
                                break;
                                } 

                                case 4:
                                {
                                    printf("Podaj nazwe pliku do zapisu w formacie .pgm: ");
                                    scanf("%s", nazwa_zapisu);
                                    if(poprawnosc_pliku(nazwa_zapisu)!=0)
                                    {
                                      printf("Obraz został zapisany pod nazwą: %s\n",nazwa_zapisu);
                                      
                                      
                                    }
                                    else
                                    {
                                      printf("Niepoprawne rozszerzenie pliku!\n");
                                      sleep(odczekaj);
                                    continue;
                                    }
                                    plik_zapis=fopen(nazwa_zapisu,"w");
                                    if(zapisz(plik_zapis,obraz,&wymx,&wymy,&odcieni,nazwa_zapisu)==1)
                                    fclose(plik_zapis);

                                  sleep(odczekaj);
                                  break;
                                }

                                case 5:
                                {
                                      printf("Podaj nazwę pliku który chcesz wyświetlić: ");
                                      scanf("%s",nazwa_wyswietl);
                                      if(poprawnosc_pliku(nazwa_wyswietl)!=0)
                                      {
                                        printf("Plik %s zostanie wyświetlony w programie obsługującym ten format.\n",nazwa_wyswietl);
                                        wyswietl(nazwa_wyswietl);                       
                                      }
                                      else
                                      {
                                        printf("Niepoprawne rozszerzenie pliku!\n");
                                        sleep(odczekaj);
                                      continue;
                                      }
                                      
                                      
                                      
                                
                                sleep(odczekaj);
                                break;
                                }

                                default:
                                if(wybor2!=6)
                                    printf("Nie ma takiej opcji w menu!\n");
                                break;
                            }

                    }
                    while(wybor2!=6);
                break;
                }

                case 5: /*Menu operacji globalnych*/
                {
                  do
                    {   
                        system("clear");
                        printf("|--------------------------------|\n");
                        printf("| Operacje globalne              |\n");
                        printf("|   1 - Rozciąganie histogramu !!|\n");
                        printf("|   2 - Zapisz plik              |\n");
                        printf("|   3 - Wyświetl plik            |\n");
                        printf("|   4 - Powrót do menu głownego  |\n");
                        printf("|--------------------------------|\n");
                        printf("Wybierz operację którą chcesz wykonać: ");
                        scanf("%d",&wybor3);
                        
                            switch(wybor3)
                            {
                                case 1:
                                {   
                                      rozciaganie_histogramu(obraz, &wymx, &wymy, &odcieni);
                                      printf("Operacja przebiegła pomyślnie.\n");
                                sleep(odczekaj);
                                break;
                                } 

                                case 2:
                                {
                                    printf("Podaj nazwe pliku do zapisu w formacie .pgm: ");
                                    scanf("%s", nazwa_zapisu);
                                    if(poprawnosc_pliku(nazwa_zapisu)!=0)
                                    {
                                      printf("Obraz został zapisany pod nazwą: %s\n",nazwa_zapisu);
                                      
                                      
                                    }
                                    else
                                    {
                                      printf("Niepoprawne rozszerzenie pliku!\n");
                                      sleep(odczekaj);
                                    continue;
                                    }
                                    plik_zapis=fopen(nazwa_zapisu,"w");
                                    if(zapisz(plik_zapis,obraz,&wymx,&wymy,&odcieni,nazwa_zapisu)==1)
                                    fclose(plik_zapis);

                                  sleep(odczekaj);
                                  break;
                                }
                            
                                case 3:
                                {
                                      printf("Podaj nazwę pliku który chcesz wyświetlić: ");
                                      scanf("%s",nazwa_wyswietl);
                                      if(poprawnosc_pliku(nazwa_wyswietl)!=0)
                                      {
                                        printf("Plik %s zostanie wyświetlony w programie obsługującym ten format.\n",nazwa_wyswietl);
                                        wyswietl(nazwa_wyswietl);                       
                                      }
                                      else
                                      {
                                        printf("Niepoprawne rozszerzenie pliku!\n");
                                        sleep(odczekaj);
                                      continue;
                                      }
                                      
                                      
                                      
                                
                                sleep(odczekaj);
                                break;
                                }

                                default:
                                if(wybor3!=4)
                                    printf("Nie ma takiej opcji w menu!\n");
                                break;
                            }


                    }
                  while(wybor3!=4);
                  break;
                }
                
                case 6: /*Zapisywanie pliku*/
                {
                  printf("Podaj nazwe pliku do zapisu w formacie .pgm: ");
                  scanf("%s", nazwa_zapisu);
                  if(poprawnosc_pliku(nazwa_zapisu)!=0)
                  {
                    printf("Obraz został zapisany pod nazwą: %s\n",nazwa_zapisu);
                  }
                  else
                  {
                    printf("Niepoprawne rozszerzenie pliku!\n");
                    sleep(odczekaj);
                  continue;
                  }
                  plik_zapis=fopen(nazwa_zapisu,"w");
                  if(zapisz(plik_zapis,obraz,&wymx,&wymy,&odcieni,nazwa_zapisu)==1)
                  fclose(plik_zapis);

                sleep(odczekaj);
                break;
                }

                   
                default:
                if(wybor!=7)
                    printf("Nie ma takiej opcji w menu!\n");
                
            }


    }
    while(wybor!=7);

return 0;
}