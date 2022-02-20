#include "definition.c"

int main(){
    struct queue* que;
    init(&que);

    for(int i = 1; i <= 5; i++){
        enqueue(que,i);
    }
    int ptr = 0;
    getRear(que, &ptr);
    printf("%d\n", ptr);
    getFront(que, &ptr);
    printf("%d\n", ptr);
    dequeue(que, &ptr);
    dequeue(que, &ptr);
    enqueue(que, 10);
    enqueue(que, 14);
    while(!isEmpty(que)){
         dequeue(que, &ptr);
         printf("%d ", ptr);
    }
    printf("\n");
    return 0;
}