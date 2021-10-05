/*
    创建一个栈  判断栈满 栈空 出入栈 查看栈顶元素
*/

#include <stdio.h>
#include <stdlib.h>
#define TYPE int

struct Stack{
    TYPE *arr;
    int len;
    int top;
};

//创建栈
Stack *createStack(int size){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (TYPE*)malloc(sizeof(TYPE)*size);
    stack->len = size;
    stack->top = -1;
    return stack;
}

//判满
bool isFull(Stack *stack){
    return stack->len+1 >= stack->size;
}

//判空
bool isEmpty(Stack *stack){
    return stack->top == -1;
}

//入栈
bool push(Stack *stack, int data){
    is(isFull(stack)) return false;
    *(stack->arr+ ++s->top) = data;
    return true;
}

//出栈
bool pop(Stack *stack){
    if(isEmpty(stack)) return false;
    s->top--;
    return true;
}

//查看栈顶元素
TYPE *top(Stack *stack){
    if(isEmpty(stack)) return false;
    return s->arr + s->top;
}