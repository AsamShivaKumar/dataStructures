#include "header.h"

int insertNode(struct node** root, int data){
    if(!(*root)){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if(!newNode) return 0;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
        return 1;
    }

    if((*root)->data == data){
        return 0;
    }else if((*root)->data > data){
        return insertNode(&((*root)->left), data);
    }else{
        return insertNode(&((*root)->right), data);
    }
}

int searchNode(struct node* root, int data){
    if(!root) return 0;

    if(root->data == data){
        return 1;
    }else if(root->data > data){
        return searchNode(root->left, data);
    }else{
        return searchNode(root->right, data);
    }
    return 0;
}

int deleteNode(struct node** root, int data){
    if(!(*root)) return 0;

    // struct node* temp = *root;

    if((*root)->data == data){
        if((*root)->left == NULL && (*root)->right == NULL){       //
            free(*root);                                           //
            *root = NULL;                                          //
        }else if((*root)->left == NULL){                           //
            struct node* temp = *root;                             
            *root = (*root)->right;
            free(temp);
        }else if((*root)->right == NULL){
            struct node* temp = *root;
            *root = (*root)->left;
            free(temp);
        }else{
            struct node* temp = (*root)->left;
            while(temp->right) temp = temp->right;
            (*root)->data = temp->data;
            deleteNode(&((*root)->left), temp->data);
            // free(temp);
            // temp = NULL;
            // (*root)->data = del;
        }
        return 1;
    }else if((*root)->data > data){
        return deleteNode(&(*root)->left,data);
    }else{
        return deleteNode(&(*root)->right,data);
    }
}

int preOrder(struct node* root){
    if(!root) return 0;
    
    printf("%d, ", root->data);
    preOrder(root->left);
    preOrder(root->right);
    return 1;
}

int inOrder(struct node* root){
    if(!root) return 0;

    inOrder(root->left);
    printf("%d, ", root->data);
    inOrder(root->right);
    return 1;
}

int postOrder(struct node* root){
    if(!root) return 0;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d, ", root->data);
    return 1;
}

int destroy(struct node** root){
    if(*root){
        destroy(&((*root)->left));
        destroy(&((*root)->right));
        deleteNode(root, (*root)->data);
        *root = NULL;
    }
    return 1;
}
