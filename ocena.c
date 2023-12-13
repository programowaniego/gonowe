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
                
                if(stol->wartosci[pole + dodatki[i]] != " " && stol->wartosci[pole + dodatki[i]] != "1"){
                    
                    if(*stol->wartosci[pole + dodatki[i]] != napotkane[dlugosc(napotkane) - 1] && dlugosc(napotkane) < 2){  //sprawdzamy czy funkcja już napotkała taki pionek
                        napotkane[dlugosc(napotkane)] = *stol->wartosci[pole + dodatki[i]];
                        printf("%d %c\n",pole + dodatki[i],napotkane[dlugosc(napotkane) - 1]);
                    }
                }
                if(stol->wartosci[pole + dodatki[i]] == " "){ //funkcja idzie dalej kiedy spotka puste pole
                    
                    terytorium(stol, pole + dodatki[i],moje_pole,napotkane);
                }    
            }
        }
    }
}
int ile_pol(plansza* stol,int wejscie[]){     //funkcja zliczająca pola terytorium w oparciu o listę moje_pole
    int k = 0;
    for(int i = 0;i < wiersze * kolumny;i++){
        if(stol->wartosci[i] == "1")
            k++;
    }
    return k;
}
int ile_pionkow(plansza* stol, char* gracz)
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
int ocena_pola(plansza* stol,int ocena,int pole){
    int dodatki[] = {1,-1,kolumny,-kolumny};
    for(int j = 0;j < 4;j++){
        
        int sprawdzone[wiersze * kolumny] = {};
        int oddechy_grupy = 0;

        if(pole + dodatki[j] >= 0 && pole + dodatki[j] < wiersze * kolumny && stol->wartosci[pole + dodatki[j]] != " "){
            
            liczenie_oddechow_grupy(stol,pole + dodatki[j],sprawdzone,&oddechy_grupy);
            //printf("%c%d %d\n",(pole) % kolumny + 'A',((pole) - (pole) % kolumny)/kolumny + 1,oddechy_grupy);
        }
        if(stol->wartosci[pole + dodatki[j]] != " " && stol->wartosci[pole + dodatki[j]] != stol->gracz_na_ruchu && oddechy_grupy == 1){
                
            ocena += 40;
            //printf("pole: %c%d ocena - %d\n",pole % kolumny + 'A',(pole - pole % kolumny)/kolumny + 1,ocena);
                
        }
    }
}
int ocena_pozycji(plansza* stol){
    //plansza* stol = utworz_plansze(stol,stol->gracz_na_ruchu);
    
    for(int i = 0;i < wiersze * kolumny;i++){
        
        stol->wartosci[i] = stol->wartosci[i];
    
    }
        element* glowa = NULL;
        glowa = dostepne_ruchy(stol,glowa,0,0);
        int dlugosc = dlugosc_jedno(glowa);
        
        for(int i = 0;i < dlugosc; i++){
            ocena_pola(stol,0,glowa->dostepne.pozycja);
            glowa = glowa->nastepny;
            //postaw_pionek(stol,0);
            //wypisz(stol);
            //wypisz(stol);
        }   
}
#endif
