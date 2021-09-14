#include <stdlib.h>
#include <stdio.h>

int  findX(int *arr, int x, int len){ 
    int high = len - 1, low = 0, mid;
    while(low < high){
        mid = (high + low)/ 2;
        x <= mid ? high = mid : low = mid + 1;    
    }
    return mid;


}

int main(){
    int arr[] = {2,2,4,4,5,7,7,10,11,12,22};

    int res = findX(arr, 10, sizeof(arr)/sizeof(int));

    printf("结果是第%d个", res);
    return 0;
}