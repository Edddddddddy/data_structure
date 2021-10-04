#include <stdio.h>
#include <stdlib.h>
#include "../source/createLink.cpp"

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
    
    reverse(h);

    printLink( h, 0);

    return 0;
}
