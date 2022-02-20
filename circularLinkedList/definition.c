#include "declaration.h"

int init(struct node** tail){
    *tail = (struct node*)malloc(sizeof(struct node));
    if(!(*tail)) return 0;

    *tail = NULL;
    return 1;
}

int insertAfterElement(struct node** tail, int ele, int data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    if(*tail == NULL){
        new->next = new;
        *tail =  new;
        return 1;
    }
    struct node* itr = (*tail)->next;
    if(itr->data == ele){
        new->next = itr->next;
        itr->next = new;
        if(new->next == itr) *tail = new;
        return 1;
    }
    do{ 
        itr = itr->next;
    }while(itr != (*tail)->next && itr->data != ele);
    if(itr == (*tail)->next) return 0;
    new->next = itr->next;
    itr->next = new;
    if(itr == *tail) *tail = new;
    return 1;
}

int traverse(struct node* tail){
    if(!tail) return 0;
    struct node* itr = tail->next;
    do{
       printf("%d ", itr->data);
       itr = itr->next;
    }while(itr != tail->next);
    printf("\n");
    return 1;
}

int searchElement(struct node* tail, int key, struct node** store){
    if(!tail) return 0;

    struct node* itr = tail->next;
    do{
        if(itr->data == key){
            *store = itr;
            return 1;
        }
        itr = itr->next;
    }while(itr != tail->next);
    return 0;
}

int deleteElement(struct node** tail, int del){
    if(!tail) return 0;
    struct node* itr = (*tail)->next;
    struct node* prev = *tail;
    if((*tail)->data == del && (*tail)->next == *tail){
        *tail = NULL;
        return 1;
    }
    do{
        if(itr->data == del){
            prev->next = itr->next;
            if(itr == *tail){
                *tail = prev;
            }
            free(itr);
            return 1;
        }
        prev = itr;
        itr = itr->next;
    }while(itr != (*tail)->next);
    return 1;
}

int destory(struct node** tail){
    if(!(*tail)) return 1;
    while(*tail){
        deleteElement(tail, (*tail)->next->data);
    }
    free(*tail);
    *tail = NULL;
    return 1;
}