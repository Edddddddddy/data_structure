
/*
    该方法用于实现判断是否为完全二叉树
    分析：
        重点在于将NULL也入队，若NULL后面没有新的节点
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createSQueueS.cpp"


bool isComplete(biTree *T, SQueueS *sq, int size){
    biTree *p = T, *r;

    enQueueS(sq, p, size);
    while(!isEmptyS(sq)){
        deQueueS(sq, &r, size);
        if(r){
            enQueueS(sq, r->lchild, size);
            enQueueS(sq, r->rchild, size);
        }
        else{
            while(!isEmptyS(sq)){
                deQueueS(sq, &r, size);
                if(r){
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
	int count = 1;
	bool isCom;
	struct biTree *T = (struct biTree*)malloc(sizeof(struct biTree));
	struct SQueueS *sq;

	T = create(T);//创建一颗二叉树
	nodeNum(T, &count);//统计二叉树节点数量
	sq = createSQueueS(count);//创建容量为二叉树节点个数大小的队列

	isCom = isComplete(T, sq, count);
	isCom ? printf("该二叉树是完全二叉树") : printf("该二叉树不是完全二叉树");
	return 0;
}