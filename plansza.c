#ifndef Plansza.c
//kolorki na Linuxa
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Kolorowanie tekstu na czerwono nwm czy to dziala wgl 
//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

// Przywróć domyślne kolory
//SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
#define wiersze 9
#define kolumny 9
typedef struct plansza
{
    char* wartosci[wiersze * kolumny];    //reprezentacja stanu gry
    char* gracz_na_ruchu;
    int* terytorium_kolko[wiersze*kolumny];
    int* terytorium_krzyżyk[wiersze*kolumny];
}plansza;
plansza* utworz_plansze(plansza* nowa){
    plansza* nowa_plansza = (plansza*)malloc(sizeof(plansza));
    
    nowa_plansza->gracz_na_ruchu = "X"; //gracz rozpoczynający
    for(int i = 0;i < wiersze * kolumny;i++)
        nowa_plansza->wartosci[i] = " ";

    return nowa_plansza;
}
void wypisz(plansza* wejscie){
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
                printf("  %s  |",wejscie->wartosci[k * kolumny + i]);
            }
            else if(wejscie->wartosci[k * kolumny + i] == "1"){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("  %s  |",wejscie->wartosci[k * kolumny + i]);
            }
            else{
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                printf("  %s  |",wejscie->wartosci[k * kolumny + i]);
            }
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
