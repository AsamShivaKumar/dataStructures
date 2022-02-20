#include "definition.c"

int main(){
    struct graph* g;
    initG(&g,4);
    addEdge(g,0,1);
    addEdge(g,1,2);
    addEdge(g,2,0);
    addEdge(g,1,3);
    addEdge(g,2,3);
    bfs(g);
    dfs(g);
    return 0;
}