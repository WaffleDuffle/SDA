#include <stdio.h>
#include <string.h>
#include "functii.h"
int main() {
    struct copii* lista_circulara;
    char **jucarii;
    char name[30];
    int n;
    scanf("%d", &n);
    jucarii = citire_jucarii(jucarii, n);

    for(int i = 0 ; i < 3 ; ++i){
        scanf("%s", name);
        lista_circulara = add_last(lista_circulara, name);
    }
    gestiune_cadouri(lista_circulara, jucarii, n);
    afisare_copii(lista_circulara);
    return 0;
}
