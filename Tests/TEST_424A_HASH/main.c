#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct HashNode{
    char nume[20]; // key
    int m; // month
    int d; // day
    int y; // year
    struct HashNode* next;
};

struct Hash{
    struct HashNode** array;
};

int h(const char* key, const int n){
    int sum = 0;
    for(int i = 0 ; key[i] != '\0' ; ++i)
        sum += (int)key[i];

    return sum % n;
}

struct HashNode* creare_nod(char* nume, int year, int month, int day){
    struct HashNode* newnode = malloc(sizeof(struct HashNode));
    if(newnode == NULL){
        perror("ERROR: Alocarea a esuat");
        return NULL;
    }

    newnode -> y = year;
    newnode -> m = month;
    newnode -> d = day;
    strcpy(newnode -> nume, nume);
    newnode -> next = NULL;
    return newnode;
}

void insert(struct Hash* hash_table, char* nume, int n, int year, int month, int day){
    int i = h(nume, n);
    struct HashNode* newnode = creare_nod(nume, year, month, day);
    if(hash_table -> array[i] == NULL){
        hash_table -> array[i] = creare_nod(nume, year, month, day);
        return;
    }
    struct HashNode* curr = hash_table -> array[i];
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = newnode;
    newnode -> next = NULL;
}

void afisare_table(struct Hash* hash_table, int n){
    for(int i = 0 ; i < n ; ++i){
        printf("%d: ", i+1);
        if(hash_table -> array[i] == NULL)
            printf("Lista este goala");
        struct HashNode* curr = hash_table -> array[i];
        while(curr != NULL){
            if(2024 - curr -> y < 18 || 2024 - curr -> y == 18 && 1 < curr -> m || 2024 - curr -> y == 18 && 1 == curr -> m && 9 < curr -> d)
                printf("%s Minor -> ", curr -> nume);
            else
                printf("%s %d %d %d -> ", curr -> nume, curr -> y, curr -> m, curr ->d);
            curr = curr -> next;
        }
        printf("\n");
    }
}

void stergere(struct Hash* hash_table, int n){
    for(int i = 0 ; i < n ; ++i){
        while(hash_table -> array[i] != NULL){
            struct HashNode* del_node = hash_table -> array[i];
            hash_table -> array[i] = hash_table -> array[i] -> next;
            free(del_node);
            del_node = NULL;
        }        
    }
    free(hash_table -> array);
    hash_table -> array = NULL;
}

void cautare_nume(struct Hash* hash_table, int n, char* nume){
    int ok = 0;
    for(int i = 0 ; i < n ; ++i){
        struct HashNode* curr = hash_table -> array[i];
        while(curr != NULL){
            if(strcmp(nume, curr -> nume) == 0)
                ok = 1;
            curr = curr -> next;
        }
    }
    if(ok == 1)
        printf("%s\n", nume);
    else
        printf("Nu exista useri similari");
}

void verificare(struct Hash* hash_table, struct Hash* hash_table2, int n){
    int k = 1;
    while(k < 20){
        int ok = 0;
        hash_table2 -> array = (struct HashNode**)malloc(k*sizeof(struct HashNode*));
        for(int i = 0 ; i < k ; ++i){
            hash_table2 -> array[i] = NULL;
        }

        for(int i = 0 ; i < n ; ++i){
            struct HashNode* curr = hash_table -> array[i];
            while(curr != NULL){
                insert(hash_table2, curr -> nume, k, 0, 0, 0);
                curr = curr -> next;
            }
        }

        for(int i = 0 ; i < k ; ++i){
            int nr = 0;
            struct HashNode* curr = hash_table2 -> array[i];
            while(curr != NULL){
                nr++;
                curr = curr -> next;
            }
            if(nr > 2)
                ok = 1;
        }
        if(ok == 0){
            printf("%d", k);
            break;
        }
        stergere(hash_table2, k);
        k++;
    }

}

int main() {
    struct Hash hash_table;
    int n, nr;
    scanf("%d %d", &n, &nr);
    hash_table.array = (struct HashNode**)malloc(nr*sizeof(struct HashNode*));
    for(int i = 0 ; i < n ; ++i){
        hash_table.array[i] = NULL;
    }
    char nume[20];
    int y, m, d;
    for(int i = 0 ; i < nr ; ++i){
        scanf("%s", nume);
        scanf("%d %d %d", &y,&m,&d);
        insert(&hash_table, nume, n, y, m, d);
    }
    int op;
    scanf("%d", &op);
    switch(op){
        case 1: {
            afisare_table(&hash_table, n);
            stergere(&hash_table, n);
            break;
        }
        case 2: {
            char nume1[20], nume2[20], nume3[20];
            scanf("%s %s %s", nume1, nume2, nume3);
            cautare_nume(&hash_table, n, nume1);
            cautare_nume(&hash_table, n, nume2);
            cautare_nume(&hash_table, n, nume3);
            stergere(&hash_table, n);
            break;
        }
        case 3: {
            struct Hash hash_table2;
            verificare(&hash_table, &hash_table2, n);
            break;
        }
    }


    return 0;
}
