#ifndef terytorium.c

int terytorium(plansza* stol,int pole,int moje_pole[],char *napotkane){
    
    int dodatki[] = {1,-1,kolumny,-kolumny};
    moje_pole[pole] = 1;
    stol->wartosci[pole] = "1";
    
    for(int i = 0;i < 4;i++){
        if(pole + dodatki[i] >= 0 && pole + dodatki[i] < wiersze * kolumny && moje_pole[pole + dodatki[i]] == 0){     //nie wychodzimy poza planszę
            
            if((pole + dodatki[i] - (pole + dodatki[i]) % kolumny)/kolumny == (pole - pole % kolumny)/kolumny || (pole + dodatki[i])% kolumny == pole % kolumny){ //zapobiegamy zmianie kolumny i wiersza na raz
                
                if(stol->wartosci[pole + dodatki[i]] != " "){

                    if(*stol->wartosci[pole + dodatki[i]] != *napotkane && stol->wartosci[pole + dodatki[i]] != "1"){  //sprawdzamy czy funkcja już napotkała taki pionek
                        *napotkane = *stol->wartosci[pole + dodatki[i]];
                        printf("%d %c\n",pole + dodatki[i],*napotkane);
                    }
                }
                if(stol->wartosci[pole + dodatki[i]] == " "){ //funkcja idzie dalej kiedy spotka puste pole
                    
                    terytorium(stol, pole + dodatki[i],moje_pole,napotkane);
                }    
            }
        }
    }
}
int ile_pol(plansza* stol,int wejscie[],int czy_pionki){     //funkcja zliczająca pola terytorium w oparciu o listę moje_pole
    int k = 0;
    for(int i = 0;i < wiersze * kolumny;i++){
        if(stol->wartosci[i] == "1" && !czy_pionki)
            k++;
        else if(wejscie[i] && czy_pionki)
            k++;
    }
    return k;
}
#endif
