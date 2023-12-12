#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
#include "Plansza.c"
#include "wpisywanie.c"
#include "wykonywanie_ruchow.c"
#include "terytorium.c"

void main()
{
    plansza* stol = utworz_plansze(stol);
    //int pozycjeX[] = {3,4,11,12,21,30,29,28,27,36,38,40,49,50,51,58,56,60,61,65,67,69,71,77,77,77}; inna pozycja
    //int pozycjeY[] = {5,13,14,15,22,31,33,34,37,39,41,42,44,45,46,47,48,52,53,55,57,62,64,66,75,76};
    int pozycjeX[] = {3,4,5,11,13,21,30,57,67,68,75};
    int pozycjeY[] = {6,15,14,23,22,31,58,59,61,69,78};
    for(int i = 0;i < 11;i++){
        postaw_pionek(stol,pozycjeX[i]);
        stol->gracz_na_ruchu = "O";
        postaw_pionek(stol,pozycjeY[i]);
        stol->gracz_na_ruchu = "X";

    }
    wypisz(stol);
    //element* poczatek = kolejne_dostepne(stol);
    element* glowa = NULL;
    //glowa = utworz_element(glowa , (ruchy) { .pozycja = 1});
    //kolejne_dostepne(stol,glowa);
    for(int i = 0;i < wiersze * kolumny;i++)
    {
        if(stol->wartosci[i] == " ")
        {
            glowa = utworz_element(glowa , (ruchy){ .pozycja = i});
        }
    }
    int k = dlugosc_jedno(glowa);
    for(int i = 0;i < k;i++){
        
        printf("%d\n",glowa->dostepne);
        glowa = glowa->nastepny;
    }
    
    for(int i = 1;i <= wiersze*kolumny && 1;i++){
        int polozenie = pozycja(stol);

        if(polozenie != 2137){
            postaw_pionek(stol,polozenie);//warunek na puste pole
            wypisz(stol);

        if(stol->gracz_na_ruchu == "O")
                stol->gracz_na_ruchu = "X";

        else
                stol->gracz_na_ruchu = "O";
        }

    }

        //ruchy* mozliwe = mozliwe_ruchy(mozliwe,stol);
        //printf("%d\n",mozliwe->dostepne_ruchy[169]);
        //free(mozliwe); 
}
    
    
