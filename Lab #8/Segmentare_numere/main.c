#include <stdio.h>
#include <stdlib.h>
struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct node* create_node(int key){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Memory failed");
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

void inorder_odd(struct node* prim){
    if(prim != NULL){
        inorder_odd(prim -> right);
        if(prim -> key % 2)
            printf("%d ", prim -> key);
        inorder_odd(prim -> left);
    }
}

void inorder_even(struct node* prim){
    if(prim != NULL){
        inorder_even(prim -> left);
        if(!(prim -> key % 2))
            printf("%d ", prim -> key);
        inorder_even(prim -> right);
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
    while(scanf("%d", &key) != EOF){
        tree = insert(tree, key);
    }
    inorder_even(tree);
    inorder_odd(tree);
    delete_tree(tree);
    return 0;
}
