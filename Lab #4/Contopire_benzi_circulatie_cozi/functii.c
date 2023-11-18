#include "functii.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_empty(struct masina* head){
    if(head == NULL)
        return 1;
    return 0;
}

int size(struct masina* head){
    struct masina* tmp = head;
    int nr = 0;
    while(tmp != NULL){
        nr++;
        tmp = tmp -> next;
    }
    return nr;
}

struct masina* creeare_nod(char* x){
    struct masina* nodNou = (struct masina*)malloc(sizeof(struct masina));
    if(nodNou == NULL){
        perror("ERROR: Alocarea a esuat!\n");
        return NULL;
    }
    strcpy(nodNou -> nr_inmatriculare, x);
    nodNou -> next = NULL;
    return nodNou;

}
void enqueue(struct masina** head, char* x){
    if(is_empty(*head)){
        *head = creeare_nod(x);
   //     printf("Masina a fost adaugata.\n");
        return;
    }
    struct masina* tmp = *head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct masina* nodNou = creeare_nod(x);
            tmp -> next = nodNou;
    //        printf("Masina a fost adaugata.\n");
            return;
        }
        tmp = tmp -> next;
    }


}

void dequeue(struct masina** head){
    if(is_empty(*head)){
        perror("ERROR: Lista este goala!\n");
        return;
    }
    if((*head) -> next == NULL){
        free(*head);
        *head = NULL;
        printf("Lista a fost stearsa.\n");
        return;
    }
    else {

        struct masina* nodSters = *head;
        *head = (*head) -> next;
        free(nodSters);
        return;
    }
}

void afisare(struct masina** head){
    if(*head == NULL){
        perror("ERROR: Lista este goala!\n");
        return;
    }
    struct masina* tmp = *head;
    while(tmp != NULL){
        printf("%s\n", tmp -> nr_inmatriculare);
        tmp = tmp -> next;
    }

}

struct masina* interclasare(struct masina* head1, struct masina* head2){
    struct masina* tmp1 = head1;
    struct masina* tmp2 = head2;
    struct masina* rez = NULL;
    while(tmp1 != NULL && tmp2 != NULL){
        printf("1");
        enqueue(&rez, tmp2 -> nr_inmatriculare);
        dequeue(&tmp2);
        enqueue(&rez, tmp1 -> nr_inmatriculare);
        dequeue(&tmp1);
  
    }
    while(tmp1 != NULL){
        printf("2");
        enqueue(&rez, tmp1 -> nr_inmatriculare);
        dequeue(&tmp1);
    
    }

    while(tmp2 != NULL){
        printf("3");
        enqueue(&rez, tmp2 -> nr_inmatriculare);
        dequeue(&tmp2);
   
    }
    return rez;
}
