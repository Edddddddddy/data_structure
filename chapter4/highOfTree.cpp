
/*
    求csTree表示的树的树高
    分析：
        找当前节点左右孩子中高度高的一棵+1
*/

#include "../include/createCSTree.cpp"
#include <stdio.h>
#include <stdlib.h>


int getHigh(Tree *T){
    int lhigh, rhigh;
    if(!T) return 0;    //递归出口为叶子结点
    else {
        lhigh = getHigh(T->fch);
        rhigh = getHigh(T->nsib);
        
        //下面的判断中，lhigh表示孩子，所以要+1
        //rhigh表示兄弟，因此不用+1
        if(lhigh + 1 > rhigh) return lhigh + 1; 
        else return rhigh; 
    }
}

int main(){
    
    Tree *T = (Tree *)malloc(sizeof(Tree *));
	T = create(T);
	int high = 0;
	high = getHigh(T);
	printf("树的高度为：%d", high);
    return 0;
}
