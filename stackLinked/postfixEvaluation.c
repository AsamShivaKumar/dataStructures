#include "definition.c"

void intTochar(int,char*);
int evaluate(char*, struct stack*);
int siz(char*);

int main(){
    struct stack* s;
    init(&s);
    char post[100];
    printf("Enter the postfix expression: \n");
    scanf("%s", post);
    printf("The value is %d\n", evaluate(post,s));
    clear(&s);
}

int evaluate(char* post, struct stack* s){
    int val = 0;
    char* ch = (char*)malloc(sizeof(char));
    char* cha = (char*)malloc(sizeof(char));
    for(char* c = post; *c != '\0'; c++){
        int a = 0;
        int b = 0;
        int r = 0;
        switch(*c){
            case '+':
                 pop(s,ch);
                 b = (int)(*ch)-(int)('0');
                 pop(s,ch);
                 a = (int)(*ch)-(int)('0');
                 r = a+b;
                 val += r;
                 intToChar(r, cha);
                 push(s, *cha);
                 break;
            case '-':
                 pop(s,ch);
                 b = (int)(*ch)-(int)('0');
                 pop(s,ch);
                 a = (int)(*ch)-(int)('0');
                 r = a-b;
                 val += r;
                 intToChar(r, cha);
                 push(s, cha);
                 break;
            case '*':
                 pop(s,ch);
                 b = (int)(*ch)-(int)('0');
                 pop(s,ch);
                 a = (int)(*ch)-(int)('0');
                 r = a*b;
                 val += r;
                 intToChar(r, cha);
                 push(s, cha);
                 break;
            case '/':
                 pop(s,ch);
                 b = (int)(*ch)-(int)('0');
                 pop(s,ch);
                 a = (int)(*ch)-(int)('0');
                 r = a*b;
                 val += r;
                 intToChar(r, cha);
                 push(s, cha);
                 break;
            default:
                 push(s,*c);     
        }
    } 
    return val;
}

void intToChar(int x, char* c){
     int i = 0;
     while(x != 0){
          int digi = x%10;
          c[i] = (char)(digi + (int)('0'));
          i++;
          x = x/10;
     }
     int s = 0;
//   int l = sizeof(c)/sixeof(c[0]); 
     int l = siz(c)-1;
     while(s < l){
         char temp = c[s];
         c[s] = c[l];
         c[l] = temp;
         s++;l--;
     }
}
int siz(char* c){
    for(int i = 0; c[i] != '\0'; i++) continue;
    return i;
}