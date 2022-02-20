#include <stdio.h>
#include <stdlib.h>

struct node{
       int data;
       struct node* next;
};

int init(struct node**);
int isEmpty(struct node*);
int enqueue(struct node**,int);
int dequeue(struct node**,int*);
int getRear(struct node*,int*);
int gerFront(struct node*,int*);
int destroy(struct node**);
