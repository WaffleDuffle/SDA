/*
Să se realizeze un program ce permite citirea de la tastatură a două numere întregi şi calculează suma, diferenţa şi media aritmetică a lor. Operațiile se vor realiza indirect, prin intermediul unor variabile pointer. Să se afişeze pe ecran valorile, adresele de memorie și valorile indicate de pointeri cât şi valorile şi adresele de memorie pentru rezultate.

Pentru evaluarea automată a problemei:

INPUT:
doi întregi;
OUTPUT (fiecare valoare pe un rând nou):
valoarea primului număr;
valoarea celui de-al doilea număr;
valoarea sumei;
valoarea diferenței;
valoarea mediei, cu 2 zecimale.
  */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1, n2;
    printf("Introduceti valorile lui n1 si n2:\n");
    scanf("%d%d",&n1,&n2);
    
    int *p1, *p2;
    p1 = &n1;
    p2 = &n2;
    
    int suma = *p1 + *p2;
    int dif = *p1 - *p2;
    float medie = (*p1 + *p2)/2;
   
    printf("Valorile rezultatelor:\nn1 = %d\nn2 = %d\nsuma = %d\ndiferenta = %d\nmedia aritmetica = %.2f\n\n", *p1, *p2, suma, dif, medie);
    
    printf("Valorile pointerilor:\nn1 = %p\nn2 = %p\n\n", p1, p2);
    
    printf("Adresele rezultatelor:\nn1 = %p\nn2 = %p\nsuma = %p\ndiferenta = %p\nmedia aritmetica = %p\n\n", &p1, &p2, &suma, &dif, &medie);

    return 0;
}
