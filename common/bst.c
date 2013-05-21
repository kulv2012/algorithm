#include <stdio.h>
//gcc  -std=c99 bst.c 
#define MAX_WEIGHT 9999999

/*pb[]  : 每个节点的概率大小
 *root  : 返回的根信息数组
 *n     : 节点数目
 *return：总搜索代价
 * */
float bst( float pb[], int *root, int n){
    float cost[n][n] ;//i到j的搜索成本期望值
    float psum[n][n] ;//i到j的权重之和
    for( int i=-1; i<n; i++ ){
        psum[i+1][i] = 0 ;
        cost[i+1][i] = 0 ;
    }

    for(int len = 1; len <= n; ++len ){// 子树长度从1到n，依次求出其最优结构
        for(int beg = 0; beg <= n-len; ++beg ){
            int end = beg + len -1 ;
            cost[beg][end] = MAX_WEIGHT ;
            psum[beg][end] = psum[beg][end-1] + pb[end] ;//逐步累积求beg到end的概率之和。
            for( int tmp=beg; tmp <= end; ++tmp ){//循环扫描,已beg-end之间的任何一个节点当根，找出最优的子树根
                float tcost = cost[beg][tmp-1] + cost[tmp+1][end] + psum[beg][end] ;
                if( cost[beg][end] > tcost) {
                    cost[beg][end] = tcost ;
                    root[beg*n + end] = tmp ;
                }
            }
        }
    }
}


int main(int argc, char* argv[]) {

    printf("hello kulv\n");
    float probability[] = {0.24, 0.18, 0.09, 0.13, 0.3, 0.06 } ;
    int count = sizeof(probability) / sizeof(float) ;
    int root[count][count] ;
    float mincost = bst( probability, (int*)root, count) ;
    printf("min cost is:%f\n", mincost);
    for(int i=0; i< count; ++i){
        for(int j=0; j< count; ++j ){
            if( j< i) printf("\t");
            else printf("%d\t", root[i][j]);
        }
        printf("\n");
    }
}

