#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

void divide(Link *la, Link* lb){
    int flag = 0;   //0 为偶数，1位奇数
    struct Link *l = la, *p = la->next, *rb = lb, *ra = la;
    l->next = NULL;
    while(p){
        // if(!flag){
        //     ra->next = p;
        //     ra = p;
        //     flag = 1;
        // }
        // else {        //     rb->next = p;
        //     rb = p;
        //     flag = 0;
        // }
        // p = p->next;
        if(!flag){
            ra->next = p;
            ra = p;
            flag = 1;
        }
        else {
            rb->next = p;
            rb = p;
            flag = 0;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;

}

int main(){
    struct Link *la = createLink(0);
    struct Link *lb = (struct Link*)malloc(sizeof(struct Link));

    divide(la, lb);

    printLink(la);
    printLink(lb);

    return 0;
}
