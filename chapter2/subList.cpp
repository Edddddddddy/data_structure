#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

/**
 * @brief 判断hb是否为ha的子序列
 * 
 * @param ha 
 * @param hb 
 * 
 * @return 是否为子序列
 */
int subList(Link *ha, Link *hb){
    struct Link *pa = ha->next, *pb = hb->next, *la = ha->next;
    while(pa&&pb){
        if(pa->type.data == pb->type.data){
            pa = pa->next;
            pb = pb->next;
        }
        else{
            pb = hb->next;
            la = la->next;
            pa = la;
        }
    }
    return pb == NULL ? true : false; 
}

int main(){
    struct Link *ha = createLink(0);
    struct Link *hb = createLink(0);

    printf("%d", subList(ha, hb));

    return 0;
}
