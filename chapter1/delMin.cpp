#include <stdio.h>
#include <stdlib.h>

void delMin(int *arr, int len){
    if(!len){
        printf("数组为空");
        return;
    }
    int min = *arr, minPos = 0;
    for(int i = 0; i < len; i++){
        if(min > *(arr+i)){
            min = *(arr + i);
            minPos = i;
        }
    }
    //找到最小值元素后，将最后一个元素
    *(arr + minPos) = *(arr + len - 1);
    *(arr + len - 1) = NULL;
}

int main(){
    int n;
    printf("enter:n=");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(n));
    printf("enter:");
    for(int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }

    delMin(arr, n);
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }

    return 0;
}