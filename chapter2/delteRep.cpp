#include <stdio.h>
#include <stdlib.h>
#include "../source/createLink.cpp"

/**
 * @brief 删除有序线性表中重复的元素
 * 
 * @param h 表头指针
 */
void deleteRep(Link *h){
    struct Link *p = h->next, *pre = h, *q;

    while(p->next){
        if(p->next->type.data == p->type.data){
            q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
        }
        pre = p;
        p = p->next;
    }
}

int main(){
    struct Link *h = createLink(0);

    deleteRep(h);

    printLink(h);

    return 0;
}
