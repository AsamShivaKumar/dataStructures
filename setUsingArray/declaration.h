#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

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
int print(struct set*);
int printSorted(struct set*);
int destroy(struct set**);
