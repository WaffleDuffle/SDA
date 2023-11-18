#include <stdio.h>
#include "functii.h"
#include <stdlib.h>
int main() {
    struct masina* lista1 = NULL;
    struct masina* lista2 = NULL;
    int m, n;
    char x[20];
    scanf("%d%d", &m, &n);
    for(int i = 0 ; i < m ; ++i){
        scanf("%s", x);
        enqueue(&lista1, x);
    }
    for(int i = 0 ; i < n ; ++i){
        scanf("%s", x);
        enqueue(&lista2, x);
    }

    struct masina* rez = interclasare(lista1, lista2);
    afisare(&rez);
}
