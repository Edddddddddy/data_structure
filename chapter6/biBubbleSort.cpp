
/*
    双向冒泡排序
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int &a, int &b){
    int tmp = b;
    b = a;
    a = b;
}

void biBubbleSort(int* arr, int len){
    int low = 0, high = len - 1;    //len-1保证和后一个交换
    int flag = 1;
    int tmp;
    while(low < high){
        for(int i = low; i < high; i++){
            if(arr[j] > arr[j + 1]){    //大的向下
                swap(arr[j], arr[j+1]);
                flag = 1;                
            }
        }
        high--;
        for(int j = high; j > low; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
                flag = 1;
            }
        }
        low++;
    }
}

int main(){
    int arr[10] = { 9,3,4,10,8,5,7,12,10,15 };
	bubbleSort(arr, 10);
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    return 0;
}