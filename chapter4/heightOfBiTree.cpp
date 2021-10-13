
/*
    非递归方法 求二叉树树高
    分析：
        一、使用两个队列，同一层放在同一个队列中，其下一层放在另一个，以此类推
        二、使用一个队列，oldNum记录上一层节点数，即这一次要deQ的次数
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkBiTree.cpp"
#include "../include/createSQueueS.cpp"



int getHigh(biTree *T, int size){
    int high = 0;

    biTree *p = T, *r = (struct biTree*)malloc(sizeof(biTree));
    
    SQueueS *sq1 = createSQueueS(size + 1);
    SQueueS *sq2 = createSQueueS(size + 1);


    enQueueS(sq1, p, size+1);
    while(!isEmptyS(sq1) || !isEmptyS(sq2)){
        if(!isEmptyS(sq1)){
            while(!isEmptyS(sq1)){
                deQueueS(sq1, &r, size + 1);
                if(r->lchild) enQueueS(sq2, r->lchild, size+1);
                if(r->rchild) enQueueS(sq2, r->rchild, size+1);
            }
        }
        else{
            while(!isEmptyS(sq2)){
                deQueueS(sq2, &r, size + 1);
                if(r->lchild) enQueueS(sq1, r->lchild, size+1);
                if(r->rchild) enQueueS(sq1, r->rchild, size+1);
            }
        }
        high++;
    }

    return high;
}

int getHigh2(biTree *T, int size){
    int high = 0, curNum = 0, oldNum = 0;

    biTree *p = T, *r = (struct biTree*)malloc(sizeof(biTree));
    SQueueS *sq = createSQueueS(size + 1);

    enQueueS(sq, p, size+1);
    oldNum++;
    while(!isEmptyS(sq)){
        deQueueS(sq,&r,size+1);
        if(r->lchild){
            curNum++;
            enQueueS(sq, r->lchild, size + 1);
        }
        if (r->rchild) {
			curNum++;
			enQueueS(sq, r->rchild, size+1);
		}
        if (!--oldNum){
            high++;
            oldNum = curNum;
            curNum = 0;
        }
    }
    return high;
}

int main(){
    //公共部分：栈 树 count
    int count = 0;
    struct biTree *T=(struct biTree *)malloc(sizeof(struct biTree));
    T = create(T);
	nodeNum(T,&count);
    
    
    //函数
    // int high = getHigh(T, count);
    int high = getHigh2(T, count);
    printf("一共有%d层", high);
    return 0;
}
