#include <stdio.h>
#include "declaration.h"
#include "definition.c"

int isPalin(char[], struct stack*);

int main(){
    struct stack* s;
    init(&s);
    int size = 50;
    printf("Enter the word: \n");
    char a[size];
    scanf("%s",a);
    if(isPalin(a,s) == 1){
        printf("The word entered is a palindrome\n");
    }else{
        printf("The word is not a palindrome\n");
    }
    clear(&s);
    return 0;
}

int isPalin(char str[], struct stack* s){
    char* c = (char*)malloc(1);
    for(char* ch = str; *ch != '\0'; ch++){
        push(s,*ch);
    }
    int i = 0;
    while(!isEmpty(s)){
        pop(s,c);
        if(*c != str[i]) return -1;
        i++;
    }
    return 1;
}

