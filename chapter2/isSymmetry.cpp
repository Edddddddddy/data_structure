#include <stdio.h>
#include <stdlib.h>
#include "../include/createDouLoopLink.cpp"

void isSymmetry(Link *h){
    struct Link *pre = h->pre, *next = h->next;
    while(pre != next && pre->pre != next){
        if(pre->data != next->data){
            printf("该双链表不是对称链表！\n");
            break;
        }
        else{
            pre = pre->pre;
            next = next->next;
        }
    }
    if (pre == next || pre->pre == next){
        printf("该双链表是对称链表！\n");
    }
}

int main(){
    struct Link *h = createDouLoopLink();
    isSymmetry(h);

    return 0;
}
