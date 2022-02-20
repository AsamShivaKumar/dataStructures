#include "definition.c"

int main(){
    struct list* ll;
    printf("%d\n",init(&ll));
    for(int i = 1; i < 6; i++){
        insertElement(ll,i,i);
    }
    printf("%d\n",delElement(ll, 2));
    clear(&ll);
    return 0;
}