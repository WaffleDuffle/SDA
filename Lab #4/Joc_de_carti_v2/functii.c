#include "functii.h"
#include <stdio.h>
#include <stdlib.h>

struct jucator* creare_nod(){

    struct jucator* nodNou = NULL;
    nodNou = (struct jucator*)malloc(sizeof(struct jucator));
    if(nodNou == NULL){
        perror("ERROR: Alocarea a esuat!\n");
        return NULL;
    }
    scanf("%s", nodNou->nume);
    nodNou -> next = NULL;
    return nodNou;
}

struct jucator* adaugare_sfarsit_lista(struct jucator* head){
    if(head == NULL){
        head = creare_nod();
        return head;
    }

    struct jucator* tmp = head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct jucator* nodNou = creare_nod();
            tmp -> next = nodNou;
            nodNou -> next = NULL;
            return head;
        }
        tmp = tmp -> next;
    }
}

struct jucator* adaugare_carti(struct jucator* head, const int *x){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return NULL;
    }
    struct jucator* tmp = head;
    int i = 0;
    while(tmp != NULL){
        tmp -> carte = *(x+i++);
        tmp = tmp -> next;
    }
    return head;
}

struct jucator* stergere_jucator(struct jucator* head, int x){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return NULL;
    }
    if(head -> carte == x){
        struct jucator* nodSters = head;
        head = head -> next;
        free(nodSters);
        return head;
    }
    struct jucator* tmp = head;
    while(tmp -> next != NULL){
        if(tmp -> next -> carte == x){
            if(tmp -> next -> next == NULL){
                struct jucator* nodSters = tmp -> next;
                free(nodSters);
                tmp -> next = NULL;
                return head;
            }
            else{
                struct jucator* nodSters = tmp -> next;
                tmp -> next = tmp -> next -> next;
                free(nodSters);
                return head;
            }
        }
        tmp = tmp -> next;
    }
    return head;

}

struct NOD * stergere_lista(struct NOD * head){
    struct NOD * tmp = head;
    while(tmp != NULL) {
        tmp = tmp->next;
        free(head);
        head = tmp;
    }
    printf("Lista a fost stearsa.\n");
    return head;
}

void afisare_lista(struct jucator* head){
    if(head == NULL){
        printf("Lista este goala!\n");
        return;
    }
    struct jucator* tmp = head;
    while(tmp != NULL){
        printf("%s\n", tmp -> nume);
        tmp = tmp -> next;
    }
}

