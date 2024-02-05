#include "arbori.h"
#include <stdio.h>
#include <stdlib.h>

struct node* create_node(int key){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Failed Allocation");
        return NULL;
    }
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> key = key;
    return newnode;
}

struct node* insert(struct node* prim, int key){
    struct node *curr, *newnode, *parent;
    newnode = create_node(key);
    if(prim == NULL){
        prim = newnode;
        printf("Added parent\n");
        return prim;
    }
    else{
        curr = prim;
        while(curr != NULL){
            parent = curr;
            if(key > curr -> key)
                curr = curr -> left;
            else
                curr = curr -> right;
        }

        if(key > parent -> key){
            parent -> left = newnode;
            printf("Added node left\nParent is node %d\n", parent -> key);
        }
        else{
            parent -> right = newnode;
            printf("Added node right\nParent is node %d\n", parent -> key);
        }
    }
    return prim;
}

void pre_order(struct node* prim){
    if(prim != NULL){
        printf("%d ", prim -> key);
        pre_order(prim -> left);
        pre_order(prim -> right);
    }

}

void in_order(struct node* prim){
    if(prim != NULL){
        in_order(prim -> left);
        printf("%d ", prim -> key);
        in_order(prim -> right);
    }

}

void post_order(struct node* prim){
    if(prim != NULL){
        post_order(prim -> left);
        post_order(prim -> right);
        printf("%d ", prim -> key);
    }

}

struct node* delete_tree(struct node* prim){
    if(prim != NULL){
        delete_tree(prim -> right);
        delete_tree(prim -> left);
        free(prim);
    }
    return NULL;
}

struct node* search_node(struct node* prim, int key){
    if(prim != NULL){
        if(prim -> key == key){
            printf("Found");
            return prim;
        }
        else if(key < prim -> key){
            search_node(prim -> left, key);
        }
        else{
            search_node(prim -> right, key);
        }
    }
    else{
        printf("Not found\n");
        return NULL;
    }
}


// This function is an extension to delete below node, it removes the whole tree including set subroot
struct node* delete_search_node(struct node* prim, int key){
    if(prim != NULL){
        if(prim -> left != NULL){
            if(prim -> left -> key == key){
                printf("Found");
                prim -> left  = delete_tree(prim -> left);
                prim -> left = NULL;
                return prim;
            }
            else if(key < prim -> key){
                delete_search_node(prim -> left, key);
            }
            else{
                delete_search_node(prim -> right, key);
            }
        }
        else if(prim -> right != NULL){
            if(prim -> right -> key == key){
                printf("Found");
                prim -> right  = delete_tree(prim -> right);
                prim -> right = NULL;
                return prim;
            }
            else if(key < prim -> key){
                delete_search_node(prim -> left, key);
            }
            else{
                delete_search_node(prim -> right, key);
            }
        }
    }
    else{
        printf("Not found\n");
        return NULL;
    }
}

void count_leaves(struct node* prim, int* nr){
    if(prim != NULL){
        count_leaves(prim -> left, nr);
        count_leaves(prim -> right, nr);
    }
    else{
        (*nr)++;
    }
}

int max_height(struct node* prim){
    if(prim == NULL)
        return 0;

    int height_left = max_height(prim -> left);
    int height_right = max_height(prim -> right);

    return 1 + (height_left > height_right ? height_left : height_right);
}

