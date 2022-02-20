#include "declaration.h"
#include "definition.c"

int post(char*, struct stack*, char*);

int main(){
    struct stack* s;
    init(&s);
    char in[100];
    printf("Enter the infix expression: \n");
    scanf("%s",in);
    char po[100];
    post(in,s,po);
    printf("%s\n", po);
    clear(&s);
    return 0;
}

int post(char* in, struct stack* s, char* po){
       char* c = (char*)malloc(sizeof(char));
       int i = 0;
       for(char* ch = in; *ch != '\0'; ch++){
           switch(*ch){
            case ')':
                 while(!isEmpty(s)){
                       peek(s,c);
                       if(*c != '('){
                       pop(s,c);
                       po[i] = *c;
                       i++;
                       }else{
                           break;
                       }
                       }
                pop(s,c);
                break;
            case '+':
                while(!isEmpty(s)){
                    peek(s,c);
                    if(*c != '('){
                    pop(s,c);
                    po[i] = *c;
                    i++;
                    }else{
                        break;
                    }
                }
                push(s,*ch);
                break;
            case '-':
                while(!isEmpty(s)){
                    peek(s,c);
                    if(*c != '('){
                    pop(s,c);
                    po[i] = *c;
                    i++;
                    }else{
                        break;
                    }
                }
                push(s,*ch);
                break;
            case '*':
                peek(s,c);
                if(*c == '*' || *c == '/'){
                    while(!isEmpty(s)){
                        peek(s,c);
                        if(*c != '(' && (*c == '*' || *c == '/')){
                            pop(s,c);
                            po[i] = *c;
                            i++;
                        }else{
                            break;
                        }
                    }
                }
                push(s,*ch);
                break;
            case '/':
                peek(s,c);
                if(*c == '*' || *c == '/'){
                    while(!isEmpty(s)){
                        peek(s,c);
                        if(*c != '(' && (*c == '*' || *c == '/')){
                            pop(s,c);
                            po[i] = *c;
                            i++;
                        }else{
                            break;
                        }
                    }
                }
                push(s,*ch);
                break;
            case '(':
                push(s,*ch);
                break;
            default:
                po[i] = *ch;
                i++;
           }
       }
       while(!isEmpty(s)){
           pop(s,c);
           po[i] = *c;
           i++;
       }
       po[i] = '\0';
    return 1;
}