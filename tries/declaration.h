#include <stdio.h>
#include <stdlib.h>

struct trieNode{
       int flag;
       struct trieNode* alpha[26];
};

int init(struct trieNode**);
int insert(struct trieNode*, char*);
int search(struct trieNode*, char*);