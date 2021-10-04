#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include "./createLink.cpp"


int main(){
    struct Link *h = createLink(0);
    
    printLink(h);

    

    return 0;
}
