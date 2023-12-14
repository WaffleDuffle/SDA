#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char vers[100];
    struct node* next;
    int nr;
};

struct node* creeare_nod(char *nume){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode -> vers, nume);
    newnode -> next = NULL;
    newnode -> nr = 0;
    return newnode;
}

struct node* add_node(struct node* head, char* nume){
    if(head == NULL){
        head = creeare_nod(nume);
    }
    else{
        struct node* tmp = head;
        while(tmp -> next != NULL)
            tmp = tmp -> next;
        struct node* newnode = creeare_nod(nume);
        tmp -> next = newnode;
    }
    return head;
}

void afisare(struct node* head){
    int nr = 1;
    if(head == NULL)
        printf("Lista este goala!\n");
    struct node* tmp = head;
    while(tmp != NULL){
        printf("%s\n", tmp -> vers);
        if(nr == 4){
            printf("\n");
            nr = 0;
        }
        nr++;
        tmp = tmp -> next;
    }
}

struct node* extrage_silabe(struct node* silabe, struct node* head){
    struct node* tmp = head;
    for(int i = 0 ; i < 4 ; ++i){
        silabe = add_node(silabe, (tmp -> vers) + strlen(tmp -> vers) - 2);
        tmp = tmp -> next;
    }
    return silabe;
}

void afisare_silabe(struct node* head){
    struct node* tmp = head;
    while(tmp -> next != NULL){
        printf("%s-", tmp -> vers);
        tmp = tmp -> next;
    }
    printf("%s\n", tmp -> vers);
}
void verificare_silabe(struct node* silabe){
    if(strcmp(silabe -> vers, silabe -> next -> next -> next -> vers) == 0
        && strcmp(silabe -> next -> vers, silabe -> next -> next -> vers)  == 0)
            afisare_silabe(silabe);
    else
        printf("nu\n");
}

struct node* inversare(struct node* head){
    struct node* next = NULL;
    struct node* prev = NULL;
    struct node* curr = head;
    while(curr != NULL){
        next = curr -> next -> next -> next -> next;
        curr -> next -> next -> next -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void silaba_predominanta(struct node* head){
    struct node* tmp = head;
    struct node* silabe = NULL;
    while(tmp != NULL){
        int ok = 0;
        struct node* tmp2 = silabe;
        while(tmp2 != NULL){
            if(strcmp(tmp2 -> vers, (tmp -> vers) + strlen(tmp -> vers) - 2) == 0){
                tmp2 -> nr++;
                ok = 1;
            }
            tmp2 = tmp2 -> next;
        }
        if(ok == 0) {
            silabe = add_node(silabe, (tmp->vers) + strlen(tmp->vers) - 2);
            silabe->nr++;
        }
        tmp = tmp -> next;
    }
    struct node* tmp2 = silabe;
    int maxi = -1;
    while(tmp2 != NULL){
        if(maxi < tmp2 -> nr)
            maxi = tmp2 -> nr;
        tmp2 = tmp2 -> next;
    }
    tmp2 = silabe;
    while(tmp2 != NULL){
        if(maxi == tmp2 -> nr){
            printf("%s\n", tmp2 -> vers);
            return;
        }
    }
}
int main() {
    struct node* poezie = NULL;
    int nr;
    char vers[100];
    scanf("%d", &nr);
    fgets(vers, 100, stdin);
    for(int i = 0 ; i < nr ; ++i){
        for(int j = 0 ; j < 4 ; ++j) {
            fgets(vers, 100, stdin);
            vers[strlen(vers) - 1] = '\0';
            poezie = add_node(poezie, vers);
        }
    }
    int op;

    scanf("%d", &op);

    switch(op){
        case 1:{
            afisare(poezie);
            break;
        }
        case 2:{
            struct node* silabe = NULL;
            silabe = extrage_silabe(silabe, poezie);
            verificare_silabe(silabe);
            break;
        }
        case 3:{
            poezie = inversare(poezie);
            afisare(poezie);
            break;
        }
        case 4:{
            silaba_predominanta(poezie);
            break;
        }
    }

    return 0;
}
