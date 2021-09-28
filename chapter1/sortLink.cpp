#include <stdio.h>
#include <stdlib.h>
#include "../source/createLink.cpp"

void bubbleSort(Link *h){
    int flag = 0;   
    int count = 0;  //链表长度

    struct Link *pre = h, *p = h->next, *r;
    while(p){   //求长度
        count++;
        p = p->next;
    }
    p = h->next;
    for(int i = 0; i < count; i++){
        flag = 0;   //初始化改动tag为0
        while(p->next){ //从第i个数字开始
            if(p->type.data > p->next->type.data){
                r = p->next->next;
                pre->next = p->next;
                p->next->next = p;
                pre = p->next;
                p->next = r;
                flag = 1;   //有改动
            }
            else{
                pre = pre->next;
                p = p->next;
            }
        }
        if(!flag)break;
        pre = h;    //重新遍历
        p = h->next;
    }

}

int main(){
    Link *h = createLink(0);

    bubbleSort(h);

    printLink(h);

    return 0;
}
