#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

/**
 * @brief 有ha hb两个递增链表，将其中公共元素放入ha
 * 
 * @param ha 
 * @param hb 
 * @param hc 
 */
void linkCommon2(Link *ha, Link *hb){
    struct Link *la = ha->next, *lb = hb->next, *pre = ha;
    while(la&&lb){
        if(la->type.data == lb->type.data){
            pre->next = la;
            pre = la;
            la = la->next;
            lb = lb->next;
        }
        else
            la->type.data < lb->type.data ? la = la->next : lb = lb->next;
    }
    pre->next = NULL;
}

int main(){ 
    struct Link *ha = createLink(0);
    struct Link *hb = createLink(0);

    linkCommon2(ha,hb);

    printLink(ha);

    return 0;
}