#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

int findMidNum(int *l1, int *l2, int len){
    int count = 0;

    for (int i =0, j = 0; *l1 && *l2; ){
        if(count++ == len) return l1[i] < l2[j] ? l1[i] : l2[j];
        else l1[i] < l2[j] ? i++ : j++;
    }
    
}


int main(){
    int l1[] = {1,2,3,5,6,6,7};
    int l2[] = {1,3,5,5,6,8,9};

    int len = sizeof(l1)/sizeof(int);
    
    int midNum = findMidNum(l1, l2, len);

    printf("中位数是：%d ", midNum);
    
    return 0;
}