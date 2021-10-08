#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

/**
 * @brief 判断是否有环，使用快慢指针法
 * 
 * @param h 
 * @return Link* 返回环的入口
 */

Link *isLoop(struct Link *h){
    struct Link *fast = h->next , *slow = h->next;

    while(fast && slow){
        if(fast == slow){
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == NULL || slow == NULL) {
        printf("不存在环！\n");
        return NULL;
    }
    slow = h->next;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main(){
    //手动创建环
    struct Link *h = createLink(0), *p = h->next, *r = h->next;
    int n;

    printf("输入你希望第几个数字是环的入口：n=");
    scanf("%d", &n);

    while(--n){
        p = p->next;
    }
    while(r->next){
        r = r->next;
        
    }
    r->next = p;
    r = isLoop(h);
    for(int i = 0; i < 10; i++){
        printf("%d", r->next->type.data);
        r = r->next;
    }
    return 0;
}
