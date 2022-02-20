#include "definition.c"

int main(){
    struct set* s;
    init(&s,10);
    printf("%d\n", find(s,5));

    setUnion(s,2,5);
    setUnion(s,2,3);
    setUnion(s,1,6);
    setUnion(s,1,7);
    setUnion(s,1,8);
    printf("%d\n", find(s,5));
    setUnion(s,1,2);
    printf("%d\n", find(s,5));
    for(int i = 0; i <= s->n; i++) printf("%d * ", s->arr[i]);
    return 0;
}