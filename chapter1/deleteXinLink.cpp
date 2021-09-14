#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

struct Link{
    int value;
    struct Link *next;
};

void deleteX(Link *&p, int delNum){  //递归删除
    struct Link *pre;   //用于释放
    if (p == NULL) return;
    if (p->value == delNum){
        pre = p;
        p = p->next;
        free(pre);
        deleteX(p, delNum);
    }
    else 
        deleteX(p->next, delNum);
}

//尾插法
Link *create(){ 
    struct Link *p, *rear, *head;
    int count = 0;
    rear = (struct Link *)malloc(sizeof(struct Link));
    head = (struct Link *)malloc(sizeof(struct Link));

    int value;
    printf("请输入链表节点value：（9999结束）");
    scanf("%d", &value);
    while(value != 9999){
        p = (struct Link *)malloc(sizeof(struct Link));
        p->value = value;
        p->next = NULL;
        if (count++ == 0){
            rear = p;
            head = p;
        }
        else {
            rear->next = p;
            rear = p;
        }
        scanf("%d", &value);
    }
    rear->next = NULL;
    return head;
}

//头插法创建单链表
Link *create2(){
    struct Link *p , *rear, *head;
    rear = (struct Link *)malloc(sizeof(struct Link));
    head = (struct Link *)malloc(sizeof(struct Link));
    head = rear = NULL;
    int value;
    printf("请输入链表节点value：（9999结束）");
    scanf("%d", &value);
    int count = 0;
    while(value != 9999){
        p = (struct Link *)malloc(sizeof(struct Link));
        p->value = value;
        if (head == NULL){
            head = p;
            rear = p;
        }
        else {
            p->next = head->next;
            head->next = p;
            rear = p;   //head 后面是rear
            if (count++ == 0){  //插入第二个元素
                rear->next = NULL;
            }
        }
        
        scanf("%d", &value);
    }

}

int main(){
    printf("尾插法创建单链表\n");
    struct Link *head, *q;
    head = create();
    q = head;
    printf("打印链表：");
    while (q != NULL){
        printf("%d ", q->value);
		q = q->next;
    }
    q = head;

    printf("输入要删除元素：");
    int delNum;
    scanf("%d", &delNum);
    deleteX(q, delNum);

    printf("打印删除后的链表：");
    while (q != NULL){
        printf("%d ", q->value);
		q = q->next;
    }
    q = head;

    return 0;
}


