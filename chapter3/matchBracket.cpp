#include <stdio.h>
#include <stdlib.h>

struct LinkQueue{
    struct Link *front, *rear;
};

struct Stack{
    char* arr;
    int len;
    int top;
};

int main(){
    int n;
    char letter ;
    struct LinkQueue *lq;
    struct Stack *s;
    LinkQueue *create();
}