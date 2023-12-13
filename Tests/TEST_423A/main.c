#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    char nume[20];
    struct lista* next;
};

struct lista* creare_nod(char* nume){
    struct lista* nodNou = malloc(sizeof(struct lista));
    strcpy(nodNou -> nume, nume);
    nodNou -> next = NULL;
    return nodNou;
}

struct lista* add_last(struct lista* head, char* nume){
    if(head == NULL){
        head = creare_nod(nume);
        return head;
    }
    struct lista* tmp = head;
    while(tmp -> next != NULL)
        tmp = tmp -> next;

    struct lista* nodNou = creare_nod(nume);
    tmp -> next = nodNou;
    return head;
}

struct lista* add_first(struct lista* head, char* nume){
    if(head == NULL){
        head = creare_nod(nume);
        return head;
    }
    struct lista* nodNou = creare_nod(nume);
    nodNou -> next = head;
    return nodNou;
}

void afisare_lista(struct lista* head){
    struct lista* tmp = head;
    if(head == NULL){
        printf("Lista este goala!\n");
    }
    while(tmp != NULL){
        printf("%s\n", tmp -> nume);
        tmp = tmp -> next;
    }
}

struct lista* stergere_inceput(struct lista* head){

    if(head -> next == NULL){
        free(head);
        return NULL;
    }
    struct lista* nodSters = head;
    head = head -> next;
    free(nodSters);
    return head;
}

struct lista* stergere_lista(struct lista* head){
    struct lista* nodSters = NULL;
    while(head != NULL){
        nodSters = head;
        head = head -> next;
        free(nodSters);
    }
    printf("Lista a fost sterasa!\n");
    return head;

}

struct lista* inversare(struct lista* head, struct lista *head2, int n, int caz){
    struct lista* tmp = head;
    int nr = 0;
    struct lista* stiva = NULL;
    for(int i = 1 ; i <= n ; ++i){
        stiva = add_first(stiva, tmp -> nume);
        if(i % caz == 0){
            for(int j = 1 ; j <= caz ; ++j){
                head2 = add_last(head2, stiva -> nume);
                stiva = stergere_inceput(stiva);
                nr++;
            }
        }
        tmp = tmp -> next;
    }
    printf("n = %d nr = %d\n", n, nr);

    if(n != nr){
        struct lista* tmp2 = head;
        for(int i = 1 ; i <= nr ; ++i)
            tmp2 = tmp2 -> next;
        while(tmp2 != NULL){
            head2 = add_last(head2, tmp2 -> nume);
            tmp2 = tmp2 -> next;
        }
    }
    return head2;
}

struct lista* stergere_div7(struct lista* head){
    struct lista* tmp = head;
    int i = 1;
    while(tmp != NULL){
        if((i+1)%7 == 0){
            struct lista* nodSters = tmp -> next;
            tmp -> next = nodSters -> next;
            free(nodSters);
        }
        tmp = tmp -> next;
        i++;
    }
    return head;
}
int main() {
    int n;
    char nume[20];
    struct lista* istoric = NULL;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%s", nume);
        istoric = add_last(istoric, nume);
    }
    int op;
    scanf("%d", &op);
    switch(op){
        case 1: {
            afisare_lista(istoric);
            break;
        }
        case 2: {
            struct lista* lista2 = NULL;
            lista2 = inversare(istoric, lista2, n, 3);
            afisare_lista(lista2);
            break;
        }
        case 3: {
            struct lista* lista2 = NULL;
            int caz;
            scanf("%d", &caz);
            lista2 = inversare(istoric, lista2, n, caz);
            afisare_lista(lista2);
            break;
        }
        case 4: {
            struct lista* lista2 = NULL;
            lista2 = inversare(istoric, lista2, n, 3);
            lista2 = stergere_div7(lista2);
            afisare_lista(lista2);
            break;
        }
    }
    return 0;
}
