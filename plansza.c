#ifndef Plansza.c
#define wiersze 9
#define kolumny 9
 
// Kolorowanie tekstu na czerwono nwm czy to dziala wgl 
//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

// Przywróć domyślne kolory
//SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
typedef struct plansza
{
    char* wartosci[wiersze * kolumny];    //reprezentacja stanu gry
    char* gracz_na_ruchu;
    int* terytorium_kolko[wiersze*kolumny];
    int* terytorium_krzyzyk[wiersze*kolumny];
}plansza;
plansza* utworz_plansze(plansza* nowa,char gracz[2]){
    plansza* nowa_plansza = (plansza*)malloc(sizeof(plansza));

    nowa_plansza->gracz_na_ruchu = gracz; //gracz rozpoczynający
    for(int i = 0;i < wiersze * kolumny;i++)
        nowa_plansza->wartosci[i] = " ";

    return nowa_plansza;
}
typedef struct{
    int pozycja;
}ruchy;
//generator ruchow
typedef struct element{
    ruchy dostepne;
    struct element* nastepny;
    struct element* poprzedni;
}element;
/*element* utworz_element(element* glowa,ruchy dostepne){ 
    element* nowy_element = (element*)malloc(sizeof(element));
    
    if(nowy_element == NULL)
    {
        exit(1);    //obsługa błędnej alokacji pamięci
    }
    nowy_element->dostepne = dostepne;
    nowy_element->nastepny = NULL;
    
    return nowy_element;
}*/
element* utworz_element(element* glowa, ruchy dostepne)
{
    element* nowy = malloc(sizeof(element));
    *nowy = (element){ nowy->dostepne = dostepne, nowy->nastepny = NULL};
    if (glowa)
    {
        for(element* pom = glowa; pom->nastepny || !(pom->nastepny = nowy); pom = pom->nastepny);
            return glowa;
    }
    return nowy;
}
element* dostepne_ruchy(plansza* stol,element* glowa,int posuniecie,int czy_ko){
    
    for(int i = 0;i < wiersze * kolumny && czy_ko == 0;i++)
    {
        if(stol->wartosci[i] == " ") //czy_ko to zmienna ktora determinuje czy tworzymy liste do zapisywania posuniec czy generator ruchow
        {
            glowa = utworz_element(glowa , (ruchy) { .pozycja = i});
            
        }
    }
    if(czy_ko == 1){

            glowa = utworz_element(glowa,(ruchy){.pozycja = posuniecie});
    
    }
    return glowa;
}
void wypisz(plansza* wejscie){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0;i < kolumny;i++)
        {
                printf("   %c  ",'A' + i);
        }
    printf("\n");
    for(int i = 0;i < kolumny;i++)
        {
            printf(" _____");
        }
    for(int k = 0;k < wiersze;k++)
    {
        printf("\n|");
        for(int i = 0;i < kolumny;i++)
        {
            printf("     |");
        }
        printf("\n|");
        for(int i = 0;i < kolumny;i++)
        {
            if(wejscie->wartosci[k * kolumny + i] == "O"){
               SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                printf("  %s  ",wejscie->wartosci[k * kolumny + i]);
            }
            else if(wejscie->wartosci[k * kolumny + i] == "1"){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("  %s  ",wejscie->wartosci[k * kolumny + i]);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("  %s  ",wejscie->wartosci[k * kolumny + i]);
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            printf("|");
        }
        printf(" %d \n|",1 + k);
        for(int i = 0;i < kolumny;i++)
        {
            printf("_____|");
        }
    }
    printf("\n\n");
}
#endif
