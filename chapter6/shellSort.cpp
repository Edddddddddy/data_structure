
/*
    希尔排序：
        直接插入排序的变化版本，初始化是有一个排序增量，为len/2
        使用直接插入排序堆每一瓣数组排序，到长度为1，结束
*/

#include <stdio.h>
#include <stdlib.h>

void shellSort(int *arr, int len){
    int d = len/2;
    while(d >= 1){  //一直迭代直到d=1
        for (int i = 0; i < d; i++){      
            /*对len/d个数进行直接插入排序，如：0+d，d+2d，d+3d...., 0+d-1, 0+2(d-1)
                                        1+d, 1+2d
            */
            for(int j = i + d; j < len; j += d){
                //找到了逆序元素
                if (arr[j] < arr[j - d]) {
                    //将小的元素向前交换到正确的位置，大的向后平移
					int numK = arr[j], k;//将该值暂存于numK
					for (k = j; numK < arr[k - d]; k -= d) {
						arr[k] = arr[k - d];
					}
					arr[k] = numK;
				}
            }
        }
        d /= 2;
    }
}

int main(){
    int arr[] = { 9,3,4,10,2,5,7,12,10,15 };

	shellSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

    return 0;
}
