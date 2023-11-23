#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fabrica{
    unsigned nr;
    struct fabrica* next;
};


struct fabrica* enqueue(struct fabrica* head, unsigned x){
    if(head == NULL){
        head = malloc(sizeof(struct fabrica));
        head -> nr = x;
        head -> next = NULL;
        return head;
    }
    struct fabrica* tmp = head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct fabrica* nodNou = malloc(sizeof(struct fabrica));
            nodNou -> nr = x;
            tmp -> next = nodNou;
            nodNou -> next = NULL;
            return head;
        }
        tmp = tmp -> next;
    }
}

struct fabrica* dequeue(struct fabrica* head){
    if(head == NULL){
        return NULL;
    }
    struct fabrica* nodSters = head;
    head = head -> next;
    free(nodSters);
    return head;
}

void afisare(struct fabrica* head){
    if(head == NULL){
        printf("\n");
        return;
    }
    struct fabrica* tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp -> nr);
        tmp = tmp -> next;
    }
    printf("\n");
}

int main() {
    struct fabrica* receptie = NULL;
    struct fabrica* productie = NULL;
    struct fabrica* livrare = NULL;
    struct fabrica* camioane = NULL;
    unsigned n, d;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d", &d);
        camioane = enqueue(camioane, d);
    }
    char c;
    while(scanf("%c", &c) != EOF){
        if(c == 'r'){
            receptie = enqueue(receptie, camioane -> nr);
            camioane = dequeue(camioane);
        }
        else if(c == 'p'){
            productie = enqueue(productie, receptie -> nr);
            receptie = dequeue(receptie);
        }
        else if(c == 'l'){
            livrare = enqueue(livrare, productie -> nr);
            productie = dequeue(productie);
        }
    }
    afisare(camioane);
    afisare(receptie);
    afisare(productie);
    afisare(livrare);
    return 0;
}
