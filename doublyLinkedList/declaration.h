#include <stdio.h>
#include <stdlib.h>

struct node{
       int data;
       struct node* prev;
       struct node* next;
}; 

struct list{
       struct node* head;
       struct node* tail;
};

int init(struct list**);
int isEmpty(struct list*);
int insertElement(struct list*, int, int);
int delElement(struct list*,int);
int traverse(struct list*,int);
int clear(struct list**);