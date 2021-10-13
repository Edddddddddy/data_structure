
/*
    该方式统计双分支节点
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createSQueueS.cpp"

int doubleNode(biTree *T){
    static int num = 0;
    if(!T)num = 0;
    if(T->rchild && T->lchild){
        num++;
        doubleNode(T->lchild);
        doubleNode(T->rchild);
    }
    else{
        if(T->lchild) doubleNode(T->lchild);
        if(T->rchild) doubleNode(T->rchild);
    }
    return num;
}

int main(){
    int num = 0;
    biTree *T = (biTree *)malloc(sizeof(biTree));
    
    T = create(T);
    
    num = doubleNode(T);

    printf("该二叉树中的双分支节点个数有：%d",num);

    return 0;
}
