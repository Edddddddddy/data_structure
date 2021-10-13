
/*
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/sequenceTree.cpp"

int findComAncestor(int *arr, int i, int j){
    while(i != j){
        i > j ? i /= 2 : j /= 2;
    }
    return *(arr + i - 1);
}

int main(){
    int count = 7, i = 4, j = 6;
    int *arr = (int *)malloc(sizeof(int) * (count + 2));

    createBiTree(arr, count);

    printf("%d和%d的共同祖先为：%d", i, j, findComAncestor( arr, i, j));


    return 0;
}
