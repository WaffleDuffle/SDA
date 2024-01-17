#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct hashmap{
    struct node** array;
    int size;
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
        table -> size += 1;
        return;
    }
    while(table -> array[i] != NULL)
        i++;
    if(i < m){
        table -> array[i] = creare_nod(val);
        table -> size += 1;
    }
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

void rehash(struct hashmap* table, int m){
    printf("rehashing\n");
    struct hashmap tmp;
    struct hashmap table2;

    table2.array = (struct node**)malloc(m*sizeof(struct node*));
    table2.size = 0;

    for(int i = 0 ; i < m; ++i)
        table2.array[i] = NULL;

    for(int i = 0 ; i < m >> 1; ++i){
        if(table -> array[i] != NULL)
            insert(&table2, table -> array[i] -> val, m);
    }

    stergere(table, m >> 1);
    table -> array = (struct node**)malloc(m*sizeof(struct node*));
    for(int i = 0 ; i < m ; ++i)
        table -> array[i] = NULL;

    tmp.array = table -> array;
    table -> array = table2.array;
    table2.array = tmp.array;
    table -> size = table2.size;
    stergere(&table2, m >> 1);

}

void afisare(struct hashmap* table, int m){
    if(table -> array == NULL){
        printf("Hash gol\n");
        return;
    }
    for(int i = 0 ; i < m ; ++i){
        printf("%d: ", i);
        struct node* curr = table -> array[i];
        while(curr != NULL){
            printf("%d", curr -> val);
            curr = curr -> next;
        }
        printf("\n");
    }
}

int main() {
    struct hashmap table;
    int m = 2;
    table.array = (struct node**)malloc(m*sizeof(struct node*));
    table.size = 0;
    for(int i = 0 ; i < 2 ; ++i)
        table.array[i] = NULL;
    int val;
    int op = 0;
    while(op != 3){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &val);
            if(((float) table.size / m) - 0.75 > 0.00000001){
                m <<= 1;
                rehash(&table, m);
            }

            insert(&table, val, m);
        }
        else if(op == 2)
            afisare(&table, m);
    }
    stergere(&table, m);
    return 0;
}
