#ifndef ocena.c
typedef struct{
    int pozycja;
}ruchy;

typedef struct element{
    ruchy dostepne;
    struct element* nastepny;
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
element* dostepne_ruchy(plansza* stol,element* glowa){
    
    for(int i = 0;i < wiersze * kolumny;i++)
    {
        if(stol->wartosci[i] == " ")
        {
            glowa = utworz_element(glowa , (ruchy) { .pozycja = i});
            
        }
    }
    return glowa;
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
int ocena_pola(plansza* kopia,int ocena,int pole){
    int dodatki[] = {1,-1,kolumny,-kolumny};
    for(int j = 0;j < 4;j++){
        
        int sprawdzone[wiersze * kolumny] = {};
        int oddechy_grupy = 0;

        if(pole + dodatki[j] >= 0 && pole + dodatki[j] < wiersze * kolumny && kopia->wartosci[pole + dodatki[j]] != " "){
            liczenie_oddechow_grupy(kopia,pole + dodatki[j],sprawdzone,&oddechy_grupy);
            printf("%c%d %d\n",(pole + dodatki[j]) % kolumny + 'A',((pole + dodatki[j]) - (pole + dodatki[j]) % kolumny)/kolumny + 1,oddechy_grupy);
        }
        if(kopia->wartosci[pole + dodatki[j]] != " " && kopia->wartosci[pole + dodatki[j]] != kopia->gracz_na_ruchu && oddechy_grupy == 1){
                
            ocena += 40;
            printf("pole: %c%d ocena - %d\n",pole % kolumny + 'A',(pole - pole % kolumny)/kolumny + 1,ocena);
                
        }
    }
}
int ocena_pozycji(plansza* stol){
    plansza* kopia = utworz_plansze(kopia,stol->gracz_na_ruchu);
    
    for(int i = 0;i < wiersze * kolumny;i++){
        
        kopia->wartosci[i] = stol->wartosci[i];
    
    }
        element* glowa = NULL;
        glowa = dostepne_ruchy(stol,glowa);
        int dlugosc = dlugosc_jedno(glowa);
        for(int i = 0;i < dlugosc; i++){
            ocena_pola(kopia,0,glowa->dostepne.pozycja);
            glowa = glowa->nastepny;
            //postaw_pionek(kopia,0);
            //wypisz(kopia);
            //wypisz(stol);
        }   
}
#endif
