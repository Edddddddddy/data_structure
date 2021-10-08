#include <stdio.h>
#include <stdlib.h>

struct Link{
    int data;
    struct Link *next;
};
/**
 * @brief Create a Sin Loop Link object,尾插法创建循环单链表
 * 
 * @return Link* 
 */
Link *createSinLoopLink(){
    int n, data;
    struct Link *h = (struct Link *)malloc(sizeof(struct Link));
    h->next = NULL;
    struct Link *p = h;
    printf("请输入节点个数：n=");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Link *newP = (struct Link *)malloc(sizeof(struct Link));
        printf("请输入第%d个节点值：", i+1);
        scanf("%d", &data);
        newP->data = data;
        p->next = newP;
        p = newP;
    }
    p->next = h;
    return h;
}

void printLink(struct Link *h){
    struct Link *p = h->next;
    while(p != h) {
        printf("%d", p->data);
        p = p->next;
    }
}