
/*
    该文件实现删除节点值为x的节点以及后续节点
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

/**
 * @brief 删除该节点及其所有子节点
 * 
 * @param T 
 */
void del(biTree *T){    
    if(T){  
        if(T->lchild) del(T->lchild);   //找到最左子节点
        if(T->rchild) del(T->rchild);   //向右走一步
        free(T);    //释放这个节点
    }
}

void delXSub(biTree *T, char x){
    biTree *p = T;
    //判断当前节点左右子节点是否为x，并删除
    //注意删除首先要释放该节点（消除数据），然后将指向它的指针指向NULL
    if(p->lchild && p->lchild->data == x){
        del(p->lchild);
        p->lchild = NULL;
    }
    	if (p->rchild && p->rchild->data == x) {
		del(p->rchild);
		p->rchild = NULL;
	}
    //若左右节点不为x，则递归调用
    if(p->lchild) delXSub(p->lchild, x);
    if(p->rchild) delXSub(p->rchild, x);
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    nodeNum(T, &count);

    char x = 'b';
    delXSub(T, x);

    inOrder(T);
    return 0;
}
