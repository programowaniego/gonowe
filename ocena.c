#ifndef ocena.c
int dlugosc(char wejscie[]){
    
    int k = 0;
    while(wejscie[k])
        k++;
    
    return k;
}
int terytorium(plansza* stol,int pole,int moje_pole[],char *napotkane){
    
    int dodatki[] = {1,-1,kolumny,-kolumny};
    moje_pole[pole] = 1;
    stol->wartosci[pole] = "1";
     
    for(int i = 0;i < 4;i++){
        if(pole + dodatki[i] >= 0 && pole + dodatki[i] < wiersze * kolumny && moje_pole[pole + dodatki[i]] == 0){     //nie wychodzimy poza planszę
            
            if((pole + dodatki[i] - (pole + dodatki[i]) % kolumny)/kolumny == (pole - pole % kolumny)/kolumny || (pole + dodatki[i])% kolumny == pole % kolumny){ //zapobiegamy zmianie kolumny i wiersza na raz
                
                if(stol->wartosci[pole + dodatki[i]] != " " && stol->wartosci[pole + dodatki[i]] != "1"){           //nie liczymy pustych pól i znaczników terytorium(1)
                    
                    if(*stol->wartosci[pole + dodatki[i]] != napotkane[dlugosc(napotkane) - 1] && dlugosc(napotkane) < 2){  //sprawdzamy czy funkcja już napotkała taki pionek
                        
                        napotkane[dlugosc(napotkane)] = *stol->wartosci[pole + dodatki[i]];
                    
                    }
                }
                if(stol->wartosci[pole + dodatki[i]] == " "){ //funkcja idzie dalej kiedy spotka puste pole
                    
                    terytorium(stol, pole + dodatki[i],moje_pole,napotkane);
                }    
            }
        }
    }
}
int ile_pol(plansza* stol){     //funkcja zliczająca pola terytorium w oparciu o listę moje_pole
    int k = 0;
    for(int i = 0;i < wiersze * kolumny;i++){
        if(stol->wartosci[i] == "1")
            k++;
    }
    return k;
}
int ile_pionkow(plansza* stol, char* gracz)     //gracz jest po to żeby funkcja mogła przeliczyć pionki nie tylko gracza na ruchu ale przeciwnika a nawet puste pola
{
    int k = 0;
        for(int i = 0 ; i < wiersze * kolumny ; i++ )
        {
        if(stol->wartosci[i] == gracz) k++; 
        }
    return k;
}
int dlugosc_jedno(element* glowa)
{
    if (!glowa) 
        return 0;
    
    int i = 1;
    
    while (glowa -> nastepny)
    {
        glowa = glowa -> nastepny;
        i++;
    }
    return i;
}
int odleglosc_od_srodka(int srodek,int pozycja){
    int odlegloscx = srodek % kolumny - pozycja % kolumny;
    int odlegloscy = (srodek - srodek % kolumny)/kolumny - (pozycja - pozycja % kolumny)/kolumny;
    if(odlegloscx < 0)
        
        odlegloscx *= -1;
    
    if(odlegloscy < 0)
        
        odlegloscy *= -1;    
    
    return odlegloscx + odlegloscy;
}
int ocena_pozycji(plansza* stol){
    int ocena = 0;
    int oddechy_grupy = 0;
    int moje_pole[wiersze * kolumny] = {};

    ocena += 10 * ile_pionkow(stol,stol->gracz_na_ruchu);
    printf("ocena z pionkow - %d\n",ocena);
    
    for(int i = 0;i < wiersze * kolumny; i++){
        
        int sprawdzone[wiersze * kolumny] = {};
        //oddechy_grupy = 0;
        if(stol->wartosci[i] == stol->gracz_na_ruchu){
                
            liczenie_oddechow_grupy(stol,i,sprawdzone,&oddechy_grupy);
        
        }
        if(moje_pole[i] == 0 && stol->wartosci[i] == " "){      //warunek czy już nie sprawdzone i czy puste
            
            char napotkane[2] = "";
            terytorium(stol,i,moje_pole,napotkane);
            
            if(dlugosc(napotkane) == 1 && napotkane[0] == *stol->gracz_na_ruchu){         //dodajemy ocene terytorium tylko gracza który się rusza
                
                int pomocnicza = 0;
                pomocnicza = ocena;
                ocena += ile_pol(stol) * 50;
                printf("ocena z terytorium- %d\n",ocena - pomocnicza);
            }

            for(int j = 0;j < wiersze * kolumny;j++){
                
                if(stol->wartosci[j] == "1")
                    
                    stol->wartosci[j] = " ";
            
            }
        }
        if(stol->wartosci[i] == stol->gracz_na_ruchu)
            
            ocena -= odleglosc_od_srodka(wiersze*kolumny/2,i) * 2;
    }
    int pomocnicza = 0;
    pomocnicza = ocena;
    ocena += 1 * oddechy_grupy;
    printf("ocena z oddechow - %d\n",ocena - pomocnicza);

    return ocena;
}
#endif
