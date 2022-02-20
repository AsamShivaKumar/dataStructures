#include <stdio.h>
#include <stdlib.h>

struct node{
       int data;
       struct node* next;
};

struct queue{
       struct node* head;
       struct node* tail;
};

int init(struct queue**);
int isEmpty(struct queue*);
int getFront(struct queue*, int*);
int getRear(struct queue*, int*);
int enqueue(struct queue*,int);
int dequeue(struct queue*,int*);
int destroy(struct queue**);