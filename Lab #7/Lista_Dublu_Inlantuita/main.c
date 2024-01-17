#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char cuvant[30];
    struct node* next;
    struct node* prev;
};

struct node* create_node(char* cuvant){
    struct node* newnode = malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Alocarea a esuat");
        return NULL;
    }
    strcpy(newnode->cuvant, cuvant);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}

struct node* add_first(struct node* head, char* cuvant){
    if(head == NULL){
        head = create_node(cuvant);
        return head;
    }
    struct node* newnode = create_node(cuvant);
    newnode -> next = head;
    head -> prev = newnode;
    return newnode;
}

struct node* add_last(struct node* head, char* cuvant){
    if(head == NULL){
        head = create_node(cuvant);
        return head;
    }
    struct node* curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    struct node* newnode = create_node(cuvant);
    curr -> next = newnode;
    newnode -> prev = curr;
    return head;
}

struct node* add_o(struct node* head, char* cuvant, int n) {
    if (head == NULL) {
        head = create_node(cuvant);
        return head;
    }
    struct node* curr = head;
    int i = 0;
    while (curr -> next != NULL) {
        if (i == n - 1) {
            struct node* newnode = create_node(cuvant);
            newnode -> next = curr -> next;
            newnode -> prev = curr;
            if (curr -> next != NULL) {
                curr -> next -> prev = newnode;
            }
            curr -> next = newnode;
            return head;
        }
        curr = curr -> next;
        i++;
    }
    // If n is greater than the length of the list, you can add to the end
    struct node* newnode = create_node(cuvant);
    curr -> next = newnode;
    newnode -> prev = curr;
    return head;
}

void afisare(struct node* head){
    struct node* curr = head;
    while(curr != NULL){
        printf("%s ", curr -> cuvant);
        curr = curr -> next;
    }
}

struct node* del_first(struct node* head){
    struct ndoe* del_node = head;
    head = head -> next;
    free(del_node);
    head -> prev = NULL;
    return head;
}

struct node* del_last(struct node* head){
    struct node* curr = head;
    if(head -> next == NULL){
        free(head);
        return NULL;
    }
    while(curr -> next -> next != NULL)
        curr = curr -> next;
    struct node* del_node = curr -> next;
    free(del_node);
    curr -> next = NULL;
    return head;
}

struct node* del_o(struct node* head, int n){
    if(head -> next == NULL){
        free(head);
        return NULL;
    }

    if(n == 0){
        head = del_first(head);
    }
    struct node* curr = head;
    int i = 0;
    while(curr -> next -> next != NULL){
        if(i == n - 1){
            struct node* del_node = curr -> next;
            curr -> next = del_node -> next;
            del_node -> next -> prev = curr;
            free(del_node);
            return head;
        }
        i++;
        curr = curr -> next;
    }
    head = del_last(head);
    return head;
}

struct node* delete(struct node* head){
    while(head != NULL){
        struct node* del_node = head;
        head = head -> next;
        free(del_node);
    }
    printf("Lista golita");
    return head;
}

void afisare_invers(struct node* head){
    struct node* curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    do{
        printf("%s ", curr -> cuvant);
        curr = curr -> prev;
    }while(curr != NULL);
}



int main() {
    char cuvant[20];
    struct node* lista = NULL;
    FILE *in = fopen("input.txt", "rt");
    if (in == NULL) {
        fprintf(stderr, "ERROR: Can't open file %s", "input.txt");
        return -1;
    }
    while(fscanf(in, "%s", cuvant) != EOF){
        lista = add_last(lista, cuvant);
    }
    lista = delete(lista);
    afisare(lista);
    return 0;
}
