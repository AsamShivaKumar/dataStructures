#include "declaration.h"

int init(struct set** s, int n){
    *s = (struct set*)malloc(sizeof(struct set));
    if(!(*s)) return 0;
    (*s)->arr = (int*)malloc(sizeof(int)*(n+1));
    for(int i = 1; i <= n; i++) (*s)->arr[i] = -1;
    (*s)->arr[0] = 0;
    (*s)->n = n;
    return 1;
}

int find(struct set* s, int e){
    if(s->arr[e] < 0) return e;
    int parent = find(s,s->arr[e]);
    s->arr[e] = parent;
    return parent;
}

int setUnion(struct set* s, int i, int j){
    if(i > s->n || j > s->n || s->arr[i] >= 0 || s->arr[j] >= 0) return 0;

    if(abs(s->arr[j]) > abs(s->arr[i])){
          s->arr[j] += s->arr[i];
          s->arr[i] = j;
    }else{
         s->arr[i] += s->arr[j];
         s->arr[j] = i;
    }

    return 1;   

}