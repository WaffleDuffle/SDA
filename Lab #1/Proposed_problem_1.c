/* Să se realizeze un program ce permite citirea de la tastatură a două şiruri de caractere şi afişează pe ecran şirul concatenat. Operaţiile se vor realiza folosind pointeri.

Pentru evaluarea automată a problemei:

INPUT:
două șiruri de caractere, citite de pe rânduri diferite;
OUTPUT:
șirul de caractere obținut prin concatenarea celui de-al doilea șir în continuarea primului șir.*/


#include <stdio.h>
#include <stdlib.h>

char* concat(char *c1, char *c2){
    while(*c1 != '\0'){
        *c1++;
    }
    
    while(*c2 != '\0'){
        *c1++ = *c2++;
    }
    
    *c1 = '\0';
    
    return c1;
}

int main(){
    
    char* c1 = NULL; 
    char* c2 = NULL;
    int nr = 0;
    char c;
    c1 = malloc(sizeof(char));
    c = getc(stdin);
    *c1 = c;
    while(*(c1+nr) != '\n'){
        nr++;
        c1 = realloc(c1, nr*sizeof(char));
        c = getc(stdin);
        *(c1 + nr) = c;
    }
    *(c1 + nr) = '\0';
    
    int nr2 = 0;
    c2 = malloc(sizeof(char));
    c = getc(stdin);
    *c2 = c;
    while(*(c2+nr2) != '\n'){
        nr2++;
        c2 = realloc(c2, nr2*sizeof(char));
        c = getc(stdin);
        *(c2 + nr2) = c;
    }
    c1 = realloc(c1, (nr + nr2)*sizeof(char));
    concat(c1,c2);
    printf("%s", c1);
    
    return 0;
}
