#include "declaration.h"
#include "D:\cppFiles\dataStructuresImplementation\queue\usingArray\definition.c"

int initG(struct graph** g, int v){
    *g = (struct graph*)malloc(sizeof(struct graph));
    if(!(*g)) return 0;
    // (*g)->adj = (struct node*)malloc(sizeof(struct node)*v);
    for(int i = 0; i < v; i++){
        (*g)->adj[i] = (struct node*)malloc(sizeof(struct node));
        (*g)->adj[i] = NULL;
    }
    (*g)->v = v;
    return 1;
}

int addEdge(struct graph* g, int u, int v){
    struct node* e1 = (struct node*)malloc(sizeof(struct node));
    e1->data = u;
    struct node* e2 = (struct node*)malloc(sizeof(struct node));
    e2->data = v;
    e1->next = g->adj[v];
    g->adj[v] = e1;
    e2->next = g->adj[u];
    g->adj[u] = e2;
    return 1;
}

void bfs(struct graph* g){
     struct queue* q;
     init(&q);
     enqueue(q,0);
     int* visited = (int*)malloc(sizeof(int)*(g->v));
     int curr = 0;
     for(int i = 0; i < g->v; i++){
         visited[i] = 0;
     }
     while(!isEmpty(q)){    
         dequeue(q,&curr);
         if(visited[curr] != 1){
         printf("%d, ", curr);
         visited[curr] = 1;
         struct node* itr = g->adj[curr];
         while(itr){
             if(!visited[itr->data])enqueue(q,itr->data);
             itr = itr->next;
         }         
       }
     }
     printf("\n");
     destroy(&q);
     free(visited);
}

void dfsUtil(struct graph* g, int v, int* visited){
     if(visited[v]) return;
     visited[v] = 1;
     printf("%d, ", v);
     struct node* itr = g->adj[v];
     
     while(itr){
          dfsUtil(g,itr->data,visited);
          itr = itr->next;
     }
}

void dfs(struct graph* g){
     int* visited = (int*)malloc(sizeof(int)*(g->v));
     for(int i = 0; i < g->v; i++){
         visited[i] = 0;
     }

     for(int i = 0; i < g->v; i++){
         dfsUtil(g,i,visited);
     }
     printf("\n");
}

