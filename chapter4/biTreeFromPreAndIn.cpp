
/*
    该方法实现通过先序和中序遍历，建立原二叉树
    分析：

*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"


biTree *preInCreate(char *arrIn, char *arrPre, int l1, int h1, int l2, int h2){
    //l1 h1 表示中序的第一个和最后一个节点下标， h2 l2为先序
    int llen, rlen , i;
    biTree *T = (biTree *)malloc(sizeof(biTree));
    T->data = *(arrPre + l2);
    for( i = l1; *(arrIn + i) != T->data; i++); //找到目前的根节点

    llen = i - l1;
    rlen = h1 - i;

    if(llen){
        T->lchild = preInCreate(arrIn, arrPre, l1, l1+llen-1, l2+1, l2+llen);
    }else{
        T->rchild = NULL;
    }
    if(rlen){
        T->rchild = preInCreate(arrIn, arrPre, h1-llen+1, h1, h2-llen+1, h2);
    }
    else{
        T->rchild = NULL;
    }
    return T;
}

int main(){
	char arrIn[] = { 'D','B','E','A','F','C','G' }, 
		arrPre[] = {'A','B','D','E','C','F','G'};
    
    biTree *T = preInCreate(arrIn, arrPre, 0, 6, 0, 6);
    // biTree *T = create(T);
    inOrder(T);
    printf("\n");
    preOrder(T);
    return 0;
}
