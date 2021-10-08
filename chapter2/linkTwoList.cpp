#include <stdio.h>
#include <stdlib.h>
#include "../include/createSinLoopLink.cpp"
/**
 * @brief 将两个循环单链表连接，h2连接到h1后
 * 
 * @param h1 
 * @param h2 
 */
void linkTwoList(Link *h1, Link *h2){
    struct Link *p1 = h1->next, *p2 = h2->next;
    while(p1->next != h1) p1 = p1->next;
    p1->next = p2;
    while(p2->next != h2) p2 = p2->next;
    p2->next = h1;
}

int main(){
    struct Link *h1 = createSinLoopLink();
    struct Link *h2 = createSinLoopLink();

    linkTwoList(h1, h2);
    printLink(h1);

    return 0;
}
