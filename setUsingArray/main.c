#include "declaration.h"
#include "definition.c"

int main(){
    struct set* s = (struct set*)malloc(sizeof(struct set));
    printf("%d\n",init(&s));
    addElement(s,2);
    for(int i = 1; i < 6; i++){
        addElement(s,i);
    }
    print(s);
    delElement(s,2);
    printf("%d\n",s->length);
    printSorted(s);
    return 0;
}