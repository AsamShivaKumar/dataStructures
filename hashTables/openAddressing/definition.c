#include "declaration.h"

int init(struct hashTable** h){
    *h = (struct hashTable*)malloc(sizeof(struct hashTable));
    if(!(*h)) return 0;

    for(int i = 0; i < N; i++) (*h)->arr[i] = -1;
    (*h)->n = 0;
    return 1;
}

int hash(int key){
    return (key % N);
}

int flinear(int i){
    return (i*5 + 7);
}

int fqua(int i){
    return (5*i*i + 3*i + 1);
}

int dhash(int key){
    return (7 - key%7);
}

int fd(int i, int key){
    return i*dhash(key);
}

int insertl(struct hashTable* h, int key){
    if(h->n == N) return 0;
    int hval = hash(key);
    int i = 0;
    
    int ind = (hval + flinear(i))%N;

    while(h->arr[ind] != -1){
        i++;
        ind  = (hval + flinear(i))%N;
        if(i == N) break;
    }

    if(i != N){
        h->arr[ind] = key;
        h->n++;
        return 1;
    }

    return 0;
}
int insertq(struct hashTable* h, int key){
    if(h->n == N) return 0;
    int hval = hash(key);
    int i = 0;
    
    int ind = (hval + fqua(i))%N;

    while(h->arr[ind] != -1){
        i++;
        ind  = (hval + fqua(i))%N;
        if(i == N) break;
    }

    if(i != N){
        h->arr[ind] = key;
        h->n++;
        return 1;
    }
    
    return 0;
}
int insertd(struct hashTable* h, int key){
    if(h->n == N) return 0;
    

    int hval = hash(key);
    int i = 0;
    
    int ind = (hval + fd(i,key))%N;

    while(h->arr[ind] != -1){
        i++;
        ind  = (hval + fd(i,key))%N;
        if(i == N) break;
    }

    if(i != N){
        h->arr[ind] = key;
        h->n++;
        return 1;
    }
    
    return 0;

}