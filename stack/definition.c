#include "declaration.h"

struct stack{
    int arr[SIZE];
    int top;
};

int init(struct stack** s){
    *s = (struct stack*)malloc(sizeof(struct stack));
    if(*s == NULL)return 0;
    (*s)->top = -1;
    return 1;
}
int push(struct stack* s, int data){
    if(isFull(s)) return 0;
    s->top = s->top+1;
    s->arr[s->top] = data;
    return 1;
}

int isEmpty(struct stack* s){
    return s->top == -1;
}
int isFull(struct stack* s){
    return s->top == SIZE-1;
}
int pop(struct stack* s, int* ptr){
    if(isEmpty(s)) return 0;
    *ptr = s->arr[s->top];
    s->top = s->top-1;
    return 1;
}
int peek(struct stack* s, int* ptr){
    if(isEmpty(s)) return 0;
    *ptr = s->arr[s->top];
    return 1;
}
int clear(struct stack** s){
    // top = -1;
    free(*s);
    *s = NULL;
    return 1;
}