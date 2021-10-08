#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

void deleteNum(Link *h, int min, int max){
    struct Link *p = h->next, *pre = h, *q;
    while(p){
        if(p->type.data >= min && p->type.data <= max){
            q = p;
            pre->next  = p->next;
            free(q);
            p = pre->next;
        }
        else{
            pre = pre->next;
            p = p->next;
        }
    }
}

int main(){
    struct Link *h = createLink(0);

    int min, max;

    printf("输入最大值和最小值并用空格隔开（min max）：");
    scanf("%d %d", &min, &max);

    deleteNum(h, min, max);

    printLink(h);

    return 0;
}
