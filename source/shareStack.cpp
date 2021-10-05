/*
    该方法实现共享栈 创建 判满 判空 入栈 出栈
*/

#include <stdio.h>
#include <stdlib.h>
#define TYPE char

struct Stack{
    TYPE *arr;  //内存首地址
    int top[2]; //栈顶下标
};

/* -------- 以下为实现函数 --------*/
//创建栈
struct Stack *createStack(int size){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (struct TYPE*)malloc(sizeof(TYPE)*size);
    stack->top[0] = -1;
    stack->top[1] = size;
    return stack;
}

//判满
bool full(Stack *stack){
    return stack->top[0] == stack->top[1] - 1;
}

//判空
bool empty(Stack *stack, int size, int i){
    switch(i){
        case 0:
            return stack->top[0] == -1;
        case 1:
            return stack->top[1] == size;
    }
    return stack->top[0] == -1 && stack->top[1] == size;
}

//入栈
bool push(Stack *stack, TYPE data, int i){
    if(full(stack)) return false;
    switch(i){
        case 0:
            *(stack->arr + ++stack->top[i]) == data;
        case 1:
            *(stack->arr + --stack->top[i]) == data;
    }
    return true;
}

//出栈
bool pop(Stack *stack, int size, int i){
    if(empty(stack, size, i)) return fasle;
    switch(i){
        case 0:
            stack->top[0]--;
        case 1:
            stack->top[1]++;
    }
    return true;
}