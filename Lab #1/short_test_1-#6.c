/* Realizați un program care să permită citirea de la tastatură a unei variabile var de tip real, schimbarea valorii acesteia prin intermediul unui pointer p, și afișarea noii valori a variabilei var în consolă.*/

#include <stdio.h>

int main(){
    float var, *p;
    printf("Introduceti valoarea: ");
    
    scanf("%f", &var);
    
    p = &var;
    *p = *p + 3.141592;
    printf("%f", var);
}
