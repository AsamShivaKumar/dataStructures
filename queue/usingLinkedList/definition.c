#include "declaration.h"

int init(struct queue** qPtrPtr){
    *qPtrPtr = (struct queue*)malloc(sizeof(struct queue));
    if(*qPtrPtr == NULL) return 0;

    (*qPtrPtr)->head = NULL;
    (*qPtrPtr)->tail = NULL;
    return 1;
}

int isEmpty(struct queue* qPtr){
    return qPtr->head == NULL;
}

int getFront(struct queue* qPtr, int* ptr){
    if(isEmpty(qPtr)) return 0;
    *ptr = qPtr->head->data;
    return 1;
}
int getRear(struct queue* qPtr, int* ptr){
    if(isEmpty(qPtr)) return 0;
    *ptr = qPtr->tail->data;
    return 1;
}

int enqueue(struct queue* qPtr, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) return 0;
    temp->data = data;
    if(qPtr->tail == NULL){
       qPtr->head = qPtr->tail = temp;
       return 1;
    }
    if(qPtr->head == qPtr->tail){
        qPtr->head->next = temp;
        qPtr->tail = temp;
        return 1;
    }
    qPtr->tail->next = temp;
    qPtr->tail = temp;
    return 1;
}
int dequeue(struct queue* qPtr, int* ptr){
    if(isEmpty(qPtr)) return 0;
    *ptr = qPtr->head->data;
    if(qPtr->head == qPtr->tail){
        qPtr->head = qPtr->tail = NULL;
        return 1;
    }
    struct node* temp = qPtr->head;
    qPtr->head = qPtr->head->next;
    free(temp);
    return 1;
}
int destroy(struct queue** qPtrPtr){
    int* ptr = (int*)malloc(sizeof(int));
    while(!isEmpty(*qPtrPtr)){
        dequeue(*qPtrPtr,ptr);
    }
    free(*qPtrPtr);
    *qPtrPtr = NULL;
    free(ptr);
    return 1;
}
