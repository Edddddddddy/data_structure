
/*
    堆排序
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int &a, int &b){
    int tmp = b;
    b = a;
    a = tmp;
}


void heapAdjust(int *arr, int k, int len){
    //找k最大的孩子，交换k
    arr[0] = arr[k];
    for(int i = 2*k; i <= len; i *= 2){ 
        //判断左右孩子大小
        if(i < len && arr[i] < arr[i+1]) i++;
        //若孩子小，则退出
        if (arr[0] >= arr[i]) break;
        //否则交换
		else {
			arr[k] = arr[i];
			k = i;//继续向下调整
		}
    }
    arr[k] = arr[0];
}

void buildMaxHeap(int *arr, int len){
    //初始建堆
    for(int i = len /2; i > 0; i--)
        heapAdjust(arr, i, len);
}


void heapSort(int *arr, int len){
    //创建大根堆
    buildMaxHeap(arr, len); 

    for (int i = len; i >=1; i--){
        printf("%d ", arr[1]);
        swap(arr[i], arr[1]);
        heapAdjust(arr, 1, i-1);
    }
}

int main(){
    int arr[] = { 0,9,3,4,10 };
	heapSort(arr,4);
    return 0;
}
