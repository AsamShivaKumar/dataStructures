#include "definition.c"

int evaluate(char*, struct stack*);

int main(){
    struct stack* s;
    init(&s);
    char post[100];
    printf("Enter the postfix expression: \n");
    scanf("%s", post);
    printf("The value is %d\n", evaluate(post,s));
}

int evaluate(char* post, struct stack* s){
    int* ch = (int*)malloc(sizeof(int));

    for(char* c = post; *c != '\0'; c++){
        int a = 0;
        int b = 0;
        int r = 0;
        switch(*c){
            case '+':
                 pop(s,ch);
                 b = *ch;
                 pop(s,ch);
                 a = *ch;
                 r = a+b;
                 push(s, r);
                 break;
            case '-':
                 pop(s,ch);
                 b = *ch;
                 pop(s,ch);
                 a = *ch;
                 r = a-b;
                 push(s, r);
                 break;
            case '*':
                 pop(s,ch);
                 b = *ch;
                 pop(s,ch);
                 a = *ch;
                 r = a*b;
                 push(s, r);
                 break;
            case '/':
                 pop(s,ch);
                 b = *ch;
                 pop(s,ch);
                 a = *ch;
                 r = a/b;
                 push(s, r);
                 break;
            default:
                 push(s, (int)(*c)-(int)('0'));     
        }
    } 
    pop(s,ch);
    return *ch;
}