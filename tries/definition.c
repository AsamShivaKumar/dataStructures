#include "declaration.h"

void nodeInit(struct trieNode** n){
     *n = (struct trieNode*)malloc(sizeof(struct trieNode));
     for(int i = 0; i < 26; i++){
        (*n)->alpha[i] = NULL;
     }
     (*n)->flag = 0;
}

int init(struct trieNode** root){
    nodeInit(root);
    return 1;
}

int insert(struct trieNode* root, char* str){
    
    struct trieNode* temp = root;

    for(char* c = str; *c != '\0'; c++){
        if(!(temp->alpha[*c - 'a'])){
            struct trieNode* newNode;
            nodeInit(&newNode);
            temp->alpha[*c - 'a'] = newNode;
        }  
        temp = temp->alpha[*c - 'a'];
        if(*(c+1) == '\0') temp->flag = 1;
    }
    return 1;
}

int search(struct trieNode* root, char* str){

    struct trieNode* temp = root;

    for(char* c = str; *c != '\0'; c++){
        if(!(temp->alpha[*c - 'a'])) return 0;
        temp = temp->alpha[*c - 'a'];
        if(*(c+1) == '\0' && !temp->flag) return 0;
    }
    return 1;
}
