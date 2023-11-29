#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "Plansza.c"
#include "wpisywanie.c"
#include "wykonywanie_ruchow.c"
void main()
{
    plansza* stol = utworz_plansze(stol);
    for(int i = 1;i <= wiersze*kolumny;i++){
        postaw_pionek(stol,pozycja(stol));//warunek na puste pole
        ruchy* mozliwe = mozliwe_ruchy(mozliwe,stol);
        //printf("%d\n",mozliwe->dostepne_ruchy[169]);
        free(mozliwe); 
    }
    
}
    
