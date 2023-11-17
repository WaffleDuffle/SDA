#include <stdio.h>
#include "functii.h"
#include <stdlib.h>
int main() {
    struct jucator* lista_noua;
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i){
        lista_noua = adaugare_sfarsit_lista(lista_noua);
    }

    do{
       // printf("n = %d\n", n);
        afisare_lista(lista_noua);
        int mini = 15;
        int* x = (int*)malloc(n*sizeof(int));
        if(x == NULL){
            perror("ERROR: Alocarea a esuat!\n");
            return -1;
        }
        for(int i = 0 ; i < n ; ++i){
            scanf("%d", (x+i));
            if(mini > *(x+i))
                mini = *(x+i);
        }

        lista_noua = adaugare_carti(lista_noua, x);
        lista_noua = stergere_jucator(lista_noua, mini);

        free(x);
        n--;
    }while(n > 1);
    afisare_lista(lista_noua);
    lista_noua = stergere_lista(lista_noua);
    return 0;
}
