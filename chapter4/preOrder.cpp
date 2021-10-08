

/*
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createStackS.cpp"

void preOrder(biTree *T, Stack *s){
    biTree *p = T;

    while(p || !empty(s)){
        if(p){  
            printf("%c ", p->data);
            push(s, p);
            p = p->lchild;
        }
        else{
            p = top(s);
            pop(s);
            p = p->rchild;
        }
    }

}


int main(){
    int count = 0;
    biTree *T = (struct biTree *)malloc(sizeof(biTree));
    T = create(T);

    nodeNum(T, &count);

    Stack *s = createStackS(count);

    preOrder(T, s);

    return 0;
}
