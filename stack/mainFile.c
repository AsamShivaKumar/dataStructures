#include "declaration.h"
#include "definition.c"
#include <stdio.h>

int main(){
    struct stack* s;
    init(&s);
    for(int i = 1; i < 6; i++){
        push(s,i);
    }
    int *p = (int*)malloc(sizeof(int));
    peek(s,p);
    printf("%d\n",*p);
    while(!isEmpty(s)){
        pop(s, p);
        printf("%d ",*p);
    }
    printf("\n");
    printf("%d\n",isFull(s));
    printf("%d\n", clear(&s));
    return 0;
}