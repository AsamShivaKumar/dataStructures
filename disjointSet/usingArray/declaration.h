#include <stdio.h>
#include <stdlib.h>

struct set{
       int* arr;
       int n;
};

int init(struct set**, int);
int findParent(struct set*,int);
int setUnion(struct set*,int,int);
