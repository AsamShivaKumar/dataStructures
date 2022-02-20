#include "definition.c"

void searchPath(struct node*,int,int);
int path(struct node*,int,int);
void searchP(struct node*,int);

int main(){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    int arr[] = {20,10,50,9,18,40,60,8,12};
    for(int i = 0; i < 9; i++){
        insertNode(&root,arr[i]);
    }                                                                  //            20
    inOrder(root);                                        //              10                     50
    printf("\n");                                         //         9         18           40       60
    path(root,9,60);                                      //      8          12
    path(root,8,18);
    path(root,40,60);
    path(root,20,8);
    return 0;
}

int path(struct node* root, int a, int b){
    if(root){
        
        if(searchNode(root->left,a) && searchNode(root->right,b)){
            searchPath(root,a,b);
        }else if(searchNode(root->left,b) && searchNode(root->right,a)){
            searchPath(root,b,a);
        }else if(searchNode(root->left,b) && searchNode(root->left,a)){
            path(root->left,a,b);
        }else if(searchNode(root->right,b) && searchNode(root->right,a)){
            path(root->right,a,b);
        }else{
            if(root->data == a){
                searchP(root,b);
            }else{
                searchP(root,a);
            }
            printf("\n");
        }
        return 1;
    }
    return 0;
}

void searchPath(struct node* root, int a, int b){
    int* ptr = (int*)malloc(sizeof(int));
            int i = 0;
            struct node* itr = root->left;
            while(itr){
                ptr[i] = itr->data;
                if(itr->data == a){
                    break;
                }else if(itr->data > a){
                    itr = itr->left;
                }else{                   
                    itr = itr->right;
                }
                i++;
            }
            for(int j = i; j >= 0; j--){
                printf("%d, ", ptr[j]);
            }
            printf("%d, ", root->data);
            itr = root->right;
            while(itr){
                 printf("%d, ", itr->data);
                 if(itr->data == b){
                     break;
                 }else if(itr->data > b){
                     itr = itr->left;
                 }else{
                     itr = itr->right;
                 }
            }
            printf("\n");
}

void searchP(struct node* root, int x){
     if(!root) return;
     
     printf("%d, ", root->data);
     if(root->data == x){ 
        return;
    }else if(root->data > x){
        searchP(root->left, x);
    }else{
        searchP(root->right, x);
    }
}