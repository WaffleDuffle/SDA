#include "arbori.h"
#include <stdio.h>


int main() {
    struct node* tree = NULL, *found_node;
    int key;
    int op;
    printf("MENU: \n");
    printf("[1] Insert \n");
    printf("[2] Pre_order print \n");
    printf("[3] In_order print \n");
    printf("[4] Post_order print \n");
    printf("[5] Delete tree \n");
    printf("[6] Search in tree \n");
    printf("[7] Count leaves \n");
    printf("[8] Find the length \n");
    printf("[0] Exit \n");
    do{
       printf("Insert operation: ");
       scanf("%d", &op);
       switch(op){
           case 1:{
               printf("What number?:");
               scanf("%d", &key);
               tree = insert(tree, key);
               break;
           }
           case 2:{
               pre_order(tree);
               printf("\n");
               break;
           }
           case 3:{
               in_order(tree);
               printf("\n");
               break;
           }
           case 4:{
               post_order(tree);
               printf("\n");
               break;
           }
           case 5:{
               printf("Witch node?:");
               scanf("%d", &key);
               delete_search_node(tree, key);
           //    found_node = search_node(tree, key);
           //    if(found_node != NULL){
           //        found_node -> left = delete_tree(found_node -> left);
           //        found_node -> right = delete_tree(found_node -> right);
            //       printf("Tree is gone\n");
            //   }
               break;
           }
           case 6:{
               printf("Which node?:");
               scanf("%d", &key);
               found_node = search_node(tree, key);
               printf("Node is %d\n", found_node -> key);
               break;
           }
           case 7:{
               int nr = 0;
               count_leaves(tree, &nr);
               nr /= 2;
               printf("Number of leaves in tree: %d\n", nr);
               break;
           }
           case 8:{
               printf("Lentgh: %d\n", max_height(tree));
               break;
           }
           case 0:{
               delete_tree(tree);
               return 0;
           }
           default:{
               printf("Invalid operation\n");
           }
       }
    }while(1);
}
