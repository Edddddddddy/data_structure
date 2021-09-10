#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int len){
    int tmp;
    for(int i = 0; i < len/2; i++){
        tmp = *(arr + i);
        *(arr+i) = *(arr+len-i-1);
        *(arr+len-i-1) = tmp;
    }
}

int main(){
    int n;
    printf("enter:n=");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(n));
    printf("enter nums:");
    for(int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }

    printf("before:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    reverse(arr, n);

    printf("after:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}