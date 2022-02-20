#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int insertNode(struct node**,int);
int searchNode(struct node*,int);
int deleteNode(struct node**,int);

int preOrder(struct node*);
int inOrder(struct node*);
int postOrder(struct node*);

int destroy(struct node**);