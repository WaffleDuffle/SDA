/*Să se realizeze un program care să permită stocarea datelor în mod dinamic pentru un joc de loto. Jucătorul poate juca mai multe variante. Fiecare variantă este reprezentată de o serie de maxim 49 de numere întregi în intervalul [1, 49] pe care le-a jucat și de un preț care depinde de câte numere au fost jucate astfel: pentru 6 numere jucate, biletul va costa un preț fix (de ex. 10 RON). Fiecare număr în plus peste cele 6 numere mărește prețul biletului de 1.3 ori (ex: pentru 7 numere se va achita suma de 10 * 1.3 = 13 RON; pentru 8 numere se va achita suma de (10 * 1.3) * 1.3 = 16.9 RON etc).

Să se realizeze în limbajul C următoarele:

o funcție ce permite citirea de la tastatură a unui număr de variante;
o funcție ce permite citirea de la tastatură a unui număr de numere jucate pentru fiecare variantă, în parte, respectiv numerele care reprezintă varianta respectivă;
o funcție care calculează prețul fiecărei variante;
o funcție care calculează suma totală plătită de jucător;
o funcţie care afişează preţul total plătit de jucător şi, pe câte o linie separată, fiecare variantă jucată;
un program ce integrează funcțiile realizate anterior pentru a rezolva problema enunțată.*/

#include <stdio.h>
#include <stdlib.h>

struct jucator{
    int* numere;
    int dim;
    float pret;
};

int* citire_variante(int* x, int m){
    x = malloc(m*sizeof(int));
    for(int i = 0 ; i < m ; ++i){
        scanf("%d", (x+i));
    }
    return x;
}

struct jucator* citire_jucator(struct jucator* jucator, int n){
    jucator = malloc(n*sizeof(struct jucator));
    for(int i = 0 ; i < n ; ++i){
        scanf("%d", &(jucator+i)->dim);
        (jucator+i)->numere = citire_variante((jucator+i)->numere, (jucator+i)->dim);
        (jucator+i)->pret = 0;
    }
    return jucator;
}

void afisare(struct jucator* jucator, int n){
    for(int i = 0 ; i < n ; ++i, printf("\n")){
        for(int j = 0 ; j < (jucator+i)->dim ; ++j)
            printf("%d ", (jucator+i)->numere[j]);
    }
}

float calcul_pret(struct jucator* x){

    if(x->dim <= 6)
        x->pret = 10.0;
    else{

        x->pret = 10.0;
        for(int i = 6 ; i < x->dim ; ++i)
            x->pret *= 1.3;
    }
    return x->pret;

}

float calcul_suma(struct jucator* x, int n){
    float s = 0;
    for(int i = 0 ; i < n ; ++i){
        (x+i)->pret = calcul_pret((x+i));
        s += (x+i)->pret;
    }
    return s;
}

int main(){
    int n;
    int op;
    scanf("%d", &n);
    struct jucator* jucatori = citire_jucator(jucatori, n);
    scanf("%d", &op);
    switch(op){
        case 3: {
            for(int i = 0 ; i < n ; ++i){
                (jucatori+i)->pret = calcul_pret((jucatori+i));
                printf("%.2f\n", (jucatori+i)->pret);
            }
            break;
        }
        case 4: {
            printf("%.2f\n", calcul_suma(jucatori, n));
        }
        case 5: {
            printf("%.2f\n", calcul_suma(jucatori, n));
            afisare(jucatori, n);
        }
    }
    return 0;
}