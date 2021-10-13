


/*
    该文件用于创建结构体链式队列
*/

#include <stdio.h>
#include <stdlib.h>


struct SQueueS{
    biTree* *arr;
    int front;
    int rear;
};

SQueueS *createSQueueS(int size){
    SQueueS *sq = (SQueueS*)malloc(sizeof(SQueueS));
    sq->arr = (biTree**)malloc(sizeof(biTree*)*size);
    sq->rear = sq->front = 0;
    return sq;
}

bool isFullS(SQueueS *sq, int size){
    return  (sq->rear + 1) % size == sq->front;
}

bool isEmptyS(SQueueS *sq){
    return sq->front == sq->rear;
}

bool enQueueS(SQueueS *sq, biTree* p, int size){
    if(isFullS(sq, size)) return false;
    (sq->arr[sq->rear]) = p;
    sq->rear = (sq->rear + 1) % size;
    return true;
}

bool deQueueS(SQueueS *sq, biTree* *p, int size){
    if(isEmptyS(sq)) return false;
    *p = sq->arr[sq->front];
    sq->front = (sq->front + 1) % size;
    return true;
}

