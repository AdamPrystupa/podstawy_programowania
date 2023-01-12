#include<stdio.h>
#include<string.h>
#include"funkcje.h"

#define W_OK 0                   /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1    /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY   -2
#define B_BRAKWARTOSCI  -3
#define B_BRAKPLIKU   -4

int main(int argc, char **argv){
    t_opcje opcje;
    struct_obrazka obrazek;
    int kod_bledu;
    kod_bledu=przetwarzaj_opcje(argc,argv,&opcje);
    
    /*Warunek sprawdzajacy czy przetwarzanie opcji przebieglo pomysnie*/
    if(kod_bledu!=0)
    printf("BLAD nr %d!\n",kod_bledu);

    if(kod_bledu==0)
    {
        /*na początku tworzymy pomocnicze pliki do wyswietlania obrazka w przypadku braku checi zapisu pliku*/
        system("touch temp.pgm");
        system("touch temp.ppm");
    czytaj(&opcje,&obrazek);

    if(opcje.nie_kolorowy==1 && obrazek.nr_magiczny==3)
    {
        konwersja(&obrazek);
    } 

    if (opcje.negatyw==1)
    {
        negatyw(&obrazek); 
    }

    if (opcje.konturowanie==1 && obrazek.nr_magiczny==2)
    {
        konturowanie(&obrazek);
    }
    if (opcje.progowanie==1 && obrazek.nr_magiczny==2)
    {
        progowanie(&obrazek,&opcje);
    }
     
    if (opcje.wyswietlenie==1)
    { 
        if (opcje.plik_wy==stdout)
        { 
            if (obrazek.nr_magiczny==2) /*aspekt formatu pgm*/
            { 
                opcje.do_wyswietlania="temp.pgm";
                opcje.plik_wy=fopen("temp.pgm", "w");
                zapisz(&opcje,&obrazek);    /*aby wyswietlic obrazek musimy go tymczasowo zapisac*/
                wyswietl(&opcje); 
                fclose(opcje.plik_wy); /*zamykamy plik tymczasowy*/

                /*powracamy do poczatkowego stanu czyli wyjscia standardowego*/
                opcje.plik_wy=stdout;
                zapisz(&opcje,&obrazek);
            }
            if (obrazek.nr_magiczny==3) /*aspekt formatu ppm*/
            {
                opcje.do_wyswietlania="tempo.ppm";
                opcje.plik_wy=fopen("temp.ppm", "w");
                zapisz(&opcje,&obrazek); /*aby wyswietlic obrazek musimy go tymczasowo zapisac*/
                wyswietl(&opcje); 
                fclose(opcje.plik_wy); /*zamykamy plik tymczasowy*/

                /*powracamy do poczatkowego stanu czyli wyjscia standardowego*/
                opcje.plik_wy=stdout; 
                zapisz(&opcje,&obrazek);
            }
          
        } else {
          zapisz(&opcje,&obrazek); /*aby wyswietlic obrazek musimy go zapisac*/
          wyswietl(&opcje); 
        }
      }
      if (opcje.wyswietlenie==0){  /*zapis bez wyswietlania*/
        zapisz(&opcje,&obrazek);
      }
    /*usuwamy tymczasowe pliki*/ 
    system("rm -r temp.pgm");
    system("rm -r temp.ppm"); 
    }
    
    /*zwalniamy pamiec dynamiczna*/
   
    free(obrazek.piksele);
    return 0;
   

}