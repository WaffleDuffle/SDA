#include "functii.h"
#include <stdlib.h>
#include <stdio.h>


void my_strcpy(char* x, char *y){

    char* x1 = x;
    char* y1 = y;

    while(*y1 != '\0'){
        *x1++ = *y1++;
    }
    *x1 = '\0';

}

int my_strcmp(char* x, char* y){
    char* x1 = x;
    char* y1 = y;
    while(*x1 != '\0'){
        if(*x1 != *y1)
            return 1;
        x1++;
        y1++;
    }
    if(*y1 != '\0')
        return 1;
    return 0;
}
struct calendar* creare_nod(){
    struct calendar* nod;
    nod = (struct calendar*)malloc(sizeof(struct calendar));
    if(nod == NULL) {
        perror("ERROR: Alocarea a esuat!\n");
        return NULL;
    }
    scanf("%s%d", nod->nume, &nod->data);
    nod->next = NULL;
    return nod;
}

struct calendar* adaugare_sfarsit(struct calendar* head){
    if(head == NULL){
        head = creare_nod();
        return head;
    }
    struct calendar* nod_curent = head;
    struct calendar* tmp;
    while(nod_curent != NULL){
        if(nod_curent -> next == NULL){
            tmp = creare_nod();
            nod_curent -> next = tmp;
            return head;
        }
        nod_curent = nod_curent -> next;
    }
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

void afisare_elemente(struct calendar* head){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return;
    }
    struct calendar* tmp = head;
    while(tmp != NULL){
        printf("%s %d\n", tmp->nume, tmp->data);
        tmp = tmp -> next;
    }
}

void afisare_dupa_nume(struct calendar* head, char *x){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return;
    }
    struct calendar* tmp = head;
    while(tmp != NULL){
        if(!my_strcmp(tmp->nume, x)){
            printf("%d\n", tmp->data);
        }
        tmp = tmp -> next;
    }
}

void afisare_dupa_data(struct calendar* head, int x){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return;
    }
    struct calendar* tmp = head;
    while(tmp != NULL){
        if(x == tmp->data){
            printf("%s\n", tmp->nume);
        }
        tmp = tmp -> next;
    }
}

int dimensiune_lista(struct calendar* head){
    int nr = 0;
    struct calendar* tmp = head;
    while(tmp != NULL){
        nr++;
        tmp = tmp -> next;
    }
    return nr;
}


void sort_cronologic(struct calendar* head){
    struct calendar* curr_x = head, *index = NULL;
    int tmp_data;
    char tmp_nume[20];
    while(curr_x != NULL){
        index = curr_x -> next;
        while(index != NULL){
            if(curr_x -> data > index -> data){
                tmp_data = index -> data;
                index -> data = curr_x -> data;
                curr_x -> data = tmp_data;
                my_strcmp(tmp_nume, index -> nume);
                my_strcmp(index -> nume, curr_x -> nume);
                my_strcmp(curr_x -> nume, tmp_nume);
            }
            index = index -> next;
        }
        curr_x = curr_x -> next;
    }
}

