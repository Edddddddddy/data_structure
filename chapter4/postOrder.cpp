
/*
    该文件用于实现非递归的后续遍历
    分析：
        使用栈和一个pre指针，使得pre指向p->rchild时直接pop，
        避免陷入再次进入p->rchild的循环
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createStackS.cpp"

void preOrder(biTree *T, Stack *s){
    biTree *p = T;
    biTree *pre = (struct biTree*)malloc(sizeof(struct biTree));
    
    
    while(p || !empty(s)){
        if(p) {
            push(s, p);
            p = p->lchild;
        }
        else{
            p = top(s);
            if(p->rchild && (pre != p->rchild)) {
                p = p->rchild;
                push(s, p);
                p = p->lchild;
            }
            else{
                printf("%c ", p->data);
                pre = p;
                pop(s);
                p = NULL;
            }
        }
    }
}


int main(){
    int count = 6;
    biTree *T = (biTree *)malloc(sizeof(biTree));
    T = create(T);
    
    Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s = createStackS(count);
    preOrder(T, s);
    return 0;
}
