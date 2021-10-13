
/*
    该方法用于实现结构体单链表
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"


int main(){
   int count = 0;
   biTree *T = (biTree*)malloc(sizeof(biTree));
   T = create(T);
   nodeNum(T, &count);
   

   return 0;
}
