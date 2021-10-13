
/*
    该文件用于实现交换左右子树
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

void swapChild(biTree *T){
    biTree *p = T, *t;
    if(!p)return;   //T为空，返回
    if (!p->lchild && !p->rchild) return;   //没有左或右孩子，返回
    else{
        swapChild(p->lchild);   //一直往左走，走到最后一个有左右节点的节点
        t = p->lchild;  //交换孩子
        p->lchild = p->rchild;
        p->rchild = t;
        swapChild(p->lchild);
    }
}


int main(){
    int num = 0;
    biTree *T = (biTree *)malloc(sizeof(biTree));
    T = create(T);
    
    swapChild(T);

    inOrder(T);

    return 0;
}
