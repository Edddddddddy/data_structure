
/*
    查找第k小的节点
    分析：
        时间复杂度为O(log2n)，使用递归
        1 T->lchild != NULL
            1.1 T->lchild->count == k-1: return T
            1.2 T->lchild->count > k-1, 向左走
            1.3 T->lchild->count < k-1， 向右走
        2 T->rchild == NULL
            2.1 T->rchild != NULL && k = 1 : return T
            2.2 T->rchild != NULL && k!=1 : go right

    getCount方法:
        计算该节点指针所指的树有多少节点
        

*/
typedef struct node
{
    int data;
    int count;
    struct node *lchild, *rchild;
}biTree;

#include <stdio.h>
#include <stdlib.h>

biTree *create(biTree *T){
    int data;
    printf("请输入当前节点值：data=");
    scanf("%d", &data);
    getchar();
    if(data != -1){
        T = (node *)malloc(sizeof(node));
        T->data = data;
        T->lchild = NULL;
        T->rchild = NULL;
        T->lchild = create(T->lchild);
        T->rchild = create(T->rchild);
    }
    return T;
}

/**
 * @brief 计算每个节点的count
 * 
 * @param T 
 * @return int 
 */
int getCount(biTree *T){
    if(!T) return 0;
    int lcount, rcount;
    lcount = getCount(T->lchild);
    rcount = getCount(T->rchild);
    T->count = lcount + rcount + 1;
    return lcount + rcount + 1;
}

biTree *findKth(biTree *T, int k){
    if(k < 1 || k>T->count)return NULL;
    if(T->lchild){
        if(T->lchild->count == k-1) return T;
        else if(T->lchild->count < k-1) return findKth(T->rchild, k - T->lchild->count - 1);
        else return findKth(T->lchild, k);
    }
    else {
        if(k == 1) return T;
        else return findKth(T->rchild, k - 1);
    }
}

int main(){
    int k = 2;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    getCount(T);
    printf("%d", findKth(T, k)->data);

    return 0;
}
