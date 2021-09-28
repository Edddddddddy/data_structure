#include <stdio.h>
#include <stdlib.h>
#include "../source/createLink.cpp"

void divide(Link *la, Link *lb){
    int flag = 0;
    struct Link *p = la->next, *ra = la, *rb = lb, *q;
    la->next = NULL;
    while(p){
        if(!flag){
            ra->next = p;
            ra = p;
            flag = 1;
            p=p->next;
        }
        else{
            q = p;
            p=p->next;
            if (!lb->next) {
                q->next = NULL;
                rb = q;
            }
            else q->next = rb;
            lb->next = q;
            flag = 0;
        }
    }
    ra->next = NULL;
}

int main(){
    struct Link *la = createLink(0);
    struct Link *lb = (struct Link*)malloc(sizeof(struct Link));

    divide(la, lb);

    printLink(la);
    printLink(lb);

    return 0;
}
