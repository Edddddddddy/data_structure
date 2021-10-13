
/*
    该文件用于创建顺序二叉树
*/

#include <stdio.h>
#include <stdlib.h>

void createBiTree(int *arr, int count){
    int data;
    
    for (int i = 0; i < count; i++){
        printf("请输入第%d个节点:", i+1);
        scanf("%d",&data);
        *(arr + i) = data;
    }
}
