#ifndef alfabeta.c
/*
int alfaBeta(stan s, int glebokosc, int alfa, int beta)
{
    if (is_terminal_node(s) || glebokosc == 0)
        return(Eval(s, glebokosc));
    for(child=1; child<=NumOfSucc(s); child++) 
    {
        val = -alfaBeta(Succ(s, child), glebokosc - 1, -beta, -alfa);
        if(val > alfa) 
            alfa = val; // alfa=max(val,alfa);
        if(alfa >= beta) 
            return beta; // cutoff
    }
    return alfa;
}
*/
void zabij_ruchy(element* ofiara)
{
    if(ofiara)
        zabij_ruchy(ofiara->nastepny);
    free(ofiara);

}
int alfaBeta(plansza* stol,int glebokosc,int alfa,int beta,int* debesciak)
{
    element* glowa = NULL;
    //element* lista_posuniec = NULL;
    glowa = dostepne_ruchy(stol,glowa,0,0);
    if(!glebokosc || !glowa)
            
            return ocena_pozycji(stol);
    
    else{
        do 
        {
            plansza* kopia = utworz_plansze(kopia,stol->gracz_na_ruchu,stol->wartosci,0); //do kopii daję wartosci ze stolu zeby miala takie same
            //lista_posuniec = dostepne_ruchy(kopia,lista_posuniec,glowa->dostepne.pozycja,1);
            postaw_pionek(kopia,glowa->dostepne.pozycja);
            int ocena_czymtasowa = -alfaBeta(kopia,glebokosc - 1,-alfa,-beta,debesciak);
            
            kopia->gracz_na_ruchu = stol->gracz_na_ruchu == "O" ? "X" : "O"; //zmiana gracza na ruchu
            
            //printf("ocena - %d\n",ocena_czymtasowa);
            if(ocena_czymtasowa > beta)         //nie ma sensu iść w ten węzeł
                break;

            if(ocena_czymtasowa < alfa) //&& ko(stol,lista_posuniec,glowa->dostepne.pozycja))
            {
                alfa = ocena_czymtasowa;
                *debesciak = glowa->dostepne.pozycja;
                //printf("best - %d ocena - %d\n",*debesciak,alfa);
            }
            //if(glowa->poprzedni)
                free(glowa->poprzedni);
            
            glowa = glowa->nastepny;
            free(kopia);
        }while(glowa);
        
        //zabij_ruchy(glowa);
        return alfa;
    }
}
#endif