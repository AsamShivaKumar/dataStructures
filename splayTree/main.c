#include "definition.c"

void inOrder(node* root){
     if(!root) return;
     inOrder(root->left);
     printf("%d, ", root->data);
     inOrder(root->right);
}

int main(){
    node* root = (node*)malloc(sizeof(node));
    root = NULL;
    
    int arr[] = {20,70,40,30,10,15,80};

    for(int i = 0; i < 7; i++){
        root = insertNode(root,arr[i]);
    }
    printf("%d\n", root->data);

    inOrder(root);
    printf("\n");

    root = deleteNode(root,80);
    inOrder(root);
    printf("\n");

    root = deleteNode(root,15);
    inOrder(root);
    printf("\n");

    return 0;
}