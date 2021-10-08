#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

void reverse(Link *h){
    struct Link *pre = h, *p = h->next, *q = h->next, *r;
    // q保存第一个元素，也就是倒置后最后一个元素，用于置NULL
    while (p){
        r = p->next;
        p->next = pre;
        pre = p;
        p = r;
    }
    h->next = pre;
    q->next = NULL;
    
    printLink(h);
}
    
int main(){
   struct Link *l = createLink(0);

   reverse(l);
    
   return 0;
}
