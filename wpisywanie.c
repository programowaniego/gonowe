#ifndef wpisywanie.c
int pozycja(char gracz[2])
{
int pozycja = 0;
 char kolumna;
 int wiersz;
printf("Tura %s \nPodaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",gracz);  
scanf("%c%d", &kolumna , &wiersz);
getchar();
 while(kolumna < 'A'|| kolumna  > 'M' || wiersz < 0 || wiersz > 13 || wiersz == ' ' || kolumna == ' ')
    {
        printf("podano niewlasciwa wartosc kolumny/wiersza\n");
        printf("Tura %s \n Podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",gracz);  
        scanf("%c%d", &kolumna , &wiersz);
        getchar();
    }
    pozycja = (wiersz - 1)*13 + kolumna - 'A';
    return pozycja;
}
#endif


