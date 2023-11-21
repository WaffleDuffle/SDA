#include <stdio.h>
#include "functii.h"

int main() {
    char cuvant[100];
    scanf("%s", cuvant);
    struct cuvant* consoane = NULL;
    struct cuvant* vocale = NULL;
    for(int i = 0 ; cuvant[i] != '\0' ; ++i){
        if(cuvant[i] == 'a' || cuvant[i] == 'A' || cuvant[i] == 'e' || cuvant[i] == 'E' ||
            cuvant[i] == 'i' || cuvant[i] == 'I'  || cuvant[i] == 'o'  || cuvant[i] == 'O' ||
                cuvant[i] == 'u' || cuvant[i] == 'U'){
            vocale = push(vocale, cuvant[i]);
        }
        else{
            consoane = push(consoane, cuvant[i]);
        }
    }
    struct cuvant* rez = merge(vocale, consoane);
    rez = merge(rez, NULL);
    afisare(rez);
    return 0;
}
