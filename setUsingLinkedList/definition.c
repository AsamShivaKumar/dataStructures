#include "declaration.h"

struct node{
    int data;
    struct node* next;
};

struct set{
       int length;
       struct node* top;     
};

int init(Struct set** s){
    *s = (struct set*)malloc(struct set);
    if(*s == NULL) return 0;
    top = NULL;
    length = 0;
    return 1;
}
int isEmpty(struct set* s){
    return s->length == 0;
}
int isSingleton(struct set* s){
    return s->length == 1;
}
int isMemeber(struct set* s, int x){
    if(isEmpty(s)) return 0;
    struct node* temp = s->top;
    while(temp != NULL && temp->data != x) temp = temp->next;
    if(temp == NULL) return 0;
    return 1;
}
int addElement(struct set* s, int e){
    if(isMember(s,e)) return 0;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = e;
    newNode->next = s->top;
    s->top = newNode;
    s->length++;
    free(newNode);
    return 1;
}
int delElement(struct set* s, int del){
    if(isEmpty(s)) return 0;
    struct node* itr = s->top;
    if(itr->next == NULL){
        if(itr->data = del){
            free(itr);
            s->top = NULL;
            return 1;
        }else{
            return 0;
        }
    }
    while(itr->next != NULL && itr->next->data != del) itr = itr->next;
    if(itr->next == NULL) return 0;
    struct node* temp = itr->next;
    itr->next = itr->next->next;
    free(temp);
    return 1;
}
int unionUV(struct set* s, struct set* u, struct set* v){
    if(isEmpty(u) || isEmpty(v)) return 0;
    struct node* itr = u->top;
    while(itr != NULL) addElement(s, itr->data);
    itr = v->top;
    while(itr != NULL) addElement(s, itr->data);
    return 1;
}
int intersectUV(struct set* s, struct set* u, struct set* v){
    if(isEmpty(u) || isEmpty(v)) return 0;
    struct node* itr = u->top;
    while(itr != NULL){
        if(isMember(v, itr->data)) addElement(s,itr->data);
        itr = itr->next;
    }
    return 1;
}
int difference(struct set* s, struct set* u, struct set* v){
    if(isEmpty(u)) return 0;
    struct node* itr = u->top;
    while(itr != NULL){
        if(!isMember(v, itr->data)) addElement(s,itr->data);
        itr = itr->next;
    }
    return 1;
}
int symDifUV(Struct set* s, struct set* u, struct set* v){
    if(isEmpty(u)) return 0;
    struct node* itr = u->top;
    while(itr != NULL){
        if(!isMember(v, itr->data)) addElement(s,itr->data);
        itr = itr->next;
    }
    itr = v->top;
    while(itr != NULL){
        if(!isMember(u, itr->data)) addElement(s,itr->data);
        itr = itr->next;
    }
    return 1;
}
void print(struct set* s){
    struct node* itr = s->top;
    while(itr != NULL){
         printf("%d ", itr->data);
    }
}
void printSorted(struct set* s){
    struct node* itr = s->top;
    int a[length];
    for(int i = 0; i < length && itr == NULL; i++){
        a[i] = itr->data;
        itr = itr->next;  
    } 
    for(int i = 0; i < length-1; i++){
        int min = i;
        for(int j = i+1; j < length; j++){
            if(a[min] > a[j]) min = j;
        }
        if(min != j){
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    for(int i = 0; i < length; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int destroy(struct set** s){
    free((*s)->top);
    free(*s);
    *s = NULL;
    return 1;
}