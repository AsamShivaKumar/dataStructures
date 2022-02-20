#include <stdio.h>
#include <stdlib.h>

struct node;
struct stack;

int init(struct stack**);
int isEmpty(struct stack*);
int push(struct stack*, char);
int pop(struct stack*,char*);
int peek(struct stack*,char*);
int clear(struct stack**);
