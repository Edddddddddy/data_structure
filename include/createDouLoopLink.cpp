#include <stdlib.h>
#include <stdio.h>

struct Link{
    int data;
    struct Link *next;
    struct Link *pre;
};
/**
 * @brief Create a Dou Loop Link object，尾插法创建循环双链表
 * 
 * @return Link* 
 */

Link *createDouLoopLink() {
	int n, data;
	struct Link *head = (struct Link *)malloc(sizeof(struct Link));
	head->next = NULL;
	head->pre = NULL;
	struct Link *p = head;
	printf("请输入节点个数：n=");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("请输入第%d个节点值:", i + 1);
		scanf("%d", &data);
		struct Link *newP = (struct Link*)malloc(sizeof(struct Link));
		newP->data = data;
		newP->pre = p;
		p->next = newP;
		p = newP;
	}
	p->next = head;
	head->pre = p;
	return head;
}

