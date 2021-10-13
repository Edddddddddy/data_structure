
/*
    给定树的层次遍历和节点的度，构造CSTree
    分析：
        出度d，d>0则将第一个孩子放到fch其他放到nsib
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createCSTree.cpp"


void createCSTree_degree(char *level, int *degree, node **ptr, int n){
    int k = 0;
    for(int i = 0; i < n; i++){ //初始化ptr
        (ptr[i]->data) = level[i];
        (ptr[i]->fch) = NULL;
        (ptr[i]->nsib) = NULL;
    }
    for(int i = 0; i < n; i++){
        int d = degree[i];  
        if(d){  //不是叶子结点
            k++;    //记录第几个孩子节点
            (ptr[i])->fch = (ptr[k]);   //第一个指向fch
            for(int j = 0; j < d - 1; j++){ //后面的连着nsib
                k++;
                ptr[k-1]->nsib = ptr[k];
            }
        }
    }
}


int main(){
    char level[6] = { 'A','B','E','G','D','F'};//层次遍历结果
	int degree[] = { 3,2,0,0,0,0 }; //节点出度（层次遍历对应）
    
    node* *ptr = (node* *)malloc(sizeof(node*)*6);   //分配整个二维数组
    for(int i = 0; i < 6; i++){
        ptr[i] = (node*)malloc(sizeof(node*));  //分配每个一维数组
    }
    createCSTree_degree(level, degree, ptr, 6);
    inOrder(ptr[0]);
    return 0;
}
