
/*
    该方法实现把邻接表转换成邻接矩阵
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"


// //复习
//邻接矩阵
typedef struct Graph{
    char Vertex[MAXSIZE];
    int Edge[MAXSIZE][MAXSIZE];
    int numV, numE;
}adjMatrix;


// //邻接表
// typedef struct EdgeNode{    //边
//     int index;  //指向的结点
//     int weight;
//     EdgeNode *next;
// }EdgeNode;

// typedef struct VertexNode{  //结点
//     char info;
//     EdgeNode *findEdge;
// }VertexNode, Adjlist[MAXSIZE];

// typedef struct ALGraph{
//     Adjlist adjlist;
//     int numE, numV;
// }ALGraph;

// void edgeIput(ALGraph *alG, adjMatrix *amG, int index, int *visited) {
// 	visited[index] = 1;//标记为已访问
// 	for (EdgeNode *p = alG->adjlist[index].firstEdge; p; p = p->next) {
// 		amG->Edge[index][p->index] = p->weight;//边信息存入邻接矩阵
// 		if (!visited[p->index])
// 			edgeIput(alG, amG, p->index, visited);
// 	}
// }
void dispGraph(adjMatrix *G) {
	/*
			
	*/
	int i, j;
	printf("\n输出顶点的信息（字符）:\n");
	for (i = 0; i < G->numV; i++)
		printf("%8c", G->Vertex[i]);

	printf("\n输出邻接矩阵:\n");
	printf("\t");
	for (i = 0; i < G->numV; i++)
		printf("%8c", G->Vertex[i]);

	for (i = 0; i < G->numV; i++)
	{
		printf("\n%8c", G->Vertex[i]);
		for (j = 0; j < G->numV; j++)
		{
			if (G->Edge[i][j] == 32767)
				//两点之间无连接时权值为默认的32767，
				//在无向图中一般用"0"表示，在有向图中一般用"∞",
				//这里为了方便统一输出 "∞"
				printf("%8s", "∞");
			else
				printf("%8d", G->Edge[i][j]);
		}
		printf("\n");
	}
}
void transform(ALGraph *alG, adjMatrix *amG){
    /*
        1 存入数量信息，结点数据
        2 存入边信息
    */
    //传输信息
    amG->numE = alG->numE;
    amG->numV = alG->numV;
    for (int v = 0; v < amG->numV; v++)  amG->Vertex[v] = alG->adjlist[v].info; 
    //初始化矩阵，到自己是0，到别人初始化为无穷
    for (int i = 0; i < amG->numV; i++)
    	for (int j = 0; j < amG->numV; j++)
            i == j ? amG->Edge[i][j] = 0 : amG->Edge[i][j] = 32767;
    //存入边的信息
    for (int v = 0; v < amG->numV; v++) {
		//存入边信息
		EdgeNode *p = alG->adjlist[v].firstEdge;    //p是自己，再往后
		while (p) {     
			amG->Edge[v][p->index] = p->weight;
			p = p->next;
		}
	}
}

int main(){
    ALGraph *alG= (ALGraph *)malloc(sizeof(ALGraph *));
    adjMatrix *amG = (adjMatrix *)malloc(sizeof(adjMatrix *));
    createGraphInFile(alG);
    transform(alG, amG);
    dispGraph(amG);
    
    return 0;
}
