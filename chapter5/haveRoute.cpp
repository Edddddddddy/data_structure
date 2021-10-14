
/*
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"
#include "../include/createLQueue.cpp"

void DFS2(ALGraph *G, int vi, int vj, int *visited, int &flag){
    for(EdgeNode *p = G->adjlist[vi].firstEdge; p; p = p->next){
        if(!visited[p->index]){
            visited[p->index] = 1;
            if(p->index == vj) flag = 1;    //找到
            DFS2(G, p->index, vj, visited, flag);
        }
    }
}

bool judgeRouteInDFS(ALGraph *G, int vi, int vj){
    int *visited = (int*)malloc(sizeof(int)*G->numV);
    int flag = 0;
    for(int i = 0; i < G->numV; i++) visited[i] = 0;
    if(!visited[vi]) {
        visited[vi] = 1;
        DFS2(G, vi, vj, visited, flag);
    }
    return flag;
}

bool judgeRouteInBFS(ALGraph *G, int vi, int vj){
    int *visited = (int*)malloc(sizeof(int)*G->numV);
    int flag = 0;
    int index;
    LQueue *lq = createLQueue();
    for(int i = 0; i < G->numV; i++) visited[i] = 0;
    // if(!visited[vi]){
    //     visited[vi] = 1;
    //     enQueue(lq, vi);
    // }
    enQueue(lq, vi);
    while(!isEmpty(lq)){
        deQueue(lq, &index);
        if (!visited[index]) {
			visited[index] = 1;
			if (vj == index) {
				flag = 1;
			}
		}
        for (EdgeNode *p = G->adjlist[index].firstEdge; p; p = p->next) {
			if (!visited[p->index]) {
				enQueue(lq, p->index);  //把所有的未访问过得邻接顶点入队
			}
		}
    }
    return flag;
}


int main(){
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph *));
    createGraphInFile(G);
    dispGraph(G);
    
    // judgeRouteInDFS(G, 1, 7) ? printf("存在路径。") : printf("不存在路径。");
    judgeRouteInBFS(G, 1, 10) ? printf("存在路径。") : printf("不存在路径。");
    return 0;
}
