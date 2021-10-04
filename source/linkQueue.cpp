
/*
    该文件用来创建一个链表形式的队列 创建 判空 入队 出队
*/

struct Link {
    int node;
    struct Link *next;
};

struct LinkQueue {
    struct Link *front, *rear;
};

//创建一个带头节点的空链表
Link *createLink(){
    struct Link *head = (struct Link*)malloc(sizeof(struct Link));
    head->next = NULL;
    return head;
}

//初始化队列
LinkQueue *createQueue(){
    struct Link *h;
    struct LinkQueue *lq = (struct LinkQueue*)malloc(sizeof(struct LinkQueue));
    h = createLink();
    lq->front = lq->rear = h;
    return lq;
}

//判断是否为空队列
bool isEmpty(LinkQueue *lq){
    return lq->front == lq->rear;
}

//入队
bool enQueue(LinkQueue *lq, int data){  //队尾插入  
    struct Link *newD = (struct Link*)malloc(sizeof(struct Link));
    newD->node = data;
    lq->rear->next = newD;
    lq->rear = newD;
    return true;
}

//出队
bool deQueue(LinkQueue *lq, int *data){
    //先判空
    if (isEmpty(lq)) return false;
    struct Link *p = lq->front->next;
    *data = lq->front->next->node;
    lq->front->next = p->next;
    if(lq->rear == p){  //若出队的是队尾的元素，则需要对rear指针重新赋值
        lq->rear = lq->front;
    }
    free(p);
    return true;
}