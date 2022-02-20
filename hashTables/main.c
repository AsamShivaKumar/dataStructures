#include "definition.c"

int main(){
    struct hashTable* h;
    init(&h);
    printf("%d\n", hasKey(h,5));
    insert(h,2);
    insert(h,24);
    insert(h,35);
    printf("%d\n", hasKey(h,24));
    printf("%d\n", hasKey(h,35));
}