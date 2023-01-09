#include <stdio.h>

int main()
{
    int wybor;
    do
    {
        printf("|**************************|\n");
        printf("|    Proste menu           |\n");
        printf("|   1 - Pozycja pierwsza   |\n");
        printf("|   2 - Pozycja druga      |\n");
        printf("|   3 - Pozycja trzecia    |\n");
        printf("|   4 - Zakończ dzialanie  |\n");
        printf("|**************************|\n");
        printf("Twój wybór: ");
        scanf("%d",&wybor);

            switch (wybor)
            {
            case 1:
                printf("Wybrano pozycję pierwszą\n");
                break;
            
            case 2:
                printf("Wybrano pozycję drugą\n");
                break;

            case 3:
                printf("Wybrano pozycję trzecią\n");
                break;
            
            default:
                if(wybor!=4)
                printf("Takiej pozycji nie ma w menu!");
                break;
            }
    printf("\n");
    }
    while (wybor!=4);

return 0;
}