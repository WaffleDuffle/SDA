#include "list.h"
#include<stdlib.h>
#include<stdio.h>

struct ListTemplate {
    struct ListTemplate* next;
    int value;
};

LIST(list);

int main()
{
    list_init(list);

    struct ListTemplate* HEAD, * TAIL, *CurrentNode;
    // Usually, you will define and call a function that creates and reads each node. Here, we will manually create them as it is easier to follow in this short example.
    struct ListTemplate* Node1 = (struct ListTemplate*)malloc(sizeof(struct ListTemplate));
    struct ListTemplate* Node2 = (struct ListTemplate*)malloc(sizeof(struct ListTemplate));
    struct ListTemplate* Node3 = (struct ListTemplate*)malloc(sizeof(struct ListTemplate));
    struct ListTemplate* Node4 = (struct ListTemplate*)malloc(sizeof(struct ListTemplate));
    struct ListTemplate* Node5 = (struct ListTemplate*)malloc(sizeof(struct ListTemplate));

    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;
    Node4->value = 4;
    Node5->value = 5;

    // Add Node1 and Node2 to the list
    list_append(list, Node1);
    printf("Adding Node1 to the end of the list. The length of the list is %d\n", list_length(list));
    list_append(list, Node2);
    printf("Adding Node2 to the end of the list. The length of the list is %d\n", list_length(list));

    // Get the first node
    HEAD = list_head(list);
    printf("Printing head: %d\n", HEAD->value);

    // Add Node3 at the beginning of the list
    list_push(list, Node3);
    printf("Adding Node3 to the beginning of list. The length of the list is %d\n", list_length(list));

    HEAD = list_head(list);
    printf("Printing the new head: %d\n", HEAD->value);

    // Get the last node
    TAIL = list_tail(list);
    printf("Printing tail: %d\n", TAIL->value);

    // Add Node4 to the end of the list
    list_append(list, Node4);
    printf("Adding Node4 to the end of the list. The length of the list is %d\n", list_length(list));
    TAIL = list_tail(list);
    printf("Printing the new tail: %d\n", TAIL->value);

    printf("Pops the head and removes it from the list. ");
    list_pop_head(list);

    HEAD = list_head(list);
    printf("Printing the new head: %d\n", HEAD->value);

    printf("Pops the tail and removes it from the list. ");
    list_pop_tail(list);

    TAIL = list_tail(list);
    printf("Printing the new tail: %d\n", TAIL->value);

    printf("Printing the whole list:\n");
    for (CurrentNode = list_head(list); CurrentNode != NULL; CurrentNode = list_item_next(CurrentNode)) {
        printf("List element number %d\n", CurrentNode->value);
    }

    printf("Adding the deleted Node3 immediately after the node that contains the value 1:\n");
    for (CurrentNode = list_head(list); CurrentNode != NULL; CurrentNode = list_item_next(CurrentNode)) {
        if(CurrentNode->value == 1)
            list_insert(list, CurrentNode, Node3);
    }

    printf("Printing the whole list:\n");
    for (CurrentNode = list_head(list); CurrentNode != NULL; CurrentNode = list_item_next(CurrentNode)) {
        printf("List element number %d\n", CurrentNode->value);
    }

    return 0;
}