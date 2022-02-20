#include "declaration.h"

int init(struct queue** que){
    *que = (struct queue*)malloc(sizeof(struct queue));
    if(!(*que)) return 0;
    (*que)->front = -1;
    (*que)->rear = -1;
    return 1;
}
int isEmpty(struct queue* que){
    return que->rear == -1;
}

int isFull(struct queue* que){
    if(que->rear == SIZE-1 && que->front == 0){           //
        return 1;                                         //       if(que->front == (que->rear + 1) % SIZE)
    }else if(que->rear == que->front-1){                  //     
        return 1;                                         //
    }else{
        return 0;
    }
}

int enqueue(struct queue* que, int data){
    if(isFull(que)) return 0;
    que->rear = (que->rear + 1)%SIZE;
    que->arr[que->rear] = data;
    if(que->front == -1){
        que->front++;
    }
    return 1;
}

int dequeue(struct queue* que, int* ptr){
    if(isEmpty(que)) return 0;
    *ptr = que->arr[que->front];
     if(que->front == que->rear){
         que->front = -1;
         que->rear = -1;
         return 1;
     }
     que->front = (que->front + 1)%SIZE;     
     return 1;
}

int getRear(struct queue* que, int* ptr){
    if(isEmpty(que)) return 0;
    *ptr = que->arr[que->rear];
    return 1;
}
int getFront(struct queue* que, int* ptr){
    if(isEmpty(que)) return 0;
    *ptr = que->arr[que->front];
    return 1;
}
int destroy(struct queue** que){
    if(isEmpty(*que)) return 1;
    free(*que);
    *que = NULL;
    return 1;
}