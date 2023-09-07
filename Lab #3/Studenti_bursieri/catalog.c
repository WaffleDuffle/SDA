#include "catalog.h"
#include <stdio.h>
#include <stdlib.h>

void citire_date(struct catalog *elevi, int n, FILE *in){

    for(int i = 0 ; i < n ; ++i){
        fscanf(in, "%s %s", (elevi+i)->nume,
                                    (elevi+i)->prenume);

        (elevi+i)->note = (int*)malloc(5*sizeof(int));
        for(int j = 0 ; j < 5 ; ++j)
            fscanf(in, "%d", &(elevi+i)->note[j]);
    }
}

void afisare_date(struct catalog *elevi, int n){
    for(int i = 0 ; i < n ; ++i){
        printf("%s %s ", (elevi+i)->nume,
                        (elevi+i)->prenume);

        for(int j = 0 ; j < 5 ; ++j)
            printf("%d ", (elevi+i)->note[j]);
        printf("\n");
    }
}

void eliberare_memorie(struct catalog *elevi, int n){
    for(int i = 0 ; i < n ; ++i)
        free((elevi+i)->note);
}

void count(struct catalog* elevi, int n){
    int burse_merit = 0, burse_performanta = 0;

    for(int i = 0 ; i < n ; ++i){
        int integralist = 1;
        int suma = 0;
        float medie;
        for(int j = 0 ; j < 5 ; ++j) {
            if((elevi + i)->note[j] <= 4){
                integralist = 0;
                break;
            }
            suma += (elevi + i)->note[j];

        }
        medie = (float)suma/5;

        if(medie >= 9.8 && integralist == 1)
            burse_performanta++;
        else if(medie >= 8.0 && integralist == 1)
            burse_merit++;
    }
    printf("%d %d\n", burse_merit, burse_performanta);
}