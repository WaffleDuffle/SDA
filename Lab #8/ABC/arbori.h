#ifndef _ARBORI_H_
#define _ARBORI_H_

struct node{
    int key;
    struct node* left;
    struct node* right;
};


struct node* create_node(int);
struct node* insert(struct node*, int);
void pre_order(struct node*);
void in_order(struct node*);
void post_order(struct node*);
struct node* delete_tree(struct node*);
struct node* search_node(struct node*, int);
struct node* delete_search_node(struct node*, int);
void count_leaves(struct node*, int*);
int max_height(struct node*);
#endif