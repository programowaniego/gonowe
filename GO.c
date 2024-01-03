#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include "Plansza.c"
#include "wykonywanie_ruchow.c"
#include "ocena.c"
#include "alfabeta.c"

void main()
{
    plansza* stol = utworz_plansze(stol,"X",0,1);
    element* lista_posuniec = NULL;
    /*int pozycjeX[] = {3,4,11,12,21,30,29,28,27,36,38,40,49,50,51,58,56,60,61,65,67,69,71,77,77,77};
    int pozycjeY[] = {5,13,14,15,22,31,33,34,37,39,41,42,44,45,46,47,48,52,53,55,57,62,64,66,75,76};
    //int pozycjeX[] = {3,4,5,11,13,21,30,57,67,68,75};
    //int pozycjeY[] = {6,15,14,23,22,31,58,59,61,69,78};
    for(int i = 0;i < 26;i++){
        postaw_pionek(stol,pozycjeX[i]);
        stol->gracz_na_ruchu = "O";
        lista_posuniec = dostepne_ruchy(stol,lista_posuniec,pozycjeX[i],1);
        postaw_pionek(stol,pozycjeY[i]);
        stol->gracz_na_ruchu = "X";
        lista_posuniec = dostepne_ruchy(stol,lista_posuniec,pozycjeY[i],1);

    }*/
    stol->gracz_na_ruchu = "O";
    wypisz(stol);
    int polozenie = 0, i = 0;
    while(polozenie != 2137 && i != 81){
        
        if(stol->gracz_na_ruchu == "O")
        {
            /*polozenie = pozycja(stol,lista_posuniec);
            element* lista_posuniec = dostepne_ruchy(stol,lista_posuniec,polozenie,1);
            postaw_pionek(stol,polozenie);
            wypisz(stol);
            stol->gracz_na_ruchu = "X";*/
            
            int alfa = 1000, debesciak;
            int beta = -1000;
            alfaBeta(stol,4,&alfa,beta,&debesciak);
            postaw_pionek(stol,debesciak);
            wypisz(stol);
            //element* lista_posuniec = dostepne_ruchy(stol,lista_posuniec,polozenie,1);
            stol->gracz_na_ruchu = "X";
            printf("%c%d\n",debesciak%kolumny + 'A',(debesciak - debesciak%kolumny)/kolumny + 1);
            
        }
        else
        {
            int alfa = 1000, debesciak;
            int beta = -1000;
            alfaBeta(stol,4,&alfa,beta,&debesciak);
            postaw_pionek(stol,debesciak);
            wypisz(stol);
            //element* lista_posuniec = dostepne_ruchy(stol,lista_posuniec,polozenie,1);
            stol->gracz_na_ruchu = "O";
            printf("%c%d\n",debesciak%kolumny + 'A',(debesciak - debesciak%kolumny)/kolumny + 1);
        }
        i++;
    }
    
    terytorium_po_calosci(stol,"X");
    wypisz(stol);
    terytorium_po_calosci(stol,"O");
    printf("Podsumowanie rozgrywki:\nTerytorium X - %d Terytorium O - %d\nPionki X - %d     Pionki O - %d\nPunkty X - %.1f     Punkty O - %d\n",stol->terytoriumX,stol->terytoriumO,ile_pionkow(stol,"X"),ile_pionkow(stol,"O"),stol->terytoriumX + ile_pionkow(stol,"X") + 5.5,stol->terytoriumO + ile_pionkow(stol,"O"));
}
