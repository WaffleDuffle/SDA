/*Să se realizeze un program ce permite stocarea de date pentru N fişiere audio. Fiecare fişier va conţine următoarele informaţii: un vector de lungime 10 cu valori numere întregi cuprinse între 0 şi 255 (secvenţa audio), un şir de caractere de lungime 20 (numele fişierului) şi un vector de lungime 10 cu valori numere reale, cuprinse între 0 şi 1 (secvenţa audio normalizată). Programul va calcula şi afişa pe ecran, pentru fiecare fişier, numele şi secvenţa audio normalizată, calculată după următoarea formulă:

secventanorm(i)= (secventa(i)−minim) / (maxim−minim)

unde secventa(i)
 este valoarea elementului de indice i
 în cadrul secvenţei originale, maxim
 şi minim
 reprezintă valoarea maximă, respectiv minimă a secvenţei originale, iar secventanorm(i)
 reprezintă valoarea normalizată corespunzătoare elementului de indice i
 din secvenţa originală.

Date de intrare:
- nr de fisiere (int)
- pentru fiecare fisier:
- numele fisierului (sir de caractere)
- valorile secventei audio (10 nr intregi)

Date de iesire:
- pentru fiecare fisier, in ordinea citirii de la tastatura:
- valorile secventei audio normalizate (10 nr reale cu 2 zecimale)*/

#include <stdio.h>
#include <stdlib.h>
//structura Fisiere
struct Fisiere{
    char nume[20];
    int secventa[10];
    float secventa_norm[10];
};
//citirea elementelor structurii
void citire(struct Fisiere *pfisier, int n){
    for(int i = 0 ; i < n ; ++i){
        scanf("%s", (pfisier + i)->nume);
        for(int j = 0 ; j < 10 ; ++j)
            scanf("%d", &(pfisier + i)->secventa[j]);
    }
}
// pass by reference pentru valoarea minima si maxima din secventa
void minim_maxim(struct Fisiere fisier, int *mini, int *maxi){
    *mini = 99999;
    *maxi = -1;
    for(int i = 0 ; i < 10 ; ++i){
        if(*mini > fisier.secventa[i])
            *mini = fisier.secventa[i];
        if(*maxi < fisier.secventa[i])
            *maxi = fisier.secventa[i];
    }
}
// afisarea rezultatului
void afisare(struct Fisiere *pfisier, int n){
    for(int i = 0 ; i < n ; ++i){
        int minim, maxim;  
        minim_maxim(*(pfisier + i), &minim, &maxim);
        for(int j = 0 ; j < 10 ; ++j)
            printf("%.2f ", (float)((pfisier + i)->secventa[j] - minim)/(maxim - minim));
        printf("\n");
    }
}

int main(){
    struct Fisiere *fisiere;
    int n;
    scanf("%d", &n);
    fisiere = malloc(n*sizeof(struct Fisiere));
    citire(fisiere, n);
    afisare(fisiere,n);
    free(fisiere);
    return 0;
}
