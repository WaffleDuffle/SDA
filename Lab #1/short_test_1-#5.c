/*Realizați un program care să permită alocarea dinamică de memorie pentru un șir S de n caractere, și realocarea șirului S, cu o nouă dimensiune de n+m. Valorile n și m se vor citi de la tastatură.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char *S;
    int m, n;
    scanf("%d", &n);
    
    S = (char*)malloc(n+1);
    scanf("%d", &m);
    S = (char*)realloc(S, (n+m+1));
    
    return 0;
    free(S);
}
