
/*
    该文件用于创建二叉树结构体栈
*/
#include <stdio.h>
#include <stdlib.h>



struct Stack {
    biTree *arr;
    int len;
    int top;
};

Stack *createStackS(int size){
    Stack *s = (struct Stack*)malloc(sizeof(Stack));
    s->arr = (struct biTree *)malloc(sizeof(biTree)*size);
    s->len = size;
    s->top = -1;
    return s;
}

bool full(Stack *s){
    return s->top + 1 >= s->len;
}

bool empty(Stack *s){
    return s->top == -1;
}

bool push(Stack *s, biTree *p){
    if(full(s)) return false;
    s->top++;
    (s->arr + s->top)->data = p->data;
    (s->arr + s->top)->lchild = p->lchild;
    (s->arr + s->top)->rchild = p->rchild;
    return true;
}

bool pop(Stack *s){
    if (empty(s)) return false;
    s->top--;
    return true;
}

biTree *top(Stack *s){
    return (s->arr + s->top);
}

void destory(Stack *s){
    free(s->arr);
    free(s);
}

