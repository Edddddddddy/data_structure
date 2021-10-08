/*
    该提要求我们将数组类似{'H','S','S','H','S','H','H','S','S','H','H'}的数组变成类似{'S','S','S','S'...,'H','H'}的数组
    分析：
        记原数组为A，创建一个新的数组B用于存储排列好的数组；后对原数组进行操作，创建大小为n的栈s，遍历数组A，若为H则入栈s，否则加入B，遍历完成后将s中所有元素装入B
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createStack.cpp"

void trainArrange(char *arrA, char *arrB, Stack *s, int size){

    int j = 0;
    char c;
    for (int i = 0; i < 10; i++){
        if(arrA[i] == 'H') push(s, arrA[i]);
        else arrB[j++] = arrA[i];
    }
    while(!empty(s)) {
        c = top(s);
        pop(s);
        arrB[j++] = c;
    }
}


int main(){
    char arrA[10] = {'H','S','S','H','S','H','H','S','S','H'};
    char arrB[10] = {};
    struct Stack *s = createStack(10);
    trainArrange(arrA, arrB, s, 10);
    for (int i = 0; i < 10; i++){
        printf("%c ", arrB[i]);
    }
    return 0;
}
