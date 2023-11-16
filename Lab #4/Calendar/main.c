#include <stdio.h>
#include "functii.h"

int main(){
    int op;
    struct calendar* lista_noua;
    do{
        scanf("%d", &op);
        switch(op){
            case 1: {
                lista_noua = adaugare_sfarsit(lista_noua);
                break;
            }
            case 2: {
                char x[20];
                scanf("%s", x);
                afisare_dupa_nume(lista_noua, x);
                break;
            }
            case 3: {
                int x;
                scanf("%d", &x);
                afisare_dupa_data(lista_noua, x);
                break;
            }
            case 4: {
                afisare_elemente(lista_noua);
                break;
            }
            case 5: {
                sort_cronologic(lista_noua);
                afisare_elemente(lista_noua);
                break;
            }
            case 6: {
                return 0;
            }


        }


    }while(1);

    return 0;
}