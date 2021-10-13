
/*
    先序遍历第k个
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

biTree *preK(biTree *T, int k) {
    static int num = 0; //
    static biTree *r;
    if(!T) return NULL; //T空
    if(++num == k){ //找到了第k个
        r = T;
    } 
    else{
        preK(T->lchild, k);
        preK(T->rchild, k);
    }
    return r;
}

int main(){
    int k = 3, count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree)), *r;
    T = create(T);
    nodeNum(T, &count);

    if(!count) printf("该二叉树是空树");
    else {
        r = preK(T, k);
        printf("第%d个节点值为%c", k, r->data);
    }

    return 0;
}
