#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stiva{
    char nume[128];
    struct stiva* next;
};

struct stiva* creare_nod(char *nume){
    struct stiva* nodNou = malloc(sizeof(struct stiva));
    if(nodNou == NULL){
        perror("ERROR: Alocarea a esuat!\n");
        return NULL;
    }
    strcpy(nodNou -> nume, nume);
    nodNou -> next = NULL;
    return nodNou;
}

struct stiva* add_last(struct stiva* head, char* nume){
    if(head == NULL){
        head = creare_nod(nume);
        head -> next = NULL;
        return head;
    }
    struct stiva* tmp = head;
    while(tmp != NULL){
        if(tmp -> next == NULL){
            struct stiva* nodNou = creare_nod(nume);
            tmp -> next = nodNou;
            return head;
        }
        tmp = tmp -> next;
    }
}
struct stiva* push(struct stiva* head, char *nume){
    if(head == NULL){
        head = creare_nod(nume);

        head -> next = NULL;
        return head;
    }
    struct stiva* nodNou = creare_nod(nume);
    nodNou -> next = head;
    return nodNou;
}

struct stiva* pop(struct stiva* head, struct stiva** head2){
    if(head == NULL){
        return NULL;
    }
    struct stiva* nodSters = head;
    head = head -> next;
    *head2 = add_last(*head2, nodSters -> nume);
    free(nodSters);

    return head;
}

void afisare(struct stiva* head){
    struct stiva* tmp = head;
    while(tmp != NULL){
        printf("%s,", tmp -> nume);
        tmp = tmp -> next;
    }
}
int main() {
    char nume[128];
    struct stiva* biblioteca = NULL;
    struct stiva* rez = NULL;
    char op;
    int ok = 0;
    while(1){
        scanf("%c", &op);
        if(op == '+'){
            ok = 1;
            op = getc(stdin);
            fgets(nume, 128, stdin);
            nume[strlen(nume) - 1] = '\0';
            biblioteca = push(biblioteca, nume);
        }
        else if(op == '-'){
            biblioteca = pop(biblioteca, &rez);
            if(biblioteca == NULL && ok == 1)
                break;
        }

    }
    afisare(rez);
    return 0;

}
