#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};
struct node* createNode(int key) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode -> key = key;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

void sort(struct node** array, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(array[i] -> key > array[j] -> key) {
                struct node* aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

struct node** deleteFirst(struct node** array, int* size) {
    for(int i = 0 ; i < *size - 1 ; i++) {
        array[i] = array[i + 1];
    }
    array = realloc(array, (*size - 1) * sizeof(struct node*));
    (*size)--;

    return array;
}

struct node** add(struct node** array, int* size, struct node* node) {
    array = realloc(array, (*size + 1) * sizeof(struct node*));
    array[*size] = node;
    (*size)++;
    return array;
}

void display(struct node* prim) {
    if(prim != NULL) {
        printf("%d\n", prim -> key);
        display(prim -> left);
        display(prim -> right);
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
    int size;
    scanf("%d", &size);
    struct node** array = malloc(size*sizeof(struct node*));
    int entry;
    for(int i = 0; i < size; i++) {
        scanf("%d", &entry);
        array[i] = createNode(entry);
    }
    sort(array, size);
    while(size > 1) {
        struct node* first = array[0];
        struct node* second = array[1];

        struct node* newnode = createNode(first -> key + second -> key);
        newnode -> left = first;
        newnode -> right = second;

        array = deleteFirst(array, &size);
        array = deleteFirst(array, &size);
        array = add(array, &size, newnode);
        sort(array, size);
    }
    display(array[0]);
    delete_tree(array[0]);
    free(array);
    return 0;
}