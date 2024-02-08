#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct stack{
    struct node* value;
    struct stack* next;
};

struct stack* create_node_stack(struct node* prim){
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    if(newnode == NULL){
        perror("ERROR: Failed Allocation");
        return NULL;
    }
    newnode -> next = NULL;
    newnode -> value  = prim;
    return newnode;
}

struct stack* push(struct stack* head, struct node* prim){
    struct stack *newnode;
    newnode = create_node_stack(prim);
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
    struct stack* del_node;
    struct node* copy_node;
    if((*head) != NULL){
        del_node = *head;
        *head = (*head) -> next;
        copy_node = del_node -> value;
        free(del_node);
    }
    else{
        return NULL;
    }
    return copy_node;
}

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

        }
        else{
            parent -> right = newnode;

        }
    }
    return prim;
}

void bfs_zig_zag(struct node* prim){
    struct stack* curr_level = NULL;
    struct stack* next_level = NULL;
    int ok = 1;
    curr_level = push(curr_level, prim);
    while(curr_level != NULL){
        struct node* temp = pop(&curr_level);
        printf("%d\n", temp -> key);
        if(ok){
            if(temp -> right) next_level = push(next_level, temp -> right);
            if(temp -> left) next_level = push(next_level, temp -> left);
        }
        else{
            if(temp -> left) next_level = push(next_level, temp -> left);
            if(temp -> right) next_level = push(next_level, temp -> right);
        }

        if(curr_level == NULL){
            ok = !ok;
            struct stack* temp_stack = curr_level;
            curr_level = next_level;
            next_level = temp_stack;
        }
    }


}

struct node* delete_tree(struct node* prim){
    if(prim != NULL){
        delete_tree(prim -> left);
        delete_tree(prim -> right);
        free(prim);
    }
}

int main() {
    struct node* tree = NULL;
    int key;
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d", &key);
        tree = insert(tree, key);
    }
    bfs_zig_zag(tree);
    delete_tree(tree);
    return 0;
}
