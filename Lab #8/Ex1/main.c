#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct node* create_node(int key){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Failed allocation");
        return NULL;
    }
    else{
        newnode -> key = key;
        newnode -> left = NULL;
        newnode -> right = NULL;
        return newnode;
    }
}

struct node* insert(struct node* prim, int key){
    struct node* newnode, *curr, *parent;
    newnode = create_node(key);
    if(prim == NULL){
        prim = newnode;
        return prim;
    }
    else{
        curr = prim;
        while(curr != NULL){
            parent = curr;
            if(key < curr -> key)
                curr = curr -> left;
            else
                curr = curr -> right;
        }
        if(key < parent -> key)
            parent -> left = newnode;
        else
            parent -> right = newnode;
    }
    return prim;
}

void inorder(struct node* prim, int value){
    if(prim != NULL){
        inorder(prim -> right, value);
        if(prim -> key >= value)
            printf("%d ", prim -> key);
        inorder(prim -> left, value);
    }
}

void delete_tree(struct node* prim){
    if(prim != NULL){
        delete_tree(prim -> left);
        delete_tree(prim -> right);
        free(prim);
    }
}
int main() {
    struct node* tree = NULL;
    int key;
    char cuvant[10];
    do{
        if(scanf("%d", &key) == 1)
            tree = insert(tree, key);
        else{
            scanf("%s", cuvant);
            if(strcmp("stop", cuvant) == 0)
                break;
            else
                printf("Wrong string\n");
        }
    }while(1);
    scanf("%d", &key);
    inorder(tree, key);
    delete_tree(tree);
    return 0;
}
