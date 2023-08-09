/* Se dă matricea M de 6 elemente întregi, inițializată cu următoarea instrucțiune: 

int M[2][3] = {{ 1, 2, 3 }, { 4, 5, 6 }};

Să se realizeze un program care copiază elementele matricei M într-o nouă matrice, N , alocată dinamic.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int M[2][3] = {{1,2,3},{4,5,6}};
    
    int **N;
    N = malloc(2*sizeof(int*));
    for(int i = 0 ; i < 2 ; ++i)
        N[i] = calloc(3, sizeof(int));
    for(int i = 0 ; i < 2 ; ++i, printf("\n"))
        for(int j = 0 ; j < 3 ; ++j)
            N[i][j] = M[i][j], printf("%d ", N[i][j]);
            
    return 0;
}
