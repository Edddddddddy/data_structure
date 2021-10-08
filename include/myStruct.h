

#define TYPE char
#include <stdlib.h>
#include <stdio.h>



struct biTree{
    TYPE data;
    struct biTree *lchild;
    struct biTree *rchild;
};

struct SQueue{
    biTree *arr;
    int front;
    int rear;
};



//创建队列
SQueue *createSQueue(int size);
//判断队满
bool isFull(SQueue *sq, int size);
//判空
bool isEmpty(SQueue *sq);
//入队
bool enQueue(SQueue *sq, TYPE data, int size);
//入队（二叉节点）
bool enQueueS(SQueue *sq, biTree *p, int size);
//出队 取出数据
bool deQueue(SQueue *sq, TYPE *data, int size);
//出队（二叉节点）
bool deQueueS(SQueue *sq, biTree *p, int size);
//统计队列元素
int count(SQueue *sq, int size);
//打印队列
void printQ(SQueue *sq, int size);


//先序创建
biTree *create(biTree *T);
//前序递归遍历
void preOrder(biTree *T);
//中序递归遍历
void inOrder(biTree *T);
//后序递归遍历
void postOrder(biTree *T);
//计算节点个数
void nodeNum(biTree *T, int *num);