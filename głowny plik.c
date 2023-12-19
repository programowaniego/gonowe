#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<windows.h>
#include "Plansza.c"
#include "wpisywanie.c"
#include "wykonywanie_ruchow.c"
#include "ocena.c"

void main()
{
    plansza* stol = utworz_plansze(stol,"X");
    /*int pozycjeX[] = {3,4,11,12,21,30,29,28,27,36,38,40,49,50,51,58,56,60,61,65,67,69,71,77,77,77};
    int pozycjeY[] = {5,13,14,15,22,31,33,34,37,39,41,42,44,45,46,47,48,52,53,55,57,62,64,66,75,76};
    //int pozycjeX[] = {3,4,5,11,13,21,30,57,67,68,75};
    //int pozycjeY[] = {6,15,14,23,22,31,58,59,61,69,78};
    for(int i = 0;i < 26;i++){
        postaw_pionek(stol,pozycjeX[i]);
        stol->gracz_na_ruchu = "O";
        postaw_pionek(stol,pozycjeY[i]);
        stol->gracz_na_ruchu = "X";

    }*/
    stol->gracz_na_ruchu = "O";
    wypisz(stol);
    for(int i = 1;i <= wiersze*kolumny && 1;i++){

        int polozenie = pozycja(stol);
        postaw_pionek(stol,polozenie);
        wypisz(stol);
        
        if(stol->gracz_na_ruchu == "O"){
            
            printf("ocena gracza %s - %d\n",stol->gracz_na_ruchu,ocena_pozycji(stol));
            stol->gracz_na_ruchu = "X";
            printf("ocena gracza %s - %d\n",stol->gracz_na_ruchu,ocena_pozycji(stol));
        
        }
        else{
            
            printf("ocena gracza %s - %d\n",stol->gracz_na_ruchu,ocena_pozycji(stol));
            stol->gracz_na_ruchu = "O";
            printf("ocena gracza %s - %d\n",stol->gracz_na_ruchu,ocena_pozycji(stol));
        
        }
    }   
}   
