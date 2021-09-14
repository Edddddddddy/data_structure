#include <cstdio>
#include <stdlib.h>
#include <stdio.h>


int findMain(int *arr, int len){
    int mainNum = arr[0], count = 1;
    int mainCount = 0;

    for (int i = 1; i < len; i++){
        if (arr[i] != mainNum) {
            if(count>0){
                count--;
            }
            else {
                count = 1;
                mainNum = arr[i];
            }
        }
        else count++;
    }
    if (count){
        for(int i = 0; i < len; i++){
            if (arr[i] == mainNum){
                mainCount++;
            }
        }
        if(mainCount > len/2)
            return mainNum;
        else
            return -1;
    }else
        return -1;
    return mainNum;
}

int main(){
    int arr[] = {2,2,5,5,5,5,2,2};

    int len = sizeof(arr)/ sizeof(int);
    int mainNum = findMain(arr, len);
    printf("%d", mainNum);
    return 0;
}