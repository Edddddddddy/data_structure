
/*
    判断两个数是否相似
    分析：
        递归判断所有子树是否结构相等
        结构相等条件是
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

bool isSimilar(biTree *T1, biTree *T2){
    //先判断结束条件，即都为空则相似
    //若不同则false
    //否则一直递归调用
    if(!T1 && !T2) return true; //都没有则相同
    else if(!T1 || !T2) return false;   //有一没有
    else {
        if(isSimilar(T1->lchild , T2->lchild) 
            && isSimilar(T1->rchild, T2->rchild)) 
            return true;
        else return false;
    }
    
}

int main(){
    int count = 0;
    printf("第一棵树数据：\n");
    biTree *T1 = (biTree*)malloc(sizeof(biTree));
    T1 = create(T1);
    printf("第二棵树数据：\n");
    biTree *T2 = (biTree*)malloc(sizeof(biTree));
    T2 = create(T2);
    

    printf("两个数%s", (isSimilar(T1, T2) ? "相似": "不相似"));
    
    return 0;
}
