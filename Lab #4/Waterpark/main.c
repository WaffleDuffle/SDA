#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char nume[20];
    struct node* next;
};

struct node* enqueue(struct node* head, char *nume){
    if(head == NULL){
        head = malloc(sizeof(struct node));
        if(head == NULL){
            perror("ERROR: Alocarea a esuat!\n");
            return NULL;
        }
        strcpy(head -> nume, nume);
        head -> next = NULL;
        return head;
    }
    struct node* tmp = head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct node* nodNou = malloc(sizeof(struct node));
            if(nodNou == NULL){
                perror("ERROR: Alocarea a esuat!\n");
                return NULL;
            }
            strcpy(nodNou -> nume, nume);
            nodNou -> next = NULL;
            tmp -> next = nodNou;
            return head;
        }
        tmp = tmp -> next;
    }
}

struct node* dequeue(struct node* head){
    if(head == NULL){
        return NULL;
    }
    struct node* nodSters = head;
    head = head -> next;
    free(nodSters);
    return head;
}

struct node* afisare(struct node* head){
    struct node* tmp = head;
    while(tmp != NULL){
        printf("%s\n", tmp -> nume);
        tmp = tmp -> next;
    }
}

void concurs(struct node* head1, struct node* head2, struct node* head3){
    while(head1 != NULL && head2 != NULL & head3 != NULL){
        printf("%s %s %s\n", head1 -> nume, head2 -> nume, head3 -> nume);
        head1 = dequeue(head1);
        head2 = dequeue(head2);
        head3 = dequeue(head3);
    }
}

int main() {
    struct node* rand1 = NULL;
    struct node* rand2 = NULL;
    struct node* rand3 = NULL;
    int n;
    char string[20];
    for(int i = 0 ; i < 7 ; ++i){
        scanf("%s %d", string, &n);
        if(n == 1)
            rand1 = enqueue(rand1, string);
        if(n == 2)
            rand2 = enqueue(rand2, string);
        if(n == 3)
            rand3 = enqueue(rand3, string);
    }
    concurs(rand1, rand2, rand3);
    return 0;
}
