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

struct stack* create_stack_node(struct node* data){
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    if(newnode == NULL){
        perror("ERROR: Failed Allocation");
        return NULL;
    }
    newnode -> next = NULL;
    newnode -> value = data;
    return newnode;
}

struct stack* push(struct stack* head, struct node* data){
    struct stack* newnode = create_stack_node(data);
    if(head == NULL){
        head = newnode;
        return head;
    }
    else{
        newnode -> next = head;
        return newnode;
    }
}

struct node* pop(struct stack** head){
    if(head == NULL){
        printf("Stack is empty\n");
        return 0;
    }
    struct stack* del = *head;
    *head = (*head) -> next;
    struct node* copy = del -> value;
    free(del);
    del = NULL;
    return copy;
}

void print_stack(struct stack* head){
    while(head != NULL){
        printf("%d ", head -> value -> key);
        head = head -> next;
    }
    printf("\n");
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
            if(key < curr -> key)
                curr = curr -> left;
            else
                curr = curr -> right;
        }

        if(key < parent -> key){
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
    struct stack* stack = NULL;
    stack = push(stack, prim);

    while(stack != NULL){
        struct node* curr = pop(&stack);
        printf("%d ", curr -> key);
        if(curr -> right != NULL)
            stack = push(stack, curr -> right);
        if(curr -> left != NULL)
            stack = push(stack, curr -> left);
    }
    free(stack);
}

void in_order(struct node* prim){
    struct stack* stack = NULL;
    struct node* curr = prim;
    while(stack != NULL || curr != NULL){
        while(curr != NULL){
            stack = push(stack, curr);
            curr = curr -> left;
        }
        curr = pop(&stack);
        printf("%d ", curr -> key);
        curr = curr -> right;
    }
    free(stack);

}

void post_order(struct node* prim){
    struct stack* stack = NULL;
    struct stack* stack2 = NULL;
    stack = push(stack, prim);

    while(stack != NULL){
        struct node* curr = pop(&stack);
        stack2 = push(stack2, curr);
        if(curr -> left != NULL)
            stack = push(stack, curr -> left);
        if(curr -> right != NULL)
            stack = push(stack, curr -> right);

    }
    while(stack2 != NULL){
        struct node* temp = pop(&stack2);
        printf("%d ", temp -> key);
    }
    free(stack);
    free(stack2);
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

