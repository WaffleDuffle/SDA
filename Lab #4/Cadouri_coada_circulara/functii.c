#include <stdio.h>
#include <stdlib.h>
#include "functii.h"
#include <string.h>

char** citire_jucarii(char** x, int n){
    x = (char**)malloc(n*sizeof(char*));
    if(x == NULL){
        perror("ERROR: Alocarea a esuat!\n");
        return NULL;
    }
    for(int i = 0 ; i < n ; ++i){
        x[i] = (char*)calloc(30, sizeof(char));
        scanf("%s", x[i]);
    }
    return x;
}
struct copii* creare_nod(char* nume){
    struct copii* nod = malloc(sizeof(struct copii));
    if(nod == NULL){
        perror("Alocarea a esuat!\n");
        return NULL;
    }
    strcpy(nod -> nume, nume);
    nod -> next = NULL;
    return nod;
}
struct copii* add_last(struct copii* head, char* nume){

    if(head == NULL){
        head = creare_nod(nume);
        head -> next = head;
        return head;
    }

    struct copii* tmp = head;

    if(tmp -> next == head){
        struct copii* nodNou = creare_nod(nume);
        tmp -> next = nodNou;
        nodNou -> next = head;
        return head;
    }
    tmp = tmp -> next;
    while(tmp != head){
        if(tmp -> next == head){
            struct copii* nodNou = creare_nod(nume);
            tmp -> next = nodNou;
            nodNou -> next = head;
            return head;
        }
        tmp = tmp -> next;
    }
}

struct cadouri* creare_nod_cadou(char* nume){
    struct cadouri* nod = malloc(sizeof(struct cadouri));
    if(nod == NULL){
        perror("Alocarea a esuat!\n");
        return NULL;
    }
    strcpy(nod -> cadou, nume);
    nod -> next = NULL;
    return nod;
}

struct cadorui* add_last_cadou(struct cadouri* head, char* nume){
    if(head == NULL){
        head = creare_nod_cadou(nume);
        return (struct cadorui *) head;
    }
    struct cadouri* tmp = head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct cadouri* nodNou = creare_nod_cadou(nume);
            tmp -> next = (struct cadorui *) nodNou;
            return (struct cadorui *) head;
        }
        tmp = (struct cadouri *) tmp->next;
    }
}



void afisare_cadouri(struct cadouri* head){
    if(head == NULL){
        printf("Lista este goala.\n");
        return;
    }
    struct cadouri* tmp = head;
    while(tmp != NULL){
        printf("%s ", tmp -> cadou);
        tmp = (struct cadouri *) tmp->next;
    }
}

void afisare_copii(struct copii* head){
    if(head == NULL){
        perror("ERROR: Lista este goala!\n");
        return;
    }

    struct copii* tmp = head;
    do{
        printf("%s: ", tmp -> nume);
        afisare_cadouri(tmp -> cadouri);
        printf("\n");
        tmp = tmp -> next;
    }while(tmp != head);

}

void gestiune_cadouri(struct copii* head, char** x, int n){
    struct copii* tmp = head;
    do{
        tmp -> cadouri = NULL;
        tmp = tmp -> next;
    }while(tmp != head);
    for(int i = 0 ; i < n ; ++i){
        tmp -> cadouri = (struct cadouri *) add_last_cadou(tmp->cadouri, x[i]);
        tmp = tmp -> next;
    }
}

