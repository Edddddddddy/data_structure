
/*
    将满二叉树先序遍历序列编程后序遍历序列
    分析：
        找到先序去掉root后的half，分成两半，之后递归操作两半序列
        直到l1>h1（二分查找思想），然后开始填充后序遍历序列
        *注意half和l1 h1 l2 h2 关系
        
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"

void preToPost(char *arrPre, char* *arrPost, int l1, int h1, int l2, int h2){
    int half;
    if(l1 <= h1){
        half = (h1-l1)/2;   //root左孩子的最右下节点作为half
        *(*arrPost + h2) = *(arrPre + l1);
        preToPost(arrPre, arrPost, l1 + 1, l1 + half, l2, l2+half-1);
        preToPost(arrPre, arrPost, l1 + half+1, h1, l2+half, h2-1);
    }
}


int main(){
   char arrPre[] = {'A','B','D','M','C','F','G'};
   char *arrPost = (char *)malloc(sizeof(char)*7);
   preToPost(arrPre, &arrPost, 0, 6, 0, 6);
   for (int i = 0; i < 7; i++)
   {
       printf("%c ", arrPost[i]);
   }

   return 0;
}
