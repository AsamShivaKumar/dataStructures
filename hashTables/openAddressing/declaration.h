#include <stdio.h>
#include <stdlib.h>

#define N 11

struct hashTable{
       int arr[N];
       int n;
};

int init(struct hashTable**);
int insertl(struct hashTable*, int);
int insertq(struct hashTable*, int);
int insertd(struct hashTable*, int);
int hash(int);
int flinear(int);
int fqua(int);
int dhash(int);
