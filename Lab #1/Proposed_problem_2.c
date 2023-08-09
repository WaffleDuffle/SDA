/* Să se realizeze un program ce permite interschimbarea a două linii ale unei matrice pătratice de elemente întregi. Se vor defini şi utiliza funcţii diferite pentru citirea, afişarea şi pentru interschimbarea liniilor unei matrice. Operaţiile se vor realiza folosind pointeri.

Pentru evaluarea automată a problemei:

INPUT:
un întreg reprezentând dimensiunea n, a matricei pătratice n x n;
un întreg reprezentând indexul primei linii care urmează să fie interschimbată;
un întreg reprezentând indexul celei de-a doua linii care urmează să fie interschimbată;
n * n întregi reprezentând elementele matricei.
OUTPUT:
n * n întregi reprezentând elementele matricei rezultate.*/

#include <stdio.h>
#include <stdlib.h>

void printmat(int **a, int n){
    for(int i = 0 ; i < n ; ++i, printf("\n"))
        for(int j = 0 ; j < n ; ++j)
            printf("%d ", a[i][j]);
}

int **citiremat(int **a, int n){
    a = malloc(n*sizeof(int*));
    if(a == NULL)
        printf("alocare esuata"), exit(1);
    for(int i = 0 ; i < n ; ++i)
        a[i] = calloc(n, sizeof(int));
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            scanf("%d", &a[i][j]);
    return a;
}

void interschimbare(int **a, int n, int x, int y){
    int tmp;
    for(int i = 0 ; i < n ; ++i){
        tmp = a[x][i];
        a[x][i] = a[y][i];
        a[y][i] = tmp;
    }
    
}

void eliberare(int **a, int n){
    for(int i = 0 ; i < n ; ++i)
        free(a[i]);
    free(a);
}

int main(){
    int n, x, y;
    int **a;
    
    printf("n = ");
    scanf("%d", &n);
    
    printf("\nIntroduceti liniile care sa fie interschimbate:\n");
    scanf("%d%d", &x, &y);
    
    printf("\nIntroduceti elementele matricii:\n");
    a = citiremat(a,n);
    
    interschimbare(a,n,x,y);
    printmat(a,n);
    eliberare(a,n);
    return 0;
}
