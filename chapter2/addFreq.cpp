
#include <stdio.h>
#include <stdlib.h>
#include "../source/createDouLink.cpp"

/**
 * @brief 用户输入要查找的x，此方法根据每个节点被访问次数记录freq对链表进行降序排序
 * 
 * @param h 表头
 * @param x 要查找的数
 */
void locate(Link *h, int x){
    //先查找，若查找成功，则freq++并排序；若不成功，则提示没找到
    int flag = 0;
    struct Link *p = h->next, *r, *q;

    while(p){
        if (p->data == x){  //找到
            flag = 1;
            p->freq++;

            //排序
            struct Link *q = p->pre;
            
            while(q != h){
                if(q->freq <= p->freq) q = q->pre;
            }
            if(!p->next) {
                p->pre->next = NULL;
            }
            else{
                p->pre->next = p->next;
                p->next->pre = p->pre;
            }
            p->next = q->next;
            q->next->pre = p;
            p->pre = q;
            q->next = p;
            break;
        }
        p = p->next;
    }
    if(!flag) printf("未找到该元素,序列不做改变");
}


int main(){
    struct Link *h = createDouLink(), *p;

    int num;

    do {
		printf("请输入要查找的值,输入9999代表结束：num=");
		scanf("%d",&num);
		if (num == 9999)continue;//如果num=9999，跳入下一次循环
		locate(h,num);
		p = h->next;
		printf("调整后链表为：\n");
		while (p) {
			printf("%d ",p->data);
			p = p->next;
		}
	} while (num!=9999);

    return 0;
}
