#include <stdio.h>
#include <stdlib.h>
#include "../source/createLink.cpp"

/**
 * @brief 求两个变量common suffix的位置
 * 
 * @param h1 
 * @param h2 
 * @return struct Link* 返回common suffix的位置
 */

struct Link *findComSuffix(Link *h1, Link *h2){
    //创建工作ptr，声明变量
    struct Link *p = h1->next, *q = h2->next;
    int len1 = 0, len2 = 0, gap;

    //求两个链表长度差
    while(p){
        len1++;
        p = p->next;
    }
    while(q){
        len2++;
        q = q->next;
    }

        //p指向长的单词
    if(len1 > len2 ){
        p = h1->next;
        q = h2->next;
        gap = len1- len2;
    }
    else{
        q = h1->next;
        p = h2->next;
        gap = len2 - len1;
    }

    //开始求comSuffix的位置
    //先将p挪动到剩下长度与q相等的位置
    while (gap--){
        p = p->next;
    }

    //遍历到指向相同的节点
    while(p != q){
        p = p->next;
        q = q->next;
    }
    return p;
}

int main(){
    //创建两个链表，工作指针
    
    struct Link *h1 = createLink(1);
    struct Link *h2 = createLink(1);
    struct Link *com = createLink(1);
    
    struct Link *p1 = h1->next;
    struct Link *p2 = h2->next;

    //将两个链表脸上后缀
    while(p1->next) p1 = p1->next;
    while(p2->next) p2 = p2->next;
    
    p1->next = com->next;
    p2->next = com->next;


    printf("输入的两个单词是：");
    printLink(h1);
    printLink(h2);
    
    com = findComSuffix(h1, h2);

    while(c) {
        printf("%c ", c->type.letter);
        c = c->next;
    }
    
    

    return 0;
}
