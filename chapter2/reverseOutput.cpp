#include <stdlib.h>
#include <stdio.h>
#include "../include/createLink.cpp"

void reverseOutput(Link *p){
    if (p == NULL) return;
    else {
        reverseOutput(p->next);
        printf("%d ", p->type.data);
    }
}


int main(){
    Link *p = createLink(0);
    reverseOutput(p->next);
    printf("\n");
    return 0;
}