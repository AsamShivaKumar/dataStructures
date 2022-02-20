#include <stdio.h>
#include <stdlib.h>

#define N 11

struct node{
       int data;
       struct node* next;
};

struct hashTable{
       struct node* arr[N];
};

int init(struct hashTable**);
int hash(int);
int hasKey(struct hashTable*,int);
int insert(struct hashTable*,int);