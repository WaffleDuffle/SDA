#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct queue{
    struct node* value;
    struct queue* next;
};

struct queue* create_node_queue(struct node* prim){
    struct queue* newnode = (struct queue*)malloc(sizeof(struct queue));
    if(newnode == NULL){
        perror("ERROR: Failed Allocation");
        return NULL;
    }
    newnode -> next = NULL;
    newnode -> value  = prim;
    return newnode;
}

struct queue* enqueue(struct queue* head, struct node* prim){
    struct queue *curr, *newnode;
    newnode = create_node_queue(prim);
    if(head == NULL){
        head = newnode;
        return head;
    }
    else{
        curr = head;
        while(curr -> next != NULL)
            curr = curr -> next;
        curr -> next = newnode;
        return head;
    }
}

struct node* dequeue(struct queue** head){
    struct queue* del_node;
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

void bfs(struct node* prim){
    struct queue* queue = NULL;
    queue = enqueue(queue, prim);
    while(queue != NULL){
        struct node* curr = dequeue(&queue);
        printf("%d ", curr -> key);
        if(curr -> left != NULL)
            queue = enqueue(queue, curr -> left);
        if(curr -> right != NULL)
            queue = enqueue(queue, curr -> right);
    }
    free(queue);
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
    for(int i = 0 ; i < 11 ; ++i){
        scanf("%d", &key);
        tree = insert(tree, key);
    }
    bfs(tree);
    delete_tree(tree);
    return 0;
}
