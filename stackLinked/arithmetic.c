#include <stdio.h>
#include "declaration.h"
#include "definition.c"

int isValid(char[], struct stack*);

int main(){
    struct stack* s;
    init(&s);
    char ar[100];
    printf("Enter the arithmetic expression: \n");
    scanf("%s", ar);
    if(isValid(ar,s) == 1){
        printf("The arithmetic expression is valid\n");
    }else{
        printf("The arithmetic expression you entered is invalid\n");
    }
    clear(&s);
    return 0;
}

int isValid(char ar[], struct stack* s){
    int ret = 0;
    char* ch = (char*)malloc(1);
    for(char* c = ar; *c != '\0'; c++){
        if(*c == '('){
            push(s,*c);
        }else if(*c == ')'){
            if(isEmpty(s)){
                return -1;
            }else{
                pop(s,ch);
            }
        }
    }
    if(isEmpty(s)){
        return 1;
    }else{
        return -1;
    }
}

