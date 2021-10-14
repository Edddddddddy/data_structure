
/*
    实现prim算法（获得最小生成树）
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"

void outPut(ALGraph *G, int **weights){
    for (int i = 0; i < G->numV; i++)
        for (int j = i; j < G->numV; j++)
            if (weights[i][j] != 0)
                printf("%c->%c(%d)\n", G->adjlist[i].info, G->adjlist[j].info, weights[i][j]);
}

void prim(ALGraph *G, int start){
    //开辟空间，存储顶点序列，权值
    int *prims = (int *)malloc(sizeof(int )*G->numV);   //存储最终得到的序列
    int **weights = (int **)malloc(sizeof(int *)*G->numV);  //二维数组，存储各个点的权值
    for (int i = 0; i < G->numV; i++) prims[i]=-1;  //初始化，
    for (int i = 0; i < G->numV; i++) weights[i] = (int *)malloc(sizeof(int *)*G->numV);    //二维数组拆分为一维数组
    for (int i = 0; i < G->numV; i++)   //初始化存储的权值为0
        for (int j = 0; j < G->numV;j++) 
            weights[i][j] = 0;  
    
    int weight= 32767;  //用于比较的权值初始化为无穷
    int index = 0;  //初始下标
    int s;  //记录当前找到的最小边的启示顶点
    EdgeNode *r = (EdgeNode *)malloc(sizeof(EdgeNode *));   //记录当前最小边的终点
    prims[index++] = start;     //从哪里开始生成
    while (index != G->numV) {  //直到把所有v加入prims
        for (int i = 0; i < index; i++)     //以已经插入的每个点为中心，遍历查找，找出一个加入后s-r权值增加最少的起点s终点r
            for (EdgeNode *p = G->adjlist[i].firstEdge; p; p=p->next)      //遍历顶点数组
				if ( weight > p->weight && !weights[i][p->index] && prims[p->index]==-1 ) {//权值更小 && 未加入 && 终点未访问，则符合条件
					weight = p->weight;     //
					r = p;      //当前最小边终点
					s = i;      //起始顶点下标
				}
        
        //找到最短边后，加入prims数组，更新weights二维数组
        prims[index++] = r->index;  //加入prims
        weights[s][r->index] = r->weight;   //s-r的权重更新
        weights[r->index][s] = r->weight;   //r-s的权重更新
        weight = 32767;//重新置为无穷
    }
    outPut(G, weights);
}

int main(){
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph *));
	createGraphInFile(G);//创建图
	dispGraph(G);

    prim(G, 1);
    return 0;
}
