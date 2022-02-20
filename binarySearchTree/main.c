#include "definition.c"

int main(){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    insertNode(&root,20);
    insertNode(&root,15);
    insertNode(&root,17);
    insertNode(&root,12);
    insertNode(&root,35);
    insertNode(&root,25);
    insertNode(&root,25);
    insertNode(&root,40);
    printf("Success\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    
    //17 is a leaf node
    deleteNode(&root, 17);
    inOrder(root);
    printf("\n");
    
    //20 is the root node
    deleteNode(&root,20);
    inOrder(root);
    printf("\n");

    // 15 has a non-null left child but right child is null
    deleteNode(&root,15);
    inOrder(root);
    printf("\n");

    destroy(&root);
    inOrder(root);
    printf("\n");
    return 0;
}