#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

int deleteRepition(int *arr, int len){
    int k = 0;
    for (int i = 0; i < len ; i++){
        if (*(arr + i) - *(arr + i + 1)){
            *(arr + k++) = *(arr + i);
        }
    }
    if (*(arr + len - 1) == *(arr + len)){  //如果 存储空间中 arr后一个数正好与arr最后一个数相等，单独处理
        *(arr + k++) = *(arr + len - 1);
    }
    return k; 
}

int main(){
    int arr[] = {1,2,2,3,3,3,3,4,5,6,7,7};
    int len = sizeof(arr)/ sizeof(int );

    len = deleteRepition(arr, len);

    for(int i = 0; i < len ; i ++){
        printf("%d ", *(arr+i));
    }
    
    return 0;
}