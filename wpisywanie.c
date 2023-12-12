#ifndef wpisywanie.c
int pozycja(plansza* stol){
    char kolumna;
    int wiersz;
    printf("Tura %s \nPodaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",stol->gracz_na_ruchu);  
    scanf(" %c%d",&kolumna,&wiersz);
    /*while(kolumna < 'A'|| kolumna  > 'A' + kolumny || wiersz < 1 || wiersz > wiersze )
    { 
        printf("Podano niewlasciwa wartosc kolumny/wiersza\n");
        printf("Tura %s \n Podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",stol->gracz_na_ruchu);  
        scanf(" %c%d", &kolumna , &wiersz);
    }*/
    int moje_pole[wiersze * kolumny] = {};  
    if(wiersz == 0){
        for(int i = 0;i < wiersze * kolumny;i++){
            if(moje_pole[i] == 0 && stol->wartosci[i] == " "){      //warunek czy już nie sprawdzone i czy puste i wywolanie terytorium
                char napotkane[2] = "";
                terytorium(stol,i,moje_pole,napotkane);
                if(dlugosc(napotkane) == 1)          //spotkal dwia rozne pionki
                    printf("terytorium z pola %c%d gracz %c - %d\n",i%kolumny + 'A',(i - i%kolumny)/kolumny + 1,napotkane[0],ile_pol(stol,moje_pole));
                else
                    printf("terytorium niczyje(dami)\n");
        
                wypisz(stol);
                for(int j = 0;j < wiersze * kolumny;j++){
                    if(stol->wartosci[j] == "1")
                        stol->wartosci[j] = " ";
                }
            }
        }
    }
    else
    {
        return (wiersz - 1)*kolumny + kolumna - 'A';
    }
    return 2137;
}
#endif
