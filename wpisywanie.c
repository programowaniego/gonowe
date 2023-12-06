#ifndef wpisywanie.c
int pozycja(plansza* stol)
{
char kolumna;
int wiersz;
printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n");  
scanf("%c%d", &kolumna , &wiersz);
getchar();
/*while(kolumna < 'A'|| kolumna  > 'M' || wiersz < 0 || wiersz > 13)
    {
        printf("podano niewlasciwa wartosc kolumny/wiersza\n");
        printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n");  
        scanf("%c%d", &kolumna , &wiersz);
        getchar();
    }*/
int moje_pole[wiersze * kolumny] = {};
char napotkane[5];
if(wiersz == 0){
    for(int i = 0;i < wiersze * kolumny;i++){
        if(moje_pole[i] == 0 && stol->wartosci[i] == " "){
            if(terytorium(stol,i,moje_pole,&napotkane,0) != 0){
                printf("terytorium z pola %c%d gracz %s - %d\n",i%kolumny + 'A',(i - i%kolumny)/kolumny + 1,napotkane,ile_pol(stol,moje_pole,0));
                wypisz(stol);
            }
        }
        for(int j = 0;j < wiersze * kolumny;j++){
            if(stol->wartosci[j] == "1")
                stol->wartosci[j] = " ";
        }
        
    }
}
else
    return (wiersz - 1)*13 + kolumna - 'A';
return 2137;
}
#endif
