
/*
    该文件用于实现自下而上，自右向左的层序遍历
    分析：
        层次遍历二叉树并入队，
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createSQueueS.cpp"
#include "../include/createStackS.cpp"

void levelOrder2(biTree *T){
    int count = 0;

    nodeNum(T, &count); //获得节点数
    biTree *p = T, *r = (struct biTree *)malloc(sizeof(struct biTree)); //r保存出队指针

    struct SQueueS *sq = (struct SQueueS *)malloc(sizeof(struct SQueueS));
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    sq = createSQueueS(count + 1);
    s = createStackS(count);

    enQueueS(sq, p, count+1);
    while(!isEmptyS(sq)){   //层次遍历，每一层出队时都让其下一层入队，直到最下层叶子结点
            deQueueS(sq, &r, count+1);
            push(s, r); //出队，入栈
            if(r->lchild) enQueueS(sq, r->lchild, count+1);
            if(r->rchild) enQueueS(sq, r->rchild, count+1);
    }
    while(!empty(s)){
        r = top(s);
        printf("%c ", r->data);
        pop(s);
    }
    

}


int main(){
    struct biTree *T = (struct biTree *)malloc(sizeof(struct biTree));
    T = create(T);
    levelOrder2(T);

    return 0;
}
