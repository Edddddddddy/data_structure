
/*
    该文件实现归并排序
*/

#include <stdio.h>
#include <stdlib.h>

//静态数组用于暂存
static int *arrB = (int *)malloc(sizeof(int *)* 20);

void merge(int *arr, int low, int mid, int high){
    int k, m, n;

    //暂存数组
    for (int i = low; i <= high; i++ ) arrB[i] = arr[i];

    //low~mid存储小的，mid+1~high存储大的
    for (m = low, n = mid + 1, k = m; m <= mid && n <= high;){
        if (arrB[m] <= arrB[n]) arr[k++] = arrB[m++];   //
		else arr[k++] = arrB[n++];
    }
    while(n <= high) arr[k++] = arrB[n++];
    while(m <= mid) arr[k++] = arrB[m++];
}


void mergeSort (int *arr, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        //先分块
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        //再合并
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[] = { 38,49,65,97,76,13,27 };
	mergeSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)printf("%d ", arr[i]);
    
    return 0;
}
