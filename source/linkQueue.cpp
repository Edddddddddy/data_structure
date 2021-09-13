/* 
    此文件用于创建一个链式队列
    分析：
        创建一个链表，设置front,rear，指针表示对头/尾
 */

// #define TYPE biTree*
#define TYPE int
// #define TYPE char

struct biTree{
    //二叉树节点
    char data;
    struct biTree *lchild;
    struct biTree *rchile;
};

struct Link{
    //TYPE data
    TYPE node;
    struct Link *next;
};
struct LinkQueue{
    struct Link *front, *rear;
};

#include <stdio.h>
#include <stdlib.h>


/* ——————————以下为方法实现—————————— */
//创建空链表
Link* createLink(){
    int n,data;
    char letter;
    // struct Link *q;  
    struct Link *head = (struct Link*) malloc(sizeof(struct Link));
    head->next = NULL;
    // q = head;
    return head;
}

//创建链队
LinkQueue *create(){
    struct Link *h, *p;
    struct LinkQueue *lq = (struct LinkQueue*) malloc(sizeof(struct LinkQueue));
    h = createLink();   //创建空链表
    p = h->next;    
    lq->front = lq->rear = h;
    return lq;
}