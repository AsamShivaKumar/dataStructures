// Undirected graph

#include <stdio.h>
#include <stdlib.h>

struct node{
       int data;
       struct node* next;
};

struct graph{
       struct node** adj; 
       int v;
};

int initG(struct graph**,int);
int addEdge(struct graph*,int,int);
void bfs(struct graph*);
void dfs(struct graph*);