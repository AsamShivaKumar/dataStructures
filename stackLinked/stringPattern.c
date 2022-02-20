// checks whether the given string is of the form W#W
#include "declaration.h"
#include "definition.c"

int check(char[],struct stack*);

int main(){
    int size = 100;
    struct stack* s;
    init(&s);
    printf("Enter the string: ");
    char c[size];
    scanf("%s",c);
    printf("%d\n", check(c,s));
    clear(&s);
    return 0;
}

int check(char str[], struct stack* s){
    if(sizeof(str)/sizeof(str[0])%2 == 0) return -1;
    // int size = (sizeof(str)/sizeof(str[0]))/2;
    // char ch[size];
    int i = 0;
    while(str[i] != '#'){
        push(s,str[i]);
        i++;
    }
    for(int j = sizeof(str)/sizeof(str[0])-1; j > i; j--){
        char* c = (char*)malloc(1);
        pop(s,c);
        if(str[j] != *c) return -1;
    }
    
    return 1;
}