#include <stdio.h>
#include <string.h>

int main()
{
    char linia[100];
    int numer_slowa, i, j;
    printf("Wprowadz linie tekstu: \n");
    fgets(linia, sizeof(linia), stdin);
    printf("Podaj numer slowa do podkreslenia: ");
    scanf("%d", &numer_slowa);
    printf("%s", linia);
    char *p = strtok(linia, " ");
    for (i = 1; i <= numer_slowa; i++)
    {
        if (i == numer_slowa)
        {
            int ile = strlen(p);
            for (j = 0; j < ile; j++)
                printf("^");
        }
        else
        {
            int dlugosc_slowa = strlen(p);
            int j;
            for (j = 0; j < dlugosc_slowa; j++)
            {
                printf(" ");
            }
            p = strtok(NULL, " ");
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}