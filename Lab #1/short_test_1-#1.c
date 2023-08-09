/* Realizați un program care să permită alocarea dinamică de memorie pentru o matrice bidimensională M, de m × n elemente reale, inițializată cu valoarea 0. Să se afișeze adresele primului și ultimului element din matrice.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float **a;
    int m, n;
    scanf("%d%d",&m,&n);
    a = malloc(m*sizeof(float*));
    for(int i = 0 ; i < m ; ++i)
        a[i] = calloc(n, sizeof(float));
        
    for(int i = 0 ; i < m ; ++i, printf("\n"))
        for(int j = 0 ; j < n ; ++j)
            printf("%.2f ", a[i][j]);
    printf("Adresa primului element: %p\n", &a[0][0]);
    printf("Adresa ultimului element: %p\n", &a[m-1][n-1]);
    return 0;
}
