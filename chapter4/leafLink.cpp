
/*
    将所有叶子结点的右指针连接成一个单链表
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

biTree *h = (biTree *)malloc(sizeof(biTree));
biTree *pre = h;


biTree *leafLink(biTree *T){
    if(T){
        leafLink(T->lchild); //一直向左走
        if(!T->lchild && !T->rchild){   //碰到叶子节点了，就连接
            pre->rchild = T;
            pre = T;
        }
        leafLink(T->rchild);    //没有左子树，则向右一步
        pre->rchild = NULL; //到了链表尾
    }
    return h;
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    nodeNum(T, &count);
   
    leafLink(T);
    biTree *p = h->rchild;
    while (p){
        printf("%c ", p->data);
        p = p->rchild;
    }

   return 0;
}
