/*Realizați un program care să permită alocarea dinamică de memorie pentru un șir S de n caractere, și eliberarea memoriei alocate anterior. Se va afișa adresa de început a șirului atât înainte, cât și după eliberarea memoriei.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char *S;
    int n;
    scanf("%d", &n);
    S = malloc(n*sizeof(char));
    printf("\n%p\n", S);
    free(S);
    S = NULL;
    printf("%p", S);
    return 0;
}
