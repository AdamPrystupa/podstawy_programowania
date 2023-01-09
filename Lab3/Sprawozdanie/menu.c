#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdlib.h>

int main()
{
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
                case 1:
                    printf("Funkcja odczytu pliku");
                break;
                
                
                case 2:
                    printf("Wyświetlanie pliku\n");
                break;
                
                
                case 3:
                    do
                    {  
		      system("clear");
                        printf("|--------------------------------|\n");
                        printf("| Operacje punktowe              |\n");
                        printf("|   1 - Negatyw                  |\n");
                        printf("|   2 - Progowanie               |\n");
                        printf("|   3 - Półprogowanie czerni     |\n");
                        printf("|   4 - Półprogowanie bieli      |\n");
                        printf("|   5 - Korekcja gamma           |\n");
                        printf("|   6 - Zmiana poziomów          |\n");
                        printf("|   7 - Zapisz plik              |\n");
                        printf("|   8 - Powrót do menu głownego  |\n");
                        printf("|--------------------------------|\n");
                        printf("Wybierz operację którą chcesz wykonać: ");
                        scanf("%d",&wybor1);
                        
                            switch(wybor1)
                            {
                                case 1:
                                    printf("Negatyw\n");
                                break;
                                
                                
                                case 2:
                                    printf("Progowanie\n");
                                break;
                                
                                
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
                                    printf("Funkcja zapisu pliku\n");
                                break;
                            
                                default:
                                if(wybor1!=8)
                                    printf("Nie ma takiej opcji w menu!\n");
                                break;
                            }
                        printf("\n");

                    }
                    while(wybor1!=8);
                break;
                
                
                case 4:
                 do
                    {   
		      system("clear");
                        printf("|--------------------------------|\n");
                        printf("| Operacje lokalne               |\n");
                        printf("|   1 - Konturowanie             |\n");
                        printf("|   2 - Rozmywanie poziome       |\n");
                        printf("|   3 - Rozmywanie pionowe       |\n");
                        printf("|   4 - Zapisz plik              |\n");
                        printf("|   5 - Powrót do menu głownego  |\n");
                        printf("|--------------------------------|\n");
                        printf("Wybierz operację którą chcesz wykonać: ");
                        scanf("%d",&wybor2);
                        
                            switch(wybor2)
                            {
                                case 1:
                                    printf("Konturowanie\n");
                                break;
                                
                                
                                case 2:
                                    printf("Rozmywanie poziome\n");
                                break;
                                
                                
                                case 3:
                                    printf("Rozmywanie pionowe\n");
                                break;

                                case 4:
                                    printf("Funkcja zapisu pliku\n");
                                break;
                            
                                default:
                                if(wybor2!=5)
                                    printf("Nie ma takiej opcji w menu!\n");
                                break;
                            }
                        printf("\n");

                    }
                    while(wybor2!=5);
                break;

                case 5:
                do
                    {   
		      system("clear");
                        printf("|--------------------------------|\n");
                        printf("| Operacje globalne              |\n");
                        printf("|   1 - Rozciąganie histogramu   |\n");
                        printf("|   2 - Zapisz plik              |\n");
                        printf("|   3 - Powrót do menu głownego  |\n");
                        printf("|--------------------------------|\n");
                        printf("Wybierz operację którą chcesz wykonać: ");
                        scanf("%d",&wybor3);
                        
                            switch(wybor3)
                            {
                                case 1:
                                    printf("Rozciąganie histogramu\n");
                                break;

                                case 2:
                                    printf("Funkcja zapisu pliku\n");
                                break;
                            
                                default:
                                if(wybor3!=3)
                                    printf("Nie ma takiej opcji w menu!\n");
                                break;
                            }
                        printf("\n");

                    }
                    while(wybor3!=3);
                break;
                   
                default:
                if(wybor!=7)
                    printf("Nie ma takiej opcji w menu!\n");
                break;
            }
        printf("\n");

    }
    while(wybor!=7);
    
    

    return 0;
}
