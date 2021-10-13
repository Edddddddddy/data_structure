#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createSQueueS.cpp"


void assign(biTree **ptr){
    for(int i = 0; i < 6; i++){
        ptr[i]->data = 'b';
    }
}

int main(){
    int count = 0;
    biTree* *ptr = (biTree* *)malloc(sizeof(biTree*)*6); 
    for(int i = 0; i < 6; i++){
        ptr[i] = (biTree*)malloc(sizeof(biTree*)); 
        ptr[i]->data = 'a';
        printf("%c ", ptr[i]->data);
    }
    assign(ptr);
    printf("\n");
    for(int i = 0; i < 6; i++) printf("%c ", ptr[i]->data);
    return 0;
}
