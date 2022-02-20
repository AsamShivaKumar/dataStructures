#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct queue{
    int arr[SIZE];
    int /*front,*/rear;
};

int init(struct queue**);
int isEmpty(struct queue*);
int isFull(struct queue*);
int getFront(struct queue*, int*);
int getRear(struct queue*,int*);
int enqueue(struct queue*, int);
int dequeue(struct queue*,int*);
int destroy(struct queue**);