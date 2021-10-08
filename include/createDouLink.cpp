/**
 * @brief 非循环双链表结构体
 * 
 */
struct Link{
    int data;
    struct Link *next;
    struct Link *pre;
    int freq = 0;
};

#include <stdio.h>
#include <stdlib.h>

struct Link *createDouLink(){
    int n, data;
    struct Link *h = (struct Link *)malloc(sizeof(struct Link));
    h->next = NULL;
    h->pre = NULL;
    struct Link *p = h;
    printf("请输入节点个数：n=");
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
		struct Link *newP = (struct Link*)malloc(sizeof(struct Link));
        printf("请输入第%d个节点值:", i + 1);
        scanf("%d", &data);
        newP->data = data;
        newP->pre = p;
        p->next = newP;
        p = newP;
	}
    p->next = NULL;
    return h;
}