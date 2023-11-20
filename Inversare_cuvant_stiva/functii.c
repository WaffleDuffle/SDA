#include "functii.h"
#include <stdio.h>
#include <stdlib.h>

struct cuvant* creare_nod(char x){
    struct cuvant* nodNou = (struct cuvant*)malloc(sizeof(struct cuvant));
    if(nodNou == NULL){
        perror("ERROR: Alocarea a esuat!\n");
        return NULL;
    }
    nodNou -> x = x;
    nodNou -> next = NULL;
    return nodNou;
}
struct cuvant* push(struct cuvant* head, char x){
    if((head) == NULL){
        head = creare_nod(x);
        return head;
    }
    struct cuvant* nodNou = creare_nod(x);
    nodNou -> next = head;
    return nodNou;
}

struct cuvant* pop(struct cuvant* head){
    if(head == NULL){
        perror("ERROR: Stiva este goala!\n");
        return NULL;
    }
    struct cuvant* nodSters = head;
    head = head -> next;
    free(nodSters);
    return head;
}

void afisare(struct cuvant* head){
    struct cuvant* tmp = head;
    while(tmp != NULL){
        printf("%c", tmp -> x);
        tmp = tmp -> next;
    }
}

struct cuvant* merge(struct cuvant* head1, struct cuvant* head2){
    struct cuvant* tmp1 = head1;
    struct cuvant* tmp2 = head2;
    struct cuvant* rez = NULL;
    while(tmp1 != NULL && tmp2 != NULL){
        rez = push(rez, tmp1 -> x);
        tmp1 = pop(tmp1);
        rez = push(rez, tmp2 -> x);
        tmp2 = pop(tmp2);
    }

    while(tmp1 != NULL){
        rez = push(rez, tmp1 -> x);
        tmp1 = pop(tmp1);
    }

    while(tmp2 != NULL){
        rez = push(rez, tmp2 -> x);
        tmp2 = pop(tmp2);
    }
    return rez;
}