#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

/**
 * @brief 将两个有序链表ha，hb，合并到ha中,合并后的链表递减，采用头插法
 * 
 * @param ha 
 * @param hb 
 */

void mergeList(Link *ha, Link *hb){
    struct Link *pa = ha->next, *pb = hb->next, *l = ha, *ra, *rb; 
    l->next = NULL;
    while(pa&&pb){  
        if(pa->type.data < pb->type.data){
            ra = pa->next;
            pa->next = l->next;
            l->next = pa;
            pa = ra;
        }
        else{
            rb = pb->next;  //暂存
            pb->next = l->next;
            l->next = pb;
            pb = rb;
        }
    }
    //处理剩下的元素
    while (pa){
        ra = pb->next;
        pa->next = l->next;
        l->next = pa;
        pa = ra;
    }
    while (pb){
        rb = pb->next;
        pb->next = l->next;
        l->next = pb;
        pb = rb;
    }
}

int main(){
    struct Link *ha = createLink(0);
    struct Link *hb = createLink(0);

    mergeList(ha, hb);

    printLink(ha);
    return 0;
}
