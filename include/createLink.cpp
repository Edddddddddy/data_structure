#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>


struct Link{
    union{  //能够创建不同类型的data活letter
        int data;
        char letter;
    }type;
    struct Link *next;
};

/**
 * @brief Create a Link object
 * 
 * @param num 0表示生成的数据类型为int，1为char
 * @return Link* 返回生成链表的头节点指针
 */
Link* createLink(int num){
    
    int n,data;
    char letter;
    printf("请输入创建链表的节点个数：");
    scanf("%d", &n);

    struct Link *q;
    struct Link *head = (struct Link*)malloc(sizeof(struct Link));
    head->next = NULL;
    q = head; //保存link头指针
    for(int i = 0; i < n; i++){
        //临时指针用来插入
        struct Link *p = (struct Link*)malloc(sizeof(struct Link));
        printf("请输入第%d个节点value：", i+1);
        if(num == 0){
            scanf("%d", &data);
            p->type.data = data;
        }
        else {
            getchar();
            scanf("%c", &letter);
            p->type.letter = letter;
        }
        //插入过程中head实际上指的是rear
        p->next = NULL;
        head->next = p;
        head = head->next;
    }
    head->next = NULL;
    head = q; //head指回head
    printf("打印链表：\n");
    while(head->next){
        if(num == 0) printf("%d ", head->next->type.data);
        else printf("%c ", head->next->type.letter);
        head = head->next;
    }
    printf("\n");
    head = q;
    return head;
}

void printLink(Link *l, int num){
    struct Link *p = l->next;
    printf("打印链表：");
    if (!p) {
        printf("链表为空！\n");
        return ;
    }
    if(num == 1){
        while (p){
            printf("%c ", p->type.letter);
            p = p->next;
        }
    }
    else if (num == 0){
        while (p){
            printf("%d ", p->type.data);
            p = p->next;
        }
    }
    printf("\n");
}