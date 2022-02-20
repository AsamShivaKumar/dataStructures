#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct stack;
int init(struct stack**);
int push(struct stack*,int);
int pop(struct stack*, int*);
int isEmpty(struct stack*);
int isFull(struct stack*);
int peek(struct stack*, int*);