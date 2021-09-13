#include <stdlib.h>
#include <stdio.h>

void reverse(int *arr, int len){
    int tmp;
    for (int i = 0; i < len/2; i++){
        tmp = *(arr + i);
        *(arr + i) = *(arr + len - i - 1);
        *(arr + len - i - 1) = tmp;
    }
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
        printf("%d ", arr[i]);
    }

    // 函数
    reverse(arr, n);

    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}