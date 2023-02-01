#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main()
{
    char *original_locale = setlocale(LC_ALL, NULL);
    setlocale(LC_ALL, "pl_PL.UTF-8");
    FILE *file = fopen("alice_in_wonderland.txt", "rb");
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
        {
            printf("%c", c);
        }
        else
        {
            printf("\n");
        }
    }
    fclose(file);
    setlocale(LC_ALL, original_locale);
    return 0;
}