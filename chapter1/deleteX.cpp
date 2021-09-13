#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

void deleteX(int *arr, int x, int len){
	int k=0;

	for (int i = 0; i < len; i++){
		if(arr[i] == x){
			k++;
		}
		else{
			arr[i - k] = arr[i];
		}
	}
	for (int i = 0; i < len - k; i++){
		*(arr + len - k  + i) = NULL;
	}
}


int main() {
	int arr[] = {1,2,3,2,4,2};//也可以手动赋值的
	int len = sizeof(arr) / sizeof(int);
	deleteX(arr,2,len);//要删除的元素也可以有用户输入
	for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}