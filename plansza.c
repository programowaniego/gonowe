#ifndef Plansza.c
//kolorki na Linuxa
#define KOLKO   ' '//"\x1b[32m"
#define KRZYZYK ' '//"\x1b[34m"
#define RESET   ' '//"\x1b[0m"
#define TLO ' '//"\x1b[0m"
//#define TLO   "\x1b[48;2;139;69;19m"
#define wiersze 13
#define kolumny 13
typedef struct plansza
{
    char* wartosci[wiersze * kolumny];    //reprezentacja stanu gry
    char gracz_na_ruchu;
}plansza;
plansza* utworz_plansze(plansza* nowa){
    plansza* nowa_plansza = (plansza*)malloc(sizeof(plansza));
    
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
            if(wejscie->wartosci[k * kolumny + i] == "O")
                printf("  %s  |",wejscie->wartosci[k * kolumny + i]);
            else
                printf("  %s  |",wejscie->wartosci[k * kolumny + i]);
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
