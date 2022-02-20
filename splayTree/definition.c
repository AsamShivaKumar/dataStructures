#include "declaration.h"

node* leftRotate(node* root){
      if(!root) return NULL;
      
      node* temp = root->right;
      root->right = temp->left;
      temp->left = root;

      return temp;
}

node* rightRotate(node* root){
      if(!root) return NULL;
      
      node* temp = root->left;
      root->left = temp->right;
      temp->right = root;

      return temp;
}
node* insertNode(node* root, int key){
    //   printf("%d\n",key);
      if(!root){
          node* newNode = (node*)malloc(sizeof(node));
          newNode->data = key; newNode->left = NULL; newNode->right = NULL;
          return newNode;
      }
     
     if(root->data > key){
         root->left = insertNode(root->left,key);
     }else if(root->data < key){
         root->right = insertNode(root->right,key);
     }else{
         return root;
     }
    return splay(root,key);
} 

node* searchNode(node* root,int key){
      return splay(root,key);
}

node* splay(node* root, int key){
      if(!root || root->data == key) return root;

      if(root->data > key){
          // key may be present in the left sub-tree
          if(root->left == NULL) return root;
          if(root->left->data > key){
              // zig-zig case
              root->left->left = splay(root->left->left,key);
              root = rightRotate(root);
          }else if(root->left->data < key){
              // zag-zig case
              root->left->right = splay(root->left->right,key);
              if(root->left->right) root->left = leftRotate(root->left);
          }
          return root->left? rightRotate(root) : root;
      }else{
          // key may be present in the right sub-tree
          if(root->right == NULL) return root;

          if(root->right->data > key){
              // zag zag
              root->right->right = splay(root->right->right,key);
              root = leftRotate(root);
          }else if(root->right->data < key){
              // zig-zag
              root->right->left = splay(root->right->left,key);
              if(root->right->left) root->right = rightRotate(root->right);
          }

          return root->right? leftRotate(root) : root;
      }
}

node* deleteNode(node* root, int del){
      if(!root) return NULL;

    //   root = splay(root,key);

    //   if(root->data != key) return root;

    //   if(!root->left && !root->right){
    //       free(root);
    //       return NULL;
    //   }else if(!root->left && root->right){
    //       free(root);
    //       return root->right;
    //   }else if(root->left && !root->right){
    //       free(root);
    //       return root->left;
    //   }else{
    //       node* temp = root->left;
    //       while(temp->left->right) temp = temp->right;
    //       root->data = temp->data;
    //       root->left = deleteNode(root->left,temp->data);
    //       return root;
    //   }

     if(root->data > del){
               root->left = deleteNode(root->left, del);
       }else if(root->data < del){
               root->right = deleteNode(root->right, del);           
       }else{
           if(root->left == NULL && root->right == NULL){
               free(root);
               root = NULL;
           }else if(root->left == NULL){
               struct node* temp = root;
               root = root->right;
               free(temp);
           }else if(root->right == NULL){
               struct node* temp = root;
               root = root->left;
               free(temp);
           }else{
               struct node* temp = root->left;
               while(temp->right) temp = temp->right;
               root->data = temp->data;
               root->left = deleteNode(root->left,temp->data);
           }
       }
    return splay(root,del);
}