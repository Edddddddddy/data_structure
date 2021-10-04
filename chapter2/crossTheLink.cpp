#include <stdio.h>
#include <stdlib.h>
#include "../source/createLink.cpp"

/**
 * @brief 将链表的后一半逆置，并穿插到前一半链表中
 * 
 * @param h 
 */


void crossTheLink(struct Link *h){
    //使用快慢指针，先找到中间节点（将第[n/2]个节点(即slow)作为后一半的头节点）
    void reverse(Link *);
    struct Link *fast = h->next, *slow = h->next, *mid;
    mid = (struct Link*)malloc(sizeof(struct Link));
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    mid->next = slow->next;
    reverse(mid);
    fast = h->next;
	slow->next = NULL;
	slow = mid->next;
	while (slow) {
		mid = slow->next;
		slow->next = fast->next;
		fast->next = slow;
		slow = mid;
		fast = fast->next->next;
	}

}

/**
 * @brief 逆置链表
 * 
 * @param h 
 */
void reverse(struct Link *h){   //头插法逆置链表
    struct Link *p = h->next, *q;
    h->next = NULL;
    while(p){
        q = p->next;
        p->next = h->next;
        h->next = p;
        p = q;
    }
}


int main(){
    struct Link *h = createLink(0);

    crossTheLink(h);

    printLink(h, 0);

    return 0;
}
