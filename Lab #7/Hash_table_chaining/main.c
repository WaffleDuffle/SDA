#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct hashmap{
    struct node** array;
};

int h(int val, int m){
    while(val < 0)
        val += m;
    return val%m;
}

struct node* creare_nod(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Alocarea a esuat");
        return NULL;
    }
    newnode -> val = val;
    newnode -> next = NULL;
    return newnode;
}

void insert(struct hashmap* table, int val, int m){
    int i = h(val, m);
    if(table -> array[i] == NULL){
        table -> array[i] = creare_nod(val);
        return;
    }

    struct node* newnode = creare_nod(val);
    struct node* curr = table -> array[i];

    while(curr -> next != NULL)
        curr = curr -> next;
    curr -> next = newnode;
    newnode -> next = NULL;
}

void stergere(struct hashmap* table, int m){
    for(int i = 0 ; i < m ; ++i){
        while(table -> array[i] != NULL){
            struct node* del = table -> array[i];
            table -> array[i] = table -> array[i] -> next;
            free(del);
            del = NULL;
        }
    }
    free(table -> array);
    table -> array = NULL;
}

void afisare(struct hashmap* table, int m){
    for(int i = 0 ; i < m ; ++i){
        printf("%d: ", i);
        struct node* curr = table -> array[i];
        while(curr != NULL){
            printf("%d ", curr -> val);
            curr = curr -> next;
        }
        printf("\n");
    }
}
int main() {
    struct hashmap table;

    int m, n;
    scanf("%d%d", &m, &n);
    table.array = (struct node**)malloc(m*sizeof(struct node*));
    for(int i = 0 ; i < m ; ++i)
        table.array[i] = NULL;
    int val;
    for(int i = 0 ; i < n ; ++i){
        scanf("%d", &val);
        insert(&table, val, m);
    }
    afisare(&table, m);
    stergere(&table, m);
    return 0;
}
