#include "definition.c"

int main(){
    struct node* tail;
    init(&tail);
    for(int i = 1; i < 6; i++){
        insertAfterElement(&tail, i-1, i);
    }

    traverse(tail);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    searchElement(tail,3, &temp);
    printf("%d\n", temp->data);
    printf("%d\n",destory(&tail));
    return 0;
}