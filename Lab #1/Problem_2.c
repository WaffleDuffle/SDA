/* Să se realizeze un program ce permite citirea de la tastatură a unui vector de maxim 10 elemente numere întregi. Să se afişeze pe ecran (adresele de memorie ale elementelor vectorului şi) suma elementelor acestuia. Operațiile se vor realiza prin intermediul pointerilor.


Pentru evaluarea automată a problemei:

INPUT:
un întreg, n, reprezentând numărul de elemente ale vectorului;
n întregi, reprezentând elementele vectorului;
OUTPUT:
suma elementelor vectorului. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *p;
    int vec[10];
    printf("Introduceti dimensiunea vectorului:\n");
    scanf("%d",&n);
    int s = 0;
    for(int i = 0 ; i < n ; ++i){
        scanf("%d", &vec[i]);
        p = &vec[i];
        s += *p;
    }
    printf("suma elementelor vectorului este = %d\n\n", s);
    printf("valoarea si adresa fiecarui element din vector este:\n\n");
    for(int i = 0 ; i < n ; ++i){
        printf("%d: valoarea = %d\nadresa = %p\n\n", i, vec[i], &vec[i]);
    }
    
    return 0;
}
