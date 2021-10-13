
/*
    查找x的所有祖先节点
    分析：
        因为打印所有祖先节点，而后序遍历使用栈保存所有祖先节点
        故使用非递归的后序遍历，遇到x时把栈中所有元素pop
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createStackS.cpp"


void findAllAncestor(biTree *T, Stack *s, char x){
    biTree *p = T, 
    *r = (biTree *)malloc(sizeof(biTree));
    // *tp = (biTree *)malloc(sizeof(biTree));

    while(p || !empty(s)){
        if(p){  //p存在，一直往左走
            push(s, p);
            p = p->lchild;
        } 
        else{   //向左走到头了
            p = top(s); //把栈顶元素取出（即当前节点的父节点，）
            if(p->rchild && r != p->rchild){    //右孩子是否存在
                r = p->rchild;  //r暂存父节点（保存第二次到达该节点，防止第三次到达以为是第二次）
                        //需要使用r的情况：p->rchild是叶子节点，这是r只会指p，否则r会继续向下移动
                push(s, p);
                p = p->lchild;
            }
            else{   //现在p的右孩子不存在（p为叶子节点）或 p = r（第三次到p）
                pop(s);
                if(p->data == x){
                    printf("祖先元素有:");
                    while(!empty(s)){
                        p = top(s);
                        pop(s);
                        printf("%c ", p->data);
                    }
                }
                p = NULL;   //若没找到x，则下一轮迭代往回走一步（p的父节点）
            }
        }
    }
}

int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    nodeNum(T, &count);
    
    Stack *s = createStackS(count);
    findAllAncestor(T, s, 'd');

    return 0;
}
