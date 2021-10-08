#include <stdio.h>
#include <stdlib.h>
#include "../include/createStack.cpp"
#include "../include/createLQueue.cpp"

bool matchBracket(LQueue *lq, Stack *s){
    char letterQ, letterS;
    while(!isEmpty(lq)){
        deQueue(lq, &letterQ);
        if(letterQ == '(' || letterQ == '{' || letterQ == '['){
            push(s, letterQ);
        }
        else{
            if(empty(s)){
                return false;
            }
            letterS = top(s);
            pop(s);
            switch(letterQ){
                case ')':if(letterS != '(')return false; break;
                case '}':if(letterS != '{')return false; break;
                case ']':if(letterS != '[')return false; break;
                default: break;
            }
        }
    }
    if(empty(s)) return true;
    else return false;
}


int main(){
    int size;
    char letter;
    printf("请输入队列大小：n=");
    scanf("%d", &size);
    struct LQueue *lq = createLQueue();
    for (int i = 0; i < size; i++){
        getchar();
        printf("请输入第%d个值：", i+1);
        scanf("%c", &letter);
        enQueue(lq, letter);
    }
    struct Stack *s = createStack(size);
    if(matchBracket(lq, s)) printf("该算数表达式配对");
    else printf("该算数表达式不配对");
    return 0;
}
