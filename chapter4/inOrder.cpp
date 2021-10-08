
/*
    该方法实现非递归的中序遍历
    分析：
        利用栈，一直迭代查找左子树并入栈，若没有则出栈并查找右子树，并继续迭代查找
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createStackS.cpp"



void inOrder(biTree *T, Stack *s){
    biTree *p = T;

    while(p || !empty(s)){   //迭代直到没有右子树且栈为空
        if (p){ //迭代，压栈，直到没有左子树
            push(s, p);
            p = p->lchild;
        }   
        else {  //没有左子树时，pop最上，指针找右子树，若没有迭代下一次
            p = top(s);
            printf("%c ", p->data);
            pop(s);
            p = p->rchild;
        } 
    }

}


int main(){
    int count = 0;
    struct biTree *T = (struct biTree*)malloc(sizeof(biTree));
    T = create(T);

    nodeNum(T, &count);
    struct Stack *s = createStackS(count);

    inOrder(T, s);
    
    return 0;
}
