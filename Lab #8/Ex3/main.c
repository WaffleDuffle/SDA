#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char key[20];
    int dist;
    struct node* left;
    struct node* right;
};

struct node* create_node(char* key, int dist){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Failed Allocation");
        return NULL;
    }
    newnode -> left = NULL;
    newnode -> right = NULL;
    strcpy(newnode -> key, key);
    newnode -> dist = dist;
    return newnode;
}


struct node* insert(struct node* prim, char* key, int dist){
    struct node *curr, *newnode, *parent;
    newnode = create_node(key, dist);
    if(prim == NULL){
        prim = newnode;
        return prim;
    }
    else{
        curr = prim;
        while(curr != NULL){
            parent = curr;
            if(key[0] < curr -> key[0])
                curr = curr -> left;
            else
                curr = curr -> right;
        }
        if(key[0] < parent -> key[0])
            parent -> left = newnode;
        else
            parent -> right = newnode;
    }
    return prim;
}

void delete_tree(struct node* prim){
    if(prim != NULL){
        delete_tree(prim -> left);
        delete_tree(prim -> right);
        free(prim);
    }
}
struct node* search(struct node* prim, char* key){
    if(prim != NULL){
        if(strcmp(key, prim -> key) == 0){
            return prim;
        }
        if(key[0] < prim -> key[0])
            search(prim -> left, key);
        else
            search(prim -> right, key);
    }
    else{
        printf("Not Found\n");
        return NULL;
    }
}

int size(struct node* prim){
    if(prim != NULL){
        return 1 + size(prim -> left) + size(prim -> right);
    }
    else
        return 0;
}

int distance(struct node* prim, char* key){
    if(prim != NULL){
        if(strcmp(key, prim -> key) == 0){
            return 0;
        }
        if(key[0] < prim -> key[0])
            return (prim -> left) -> dist + distance(prim -> left, key);
        else
            return (prim -> right) -> dist + distance(prim -> right, key);
    }
    else{
        printf("Not Found\n");
        return 0;
    }
}

struct node* lca(struct node* prim, char* nume1, char* nume2){
    if(nume1[0] < prim -> key[0] && nume2[0] < prim -> key[0])
        return lca(prim -> left, nume1, nume2);
    else if(nume1[0] > prim -> key[0] && nume2[0] > prim -> key[0])
        return lca(prim -> right, nume1, nume2);
    else
        return prim;
}

int main() {
    int n, op, dist;
    char nume[20];
    struct node* tree = NULL;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%s %d", nume, &dist);
        tree = insert(tree, nume, dist);
    }
    scanf("%d", &op);
    switch(op){
        case 1:{
            scanf("%s", nume);
            printf("%d", size(search(tree, nume)) - 1);
            break;
        }
        case 2:{
            char nume2[20];
            scanf("%s %s", nume, nume2);
            struct node* common = lca(tree, nume, nume2);
            printf("%d", distance(common, nume) + distance(common, nume2));
            break;
        }
    }
    delete_tree(tree);
    return 0;
}