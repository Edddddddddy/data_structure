#include <stdio.h>
#include <stdlib.h>


int main(){
    
    biTree *T = (struct biTree*)malloc(sizeof(struct biTree));
    T = create(T);

    inOrder(T);
    return 0;
}
