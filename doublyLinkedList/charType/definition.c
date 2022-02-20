#include "declaration.h"

int init(struct list** ll){
    *ll = (struct list*)malloc(sizeof(struct list));
    if(!(*ll)) return 0;
    (*ll)->head = NULL;
    (*ll)->tail = NULL;
    return 1; 
}
int isEmpty(struct list* ll){
    return ll->head == NULL;
}

int insertElement(struct list* ll, int pos, char ele){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if(!new) return 0;
    new->data = ele;
    new->next = NULL;
    new->prev = NULL;
    int i = 1;
    if(isEmpty(ll)){
        ll->head = new;
        ll->tail = new;
        return 1;
    }
    struct node* temp = ll->head;
    struct node* pre = NULL;
    while(temp && i < pos){
          pre = temp;
          temp = temp->next;
          i++;
    }
    if(pre == ll->head && pre == ll->tail){ 
       new->prev = ll->head;
       new->next = NULL;
       ll->head->next = new;
       ll->tail = new;
    }else if(pos == 1){
        new->next = ll->head;
        ll->head->prev = new;
        ll->head = new;
    }else if(!temp){
        if(i == pos){
        new->prev = ll->tail;
        ll->tail->next = new;
        ll->tail = new;
        }else{
            return 0;
        }
    }else{
        new->prev = pre;
        pre->next = new;
        new->next = temp;
        temp->prev = new;
    }
    return 1;
}

int delElement(struct list* ll, char del){
    if(isEmpty(ll)) return 0;
    struct node* itr = ll->head;
    while(itr && itr->data != del){
        itr = itr->next;
    }
    if(itr == ll->head && itr == ll->tail){
        ll->head = NULL;
        ll->tail = NULL;
        free(itr);
        return 1;
    }else if(itr == ll->head){
        ll->head->next->prev = NULL;
        ll->head = ll->head->next;
        free(itr);
        return 1;
    }else if(itr == ll->tail){
         ll->tail->prev->next = NULL;
         ll->tail = ll->tail->prev;
         free(itr);
         return 1;
    }else{
        itr->prev->next = itr->next;
        itr->next->prev = itr->prev;
        free(itr);
        return 1;
    }
}

int clear(struct list** ll){
    if(isEmpty(*ll)) return 1;
    while(!isEmpty(*ll)){
        delElement(*ll,(*ll)->head->data);
    }
    return 1;
}