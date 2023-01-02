#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define min_wartosc -10        //minimalna wartość pomiaru                                                                                                                                                
#define max_wartosc 10         //maksymalna wartość pomiaru                                                                                                                                                
#define koniec 99              //koniec strumienia                                                                                                                                                        
#define min_czestotliwosc 8    //minimalna częstotliwość                                                                                                                                                  
#define max_czestotliwosc 14   //maksymalna częstotliwość 
#define max_dlugosc 21         //maskymalna długość wiersza

/*************************************
  
  Funkcja szukająca spacji w wierszu
  
**************************************/
 
int znajdz_spacje ( char *t, char *p )                                        //funkcja  pobiera jako dane wejsciowe linię z pliku i znak jakiego pozycję ma zwrócić w tym przypadku spację                                                                                                                        //jako dane wyjściowe zwraca pozycję znaku lini, na krótej jest szukany znak
{
  int i, j, m, n;                                                             
m = strlen ( p );                                                               
n = strlen ( t );
for ( i = 0; i <= n-m; ++i )
 {
  for ( j = 0; j < m; ++j )
    if( t[i+j] != p[j] ) break ;
    if( j == m ) return i;
   }
 return -1;
 }
 
 /*******************************************
  
  Funkcja usuwająca zbędne elementy wiersza
  
 ********************************************/

void del (char *s, int k, int n)
 {
  for (int i = k; i <=n ; i++)                                                  //pętla przypisuje do elementów wiersza elementy oddalone od początkowego
  s[i] = s[i + n];                                                              //o wartość pozycji spacji co daje efekt usuwania początkowych wyrazów czego oczekiwaliśmy
  }

int main()
{
   FILE *fin=fopen("dane_wejsciowe1.txt","r");                                  //deklaracja pliku, z którtm program będzie pracował
   char wiersz[max_dlugosc]; 
   int x,x1,x2,czestotliwosc=0;                                                 //deklaracja zmiennych pomocniczych
   int grupa=0;                                                                 //zmienna pomocna w kończeniu u rozpoczynaniu nowych grup
   int  dlugosc,poz_spacji;
do
   {
     fgets(wiersz, 21, fin);                                                    //wczytanie całego wiersza z pliku                                                                                                  
            dlugosc= strlen(wiersz);                                            //przypisanie ilości znaków w wierszu do zmiennej
            if (dlugosc<2)                                                      //warunek końca jednej grupy danych                                                                                                
            { 
                if (czestotliwosc<min_czestotliwosc ||czestotliwosc>max_czestotliwosc )       //warunek sprawdzający poprawnoćś wartości częstotliwości                                                                          
                    printf("Niepoprawna częstotliwość!! \n");
                else  printf("Częstotliwość= %d \n", czestotliwosc);            //wypoisanie częstotliwości dla danej grupy
                grupa = 0;                                                      //rozpoczęcie nowej grupy
                czestotliwosc=0;                                                //wyzerowanie częstotliwości dla nowej grupy
            }
            else
            {

           poz_spacji=znajdz_spacje (wiersz," ");                               //przypisanie miejsca spacji do zmiennej
           del(wiersz, 0 , poz_spacji );                                        //usuwanie elementów wiersza do miejsca spacji włącznie
           x =(int) atof(wiersz);                                               //zmiana typu wartości z char na int
           if (x<=max_wartosc && x>=min_wartosc){                               //warunek sprawdzający poprawność wartości danych                                                                                  
                 if (grupa==0){                                                 //warunek początku grupy
                     x2=x;                                                      //przypisanie pierwszej wartości z grupy do zmiennej x2
                     grupa=1;                                                   //warunek przejścia do liczenia kolejnych wartości w grupie
                 }
                 else {
                     x1=x;
                     if (( x1>0 && x2<0) || ( x2>0 && x1<0)|| (x==0 && x2!=0  )) czestotliwosc++; //warunek sprawdzający występowanie przecięcia zera                                                                  
                     x2=x1;
                 }

             }
            }
        }
while (x!=koniec);                                                              //warunek zakończenia programu                                                                                                                                                      
  fclose(fin);                                                                  //zamknięcie pliku, z którym pracował program                                                               
    return 0;
}

