#include <stdio.h>
#include <stdlib.h>

struct element{
       int ele;
       struct set* setPtr;
       struct element* next;
};

struct set{
       int setID;
       struct element* ptr;
};

int find(struct element*, struct set**);
int merge(struct set*,struct set*);