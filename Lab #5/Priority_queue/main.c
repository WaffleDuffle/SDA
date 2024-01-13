#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char nume[20];
    char prenume[20];
    int priority;
    char sex;
    int varsta;
    struct node* next;
};

struct node* create_node(char* nume, char* prenume, int p, char sex, int varsta){
    struct node* newnode = malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Alocarea a esuat");
        return NULL;
    }
    strcpy(newnode -> nume, nume);
    strcpy(newnode -> prenume, prenume);
    newnode -> priority = p;
    newnode -> sex = sex;
    newnode -> varsta = varsta;
    newnode -> next = NULL;
    return newnode;
}

void enqueue(struct node** head, char* nume, char* prenume, int p, char sex, int varsta) {
    if (*head == NULL) {
        *head = create_node(nume, prenume, p, sex, varsta);
        return;
    } else {
        struct node* curr = *head;
        if (p < curr->priority) {
            struct node* newnode = create_node(nume, prenume, p, sex, varsta);
            newnode->next = *head;
            *head = newnode;
        }
        else {
            struct node* newnode = create_node(nume, prenume, p, sex, varsta);
            while (curr->next != NULL && curr->next->priority < p) {
                curr = curr->next;
            }
            newnode->next = curr->next;
            curr->next = newnode;
        }
    }
}

struct node* add_last(struct node* head, char* nume, char* prenume, int p, char sex, int varsta){
    if(head == NULL){
        head = create_node(nume, prenume, p, sex, varsta);
        return head;
    }
    struct node* curr = head;
    while(curr -> next != NULL)
        curr = curr -> next;
    struct node* newnode = create_node(nume, prenume, p, sex, varsta);
    curr -> next = newnode;
    return head;
}

void afisare(struct node* head){
    while(head != NULL){
        printf("%s %s %d %c\n", head -> nume, head -> prenume, head -> varsta, head -> sex);
        head = head -> next;
    }
}

void dequeue(struct node** head){

    if(*head == NULL){
        printf("Coada este goala");
        return;
    }
    struct node* del_node = *head;
    *head = (*head) -> next;
    free(del_node);
    del_node = NULL;
}

int main() {
    char nume[20];
    char prenume[20];
    int priority;
    int varsta;
    char sex;
    char op;
    struct node* queue = NULL;
    struct node* result = NULL;
    while(1){
        scanf("%c", &op);
        if(op == '*'){
            break;
        }
        else if(op == '+'){
            scanf("%s %s %d %c %d", nume, prenume, &varsta, &sex, &priority);
            enqueue(&queue, nume, prenume, priority, sex, varsta);
        }
        else if(op == '-'){
            result = add_last(result, queue -> nume, queue -> prenume, queue -> priority, queue -> sex, queue -> varsta);
            dequeue(&queue);
        }
    }
    afisare(result);

    return 0;
}
