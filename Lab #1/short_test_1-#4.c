/*Realizați un program care să permită citirea de la tastatură a unei matrice de valori reale bidimensională M, de dimensiune m × n elemente reale folosind aritmetica pointerilor și alocarea dinamică de memorie. Valorile m și n se vor citi de la tastatură.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float **a;
    int m, n;
    scanf("%d%d",&m,&n);
    a = malloc(m*sizeof(int*));
    for(int i = 0 ; i < m ; ++i)
        a[i] = calloc(n, sizeof(int));
    for(int i = 0 ; i < m ; ++i)
        for(int j = 0 ; j < n ; ++j)
            scanf("%f", &a[i][j]);
            
    return 0;
}
