
/*
    该文件用于创建图结构，使用邻接表
    分析：
        1 顶点表
        2 边
        3 数组存储顶点
        4 图
        创建流程：
            输入顶点和边，构建顶点表，输入顶点信息
            建立边表

*/


#define MAXSIXE 100
#define TYPE int 


typedef struct EdgeNode{    //边表节点
    int index;  //边指向的节点
    int weight; 
    EdgeNode *next; 
}EdgeNode;

typedef struct VertexNode{  //顶点表节点
    TYPE info;  //顶点信息
    EdgeNode *firstEdge;    //第一条边
}VertexNode, Adjlist[MAXSIXE];

typedef struct ALGraph{ //邻接表信息总汇
    Adjlist adjlist;    //顶点数组
    int numE, numV; 
}ALGraph;

#include <stdio.h>
#include <stdlib.h>

void createGraph(ALGraph *G){
    int e, v, vi, vj, w;
    printf("输入边数与结点数（空格号分开）：");
    scanf("%d %d", &e, &v);
    G->numE = e;
    G->numV = v;
    printf("请依次输入顶点信息：\n")
    for (int i = 0; i < G->numV; i++){
        printf("请输入第%d个顶点信息：", i+1);
        scanf("\n%c", &G->adjlist[i].info);
        G->ad
    }
}