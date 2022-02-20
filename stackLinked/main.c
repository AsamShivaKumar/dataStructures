#include <stdio.h>
#include "declaration.h"
#include "definition.c"

int main(){
    struct stack* s;
    init(&s);
    char* ch = (char*)malloc(1);
    push(s,'a');
    push(s,'b');
    push(s,'c');
    push(s,'d');
    while(!isEmpty(s)){
        pop(s,ch);
        printf("%c ", *ch);
    }
    printf("\n");
    printf("%d\n",clear(&s));
    return 0;
}