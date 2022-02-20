#include "declaration.h"

int find(struct element* ele, struct set** set){
    if(!ele) return 0;
    *set = ele->setPtr;
    return 1;
}

int merge(struct set* s1, struct set* s2){
    struct set *min,*max;
    if(s1->setID > s2->setID){
        min = s2; 
        max = s1;
    }else{
        min = s1; 
        max = s2;
    }
    
    struct element* temp = max->ptr;

    while(temp){
        temp->setPtr = min;
        temp = temp->next;
    }
    temp = min->ptr;
    while(temp->next) temp = temp->next;
    temp->next = max->ptr;
    free(min);
    return 1;
}