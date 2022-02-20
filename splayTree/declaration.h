#include <stdio.h>
#include <stdlib.h>

typedef struct node{
       int data;
       struct node* left;
       struct node* right;
} node;

node* insertNode(node*,int);
node* deleteNode(node*,int);
node* searchNode(node*,int);
node* splay(node*,int);