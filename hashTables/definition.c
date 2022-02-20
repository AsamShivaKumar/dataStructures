#include "declaration.h"

int init(struct hashTable** h){
    *h = (struct hashTable*)malloc(sizeof(struct hashTable));
    if(!(*h)) return 0;
    for(int i = 0; i < N; i++){
        (*h)->arr[i] = NULL;
    }
    return 1;
}

int hash(int key){
    return (key % N);
}

int hasKey(struct hashTable* h, int key){
    int hval = hash(key);
    struct node* temp = h->arr[hval];
    while(temp){
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

int insert(struct hashTable* h,int key){
    if(hasKey(h,key)) return 0;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    int hval = hash(key);
    newNode->next = h->arr[hval];
    h->arr[hval] = newNode;
    return 1;
}