#ifndef wykonywanie_ruchow.c
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
    *nowy = (element) { nowy->dostepne = dostepne, nowy->nastepny = NULL};
    if (glowa)
    {
        for(element* pom = glowa; pom->nastepny || !(pom->nastepny = nowy); pom = pom->nastepny);
            return glowa;
    }
    return nowy;
}
void kolejne_dostepne(plansza* stol,element* glowa){
    
    for(int i = 0;i < wiersze * kolumny;i++)
    {
        if(stol->wartosci[i] == " ")
        {
            glowa = utworz_element(glowa , (ruchy) { .pozycja = i});
            
        }
    }
}
int dlugosc_jedno(element* glowa)
    {
    if (!glowa) 
    return 0;
    int i = 1;
    while (glowa -> nastepny)
    {
        glowa=glowa -> nastepny;
        i++;
    }
    return i;
    }
int oddechy(plansza* stol,int pole){    //oddechy pojedynczego pionka
    int oddechy = 4;
    if(pole % kolumny != kolumny - 1){  //Sprawdzanie czy nie jest przy prawej krawędzi

        if(stol->wartosci[pole + 1] != " ")
            oddechy -= 1;
        }

    else
        oddechy -= 1;

    if(pole % kolumny != 0){    //Sprawdzanie czy nie jest przy lewej krawędzi

        if(stol->wartosci[pole - 1] != " ")
            oddechy -= 1;
    }

    else
        oddechy -= 1;

    if(pole >= kolumny){    //Sprawdzanie czy nie jest przy górnej krawędzi

        if(stol->wartosci[pole - kolumny] != " ")
                oddechy -= 1;
            }
    else
        oddechy -= 1;

    if(pole < kolumny * (kolumny - 1)){ //Sprawdzanie czy nie jest przy dolnej krawędzi

            if(stol->wartosci[pole + kolumny] != " ")
                oddechy -= 1;
            }
    else
        oddechy -= 1;

    return oddechy;
}
int liczenie_oddechow_grupy(plansza* stol,int pole,int* sprawdzone,int oddechy_grupy)
{
    int dodatki[] = {1,-1,kolumny,-kolumny};
    
    if(stol->wartosci[pole] != " " && sprawdzone[pole] == 0){
        oddechy_grupy += oddechy(stol,pole);
        sprawdzone[pole] = 1;
        
        for(int i = 0;i < 4;i++){
            
            if(stol->wartosci[pole] == stol->wartosci[pole + dodatki[i]] && sprawdzone[pole + dodatki[i]] == 0){    //znalazl brachola
                oddechy_grupy += liczenie_oddechow_grupy(stol,pole + dodatki[i],sprawdzone,oddechy_grupy);
            }
        } 
        
        return oddechy_grupy;
    }
}
void niszczenie(plansza* stol,int* sprawdzone){
    
    for(int j = 0;j < wiersze * kolumny;j++){
        
        if(sprawdzone[j] == 1){
           
            printf("zniszczono %s na polu %c%d\n",stol->wartosci[j],j % kolumny + 'A',(j - j % kolumny)/kolumny + 1);
            stol->wartosci[j] = " ";
            sprawdzone[j] = 0;
        }
    }
}
int postaw_pionek(plansza* stol,int pole)
{
    if(stol->wartosci[pole] == " "){
        stol->wartosci[pole] = stol->gracz_na_ruchu;  
        
        for(int i = 0;i < wiersze * kolumny + 1;i++){
            int sprawdzone [wiersze * kolumny] = {};     //wskażnik musi być bo wywala błąd, sprawdzone to lista po to zeby nie chodził w kółko w grupie, zerowanie listy co fora
            
            if(i == wiersze * kolumny ? liczenie_oddechow_grupy(stol,pole,sprawdzone,0) == 0 : stol->wartosci[i] != " " && liczenie_oddechow_grupy(stol,i,sprawdzone,0) == 0 && i != pole){  //grupa nie ma oddechow
               niszczenie(stol,sprawdzone); 
            
            }
        }
    }
}

#endif
