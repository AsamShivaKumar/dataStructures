#include "declaration.h"

int init(struct queue** qPtrPtr){
    *qPtrPtr = (struct queue*)malloc(sizeof(struct queue)); 
    if(*qPtrPtr == NULL) return 0;
    (*qPtrPtr)->rear = -1;
    // (*qPtrPtr)->front = -1;
    return 1;
}
int isEmpty(struct queue* qPtr){
    return qPtr->rear == -1;
}

int isFull(struct queue* qPtr){
    return qPtr->rear == SIZE;
}
int getFront(struct queue* qPtr, int* ptr){
    if(isEmpty(qPtr)) return 0;
    *ptr = qPtr->arr[0];
    return 1;
}
int getRear(struct queue* qPtr, int* ptr){
    if(isEmpty(qPtr)) return 0;
    *ptr = qPtr->arr[qPtr->rear];
    return 1;
}

int enqueue(struct queue* qPtr, int data){
    if(isFull(qPtr)) return 0;
    qPtr->rear++;
    qPtr->arr[qPtr->rear] = data;
    return 1;
}
int dequeue(struct queue* qPtr,int* ptr){
    if(isEmpty(qPtr)) return 0;
    *ptr = qPtr->arr[0];
    for(int i = 0; i < qPtr->rear; i++){
        qPtr->arr[i] = qPtr->arr[i+1];
    }
    qPtr->rear--;
    return 1;
}

int destroy(struct queue** qPtrPtr){
    free(*qPtrPtr);
    *qPtrPtr = NULL;
    return 1;
}