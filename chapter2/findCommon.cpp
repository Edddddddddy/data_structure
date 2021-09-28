#include <stdio.h>
#include <stdlib.h>
#include "../source/createLink.cpp"

/**
 * @brief   暴力方法
 *          有ha hb两个递增链表，将其中公共元素放入hc中，并递增有序，不破坏AB链表
 * 
 * @param ha 
 * @param hb 
 * @param hc 
 */
void linkCommon(Link *ha, Link *hb, Link *hc){
    struct Link *la = ha->next, *lb = hb->next, *rc = hc;
    while(la&&lb){
        if(la->type.data == lb->type.data){
            struct Link *p = (struct  Link*)malloc(sizeof(struct Link));
            p->type.data = la->type.data;
            rc->next = p;
            rc = p;
            la = la->next;
            lb = lb->next;
        }
        else{
            la->type.data < lb->type.data ? la = la->next : lb = lb->next;
        }
    }
    rc->next = NULL;
}

int main(){
    struct Link *ha = createLink(0);
    struct Link *hb = createLink(0);
    struct Link *hc = (struct  Link*)malloc(sizeof(struct Link));

    linkCommon(ha,hb,hc);

    printLink(hc);

    return 0;
}
