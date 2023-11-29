#ifndef wpisywanie.c
int pozycja(plansza* stol)
{
 char kolumna;
 int wiersz;
int znaki = 0;
do {
        printf("Tura %s \nPodaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",stol->gracz_na_ruchu);  
        int wejscie = scanf(" %c%d", &kolumna, &wiersz);
        znaki = getchar();
    } while (znaki == " ");
while(kolumna < 'A'|| kolumna  > 'A' + kolumny || wiersz < 0 || wiersz > wiersze)
    {
        printf("podano niewlasciwa wartosc kolumny/wiersza\n");
        printf("Tura %s \n Podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n",stol->gracz_na_ruchu);  
        scanf("%c%d", &kolumna , &wiersz);
        getchar();
    }
    return (wiersz - 1)*kolumny + kolumna - 'A';
}
#endif
