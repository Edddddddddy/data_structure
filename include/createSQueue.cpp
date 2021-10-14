/*
    创建一个循环顺序队列 判满 判空 入队 出队 统计队内元素
*/



#include <stdio.h>
#include <stdlib.h>
#if !defined(TYPE)
#define TYPE int
#endif // TYPE




struct SQueue{
    TYPE *arr;
    int front;
    int rear;
};


//创建队列
SQueue *createSQueue(int size){
    //实例化和分配空间
    struct SQueue *sq = (struct SQueue*)malloc(sizeof(struct SQueue));
    sq->arr = (TYPE*)malloc(sizeof(TYPE)*size);
    sq->front = 0;
    sq->rear = 0;
    return sq;
}


//判断队满
bool isFull(SQueue *sq, int size){
    return (sq->rear + 1) % size == sq->front;  //i = size - 1处就full了 
}

//判空
bool isEmpty(SQueue *sq){
    return sq->rear == sq->front;
}

//入队
bool enQueue(SQueue *sq, TYPE data, int size){
    if(isFull(sq, size)) return false;  
    sq->arr[sq->rear] = data;   //数据覆盖sq->rear
    sq->rear = (sq->rear + 1 ) % size;  
    return true;
}




//出队 取出数据
bool deQueue(SQueue *sq, TYPE *data, int size){    
    if(isEmpty(sq)) return false;
    *data = sq->arr[sq->front];
    sq->front = (sq->front + 1) % size;
    return true;
}


//统计队列元素
int count(SQueue *sq, int size){
    return (sq->rear - sq->front + size) % size;    //如size = 5, rear = 1, front = 4, 有0，1两个数字，计算成立
}

//打印队列
void printQ(SQueue *sq, int size){
    int np = sq->front;
    while(np != sq->rear){
        printf("%d ", sq->arr[np]);
        np = (np + 1) % size;
    }
}