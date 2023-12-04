#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "Plansza.c"
#include "wpisywanie.c"
#include "wykonywanie_ruchow.c"
#include "terytorium.c"

void main()
{
    plansza* stol = utworz_plansze(stol);
    int pozycjeX[] = {3,4,5,11,13,21,30,39,40,48,57,67,68,75,76};
    int pozycjeY[] = {6,15,14,23,22,31,41,49,58,59,61,69,78,77,77};
    for(int i = 0;i < 15;i++){
        postaw_pionek(stol,pozycjeX[i]);
        stol->gracz_na_ruchu = "O";
        postaw_pionek(stol,pozycjeY[i]);
        stol->gracz_na_ruchu = "X";

    }
    for(int i = 1;i <= wiersze*kolumny && 1;i++){
        int polozenie = pozycja(stol);
        
        if(polozenie != 2137){
            postaw_pionek(stol,polozenie);//warunek na puste pole
        
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
    
    
