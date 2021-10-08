#include <stdio.h>
#include <stdlib.h>
#include "../include/createSinLoopLink.cpp"

void inputAndDeleteLink(struct Link *h){
    struct Link *pre = h, *minpre = h, *p = h->next, *min = h->next, *r;
    while(h->next != h){
        while(p!=h){
            if(p->data < min->data){
                minpre = pre;
                min = p;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        r = min;
        minpre->next = min->next;
        free(r);
        printf("%d ", min->data);
        minpre = pre = h;
        min = p = h->next;
    }
}

int main(){
    struct Link *h = createSinLoopLink();    

    inputAndDeleteLink(h);

    return 0;
}
