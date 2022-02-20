#include "definition.c"

int main(){
    struct node* tail;
    init(&tail);
    printf("%d\n", isEmpty(tail));
    for(int i = 1; i < 6; i++){
        enqueue(&tail,i);
    }

    int ptr = 0;
    getFront(tail, &ptr);
    printf("%d\n", ptr);
    getRear(tail, &ptr);
    printf("%d\n",ptr);
    while(!isEmpty(tail)){
         dequeue(&tail,&ptr);
         printf("%d ", ptr);
    }
    printf("\n");
    printf("%d\n", destroy(&tail));
    return 0;
}