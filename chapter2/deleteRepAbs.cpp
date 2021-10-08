#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

void deleteRepAbs(struct Link *h){
    struct Link *p = h->next, *pre = h, *q;
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    p = h->next;
    //创建hashmap
    int *arr = (int *)malloc(sizeof(int)*count);
    for (int i = 0; i < count; i++) arr[i] = 0;

    while(p){
        if(arr[abs(p->type.data)] == 0) {
            arr[abs(p->type.data)]++;
            p = p->next;
            pre = pre->next;
        }
        else {
            q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
        }
    }
}

int main(){
    struct Link *h = createLink(0);

    deleteRepAbs(h);

    printLink(h, 0);


    return 0;
}
