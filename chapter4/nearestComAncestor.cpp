
/*
    p，q指向二叉树中任两点，使用ancestor(root, p, q, r)寻找最近的公共节点r
    分析：
        使用两个栈，后续遍历查找p，q，找到后查找栈中第一个相同的元素
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createStackS.cpp"

/**
 * @brief 后序遍历，找到x的所有祖先，得到一个栈
 * 
 * @param s 保存用的栈
 * @param m 根节点
 * @param x 要查找的节点
 */
void findAncestor(Stack* *s, biTree *m, biTree *x){
    biTree *r = (biTree*)malloc(sizeof(biTree));

    while(m || !empty(*s)){
        if(m){  //一直向左走
            push(*s, m);
            m =m->lchild;
        }
        else{
            m = top(*s); //左走走到头，向上回一个节点
            if(m->rchild && r != m->rchild){  //右孩子存在，且r不指向m，向右走一步
                m = m->rchild;
                push(*s, m);
                m = m->lchild;
            }
            else{
                pop(*s);
                if(m->data == x->data) break;   //找到了x
                r = m;
                m = NULL;   //防止第二次进入左子树
            }
        }
    }
}


void findNearestComAncestor(biTree *T, biTree *p, biTree *q, biTree* *r){
    int count = 0;
    nodeNum(T, &count);

    biTree *m = T;

    Stack *sp = createStackS(count);
    Stack *sq = createStackS(count);

    findAncestor(&sp, m, p);
    findAncestor(&sq, m, q);
    while (!empty(sp)) {    //遍历sp，找sq中是否有元素
		*r = top(sp);
		if (contain(sq,*r)) {//判断sq中知否包含d
			break;
		}
		pop(sp);
	}
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree)), *p, *q;
    biTree *r = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    nodeNum(T, &count);
    // p = T->lchild->lchild->rchild;//手动指定一个节点，切记不要指成NULL了
	// q = T->rchild->rchild;

    p = T->lchild;
	q = T->lchild->rchild;
    findNearestComAncestor(T, p, q, &r);
    printf("最近公共祖先节点为：%c", r->data);
    return 0;
}
