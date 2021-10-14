
/*
    设计算法判断一个无向图是否是一棵树
        分析：
            统计边和顶点数
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"


/**
 * @brief 深度优先得到生成树的numV和numE
 * 
 * @param G 
 * @param visited 已访问
 * @param numV 判断连通
 * @param numE 判断无环
 * @param index 起始点
 */
void DFS(ALGraph *G, int *visited, int &numV, int &numE, int index){
   visited[index] = 1;
   numV++;
   for(EdgeNode* p = G->adjlist[index].firstEdge; p; p->next){
       if(!visited[p->index]){
           numE++;
           DFS(G, visited, numV, numE, p->index);
       }
    }
}

bool isTree(ALGraph *G){
    /*

    */
    int numV = 0, numE = 0;
    int *visited = (int*)malloc(sizeof(int)*G->numV);
    for (int i = 0; i < G->numV; i++) *(visited + i) = 0;   //初始化visited
    DFS(G, visited, numV, numE, 0);
    if(numV == G->numV && numE == G->numV - 1) return true;
    else return false;
}

int main(){
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph *));
    createGraphInFile(G);
    dispGraph(G);
    
    isTree(G) ? printf("该图是树。") : printf("该图不是树。");

    return 0;
}
