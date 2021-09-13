#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

void deletePoint(int *arr, int s, int t, int len){
    if (!len) return;
    int i = 0, k = 0;
    for ( ;i < len && *(arr + i) < s ; i++);
    if ( i == len) return;
    for ( ; k < len && *(arr + k) <= t; k++);
    for ( ; k < len; i++,k++) *(arr + i) = *(arr + k);
    for ( int j = 0 ; j < i ; j++) printf("%d ", *(arr + j));
    return;
}

int main() {
	int arr[] = {1,2,3,4,4,6,6,7,8,10};
	int s, t;

    int len = sizeof(arr) / sizeof(int);

    do{
        printf("begin:");
        scanf("%d", &s);
        printf("\nend:");
        scanf("%d", &t);
    }while(s > t);

    
    printf("删除后的arr为：");

    deletePoint(arr, s, t, len);

	return 0;
}