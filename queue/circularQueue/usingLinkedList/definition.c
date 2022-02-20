#include "declaration.h"

int init(struct node** tail){
    *tail = (struct node*)malloc(sizeof(struct node));
    if(!(*tail)) return 0;
    *tail = NULL;
    return 1;
}

int isEmpty(struct node* tail){
    return tail == NULL;
}

int enqueue(struct node** tail, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(!newNode) return 0;
    newNode->data = data;
    if(!(*tail)){
        newNode->next = newNode;
        *tail = newNode;
    }
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    *tail = newNode;
    return 1;
}

int dequeue(struct node** tail, int* ptr){
    if(isEmpty(*tail)) return 0;
    struct node* temp = (*tail)->next;
    if(*tail == (*tail)->next){
        *tail = NULL;
         *ptr = temp->data;
         free(temp);
         return 1;
    }
    (*tail)->next = temp->next;
    *ptr = temp->data;
    free(temp);
    return 1;
}

int getFront(struct node* tail, int* ptr){
    if(isEmpty(tail)) return 0;
    *ptr = tail->next->data;
    return 1;
}
int getRear(struct node* tail, int* ptr){
    if(isEmpty(tail)) return 0;
    *ptr = tail->data;
    return 1;
}
int destroy(struct node** tail){
    if(isEmpty(*tail)) return 1;
    int* pt = (int*)malloc(sizeof(int));
    while(!isEmpty(*tail)){
         dequeue(tail, pt);
    }
    free(pt);
    free(*tail);
    *tail = NULL;
    return 1;
}