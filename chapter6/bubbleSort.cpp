
/*
    
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int len){
    for(int i = 0; i < len-1; i++){    //j和j+1交换，len-1
        int flag = 0;   //标志是否有操作
        for(int j = 0; j < len-1; j++){    
            int tmp;
            if(arr[j] > arr[j+1]){  //下面小的和上面大的交换
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 1;
            }
        }
        if(!flag) break;    //遍历结束
    }
}

int main(){
    
    int arr[10] = { 9,3,4,10,8,5,7,12,10,15 };
	bubbleSort(arr, 10);
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    return 0;
}
