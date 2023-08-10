/*Având la dispoziție două valori reale, a și b, și doi pointeri p și q, cu tipul de bază real, să se interschimbe valorile variabilelor a și b, prin intermediul pointerilor p și q, și să se afișeze în consolă valorile acestora.*/

#include <stdio.h>

int main(){
    float a, b;
    float *p, *q;
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    p = &a;
    q = &b;
    
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
    
    printf("Dupa interschimbare:\na = %f\nb = %f", a, b);
    return 0;
}
