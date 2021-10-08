/*
    该文件实现层次遍历算法
    分析：
        使用队列，先访问本节点，再将该节点左右子节点入队，再继续访问队列中下一个节点
*/


#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createSQueue.cpp"



void levelOrder(biTree *T, SQueue *sq, int maxSize){
    biTree *p = T;
    biTree *r = (struct biTree *)malloc(sizeof(struct biTree));


    enQueueS( sq, p, maxSize);
    while(!isEmpty(sq)){
        deQueueS( sq, r, maxSize);
        printf("%c ", r->data);
        if(r->lchild) enQueueS( sq, r->lchild, maxSize);
        if(r->rchild) enQueueS( sq, r->rchild, maxSize);
    }
}

int main(){
    int count = 0;
    biTree *T = (struct biTree*)malloc(sizeof(biTree));
    SQueue *sq = (struct SQueue*)malloc(sizeof(SQueue));


    T = create(T);
    nodeNum(T ,&count);
    sq = createSQueue(count);

    levelOrder(T,sq,count);
    
    return 0;
}
