#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

int findMissMin(int arr[], int n){
    int *A, i;  //数组 标记
    A = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) A[i] = 0;   //A赋初值为0
    for (i = 0; i < n ; i++){   
        if (arr[i] > 0 && arr[i] < n) A[arr[i] - 1] = 1;    //将A中 下标为（arr[i]-1）且 在1～n之间 的元素 赋值为1
    }
    
    for(i = 0; i < n; i++){ //扫描A，找到最小目标
        if (A[i] == 0) break;  
    }
    return i + 1;   //返回结果
}


int main(){
    int arr[] = {1,2,5};
    int len = sizeof(arr)/sizeof(int);
    int maxMin = findMissMin(arr, len);
    printf("最小整数是%d", maxMin);
    return 0;
}