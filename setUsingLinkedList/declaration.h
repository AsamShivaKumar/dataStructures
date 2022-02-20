#include <stdio.h>
#include <stdlib.h>

struct node;
struct set;

int init(struct set**);
int isEmpty(struct set*);
int isSingleton(struct set*);
int isMember(struct set*, int);
int addElement(struct set*, int);
int delElement(struct set*,int);
int unionUV(struct set*, struct set*, struct set*);
int intersectUV(struct set*, struct set*, struct set*);
int difference(struct set*, struct set*, struct set*);
int symDifUV(struct set*, struct set*, struct set*);
void print(struct set*);
void printSorted(struct set*);
int destroy(struct set**);
