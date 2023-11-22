#include <stdio.h>
#include <stdlib.h>
#include "functii.h"
#include <string.h>
struct client* add_last_client(struct client* head, char *nume, int nr_produse){
    if(head == NULL) {
        head = (struct client*)malloc(sizeof(struct client));
        if(head == NULL){
            perror("ERROR: Alocarea a esuat!\n");
            return NULL;
        }
        strcpy(head -> nume, nume);
        head -> nr_produse = nr_produse;
        head -> val = nr_produse;
        head -> next = NULL;
   //     printf("lista de clienti a fost creata\n");
        return head;
    }
    struct client* tmp = head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct client* nodNou = (struct client*)malloc(sizeof(struct client));
            if(nodNou == NULL){
                perror("ERROR: Alocarea a esuat!\n");
                return NULL;
            }
            strcpy(nodNou -> nume, nume);
            nodNou -> nr_produse = nr_produse;
            nodNou -> val = nr_produse;
            nodNou -> next = NULL;
            tmp -> next = nodNou;
        //    printf("nodul de clienti a fost adaugat la sfarsit\n");
            return head;
        }
        tmp = tmp -> next;
    }
}

struct casa* add_last_case(struct casa* head, int poz){
    if(head == NULL){
        head = (struct casa*)malloc(sizeof(struct casa));
        if(head == NULL){
            perror("ERROR: Alocarea a esuat!\n");
            return NULL;
        }
        head -> poz = poz;
        head -> nr_total = 0;
        head -> clienti = NULL;
        head -> next = NULL;
     //   printf("lista de case a fost creata\n");
        return head;
    }
    struct casa* tmp = head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct casa* nodNou = (struct casa*)malloc(sizeof(struct casa));
            if(nodNou == NULL){
                perror("ERROR: Alocarea a esuat!\n");
                return NULL;
            }
            nodNou -> poz = poz;
            nodNou -> nr_total = 0;
            nodNou -> clienti = NULL;
            nodNou -> next = NULL;
            tmp -> next = nodNou;
          //  printf("nodul de case a fost adaugat la sfarsit\n");
            return head;
        }
        tmp = tmp -> next;
    }
}

void afisare_lista_clienti(struct client* head){
    if(head == NULL){
        printf("Lista este goala!\n");
        return;
    }
    struct client* tmp = head;
    while(tmp != NULL){
        printf("%s %d\n", tmp -> nume, tmp -> nr_produse);
        tmp = tmp -> next;
    }
}

void afisare_lista_case(struct casa* head){
    if(head == NULL){
        printf("Lista este goala!\n");
        return;
    }
    struct casa* tmp = head;
    while(tmp != NULL){
       // printf("Casa numarul %d:\n\n", tmp -> poz);
        afisare_lista_clienti(tmp -> clienti);
        tmp = tmp -> next;
    }
}

int search_min_casa(struct casa* head){
    if(head == NULL){
        perror("Lista este goala!\n");
        return -2;
    }
    int mini = 99999;
    int poz = 0;
    int x = -1;
    struct casa* tmp = head;
    while(tmp != NULL){
        if(mini > tmp -> nr_total)
            mini = tmp -> nr_total, x = poz;
        tmp = tmp -> next;
        poz++;
    }
    return x;
}

void redistribuire_1(struct client* head1, struct casa* head2){
    struct casa* tmp2 = head2;
    struct client* tmp1 = head1;
    while(tmp1 != NULL){
        int x = search_min_casa(head2);
       // printf("x = %d\n", x);
        while(tmp2 != NULL){
            if(x == tmp2 -> poz){
                tmp2 -> clienti = add_last_client(tmp2 -> clienti, tmp1 -> nume, tmp1 -> nr_produse);
                tmp2 -> nr_total += tmp1 -> nr_produse;
                break;
            }
            tmp2 = tmp2 -> next;
        }
        tmp2 = head2;
        tmp1 = tmp1 -> next;

    }
}

void redistribuire_2(struct client* head1, struct casa* head2){
    struct casa* tmp2 = head2;
    struct client* tmp1 = head1;
    while(tmp1 != NULL){
        tmp2 -> clienti = add_last_client(tmp2 -> clienti, tmp1 -> nume, tmp1 -> nr_produse);
        tmp2 -> nr_total += tmp1 -> nr_produse;
        tmp2 = tmp2 -> next;
        if(tmp2 == NULL)
            tmp2 = head2;
        tmp1 = tmp1 -> next;
    }
}

struct client* stergere_lista(struct client* head){
    while(head != NULL){
        struct client* nodSters = head;
        head = head -> next;
        free(nodSters);
    }
    return NULL;
}

void afisare_cazul3(struct casa* head, int nr_clienti){
    struct casa* tmp = head;
    int nr = 0;
    while(nr != nr_clienti){
        if(tmp == NULL)
            tmp = head;
        if(tmp -> clienti != NULL){
            tmp -> clienti -> val--;

            if(tmp -> clienti -> val == 0){
                printf("%s %d\n", tmp -> clienti -> nume, tmp -> clienti -> nr_produse);
                tmp -> clienti = tmp -> clienti -> next;
                nr++;
            }
        }

        tmp = tmp -> next;
    }
}

int timp_total(struct casa* head){
    int maxi = -1;
    struct casa* tmp = head;
    while(tmp != NULL){
        if(maxi < tmp -> nr_total)
            maxi = tmp -> nr_total;
        tmp = tmp -> next;
    }
    return maxi;
}