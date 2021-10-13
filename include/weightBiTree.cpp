
/*
    该文件用于创建带权二叉树
*/

struct biTree{
    int weight;
    struct biTree *left, *right;
};

#include <stdio.h>
#include <stdlib.h>


biTree *create(biTree *T){
    int weight;
    printf("请输入当前节点权值：weight=");
    scanf("%d", &weight);
    // getchar();
    if(weight!=-1){
        T = (biTree*)malloc(sizeof(biTree));
        T->weight = weight;
        T->left = NULL;
        T->right = NULL;
        T->left = create(T->left);
        T->right = create(T->right);
    }
    return T;
}

