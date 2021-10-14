
/*
    该文件用于创建图文件
*/

#define MAXSIZE 100
#if !defined(TYPE)
#define TYPE int
#endif // TYPE

typedef struct EdgeNode {//边表结点
	int index;//该边所指向的顶点的位置,在顶点数组里面的位置信息
	int weight;//权值
	EdgeNode *next;//下一个邻接边
}EdgeNode;

typedef struct VertexNode {//顶点表节点
	TYPE info;//顶点信息
	EdgeNode *firstEdge;//指向第一条依附该顶点的边的指针
}VertexNode, Adjlist[MAXSIZE];

typedef struct {
	Adjlist adjlist;//顶点数组
	int numE, numV;//边数、顶点数
}ALGraph;

#include <stdio.h>
#include <stdlib.h>
#include "./createSQueue.cpp"


// void createGraph(ALGraph *G){
//     int e,v,vi,vj,w;
//     printf("请输入图的边数与结点数（以空格分开）：");
// 	scanf("\n%d %d", &e, &v);
//     G->numE = e;
//     G->numV = v;
//     printf("请一次输入顶点信息：\n");
//     for (int i = 0; i < G->numV; i++){
//         printf("请输入第%d个结点信息：", i+1);
//         scanf("\n%c", &G->adjlist[i].info);
//         G->adjlist[i].firstEdge = NULL;
//     }

//     printf("请输入边表信息：\n");
//     for (int i = 0; i < G->numE; i++) {
// 		printf("请输入边（vi，vj）的顶点序号及其权值（以空格分开）：");
// 		scanf("%d %d %d", &vi, &vj, &w);
//         EdgeNode *e = (EdgeNode *)malloc(sizeof(EdgeNode *));
//         e->index = vj - 1;
//         e->weight = w;
//         e->next = G->adjlist[vi - 1].firstEdge;
//         G->adjlist[vi - 1].firstEdge = e;
//     }
// }

void createGraphInFile(ALGraph *G){ //从文件读取创建
    FILE *fp = NULL;
    char ev[4] = {};
    char numE[3] = {0}; //存储顶点个数信息
    char numV[3] = {0}; //边个个数信息
    char arc[6] = {0};  //边信息
    char *vertex;   //顶点信息，名称

    //建立图结构
    fp = fopen("../source/graph.txt", "r");
    if(fp == NULL){
        printf("该文件无法打开！");
        return;
    }
    fscanf(fp, "%hu %hu", numE, numV);  //读取第一行
    G->numE = numE[0];
    G->numV = numV[0];
    vertex = (char *)malloc(sizeof(char *)*G->numV);    //该数组专门用来存储顶点信息（名称）

    //输入信息
    for(int i = 0; i < G->numE; i++){  //开始获取第二行开始的信息
        if(i == 0){ //获取第二行的是顶点信息
            fgets(ev, 4, fp);   //之前最后一个回车没有获取，此处获取回车
            //获取第三行
            fgets(vertex, G->numV*2, fp);   //读取整个第二行（包括numV个结点和numV个空格）
            int w = 0;  //保存adjlist
            for (int j = 0; j < G->numV*2; j++){    //存入G->adjlist
                if(vertex[j] == 32) continue;   //空格跳过
                else {  //初始化每个结点
                    G->adjlist[w].info = vertex[j];
                    G->adjlist[w].firstEdge = NULL;
                    w++;
                }
            }
        }
        else{
            fgets(ev, 4, fp); //吃换行
            fgets(arc, 6, fp);  //获取边信息
            EdgeNode *e = (EdgeNode *)malloc(sizeof(EdgeNode));
            //分配信息
            e->index = atoi(&arc[2]) - 1;   //数组下标
            e->weight = atoi(&arc[4]);  //权重
            //头插法插入
            e->next = G->adjlist[atoi(&arc[0])-1].firstEdge;
            G->adjlist[atoi(&arc[0])-1].firstEdge = e;


            //下面与上面相似，目的在于构建无向图
			//EdgeNode *otherE = (EdgeNode *)malloc(sizeof(struct EdgeNode ));
			//otherE->index = atoi(&arc[0]) - 1;//数组下标要减一
			//otherE->weight = atoi(&arc[4]);
			//otherE->next = G->adjlist[atoi(&arc[2]) - 1].firstEdge;
			//G->adjlist[atoi(&arc[2]) - 1].firstEdge = otherE;
        }
    }
    fclose(fp);
}

/**
 * @brief 输出最小生成树
 * 
 * @param G 
 * @param weights 
 */
void outPut(ALGraph *G, int **weights){
    //遍历二维数组，打印有权值的边
    for (int i = 0; i < G->numV; i++)
        for (int j = i; j < G->numV; j++)
            if (weights[i][j] != 0)
                printf("%c->%c(%d)\n", G->adjlist[i].info, G->adjlist[j].info, weights[i][j]);
}

/**
 * @brief 输出邻接表
 * 
 * @param G 
 */
// void dispGraph(ALGraph *G){
//     for(int i = 0; i < G->numV; i++){
//         int j = i;
//         printf("%c-->", G->adjlist[j].info);
//         EdgeNode *p = G->adjlist[j].firstEdge;
//         while(p){
//             printf("(%d)%c-->", p->weight, G->adjlist[p->index].info);
//             p = p->next;
//         }
//         printf("^\n");
//     }
// }


//广度优先
void BFSBegin(ALGraph *G){
    void BFS(ALGraph*, int*, int);
    int *visited = (int *)malloc(sizeof(int)*G->numV);
    //初始化
    for(int i = 0; i < G->numV; i++) visited[i] = 0;
    for(int i = 1; i < G->numV; i++)
        if(!visited[i]) 
            BFS(G, visited, i);
}

void BFS(ALGraph *G, int *visited, int v){
    SQueue *sq = createSQueue(G->numV+1);
    //传入第一个结点
    printf("%c ", G->adjlist[v].info);
    enQueue(sq, v, G->numV + 1);
    visited[v] = 1;
    while(!isEmpty(sq)){
        //队首元素出队
        TYPE top;
        deQueue(sq, &top, G->numV + 1);
        //其firstEdge入队
        for (EdgeNode *w = G->adjlist[top].firstEdge; w; w=w->next){    //重复操作
            if(!visited[w->index]){ //未被访问过
                printf("%c ", G->adjlist[w->index].info);   //打印这一轮入队的元素
                visited[w->index] = 1;  //设置为已访问
                enQueue(sq, w->index, G->numV); //入队
            }
        }
    }
}


//深度优先
void DFSBegin(ALGraph *G){
    void DFS(ALGraph *, int *, VertexNode *, int);
    int *visited = (int *)malloc(sizeof(int)*G->numV);  //设置标记数组，标记
    for(int i = 0; i < G->numV; i++)visited[i] = 0;
    for(int i = 0; i < G->numV; i++)
        if(!visited[i])
            DFS(G, visited, &G->adjlist[i], i);
}

void DFS(ALGraph *G, int *visited, VertexNode *v, int index){
    //初始化第一个结点
    printf("%c ", v->info);   //打印传入的结点
    visited[index] = 1; 
    for(EdgeNode *w = v->firstEdge; w;  w= w->next){    //遍历所有节点
        if(w){  //如果有邻接的节点
            if(!visited[w->index]){ //还没有访问的节点
                DFS(G, visited, &G->adjlist[w->index], w->index);
            }
        }
    }
}

