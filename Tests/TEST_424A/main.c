#include <stdio.h>
#include "functii.h"

int main() {
    int nr_clienti;
    int nr_case;
    char nume_client[20];
    int nr_produse;
    struct client* lista_clienti = NULL;
    struct casa* lista_case = NULL;
    scanf("%d%d", &nr_case, &nr_clienti);

    for(int i = 0 ; i < nr_case ; ++i){
        lista_case = add_last_case(lista_case, i);
    }
    for(int i = 0 ; i < nr_clienti ; ++i){
        scanf("%s%d", nume_client, &nr_produse);
        lista_clienti = add_last_client(lista_clienti, nume_client, nr_produse);
    }
    int op;
    scanf("%d", &op);

    switch(op){
        case 1:{
            afisare_lista_clienti(lista_clienti);
            break;
        }
        case 2:{
            redistribuire_1(lista_clienti, lista_case);
            afisare_lista_case(lista_case);
            break;
        }
        case 3:{
            redistribuire_2(lista_clienti, lista_case);
            afisare_cazul3(lista_case, nr_clienti);
            break;
        }
        case 4:{
            struct casa* lista_case2 = NULL;
            for(int i = 0 ; i < nr_case ; ++i){
                lista_case2 = add_last_case(lista_case2, i);
            }
            redistribuire_1(lista_clienti, lista_case);
            redistribuire_2(lista_clienti, lista_case2);
            printf("%d", timp_total(lista_case) - timp_total(lista_case2));
            break;
        }
    }
    return 0;
}
