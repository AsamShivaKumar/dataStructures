#include "declaration.h"
#include "definition.c"

int balance(char[], struct stack*);

int main(){
    struct stack* s;
    init(&s);
    int size = 100;
    char str[size];
    printf("Enter the string: \n");
    scanf("%s",str);
    if(balance(str,s) == 1){
       printf("The parentheses are balanced\n");
    }else{
        printf("The parentheses are not balanced\n");
    }
    clear(&s);
   return 0;
}

int balance(char str[], struct stack* s){
    char* c = (char*)malloc(1);
    for(char* ch = str; *ch != '\0'; ch++){
        if(*ch == '[' || *ch == '{'){
            push(s,*ch);
        }else if(*ch == ']'){
            if(isEmpty(s)) return -1;
            pop(s,c);
            if(*c != '[') return -1;
        }else if(*ch == '}'){
            if(isEmpty(s)) return -1;
            pop(s,c);
            if(*c != '{') return -1;
        }
    }
    if(isEmpty(s)) return 1;
    return -1;
}