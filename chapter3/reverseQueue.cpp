/*
    该方法实现用栈逆置队列
    分析：
        一次取出队列元素，入栈，出栈，入队
*/

// struct Stack{   
//     int *arr;   //内存首地址
//     int top;    //栈顶指针
//     int len;    //容量
// };

// struct Squeue{  
//     int *arr;
//     int rear;
//     int front;
// };

#include <stdio.h>
#include <stdlib.h>
#include "../include/createSQueue.cpp"
#include "../include/createStack.cpp"    

SQueue *create(int size){
    int data;
    struct SQueue *sq = createSQueue(size+1);  //使用空一个节点的循环链表 size+1
    for (int i = 0; i < size; i++){
        printf("请输入第%d个节点值:", i + 1);
        scanf("%d", &data);
        enQueue(sq, data, size+1);
    }
    return sq;
}

void reverseQueue(SQueue *sq, int size){
    int data;
    struct Stack *stack = createStack(size);
    for (int i = 0; i < size; i++){
        deQueue(sq, &data, size+1);
        push(stack, data);
    }
    for (int i = 0; i < size; i++){
        data = top(stack);
        pop(stack);
        enQueue(sq, data, size+1);
    }
}


int main(){
    int size;

    printf("请输入队列大小：n=");
    scanf("%d", &size);

    struct SQueue *sq = create(size);
    
    reverseQueue(sq, size);
    
    printf("逆置后的队列为：\n");
    printQ(sq, size+1);

    return 0;
}
