 
 /*
     该方法能实现求二叉树的宽度
     分析：
        与求深度一样，使用old和curNum两个数记录这一层和上一层的节点个数
        使用width更新最宽个数
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "../include/linkBiTree.cpp"
 #include "../include/createSQueueS.cpp"

 
 int getWidth(biTree *T, SQueueS *sq){
    int width = 0, oldNum = 0, curNum = 0, count = 0;
    biTree *p = T;
    biTree *r = (biTree*)malloc(sizeof(biTree));
    nodeNum(T, &count);
    count++;
    if(p){  //T是否为空树
        enQueueS(sq, p , count);
        oldNum++;
        width = 1;
        while(!isEmptyS(sq)){   //队列非空
            while(oldNum--){    //将上一层所有元素出队
                deQueueS(sq, &r, count); 
                if(r->lchild){  
                    enQueueS(sq, r->lchild, count);
                    curNum++;
                }
                if(r->rchild){
                    enQueueS(sq, r->rchild, count);
                    curNum++;
                }
            }
            curNum > width ? width = curNum : true ;
            oldNum = curNum;
            curNum = 0;
        }
    }
    return width;
}
 
 int main(){
    int count = 0;
    biTree *T = (biTree*)malloc(sizeof(biTree));
    T = create(T);
    nodeNum(T, &count);
    SQueueS *sq = createSQueueS(count + 1);
    printf("该数宽为%d", getWidth(T, sq));
    return 0;
 }
 