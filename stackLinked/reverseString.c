#include <stdio.h>
#include "declaration.h"
#include "definition.c"

void rev(char[],struct stack*);

int main(){
    struct stack* s;
    init(&s);
    char str[] = "shiva";
    rev(str,s);
    printf("%s\n",str);
    clear(&s);
}

void rev(char str[], struct stack* s){
     char* cha = str;
     for(cha; *cha != '\0'; cha++){
         push(s,*cha);
     }
     int i = 0;
     char* ch = (char*)malloc(1);
     while(!isEmpty(s)){
         pop(s,ch);
         str[i] = *ch;
         i++;
     }
}

