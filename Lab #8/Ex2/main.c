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
        perror("ERROR: Failed allocation");
        return NULL;
    }
    newnode -> key = key;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;

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

void post_order(struct node* prim){
    if(prim != NULL){
        post_order(prim -> left);
        post_order(prim -> right);
        printf("%d ", prim -> key);
    }
}

void delete_tree(struct node* prim){
    if(prim != NULL){
        delete_tree(prim -> left);
        delete_tree(prim -> right);
        free(prim);
    }
}

void magic(struct node** prim, int* vec, int p, int u, int dim){
    if(p < u){
        int m = (p + u) / 2;
        *prim = insert(*prim, *(vec + m));
        magic(prim, vec, p, m, dim);
        magic(prim, vec, m + 1, u, dim);
    }
    else if(p == dim)
        insert(*prim, *(vec + p));
}
int main() {
    struct node* tree = NULL;
    int key;
    int* vec = (int*)malloc(sizeof(int));
    if(vec == NULL){
        perror("ERROR: Failed allocatiion");
        return -1;
    }
    int dim = 0;
    while(scanf("%d", &key) != EOF){
        dim++;
        vec = (int*)realloc(vec, dim*sizeof(int));

        *(vec + dim - 1) = key;
    }
    magic(&tree, vec, 0, dim-1, dim-1);
    post_order(tree);
    free(vec);
    delete_tree(tree);
    return 0;
}
