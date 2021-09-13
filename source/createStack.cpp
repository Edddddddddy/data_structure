#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TYPE int
// #define TYPE biTree
// #define TYPE char
// #define TYPE Recursion

struct biTree{
    char data;
    struct biTree *lchild;
    struct biTree *rchile;
};
struct Recurtion{
    int no;
    int val;
};
struct Stack{
    TYPE* arr;
    int len;
    int top;
};

/* ——————————以下为实现函数—————————— */
//创建栈
Stack *createStack(int size){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (TYPE *)malloc(sizeof(TYPE)*size);
    stack->len = size;
    stack->top = -1;    //栈顶下标无元素为-1
    return stack;
}

