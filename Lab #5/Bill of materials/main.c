#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stock{
    char nume[20];
    struct stock* next;
};

struct stock* create_node(char *nume){
    struct stock* newnode = (struct stock*)malloc(sizeof(struct stock));
    if(newnode == NULL){
        perror("ERROR: Alocarea a esuat!\n");
        return NULL;
    }
    strcpy(newnode -> nume, nume);
    newnode -> next = NULL;
    return newnode;
}

struct stock* add_last(struct stock* head, char *nume){
    if(head == NULL){
        head = create_node(nume);
        return head;
    }
    else{
        struct stock* curr = head;
        while(curr -> next != NULL)
            curr = curr -> next;
        struct stock* newnode = create_node(nume);
        curr -> next = newnode;
        return head;
    }
}

void afisare(struct stock* head){
    struct stock* curr = head;
    while(curr != NULL){
        printf("%s ", curr -> nume);
        curr = curr -> next;
    }

}

void stergere_lista(struct stock* head){
    while(head != NULL){
        struct stock* del = head;
        head = head -> next;
        free(del);
    }
}

int contains(struct stock* head, char* nume){
    struct stock* curr = head;
    while(curr != NULL){
        if(strcmp(curr -> nume, nume) == 0)
            return 1;
        curr = curr -> next;
    }
    return 0;
}

int check_stock(struct stock* head1, struct stock* head2){
    int nr = 0;
    struct stock* tmp1 = head1;

    while(tmp1 != NULL){
        if(contains(head2, tmp1 -> nume) == 1)
            nr++;
        printf("a");
        tmp1 = tmp1 -> next;
    }
    printf("b");
    return nr;
}
int main() {
    struct stock* lista = NULL;
    int n;
    scanf("%d", &n);
    char nume[20];
    for(int i = 0 ; i < n ; ++i){
        scanf("%s", nume);
        lista = add_last(lista, nume);
    }

    struct stock* stock = NULL;
    while(scanf("%s", nume) != EOF){
        stock = add_last(stock, nume);
    }
    printf("%d", check_stock(lista, stock));
    stergere_lista(stock);
    stergere_lista(lista);
    return 0;
}
