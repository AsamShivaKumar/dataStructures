#include "definition.c"

int main(){
    struct hashTable* h1;
    init(&h1);
    
    insertl(h1,23);
    insertl(h1,97);
    insertl(h1,86);
    insertl(h1,12);
    printf("%d\n",insertl(h1,119));
    printf("%d\n",insertl(h1,45));
    printf("%d\n",insertl(h1,133));
    printf("%d\n",insertl(h1,67));
    
    printf("%d\n",insertl(h1,45));
    insertl(h1,34);
    insertl(h1,100);
    insertl(h1,122);


    printf("\n");

    for(int i = 0; i < N; i++){
       printf("%d ", h1->arr[i]);
    }
    printf("\n");

    return 0;
}