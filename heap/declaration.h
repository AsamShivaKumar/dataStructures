// Max Heap

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

struct heap{
       int arr[SIZE];
       int heapSize;
};


int init(struct heap**);
void swap(int[],int,int);
int maxHeapify(int*,int,int);
int findMax(struct heap*,int*);
int extractMax(struct heap*, int*);
int insert(struct heap*, int);
int deleteNode(struct heap*, int);
int increaseKey(struct heap*,int,int);
int* heapSort(struct heap*);
