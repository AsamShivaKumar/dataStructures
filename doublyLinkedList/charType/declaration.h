#include <stdio.h>
#include <stdlib.h>

struct node{
       char data;
       struct node* prev;
       struct node* next;
}; 

struct list{
       struct node* head;
       struct node* tail;
};

int init(struct list**);
int isEmpty(struct list*);
int insertElement(struct list*, int, char);
int delElement(struct list*,char);
int clear(struct list**);