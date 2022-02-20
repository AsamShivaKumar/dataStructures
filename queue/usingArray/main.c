#include "definition.c"

int main(){
    struct queue* q;
    init(&q);
    printf("%d\n",isEmpty(q));
    for(int i = 1; i < 6; i++){
        enqueue(q,i);
    }
    int* ptr = (int*)malloc(sizeof(int));
    getFront(q,ptr);
    printf("%d\n",*ptr);
    getRear(q,ptr);
    printf("%d\n",*ptr);
    while(!isEmpty(q)){
        dequeue(q,ptr);
        printf("%d ", *ptr);
    }
    printf("\n");
    printf("%d\n", destroy(&q));
    return 0;
}