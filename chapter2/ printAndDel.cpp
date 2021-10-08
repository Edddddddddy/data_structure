#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

/**
 * @brief 遍历n次，每次输出最小值并且free
 * 
 * @param h 
 */
void printAndDel(Link *h){
    struct Link *p = h->next, *pre = h, *min = p, *minpre = h, *q;
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    p = h->next;
    for (int i = 0; i < count; i++){
        while(p){
            if(p->type.data < min->type.data){
                minpre = pre;
                min = p;
            }
            pre = p;
            p = p->next;
        }
        printf("%d ", min->type.data);
        q = min->next;
        minpre->next = min->next;
        free(min);
        pre = minpre = h;
        p = min = h->next;
        
    }
}

int main(){
    struct Link *h = createLink(0);

    printAndDel(h);

    return 0;
}
