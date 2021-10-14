
/*
    判断是否为平衡二叉树
    分析：
        左右子树深度差小于1
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include <algorithm>
bool isAVL(biTree *T, int *depth){
    if(!T){ //叶子结点，一定是平衡二叉树
        *depth = 0;
        return true;
    }
    //不是叶子结点
    //判断左右子树是否为平衡二叉树
    int left = 0, right = 0;    //存储
    if(isAVL(T->lchild, &left) && isAVL(T->rchild, &right)){
        //将孩子的diff of depth 返回给父亲
        int diff = left - right;
        if(abs(diff) <= 1){
            // *depth = std::max(left, right) + 1;
            *depth	= (1 + (left > right ? left : right));
            return true;
        }
    }
    //既不是叶子结点，也不平衡，
    return false;   
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    nodeNum(T, &count);
    int depth;
    isAVL(T, &depth) ? printf("是平衡二叉树") : printf("不是AVL");
    return 0;
}
