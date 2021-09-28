#include <stdio.h>
#include <stdlib.h>

int delMin(int *arr, int len){
    if(len == 0) return 0;
    int pos = 0;
    int value = *arr, minPos = 0;
    for (int i = 0; i < len; i++){
        if(value > *(arr + i)) {
            value = *(arr + i);
            minPos = i;
        }
    }
    *(arr + minPos) = *(arr + len - 1);
    *(arr + len - 1) = NULL;
    return value;
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

    int value = delMin(arr, n);

    printf("结果是 %d", value);

    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }

    return 0;
}