#include "declaration.h"
#include <stdlib.h>
struct node{
       char data;
       struct node* next;
};
struct stack{
       struct node* head;
};

int init(struct stack** s){
    *s = (struct stack*)malloc(sizeof(struct stack));
    if(*s == NULL) return 0;
    (*s)->head = NULL;
    return 1;
}

int isEmpty(struct stack* s){
     return s->head == NULL;
}

int push(struct stack* s, char data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if(new == NULL) return 0;
    new->data = data;
    new->next = s->head;
    s->head = new;
    return 1;
}
int pop(struct stack* s, char* ptr){
    if(isEmpty(s)) return 0;
    struct node* temp = NULL;
    *ptr = s->head->data;
    temp = s->head;
    s->head = s->head->next;
    free(temp);
    return 1;
}

int peek(struct stack* s, char* ptr){
    if(isEmpty(s)) return 0;
    *ptr = s->head->data;
    return 1;
}

int clear(struct stack** s){
    if(isEmpty(*s)) return 0;
    char* p = NULL;
    while(!isEmpty(*s)){
         pop(*s,p);
    }
    free(*s);
    *s = NULL;
    return 1;
}