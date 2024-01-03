#ifndef wykonywanie_ruchow.c
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
int ko(plansza* stol,element* lista_posuniec,int posuniecie){
    if(dlugosc_jedno(lista_posuniec) > 1)
        //printf("%d %d",dlugosc_jedno(lista_posuniec),lista_posuniec->nastepny->dostepne.pozycja);
    
    if(dlugosc_jedno(lista_posuniec) > 1 && lista_posuniec->nastepny->dostepne.pozycja == posuniecie)
        return 0;
    
    else 
        return 1;
}
int pozycja(plansza* stol,element* lista_posuniec){
    char kolumna;
    int wiersz;
    printf("Tura %s \nPodaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",stol->gracz_na_ruchu);  
    scanf(" %c%d",&kolumna,&wiersz);
    while(kolumna < 'A'|| kolumna  > 'A' + kolumny || wiersz < 0 || wiersz > wiersze )
    { 
        printf("Podano niewlasciwa wartosc kolumny/wiersza\n");
        printf("Tura %s \n Podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",stol->gracz_na_ruchu);  
        scanf(" %c%d", &kolumna , &wiersz);
    }
    int moje_pole[wiersze * kolumny] = {};  
    if(wiersz == 0){
       
        return 2137;
    
    }
    else if(!ko(stol,lista_posuniec,(wiersz - 1)*kolumny + kolumna - 'A'))
    {
        return (wiersz - 1)*kolumny + kolumna - 'A';
    }
    else
    {
        printf("ko");
    }
    
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

    if(pole >= kolumny && pole < wiersze * kolumny){    //Sprawdzanie czy nie jest przy górnej krawędzi

        if(stol->wartosci[pole - kolumny] != " ")
                oddechy -= 1;
            }
    else
        oddechy -= 1;

    if(pole <= kolumny * (wiersze - 1)){ //Sprawdzanie czy nie jest przy dolnej krawędzi

            if(stol->wartosci[pole + kolumny] != " ")
                oddechy -= 1;
            }
    else
        oddechy -= 1;

    return oddechy;
}
int liczenie_oddechow_grupy(plansza* stol,int pole,int* sprawdzone,int *oddechy_grupy)
{
    int dodatki[] = {1,-1,kolumny,-kolumny};
    
    if(stol->wartosci[pole] != " " && sprawdzone[pole] == 0){
        *oddechy_grupy += oddechy(stol,pole);
        sprawdzone[pole] = 1;
        for(int i = 0;i < 4;i++){
            if((pole + dodatki[i] - (pole + dodatki[i]) % kolumny)/kolumny == (pole - pole % kolumny)/kolumny || (pole + dodatki[i])% kolumny == pole % kolumny){   //zapobiegamy zmianie wiersza i kolumny na raz(taki krzaczor jest ze wzgledu na liste jednokierunkowa)
                if(pole + dodatki[i] > 0 && pole + dodatki[i] < wiersze * kolumny && stol->wartosci[pole] == stol->wartosci[pole + dodatki[i]] && sprawdzone[pole + dodatki[i]] == 0){    //znalazl brachola
                    liczenie_oddechow_grupy(stol,pole + dodatki[i],sprawdzone,oddechy_grupy);
                }
            }
        } 
    }
}
void niszczenie(plansza* stol,int* sprawdzone){
    
    for(int j = 0;j < wiersze * kolumny;j++){
        
        if(sprawdzone[j] == 1){
           
            //printf("zniszczono %s na polu %c%d\n",stol->wartosci[j],j % kolumny + 'A',(j - j % kolumny)/kolumny + 1);
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
            int sprawdzone [wiersze * kolumny] = {};     //sprawdzone to lista po to zeby nie chodził w kółko w grupie, zerowanie listy co fora
            int oddechy_grupy = 0;
            liczenie_oddechow_grupy(stol,i == wiersze * kolumny ? pole : i ,sprawdzone,&oddechy_grupy);
            if(oddechy_grupy == 0 && i != pole){  //grupa nie ma oddechow
               niszczenie(stol,sprawdzone); 
            
            }
        }
    }
}

#endif