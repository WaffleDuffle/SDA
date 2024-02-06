#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char key[20];
    struct node* left;
    struct node* right;
};

struct hashmap{
    struct node** array;
};

struct lista{
    char key[20];
    struct lista* next;
};

struct lista* create_node_list(char* key){
    struct lista* newnode = (struct lista*)malloc(sizeof(struct lista));
    if(newnode == NULL){
        printf("ERROR: Failed allocation");
        return NULL;
    }
    strcpy(newnode -> key, key);
    newnode -> next = NULL;
    return  newnode;
}

struct lista* push(struct lista* head, char *nume){
    struct lista *newnode, *curr;
    newnode = create_node_list(nume);
    if(head == NULL){
        head = newnode;
        return head;
    }
    else{
        newnode -> next = head;
        return newnode;
    }
}

int dist(struct lista* head, char* key){
    int nr = 0;
    while(head != NULL){
        nr++;
        if(strcmp(head -> key, key) == 0)
            return nr;
        head = head -> next;
    }
    printf("Cuvantul nu a fost gast\n");
    return 0;
}

int h(char *key){
    return key[0] - 'a';
}

struct node* create_node(char* key){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("ERROR: Failed allocation");
        return NULL;
    }
    strcpy(newnode -> key, key);
    newnode -> left = NULL;
    newnode -> right = NULL;
    return  newnode;
}

struct node* insert(struct node* prim, char* key){
    struct node *newnode, *curr, *parent;
    newnode = create_node(key);
    if(prim == NULL){
        prim = newnode;
        return prim;
    }
    else{
        curr = prim;
        while(curr != NULL){
            parent = curr;
            if(strcmp(key, curr -> key) < 0)
                curr = curr -> left;
            else
                curr = curr -> right;
        }
        if(strcmp(key, parent -> key) < 0)
            parent -> left = newnode;
        else
            parent -> right = newnode;
    }
    return prim;
}

void pre_order(struct node* prim){
    if(prim != NULL){
        printf("%s\n", prim -> key);
        pre_order(prim -> left);
        pre_order(prim -> right);
    }
}

void in_order(struct node* prim){
    if(prim != NULL){
        in_order(prim -> left);
        printf("%s\n", prim -> key);
        in_order(prim -> right);
    }
}

void populate(struct hashmap* map, char* key){
    int i = h(key);
    map -> array[i] = insert(map -> array[i], key);
}

int search(struct node* prim, char* key){
    if(prim != NULL){
        if(strcmp(prim -> key, key) == 0)
            return 1;
        else if(strcmp(key, prim -> key) < 0)
            return 1 + search(prim -> left, key);
        else
            return 1 + search(prim -> right, key);
    }
    else{
        printf("Cuvantul nu a fost gast\n");
        return 0;
    }
}

void delete_tree(struct node* prim){
    if(prim != NULL){
        delete_tree(prim -> left);
        delete_tree(prim -> right);
        free(prim);
    }
}

void delete_list(struct lista* head){
    struct lista* del_node;
    while(head != NULL){
        del_node = head;
        head = head -> next;
        free(del_node);
    }
}
int main() {
    struct hashmap map;
    struct lista* lista = NULL;
    char cuvant[20];
    int op;
    char c;
    int dim = 0;
    map.array = (struct node**)malloc(26*sizeof(struct node*));
    for(int i = 0 ; i < 26 ; ++i)
        map.array[i] = NULL;

    do{
        scanf("%s", cuvant);
        if(strcmp(cuvant, "stop") == 0)
            break;
        dim++;
        populate(&map, cuvant);
        lista = push(lista, cuvant);
    }while(1);


    scanf("%d", &op);
    getchar();
    switch(op){
        case 1:{
            scanf(" %c", &c);
            pre_order(map.array[h(&c)]);
            break;
        }
        case 2:{
            for(int i = 0 ; i < 26 ; ++i){
                if(map.array[i] != NULL)
                    in_order(map.array[i]);
            }
            break;
        }
        case 3:{
            scanf("%s", cuvant);
            printf("%d\n", search(map.array[h(cuvant)], cuvant));
            printf("%d\n", dim - dist(lista, cuvant) + 1);
            break;
        }
    }
    for(int i = 0 ; i < 26 ; ++i){
        if(map.array[i] != NULL)
            delete_tree(map.array[i]);
    }
    delete_list(lista);

    return 0;
}
