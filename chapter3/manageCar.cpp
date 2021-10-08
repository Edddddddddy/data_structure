/*
    重排大小为10的数组
    分析：
        创建一个大小为4的栈用于存储P，迭代遍历arrA，如果栈没满pushP入栈，如果栈满时pop栈中所有P并装入arrB，并将下一个T装入arrB，若
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/createStack.cpp"

void manageCar(char *arrA, char *arrB, Stack *s){
    int numP = 0, j = 0;
    char c;
    for (int i = 0; arrA[i]; i++){
        if(arrA[i] == 'T' && numP < 4){
            push( s, arrA[i]);  
        }
        else if(arrA[i] == 'P' && numP == 4){  
            if(!empty(s)){
                c = top(s);
                pop(s);
                arrB[j++] = c;
                numP = 0;
            }
            arrB[j++] = arrA[i];
        }
        else if(arrA[i] == 'T' && numP == 4){
            arrB[j++] = arrA[i];
            numP = 0;
        }
        else if(arrA[i] == 'P' && numP < 4){
            arrB[j++] = arrA[i];
            numP++;
        }
    }



    // int i = 0, passengerCar = 0, j = 0;
    // char c;
    // for (; arrA[i] == 'P' || arrA[i] == 'T'; i++){
    //     if(arrA[i] == 'T' && passengerCar < 4){
    //         push(s, arrA[i]);
    //     }
    //     else {
    //         if(passengerCar == 4){
    //             while(!empty(s)){
    //                 c = top(s);
    //                 pop(s);
    //                 arrB[j++] = c;
    //                 passengerCar = 0;
    //             }
    //         }
    //         arrB[j++] = arrA[i];
    //         passengerCar++; 
    //     }
    // }
    // while(!empty(s)){
    //     c = top(s);
    //     pop(s);
    //     arrB[j++] = c;
    // }
}

int main(){
    int size = 10;
    char arrA[] = {'P','T','T','P','T','P','P','T','T','P','P','P','T','T','P'};
    char arrB[20] = {};
    Stack *s = createStack(size);
    manageCar(arrA, arrB, s);
    for (int i = 0; i < size; i++)printf("%c ", arrB[i]);
    return 0;
}
