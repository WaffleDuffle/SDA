#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

void afisare(struct node* head){
    if(head == NULL){
        printf("BINGO!");
        return;
    }
    struct node* tmp = head;
    while(tmp != NULL) {
        printf("%d ", tmp -> val);
        tmp = tmp -> next;
    }
    printf("\n");
}

struct node* create(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> val = val;
    newnode -> next = NULL;
    return newnode;
}

struct node* add_set(struct node* head, int val){
    if(head == NULL){
        head = create(val);
        return head;
    }
    else{
        struct node* curr = head;
        while(curr -> next != NULL)
            curr = curr -> next;
        struct node* newnode = create(val);
        curr -> next = newnode;
        return head;
    }
}

struct node* delete(struct node* head, int val){
    if(head -> next == NULL){
        free(head);
        return NULL;
    }
    if(head -> val == val){
        struct node* d_node = head;
        head = head -> next;
        free(d_node);

        return head;
    }
    struct node* tmp = head;
    while(tmp -> next != NULL){
        if(tmp -> next -> val == val){
            struct node* d_node = tmp -> next;
            tmp -> next = tmp -> next -> next;
            free(d_node);

            return head;
        }
        tmp = tmp -> next;
    }
}

int contains(struct node* head, int val){
    struct node* tmp = head;
    while(tmp != NULL){
        if(tmp -> val == val)
            return 1;
        tmp = tmp -> next;
    }
    return 0;
}

struct node* insert(struct node* sorted, struct node* newnode){
    if(sorted == NULL || sorted -> val >= newnode -> val){
        newnode -> next = sorted;
        return newnode;
    }
    struct node* tmp = sorted;
    while(tmp -> next != NULL && tmp -> next -> val < newnode -> val)
        tmp = tmp -> next;
    newnode -> next = tmp -> next;
    tmp -> next = newnode;
    return sorted;
}

struct node* insertion_sort(struct node* head, struct node* sorted){
    struct node* curr = head;

    while(curr != NULL){
        struct node* next = curr -> next;
        sorted = insert(sorted, curr);
        curr = next;
    }
    return sorted;
}

int main() {
    struct node* bilet = NULL;
    unsigned n;
    int val;
    int nr = 15;
    struct node* bilet_sortat = NULL;
    scanf("%u", &n);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j){
            scanf("%d", &val);
            bilet = add_set(bilet, val);
        }
    while(scanf("%d", &val) != EOF) {
        if(contains(bilet, val)){
            bilet = delete(bilet, val);
        }

    }
    bilet_sortat = insertion_sort(bilet, bilet_sortat);
    afisare(bilet_sortat);
    return 0;
}
