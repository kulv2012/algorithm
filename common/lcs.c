#include <stdio.h>
#include <string.h>
//gcc  -std=c99 lcs.c 


int lcs( char *s1, char* s2, char*outstr ){
    int len1 = strlen(s1), len2 = strlen(s2);
    int common[len1][len2] ;
    int target[len1][len2] ;
    for(int i=0; i< len1; ++i){//依次求出第一个字符串的从0-len1长度，跟第二个字符串的不同长度之间的LCS
        for(int j=0; j < len2; ++j) {//从前到后，利用之前计算的结果。
            if(s1[i] == s2[j]){//尾部的2个字符串相等，递增长度
                common[i][j] = common[i-1][j-1] + 1 ;
                target[i][j] = 0 ;
            }
            else if( common[i-1][j] < common[i][j-1]){
                common[i][j] = common[i][j-1] ;
                target[i][j] = 1 ;
            }
            else {
                common[i][j] = common[i][j-1] ;
                target[i][j] = -1 ;
            }
        }       
    }
    int tmp = 0;--len1; --len2 ;
    while(1){
        if(len1 < 0 || len2 < 0) break ;
        if(target[len1][len2] == 0){
            outstr[tmp++] = s1[len1] ;
            --len1 ;--len2;
        }
        else if( target[len1][len2] == 1)
            --len2 ;
        else --len1 ;
    }
    outstr[tmp] = 0;
    return tmp ;
}

int main(int argc, char* argv[]) {
    char *str1 = "abcdefg" ;
    char *str2 = "abdefg" ;
    char out[1024] ;
    printf("hello kulv\n");
    int len = lcs( str1, str2, out);
    printf("lcs len=%d\nreversed longest common string:%s\n", len, out);
}

