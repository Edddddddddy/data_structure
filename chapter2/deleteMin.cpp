#include <stdlib.h>
#include <stdio.h>
#include "../source/createLink.cpp"

void delMin(Link *p){
    if (!p) return;
    struct Link *minp = p->next, *preminp = p, *q = p->next, *preq = p, *f;
    
    while(!q){
        if (q->type.data < minp->type.data){
            minp = q;
            preminp = preq;
        }
        q = q->next;
        preq = p;
    }
    
    f = minp;
    preminp->next = p->next;
    free(f);
    
}


int main(){
    struct Link *p = createLink(0);
    
    delMin(p);

    return 0;
}