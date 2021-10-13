
/*
    求WPL
    分析：
        设置static totaW 累加带权路径，使用depth记录深度，递归方法实现
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/weightBiTree.cpp"


int countWPL(biTree *T, int depth){
    static int totalW = 0;
    if(T){
        if(!T->left && !T->right)  totalW += T->weight*depth; //叶子结点停止
        else {
            countWPL(T->left, depth+1);
            countWPL(T->right, depth+1);
        }
    }
    return totalW;
}

int main(){
    biTree *T = (biTree *)malloc(sizeof(biTree));
    T = create(T);
    int depth = 0;
    int totalW;
    totalW = countWPL(T, depth);
    printf("该二叉树WPL=%d", totalW);


    return 0;
}
