/*
    递归计算函数
    分析：
        
*/

struct Recursion {
	int no;
	int val;
};
struct Stack{
	Recursion *arr;
	int len;
	int top;
};

#include <stdio.h>
#include <stdlib.h>
#define TYPE Recursion

Stack *createStack(int size) {
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));//给栈分配空间
	stack->arr = (TYPE *)malloc(sizeof(TYPE)*size);//给内存首地址分配空间，大小用户指定
	stack->len = size;//栈容量
	stack->top = -1;//栈顶下标，当前无元素，故为-1
	return stack;
}

int getP(Stack *s, int n, int x){
    if(n==0){
        return 1;
    }
    int fv1 = 1, fv2 = 2 * x;   //前两个元素已知，之后每个元素都有前两个元素算得
    //从n到2的顺序将Recursion压入栈
    for (int i = n; i >= 2; i--){
        s->top++;
        s->arr[s->top].no = i;
    }
    //开始从栈顶处理结果，每次迭代更新fv1和fv2储存Pn-2和Pn-1
    while(s->top >= 0){
        s->arr[s->top].val = 2 * x * fv2 - 2 * (s->arr[s->top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = s->arr[s->top].val;
        s->top--;
    }
    return fv2;
}

int main(){
    int n = 2, x = 2, p;
    Stack *s = createStack(n);
    p = getP( s, n, x);
    printf("%d", p);
    return 0;
}
