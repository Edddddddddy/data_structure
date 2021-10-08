/*
    该文件用于实现一种数组形式的循环队列，队列中数组所有元素得到使用，使用tag判断是否满
    创建队列 判满 判空 入栈 出栈
*/


#include <stdio.h>
#include <stdlib.h>
#define TYPE int

struct Squeue{
    TYPE *arr;
    int front, rear;
    int tag;
};

//创建循环队列
Squeue *createSqueue(int size){
    struct Squeue *sq = (struct Squeue*)malloc(sizeof(struct Squeue));
    sq->arr = (struct TYPE)malloc(sizeof(TPYE)*size);
    sq->front = 0;
    sq->rear = 0;
    sq->tag = 0;
    return sq;
}

//判满
bool isFull(Squeue *sq, int size){
    return sq->rear == sq->front && sq->tag == 1;
}

//判空
bool isEmpty(Squeue *sq, int size){
    return sq->rear == sq->front && sq->tag = 0;
}

//计数
int count(Squeue *sq, int size){
    return (sq->rear - sq->front + size) % size
}

//入队
bool enQueue(Squeue *sq, int data, int size){
    if(isFull(sq)) return false;
    sq->arr[sq->rear] = data;
    sq->rear = (sq->rear + 1) % size;
    sq->tag = 1;
    return true;
}

//出队
bool deQueue(Squeue *sq, int &data, int size){
    if (isEmpty(sq)) return false;
    data = sq->arr[sq->front];
    sq->front = (sq->front + 1) % size;
    sq->tag = 0;
    return true;
}