
/*
    该文件实现floyd算法
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAM.cpp"


void floyd(adjMatrix *G,int path[][MAXSIZE]) {
	/*
		1 初始化两个数组path dist
		2 三次遍历
		3 第一次 每一遍加入一个新的中转点
		4 后两次 遍历二维数组dist，更新dist和path信息
	*/
    int i, j, k;
	int dist[MAXSIZE][MAXSIZE]; 
    //初始化v间距离、中转路径
	for (int m = 0; m < G->numV; m++) {
		for (int n = 0; n < G->numV; n++) {
			dist[m][n] = G->Edge[m][n];//初始化顶点间距离
			path[m][n] = -1;//初始化路径
		}
	}
    for (k = 0; k < G->numV; k++) { //直到所有节点加入
        //更新二维矩阵每一个点
		for (i = 0; i < G->numV; i++) { 
			for (j = 0; j < G->numV; j++) {
				if (dist[i][j] > G->Edge[i][k] + G->Edge[k][j]) {   //经过新加入的k，更新每一个点，path，dist
					dist[i][j] = G->Edge[i][k] + G->Edge[k][j]; 
					path[i][j] = k; //path更改
				}
			}
		}
	}
    //输出dist矩阵
    for (int i = 0; i < G->numV; i++){
		for (int j = 0; j < G->numV; j++)
			printf("%2d  ", dist[i][j]);
		printf("\n");
	}
}    

/**
 * @brief 输出中转路径
 * 
 * @param path 
 * @param vi 
 * @param vj 
 */
void printPath(int path[][MAXSIZE],int vi,int vj) {
	if (path[vi][vj]==-1) printf("%d ",vj+1);   //自己到自己
	else {
		int mid = path[vi][vj]; 
		printPath(path, vi, mid);
		printPath(path,mid,vj);
	}
}

int main(){
    Graph *G = (Graph *)malloc(sizeof(Graph *));
    createGraphInFile(G);
    dispGraph(G);
    
    int path[MAXSIZE][MAXSIZE];
	floyd(G,path);
    printPath(path,1,3);
    return 0;
}
