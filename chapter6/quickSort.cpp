
/*
    加速排序：
        
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 该方法将arr的第一个元素放置到arr中正确的位置，并且达成该元素左边都小于pivot，右边都大于pivot
 * 
 * @param arr 
 * @param low 开始
 * @param high 结束
 * @return int 
 */
int partition(int *arr, int low , int high){
    int pivot = arr[low];   //把第一个元素当成枢纽元素
    while(low < high){  //直到交汇表示分组结束
        //从尾巴开始查找一个arr中小于pivot的元素，放置到low
        while(low < high && arr[high] >= pivot) --high;
        arr[low] = arr[high];
        //从low开始查找一个arr大于pivot的元素
        while (low < high && arr[low] <= pivot) ++low;
        //
        arr[high] = arr[low];
    }
    //low这时候已经被移动走了，这里是pivot的位置
    arr[low] = pivot;
    return low;
}

void quickSort(int *arr, int low, int high){
    if(low < high){
        int privotPos = partition(arr, low, high);  //获取存亡枢纽的位置，划分子表
        quickSort(arr, low, pivotPos-1);    //左子表
        quickSort(arr, pivotPos + 1, high);     //左子表
    }
}


int main(){
    int arr[] = { 5,3,4,10,6,11,12 };
	quickSort(arr,0,6);
	return 0;
}
