/*Se dă un vector V, declarat static, de 5 elemente întregi, inițializat cu următoarea instrucțiune: 

int V[5] = {1,2,3,4,5};

Să se realizeze un program care să afișeze în consolă, adresa fiecărui element, folosind aritmetica pointerilor, prin intermediul unui pointer p.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int V[5] = {1,2,3,4,5};
    int *p;
    p = &V[0];
    for(int i = 0 ; i < 5 ; ++i){
        printf("valoarea elementului %d este: %d\n", i, *p);
        printf("adresa elementului %d este: %p\n\n", i, p);
        *p++;
    }
    
    return 0;
}
