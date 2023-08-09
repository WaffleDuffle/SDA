/* Să se realizeze un program ce permite citirea de la tastatură a două şiruri de caractere şi afişează pe ecran şirul concatenat. Operaţiile se vor realiza folosind pointeri.

Pentru evaluarea automată a problemei:

INPUT:
două șiruri de caractere, citite de pe rânduri diferite;
OUTPUT:
șirul de caractere obținut prin concatenarea celui de-al doilea șir în continuarea primului șir.*/

#include <stdio.h>
#include <stdlib.h>

char *concat(char *p1,char *p2){
    int nr = 0;
    while(*p1 != '\n'){ //mutam pointerul p1 pana la sfarsitul sirului s1
        *p1++;
        nr++;
    }
    
    while(*p2 != '\0'){ //copiem caracterele lui s2 in continuarea lui s1 prin aritmetica pointerilor
        *p1++ = *p2++;
    }
    *p1 = '\0'; // incheiem sirul s1 prin atribuirea caracaterului NULL la sfarsit
    return p1;
}
int main(){
    int a;
    char s1[20], s2[20];
    
    printf("Introduceti sirurile s1 si s2:\n");
    fgets(s1,20,stdin);
    fgets(s2,20,stdin); 
    
    char *p1, *p2;
    p1 = s1;
    p2 = s2;
    
    concat(p1,p2);
    printf("\nsirul concatenat este:\n%s", s1);
    return 0;
}
