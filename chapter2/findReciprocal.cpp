#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

int findReciprocal(Link *h, int k){
    struct Link *p = h->next, *q = h->next;
    while(--k){
        if(q->next == NULL) {
            printf("超过链表长度，无法找到");
            return 0;
        }
        q = q->next;
    }
    while(q->next){
        p = p->next;
        q = q->next;
    }
    return p->type.data;
}

int main(){
    struct Link *h = createLink(0);
    int k;

    printf("输入要找倒数第几个数字：n=");
    scanf("%d", &k);
    printf("%d", findReciprocal(h,k));


    return 0;
}
