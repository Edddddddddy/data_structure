/*
    单链表的表头指针为h，节点结构由data和next两个域构成，其中data为char类型
    设计功能判断长度为n的链表是否中心对称。
    
    分析： 
        利用栈特点，使用fast slow指针，对后半节点逆序pop，使得前一半顺序和后一半逆序一一比较相同
        相同则对称
*/

#include <stdio.h>
#include <stdlib.h>
#include "../source/createStack.cpp"
#include "../source/createLink.cpp"

void isSymmetry(Link *h){
    int size = 0;
    struct Link *fast = h->next, *slow = h->next;
    
    //计算链表长度，获得应开辟栈的空间大小
    while(fast) {
        fast = fast->next;
        size++;
    }
    fast = h->next;
    struct Stack *s = createStack(size);  

    //slow找到中间节点，这时fast 走到倒数第一个或倒数第二个
    while (fast->next && fast->next->next){ 
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = h->next; //fast 回到第一个节点

    //将slow后（即后一半）节点元素入栈
    while(slow->next){  
        push(s, slow->next->type.letter);
        slow = slow->next;   
    }
    while(!empty(s)){   //pop(s)
        if(fast->type.letter != top(s)){
            printf("该链表非中心对称");
            break;
        } 
        fast = fast->next;
        pop(s);
    }
    if(empty(s)) printf("该链表中心对称");
    destory(s);
}

int main(){
    struct Link *h = createLink(1);
    
    isSymmetry(h);

    return 0;
}
