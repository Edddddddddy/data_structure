/*
    该文件用于创建一棵链表二叉树
*/

#include <stdio.h>
#include <stdlib.h>

struct biTree{
    int data;
    struct biTree *lchild;
    struct biTree *rchild;
};

//先序创建
biTree *create(biTree *T){
    int data;
    printf("请输入当前节点值：data=");
    scanf("%d", &data);
    if(data != -1){
        T = (biTree *)malloc(sizeof(biTree));
        T->data = data;
        T->lchild = NULL;   //别漏了
        T->rchild = NULL;
        T->lchild = create(T->lchild);
        T->rchild = create(T->rchild);
    }
    return T;
}

//前序递归遍历
void preOrder(biTree *T){
    if(T != NULL){
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//中序递归遍历
void inOrder(biTree *T){
    if(T != NULL){
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

//后序递归遍历
void postOrder(biTree *T){
    if(T!=NULL){
        postOrder(T->lchild);
        postOrder(T->lchild);
        printf("%d ", T->data);
    }
}

//计算节点个数
void nodeNum(biTree *T, int *num){
    if(T != NULL){
        (*num)++;
        nodeNum(T->lchild, num);
        nodeNum(T->rchild, num);
    }
}


// //test
// int main(){
//     biTree *T = (biTree *)malloc(sizeof(biTree));
//     T  = create(T);
//     preOrder(T);
//     return 0;
// }