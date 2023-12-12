#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
#include "Plansza.c"
#include "wpisywanie.c"
#include "wykonywanie_ruchow.c"
#include "terytorium.c"
#include "ocena.c"

void main()
{
    plansza* stol = utworz_plansze(stol,"X");
    int pozycjeX[] = {3,4,11,12,21,30,29,28,27,36,38,40,49,50,51,58,56,60,61,65,67,69,71,77,77,77};
    int pozycjeY[] = {5,13,14,15,22,31,33,34,37,39,41,42,44,45,46,47,48,52,53,55,57,62,64,66,75,76};
    //int pozycjeX[] = {3,4,5,11,13,21,30,57,67,68,75};
    //int pozycjeY[] = {6,15,14,23,22,31,58,59,61,69,78};
    for(int i = 0;i < 26;i++){
        postaw_pionek(stol,pozycjeX[i]);
        stol->gracz_na_ruchu = "O";
        postaw_pionek(stol,pozycjeY[i]);
        stol->gracz_na_ruchu = "X";

    }
    //postaw_pionek(stol,0);
    stol->gracz_na_ruchu = "O";
    wypisz(stol);
    ocena_pozycji(stol);
    /*
    element* glowa = dostepne_ruchy(stol,glowa);
    int k = dlugosc_jedno(glowa);
    for(int i = 0;i < k;i++){
        
        printf("%c%d\n",glowa->dostepne.pozycja % kolumny + 'A',1 + (glowa->dostepne.pozycja - glowa->dostepne.pozycja % kolumny)/kolumny);
        glowa = glowa->nastepny;
    }
    */
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
}
    
    
