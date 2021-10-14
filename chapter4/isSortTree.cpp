
/*
    判断是否是二叉排序树
    分析：
        根据中序序列是否升序判断
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTreeInt.cpp"


bool isSort(biTree *T){
    //设置静态最小值
    static int min = INT32_MIN;
    //静态flag用于判断是否是中序序列
    static bool flag = true;

    //中序遍历，碰到不满足的就将flag设为false
    if(T){  //不是叶子
        isSort(T->lchild);
        if(T->data < min) flag = false;
        else min = T->data;
        isSort(T->rchild);
    }
    return flag;
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    
    isSort(T) ? printf("是二叉排序树") : printf("不是二叉排序树");

    return 0;
}
