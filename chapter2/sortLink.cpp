#include <stdio.h>
#include <stdlib.h>
#include "../include/createLink.cpp"

void bubbleSort(Link *h){
    int flag = 0;   
    int count = 0;  //��������

    struct Link *pre = h, *p = h->next, *r;
    while(p){   //�󳤶�
        count++;
        p = p->next;
    }
    p = h->next;
    for(int i = 0; i < count; i++){
        flag = 0;   //��ʼ���Ķ�tagΪ0
        while(p->next){ //�ӵ�i�����ֿ�ʼ
            if(p->type.data > p->next->type.data){
                r = p->next->next;
                pre->next = p->next;
                p->next->next = p;
                pre = p->next;
                p->next = r;
                flag = 1;   //�иĶ�
            }
            else{
                pre = pre->next;
                p = p->next;
            }
        }
        if(!flag)break;
        pre = h;    //���±���
        p = h->next;
    }

}

int main(){
    Link *h = createLink(0);

    bubbleSort(h);

    printLink(h);

    return 0;
}
