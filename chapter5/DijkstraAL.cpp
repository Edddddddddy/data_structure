
/*
    邻接表实现dijkstra（单源最短路径）
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"

/**
 * @brief 计算a-b的距离
 * 
 * @param G 
 * @param a 
 * @param b 
 * @return int 
 */
int getWeiFromAtoB(ALGraph *G, int a, int b) {
    for (EdgeNode *p = G->adjlist[a].firstEdge; p; p = p->next) 
        if (p->index == b) //有直接连接，返回权值
            return p->weight;
    return 32767;
}

void dijkstra(ALGraph *G, int start){
    /*
        1 初始化flag dist prevs三个数组存储
        2 开始通过遍历将每一个结点放入
        3 找到与当前树相连的，边权值最小的结点
        4 更新start可及的结点的最短路径
    */
    //初始化
    int flag[100];  //标记是否访问过
    int preV=0;
    int dist[100];  
    int prevs[100]; //顶点前驱
    int k = start;
    for (int i = 0; i < G->numV; i++) 
        dist[i] = 32767;  //初始化为无穷
    for (EdgeNode *p = G->adjlist[start].firstEdge; p; p = p->next) 
        dist[p->index] = p->weight;     //更新当前结点的所有边权值
    for (int i = 0; i < G->numV;i++) {
		prevs[i] = 0;   
		flag[i] = 0;    
	}
    flag[0] = 1;
    //遍历每一个结点，更新numV次dist
    for (int i = 0; i < G->numV;i++) {
        //第一次
        if (start == i)continue;

        //找到具有最小的距离min且没有访问过的顶点，将其flag设置为1
        int min = 32767;
        for (int j = 0; j < G->numV; j++) {
            if (!flag[j] && dist[j]<min) {  
                min = dist[j];
                k = j;
           	}
		} 
        flag[k]=1;
        
        //找到新顶点，更新dist
        for (int m = 0; m < G->numV; m++) {
            int weight = getWeiFromAtoB(G, k, m);   //m-k的最短路径，依次更新
            if (!flag[m] && dist[m] > weight + dist[k]) {   
                dist[m] = weight + dist[k];
                prevs[m] = k;   
			}
		}
	}
    for (int i = 0; i < G->numV;i++) 
        printf("%c ",G->adjlist[prevs[i]].info);
    
}

int main(){
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph *));
    createGraphInFile(G);
    dispGraph(G);
    
	dijkstra(G, 0);
    return 0;
}
