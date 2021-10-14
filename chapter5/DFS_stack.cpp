
/*
    使用栈实现深度遍历
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"
#include "../include/createStack.cpp"



void DFS_stack(ALGraph *G, Stack *s){
    /*
        
    */
    //初始化
    int *visited = (int *)malloc(sizeof(int)*G->numV);
    for (int i = 0; i < G->numV; i++) visited[i] = 0;   
    for (int i = 0; i < G->numV; i++){  //访问每个结点
        // 如果已经访问，跳过
        if (visited[i]) continue;
        //处理start
        int v;
        printf("%c ", G->adjlist[i].info);
        visited[i] = 1; 
        push(s, i);
        EdgeNode *p;
        //进入循环
        while (!empty(s)) {
            //处理栈顶元素
			v = top(s);
			pop(s);
			p = G->adjlist[v].firstEdge;

			while (p) { 
				if (!visited[p->index]) {   //新结点
					printf("%c ", G->adjlist[p->index].info);
					visited[p->index] = 1;
					push(s, p->index);
					p = G->adjlist[p->index].firstEdge; //向下再走一步
				}
				else {
					p = p->next;    //p不是新结点，找p->next
				}
			}
			if (p == NULL) pop(s); //p没有后序
		}
    }
}

int main(){
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph *));
    createGraphInFile(G);
    dispGraph(G);
    Stack *s = createStack(10);
    DFS_stack(G,s);

    return 0;
}
