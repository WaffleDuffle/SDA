/* Să se realizeze un program ce permite citirea de la tastatură şi afişarea a două matrice de numere întregi, de dimensiuni introduse de la tastatură. Programul va calcula şi afişa matricea diferenţă a celor două matrice. Alocarea memoriei pentru matrice se va realiza dinamic. Pentru soluționarea problemei se vor folosi pointeri.


Pentru evaluarea automată a problemei:

INPUT:
un întreg, m, reprezentând numărul de linii al matricelor;
un întreg, n, reprezentând numărul de coloane al matricelor;
m*n întregi, reprezentând elementele primei matrice;
m*n întregi, reprezentând elementele celei de-a doua matrice;
OUTPUT:
valorile primei matrice;
valorile celei de-a doua matrice;
valorile matricei diferență.*/

#include <stdio.h>
#include <stdlib.h>

void printmat(int **a, int m, int n){
    for(int i = 0 ; i < m ; ++i, printf("\n"))
        for(int j = 0 ; j < n ; ++j)
            printf("%d ", a[i][j]);
}

int **citiremat(int **a, int m, int n){
    a = malloc(m*sizeof(int*));
    if(!a)
        printf("Memoria nu a putut fi alocata"), exit(1);
    for(int i = 0 ; i < m ; ++i){
        a[i] = calloc(n,sizeof(int));
    }
    
    for(int i = 0 ; i < m ; ++i)
        for(int j = 0 ; j < n ; ++j)
            scanf("%d", &a[i][j]);
    return a;
}

void eliberare(int **a, int m, int n){
    if(a != NULL){
        for(int i = 0 ; i < m ; ++i)
            free(a[i]);
        free(a);
    }
}
int main(){
    int **a, **b;
    int m,n;
    
    scanf("%d%d",&m,&n);
    
    
    a = citiremat(a,m,n);
    b = citiremat(b,m,n);
    printmat(a,m,n);
    printmat(b,m,n);
    for(int i = 0 ; i < m ; ++i)
        for(int j = 0 ; j < n ; ++j)
            a[i][j] = a[i][j] - b[i][j];
    printmat(a,m,n);
    eliberare(a,m,n);
    eliberare(b,m,n);
    return 0;
}
