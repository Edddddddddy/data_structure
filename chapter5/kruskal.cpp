
/*
    该文件实现kruskal算法
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"

int find(int *fa, int i){   
    //查
    if(fa[i] != i) fa[i] = find(fa, fa[i]);
    return fa[i];
}

void unionn(int *fa, int i, int j){
    //并
    fa[find(fa, i)] = find(fa, j);  //i的祖先指向j的祖先
}

void kruskal(ALGraph *G){

    int **weights = (int **)malloc(sizeof(int *)*G->numV);
    int *fa = (int *)malloc(sizeof(int)*G->numV);
    for (int i = 0; i < G->numV; i++) 
        fa[i] = i;
    for (int i = 0; i < G->numV; i++) 
        weights[i] = (int *)malloc(sizeof(int *)*G->numV);
    for(int i = 0; i < G->numV; i++)
        for(int j = 0; j < G->numV; j++)
            weights[i][j] = 0;
    int edges = 0;  //记录边数

    while(edges < G->numV){
        int weight = 32767;
        int start, end;
        for (int i = 0; i < G->numV; i++)
            for(EdgeNode *p = G->adjlist[i].firstEdge; p; p = p->next)
                //找weight最小且有共同祖先的p和fai
                if(p->weight < weight && find(fa, i) != find(fa, p->index)){
                    weight = p->weight;
                    start = i;
                    end = p->index;
                }
        unionn(fa, start, end);
        weights[start][end] = weight;
		weights[end][start] = weight;
		edges++;
    }
    outPut(G, weights);
}

int main(){
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph *));
    createGraphInFile(G);
    dispGraph(G);
    
    kruskal(G);
    return 0;
}
