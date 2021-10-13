
/*
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkTreadBiTree.cpp"

biTree *findPre(biTree *T, biTree *p){
    biTree *f;
    if(p->rchild && p->rtag == 0) return p->rchild; //有右孩子则右孩子为后续前驱
    else if(p->lchild && p->ltag==0) return p->lchild; //有左孩子
    else {  //都没有，则当作其祖先的右叶子结点查找
        f = p->lchild;  //f指向p的祖先或者NULL
        while(f && f->ltag)f = f->lchild;   //找到有左孩子的祖先
        if(f) return f->lchild; //如果节点非空,返回他的前驱，
        else return NULL;   //节点本身就是根节点，则无祖先
    }
}


int main(){
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    inTread(T, NULL);
    biTree *p = T->rchild->lchild, *pre = NULL; //手动创建
    pre = findPre(T, p);
    if(pre) printf("节点前驱为%c", pre->data);
    else printf("节点无前驱");
    return 0;
}
