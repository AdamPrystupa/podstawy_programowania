#include <stdio.h>
typedef struct info_log
{
    char *nazwa_uzytkownika;
    char *adres_komputera;
    struct info_log *lewy;
    struct info_log *prawy;
    struct info_log *rodzic;
} info_log;

// Wyświetlenie zawartości wskazanego elementu
void wyswietl_element(info_log *element)

{
    printf("Nazwa uzytkownik: %s\n", element->nazwa_uzytkownika);
    printf("Adres komputera: %s\n", element->adres_komputera);
}

// Uzyskanie wskaźnika (przejście do) lewego/prawego potomka wskazanego elementu
info_log *uzyskaj_lewy_elem(info_log *element)
{
    return element->lewy;
}
info_log *uztskaj_prawy_elem(info_log *element)
{
    return element->prawy;
}

// Uzyskanie wskaźnika (przejście do) elementu nadrzędnego (rodzica) wskazanego elementu
info_log *uzyskaj_rodzica(info_log *element)
{
    return element->rodzic;
}

// Wskazanie położenia elementu na drzewie uporządkowanym według nazw komputerów na podstawie wskazania jego położenia na drzewie uporządkowanym według nazw użytkowników
info_log *znajdz_po_nazwie_uzytkownika(info_log *korzen, char *nazwa_uzytkownika)
{
    if (korzen == NULL)
    {
        return NULL;
    }
    if (strcmp(korzen->nazwa_uzytkownika, nazwa_uzytkownika) == 0)
    {
        return korzen;
    }
    info_log *left_result = znajdz_po_nazwie_uzytkownika(korzen->lewy, nazwa_uzytkownika);
    if (left_result != NULL)
    {
        return left_result;
    }
    return znajdz_po_nazwie_uzytkownika(korzen->prawy, nazwa_uzytkownika);
}

// Wskazanie położenia elementu na drzewie uporządkowanym według nazw użytkowników na podstawie wskazania jego położenia na drzewie uporządkowanym według nazw komputerów
info_log *znajdz_po_adresie_komputera(info_log *korzen, char *adres_komputera)
{
    if (korzen == NULL)
    {
        return NULL;
    }
    if (strcmp(korzen->adres_komputera, adres_komputera) == 0)
    {
        return korzen;
    }
    info_log *left_result = znajdz_po_adresie_komputera(korzen->lewy, adres_komputera);
    if (left_result != NULL)
    {
        return left_result;
    }
    return znajdz_po_adresie_komputera(korzen->prawy, adres_komputera);
}

// Wyświetlenie dla wybranego użytkownika listy komputerów, z których nastąpiło jego logowanie
void wyswietl_koputery_dla_uzytkownika(info_log *korzen, char *nazwa_uzytkownika)
{
    if (korzen == NULL)
    {
        return;
    }
    if (strcmp(korzen->nazwa_uzytkownika, nazwa_uzytkownika) == 0)
    {
        printf("Adres komputera: %s\n", korzen->adres_komputera);
    }
    wyswietl_koputery_dla_uzytkownika(korzen->lewy, nazwa_uzytkownika);
    wyswietl_koputery_dla_uzytkownika(korzen->prawy, nazwa_uzytkownika);
}

// Wyświetlenie dla wybranego komputera listy użytkowników, którzy z niego się zalogowali
void wyswietl_urzytkownikow_dla_komputera(info_log *korzen, char *adres_komputera)
{
    if (korzen == NULL)
    {
        return;
    }
    if (strcmp(korzen->adres_komputera, adres_komputera) == 0)
    {
        printf("Nazwa uzytkownika: %s\n", korzen->nazwa_uzytkownika);
    }
    wyswietl_urzytkownikow_dla_komputera(korzen->lewy, adres_komputera);
    wyswietl_urzytkownikow_dla_komputera(korzen->prawy, adres_komputera);
}