
/*
    该方法输出等价中缀表达式
    分析：
        采用中序遍历，主要判断加"()"的位置，取反为不加的位置为叶子结点和根节点
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

void putInExp(biTree *T, int deep){
    if(T==NULL) return;
    if(!T->lchild && !T->rchild) printf("%c ", T->data); //叶子结点直接输出
    else{
        if(deep>1)  printf("( ");
        putInExp(T->lchild, deep+1);
        printf("%c ", T->data);
        putInExp(T->rchild, deep+1);
        if(deep>1)  printf(") ");
    }
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    printf("中缀表达式为：");
    putInExp(T, 1);
    return 0;
}
