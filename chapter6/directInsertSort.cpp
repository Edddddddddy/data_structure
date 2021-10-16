
/*
    直接插入排序
*/

#include <stdio.h>
#include <stdlib.h>

void directInsertSort(int *arr, int len){
    /*
        1 一个一个数插进去
        2 从头开始遍历当前数组，如果发现 要插入的数 小于当前数组中的某一个数，则那个数开始向后挪一位
                                    否则 排在最后
    */
    int nowN ;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j]){
                nowN = arr[i];
                for(int k = i - 1; k >= j; k--){
                    arr[k+1] = arr[k];
                }
                arr[j] = nowN;
            }
        }
    }
}

int main(){
    int arr[] = {5,3,4,10,8,9,7,12};
    directInsertSort(arr, 8);
    for(int i = 0; i < 8; i++) printf("%d ", arr[i]);

    return 0;
}
