
/*
    层次便利，构造孩子兄弟链表
    分析：
        结构体有fch（firstchild）和nsib（nextsibling），创建时为空
        遍历节点，计算出度d>0时有孩子节点，分成fch和nsib

*/

typedef struct node{
    char data;
    node *fch, *nsib;
}Tree;

#include <stdio.h>
#include <stdlib.h>

node *create(node *T){
    char data;
    printf("请输入当前节点值：data=");
    scanf("%c", &data);
    getchar();
    if(data != '#'){
        T = (node *)malloc(sizeof(node));
        T->data = data;
        T->fch = NULL;
        T->nsib = NULL;
        T->fch = create(T->fch);
        T->nsib = create(T->nsib);
    }
    return T;
}

void inOrder(Tree *T) {
	if (T) {
		inOrder(T->fch);
		printf("%c ", T->data);
		inOrder(T->nsib);
	}
};