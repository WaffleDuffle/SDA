#include <stdlib.h>
#include <stdio.h>

struct NOD
{
    int data;
    struct NOD *next;
};


struct NOD *add_to_end(struct NOD *head);
int find_min_in_list(struct NOD *head);

int main()
{
    int nr_noduri, i;
    struct NOD *head = NULL;
    scanf("%d", &nr_noduri);
    for (i = 0; i < nr_noduri; i++)
    {
        head = add_to_end(head);
    }
    printf("%d", find_min_in_list(head));
    return 0;
}

struct NOD *add_to_end(struct NOD *head)
{
    struct NOD *current = head;

    struct NOD *new_node = (struct NOD *)malloc(sizeof(struct NOD));
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head != NULL)
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    else
    {
        head = new_node;
    }

    return head;
}

int find_min_in_list(struct NOD * head){
    if (head == NULL){
        perror("Lista este goala!\n");
        return 0;
    }
    struct NOD* tmp = head;
    int mini = 99999;
    while(tmp != NULL){
        if(tmp -> data < mini)
            mini = tmp -> data;
        tmp = tmp -> next;
    }
    return mini;
}
