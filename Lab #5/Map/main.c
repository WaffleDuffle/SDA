#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char key[30];
    char descriere[1024];
    struct node* next;
};

struct node* creare_nod(char* key, char* descriere){
    struct node* newnode = malloc(sizeof(struct node));
    if(newnode == NULL){
        perror("ERROR: Alocarea a esuat");
        return NULL;
    }

    strcpy(newnode -> key, key);
    strcpy(newnode -> descriere, descriere);
    newnode -> next = NULL;
    return newnode;
}

struct node* add_last(struct node* head, char* key, char* descriere){
    if(head == NULL){
        head = creare_nod(key, descriere);
        return head;
    }
    struct node* curr = head;
    while(curr -> next != NULL)
        curr = curr -> next;
    struct node* newnode = creare_nod(key, descriere);
    curr -> next = newnode;
    return head;
}

void keys(struct node* head){
    while(head != NULL){
        printf("%s ", head -> key);
        head = head -> next;
    }
}

void values(struct node* head){
    while(head != NULL){
        printf("%s ", head -> descriere);
        head = head -> next;
    }
}

void afisare(struct node* head){
    while(head != NULL){
        printf("%s: %s\n", head -> key, head -> descriere);
        head = head -> next;
    }
}

int contains(struct node* head, char* key){
    struct node* curr = head;
    while(curr != NULL){
        if(strcmp(key, curr -> key) == 0)
            return 1;
        curr = curr -> next;
    }
    return 0;
}
char* get(struct node* head, char* key){
    struct node* curr = head;
    while(curr != NULL){
        if(strcmp(key, curr -> key) == 0)
            return curr -> descriere;
        curr = curr -> next;
    }
    return NULL;
}

void set(struct node* head, char* key, char* text){
    struct node* curr = head;
    while(curr != NULL){
        if(strcmp(key, curr -> key) == 0)
            strcpy(curr -> descriere, text);
        curr = curr -> next;
    }

}

struct node* search(struct node* head1, struct node* head2){
    struct node* curr = head2;
    while(curr != NULL){
        if(contains(head1, curr -> key) == 1)
            set(head2, curr -> key, get(head1, curr -> key));
        curr = curr -> next;
    }
    return head2;
}
int main() {
    int n;
    char key[30];
    char descriere[1024];
    struct node* map = NULL;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i){
        getchar();
        scanf("%[^,]%*c%[^\n]", key, descriere);
        map = add_last(map, key, descriere);
    }
    struct node* result = NULL;
    while(scanf("%s", key) != EOF){
        result = add_last(result, key, "-");
    }
    result = search(map, result);
    afisare(result);


    return 0;
}
