/*Să se modifice problema rezolvată nr. 2, astfel încât să stocheze şi să calculeze, pentru fiecare fişier audio, și histograma normalizată, conform formulei:
histnorm(i) = (maxim−hist(i)) / (maxim−minim)
unde hist(i)
 este frecvenţa de apariţie a elementului de indice i
 în vector (secvenţa audio), maxim
 şi minim
 reprezintă frecvenţa maximă, respectiv minimă a vectorului. De data aceasta, valorile secvenței audio vor fi de valoare maxim 10.



Date de intrare:
- nr de fisiere (int)
- pentru fiecare fisier:
- numele fisierului (sir de caractere)
- valorile secventei audio (10 nr. intregi)

Date de iesire:
- pentru fiecare fisier, in ordinea citirii de la tastatura:
- valorile histogramei secventei audio normalizate (11 nr. reale cu 2 zecimale)*/

#include <stdio.h>
#include <stdlib.h>

struct Fisier{
    char nume[20];
    int secventa[11];
    float histograma[11];
};


void citire(struct Fisier *fisier, int nr){
    for(int i = 0 ; i < nr ; ++i){
        scanf("%s", (fisier + i)->nume);
        for(int j = 0 ; j < 10 ; ++j)
            scanf("%d", &(fisier + i)->secventa[j]);
    }
}

void minim_maxim(struct Fisier *element, int *minim, int *maxim){
    *minim = 99999;
    *maxim = -1;
    for(int i = 0 ; i < 10 ; ++i){
        if(*minim > element->secventa[i])
            *minim = element->secventa[i];
        if(*maxim < element->secventa[i])
            *maxim = element->secventa[i];

    }
}

void normalizare(struct Fisier *fisier, int nr){
    for(int i = 0 ; i < nr ; ++i){
        int mini, maxi;
        minim_maxim((fisier + i), &mini, &maxi);

        for(int j = 0 ; j < 10 ; ++j)
            (fisier+i)->histograma[j] = ((fisier+i)->secventa[j] - mini ) / (float)(maxi - mini);

    }
}

void histograma(struct Fisier *fisier, int nr){
    for(int i = 0 ; i < nr ; ++i)
        for(int j = 0 ; j < 10 ; ++j)
            (fisier+i)->histograma[(fisier+i)->secventa[j]]++;
}

void afisare(struct Fisier *fisier, int nr){
    for(int i = 0 ; i < nr ; ++i, printf("\n")){

        for(int j = 0 ; j < 10 ; ++j)
            printf("%.2f ", (fisier + i)->histograma[j]);
    }
}
int main(){
    int nr;

    scanf("%d", &nr);
    struct Fisier *fisier = malloc(nr*sizeof(struct Fisier));
    citire(fisier, nr);
    histograma(fisier, nr);
    normalizare(fisier, nr);
    afisare(fisier, nr);
    return 0;
}