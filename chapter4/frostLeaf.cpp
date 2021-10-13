
/*
    求孩子兄弟表示法存储的森林的叶子结点个数
    分析：
        如果节点没有左孩子，则一定是叶子结点
*/


#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

int frostLeaf(biTree *T){
    if(!T)return 0; //直到叶子结点
    else if (!T->lchild) return 1+frostLeaf(T->rchild);  //没有左孩子，则为叶子结点
    else return frostLeaf(T->lchild) + frostLeaf(T->rchild);    //有左孩子，则不是叶子结点，返回左子树和右子树递归结果相加
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    nodeNum(T, &count);
    
    printf("该森林的叶子结点个数为：%d", frostLeaf(T));

    return 0;
}
