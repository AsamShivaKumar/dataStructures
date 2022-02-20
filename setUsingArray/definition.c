#include "declaration.h"

struct set{
    int elements[SIZE];
    int length;
};

int init(struct set** s){
    *s = (struct set*)malloc(sizeof(struct set));
    if(*s == NULL) return 0;
    (*s)->length = 0;
    return 1;
}
int isEmpty(struct set* s){
    return s->length == 0;
}
int isSingleton(struct set* s){
    return s->length == 1;
}
int isMember(struct set* s, int x){
    for(int i = 0; i < s->length; i++){
        if(s->elements[i] == x){
            return 1;
        }
    }
    return 0;
}
int isFull(struct set* s){
    return s->length == SIZE;
}
int addElement(struct set* s, int ele){
    if(isFull(s)) return 0;
    if(isMember(s,ele)) return 0;
    s->elements[s->length] = ele;
    s->length++;
    return 1;
}
int delElement(struct set* s, int ele){
    if(isEmpty(s)) return 0;
    int i = 0;
    while(i < s->length && s->elements[i] != ele) i++;
    if(i == s->length) return 0;
    for(int j = i; j < s->length-1; j++){
        s->elements[j] = s->elements[j+1];
    }
    s->elements[s->length-1] = 0;
    s->length--;
    return 1;
}
int unionUV(struct set* s, struct set* u, struct set* v){
    for(int i = 0; i < u->length; i++){
        addElement(s,u->elements[i]);
    }
    for(int i = 0; i < v->length; i++){
        addElement(s,v->elements[i]);
    }
    return 1;
}
int intersectUV(struct set* s, struct set* u, struct set* v){
    for(int i = 0; i < u->length; i++){
        for(int j = 0; j < v->length; j++){
            if(u->elements[i] == v->elements[j]) addElement(s,u->elements[i]);
        }
    }
    return 1;
}
int difference(struct set* s, struct set* u, struct set* v){
    for(int i = 0; i < u->length; i++){
        int is = 0;
        for(int j = 0; j < v->length; j++){
            if(u->elements[i] == v->elements[j]){
                is = 1;
                break;
            }
        }
        if(is == 0) addElement(s,u->elements[i]);
    }
    return 1;
}
int symDifUV(struct set* s, struct set* u, struct set* v){
    for(int i = 0; i < u->length; i++){
        if(!isMember(v, u->elements[i])){
            addElement(s,u->elements[i]);
        }
    }
    for(int i = 0; i < v->length; i++){
        if(!isMember(u, v->elements[i])){
            addElement(s,v->elements[i]);
        }
    }
    return 0;
}
int print(struct set* s){
    if(isEmpty(s)){
        printf("The set is empty!\n");
        return 0;
    }
    for(int i = 0; i < s->length; i++){
        printf("%d ", s->elements[i]);
    }
    printf("\n");
    return 1;
}
int printSorted(struct set* s){
    if(isEmpty(s)){
        printf("The set is empty!\n");
        return 0;
    }
     int ar[s->length];
     for(int i = 0; i < s->length; i++){
         ar[i] = s->elements[i];
     }
     for(int i = 0; i < s->length-1; i++){
         int min = i;
         for(int j = i+1; j < s->length; j++){
             if(ar[j] < ar[min]){
                 min = j;
             }
         }
         if(min != i){
             int temp = ar[min];
             ar[min] = ar[i];
             ar[i] = temp;
         }
     }
    for(int i = 0; i < s->length; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
    return 1;
}
int destroy(struct set** s){
    if(*s == NULL) return 0;
    free(*s);
    *s = NULL;
    return 1;
}