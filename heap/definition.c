#include "declaration.h"

void swap(int* arr, int i, int j){
     int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
}

int init(struct heap** h){
    *h = (struct heap*)malloc(sizeof(struct heap));
    if(!(*h)) return 0;

    (*h)->heapSize = 0;
    for(int i = 0; i < 1000; i++) (*h)->arr[i] = 0;
    return 1;
}

int maxHeapify(int* arr, int pos, int size){
    
    int max = pos;
    int l = pos*2;
    int r = pos*2+1;
    
    if(l > size || r > size || max > size) return 0;

    if(arr[pos] < arr[l]) max = l;
    if(arr[max] < arr[r]) max = r;
    if(max != pos){
        swap(arr,pos,max);
        maxHeapify(arr,max,size);
    }

    return 1;
}

int findMax(struct heap* h, int* max){
    if(h->heapSize == 0) return 0;
    
    *max = h->arr[1];
    return 1;
}

int extractMax(struct heap* h, int* max){
    if(h->heapSize == 0) return 0;

    *max = h->arr[1];
    h->arr[1] = h->arr[h->heapSize];
    h->heapSize--;
    maxHeapify(h->arr,1,h->heapSize);
    return 1;
}

int increaseKey(struct heap* h, int pos, int newKey){
    if(pos > h->heapSize || h->arr[pos] > newKey) return 0;

    h->arr[pos] = newKey;
    while(pos > 1 && h->arr[pos] > h->arr[pos/2]){
        swap(h->arr,pos,pos/2);
        pos /= 2;
    }
    return 1;
}

int insert(struct heap* h, int element){
    if(h->heapSize == SIZE-1) return 0;
    h->heapSize++;
    h->arr[h->heapSize] = -INFINITY;
    return increaseKey(h,h->heapSize,element);
}

int deleteNode(struct heap* h, int pos){
    if(h->heapSize == 0) return 0;
    increaseKey(h,pos,INFINITY);
    int ptr = 0;
    extractMax(h,&ptr);
    return 1;
}
int* heapSort(struct heap* h){
    if(h->heapSize == 0) return 0;
    int* a = (int*)malloc(sizeof(int)*(h->heapSize+1));
    
    for(int i = 1; i <= h->heapSize; i++){
        a[i] = h->arr[i];
    }
    
    int num = h->heapSize;

    while(num > 0){
        swap(a,1,num);
        num--;
        maxHeapify(a,1,num);
    }    

    return a;
}
