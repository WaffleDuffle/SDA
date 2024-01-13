#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct node* creare_nod(int nr){
    struct node* newnode = malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Alocarea a esuat");
        return NULL;
    }
    newnode -> val = nr;
    newnode -> next = NULL;
    return newnode;
}

struct node* add_last(struct node* head, int nr){
    if(head == NULL){
        head = creare_nod(nr);
        return head;
    }
    struct node* curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    struct node* newnode = creare_nod(nr);
    curr -> next = newnode;
    return head;
}

void afisare(struct node* head){
    struct node* curr = head;
    while(curr != NULL){
        printf("%d ", curr -> val);
        curr=  curr -> next;
    }
}

int contains(struct node* head, int k){
    while(head != NULL){
        if(head -> val == k)
            return 1;
        head = head -> next;
    }
    return 0;
}

int missing(struct node* head, int n){
    int nr = 0;
    for(int i = 0 ; i <= n ; ++i){
        if(contains(head, i) == 0)
            nr++;
    }
    return nr;
}
int main() {
    struct node* lista = NULL;
    int n;
    scanf("%d",&n);
    int nr;
    while(scanf("%d", &nr) != EOF){
        lista = add_last(lista, nr);
    }
    printf("%d", missing(lista, n));

    return 0;
}
