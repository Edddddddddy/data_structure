#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

int *mergeList(int *l1, int *l2, int len1, int len2){
    int *l = (int *)malloc(sizeof(len1 + len2));
    int i = 0, j = 0, k = 0;
    for (; i < len1 && j < len2; ){
        if(*(l1 + i) < *(l2 + j)) *(l + k++) = *(l1+i++);
        else *(l + k++) = *(l2 + j++);
    }

    for(;i < len1; i++) *(l + k++) = *(l1+i);
    for(;j < len2; j++) *(l + k++) = *(l2+j);

    return l;
}

int main(){
    int l1[] = {1,2,2,3,4,7,8,9};
    int l2[] = {2,2,4,4,5,7,7,10,11,12,22};

    int len1 = sizeof(l1)/sizeof(int);
    int len2 = sizeof(l2)/sizeof(int);

    int *res = mergeList(l1, l2, len1, len2);

    for (int i = 0; i < len1 + len2; i++) {
        printf("%d ", *(res + i));
    }
    return 0;
}