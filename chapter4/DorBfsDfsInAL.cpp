
/*
    测试DFS BFS算法
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createGraphInAL.cpp"


int main(){
    ALGraph *graph = (ALGraph *)malloc(sizeof(ALGraph *));

    createGraphInFile(graph);
    dispGraph(graph);
    dispGraph(graph);

    //广度优先
    // BFSBegin(graph);
    //深度优先
    DFSBegin(graph);
    return 0;
}
