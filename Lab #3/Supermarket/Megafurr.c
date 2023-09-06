#include "Megafurr.h"
#include <stdio.h>

void citire_baza(struct megafurr *baza, int b, FILE *fp){

    for(int i = 0 ; i < b ; ++i){
        fscanf(fp, "%x %c %f", &(baza + i)->cod, &(baza + i)->tip, &(baza + i)->val);
    }
}

void citire_produse(int *a, int n, FILE *fp){

    for(int i = 0 ; i < n ; ++i)
        fscanf(fp, "%x", &a[i]);
}

void afisare_baza(struct megafurr *baza, int b){

    for(int i = 0 ; i < b ; ++i)
        printf("%x %c %.2f\n", (baza + i)->cod, (baza + i)->tip, (baza + i)->val);
}

void afisare_produse(int *a, int n){

    for(int i = 0 ; i < n ; ++i)
        printf("%x ", a[i]);
}

float suma_totala(struct megafurr *baza, const int *a, int b, int n){

    float suma = 0;
    float reducere = 0;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < b ; ++j){
            if(a[i] == (baza + j)->cod){

                if((baza + j)->tip == 'p')
                    suma += (baza + j)->val;

                else if((baza + j)->tip == 'c')
                    reducere += (baza + j)->val;
            }
        }

    return suma - suma*(reducere/100);
}