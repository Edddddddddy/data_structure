
/*
    该文件用于创建一个线索二叉树，
*/


struct biTree{
    char data;
    biTree *lchild, *rchild;
    int ltag, rtag; //标记左右指针指的是不是祖先节点
};

#include <stdio.h>
#include <stdlib.h>


//先序创建线索二叉树
biTree *create(biTree *T){  
    char data;
    printf("请输入当前节点值：data=");
    scanf("%c", &data);
    getchar();
    if(data != '#'){
        T = (biTree *)malloc(sizeof(biTree));
        T->data = data;
        T->lchild = NULL;
        T->rchild = NULL;
        T->ltag = 0;
        T->rtag = 0;
        T->lchild = create(T->lchild);
        T->rchild = create(T->rchild);
    }
    return T;
}


biTree *inTread(biTree *T, biTree *pre){
    if( T != NULL){ //退出条件为走到叶子结点的子节点
        inTread(T->lchild, pre);    //一直向左走
        if(T->lchild == NULL){  //没有左子树，最左子树lchild为NULL
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre != NULL && pre->rchild==NULL){   //前驱的后继节点
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        inTread(T->rchild, pre);   
    }
    return T;
}

biTree *preTread(biTree *T, biTree *pre){
    if(!T){ //不是叶子结点的子节点
        
        if(T->lchild == NULL){  //T左子树不存在，构建线索
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){ //构建前驱的线索
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;    //pre每次都重新赋值
        preTread(T->lchild, pre);
        preTread(T->rchild, pre);
    }
    return T;
}

biTree *postTread(biTree *T, biTree *pre){
    if(!T){
        postTread(T->lchild, pre);
        postTread(T->rchild, pre);
        
        if(T->lchild == NULL){
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre->rchild != NULL && pre != NULL){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
    }
    return T;
}