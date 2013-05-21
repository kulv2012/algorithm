#include <stdio.h>
#include <string.h>
//gcc  -std=c99 bracket.c 

int bracket( char *p, int count){
    //返回为0匹配，否则不匹配
    if(*p == '\0') return count ;
    else if(*p == '(') return bracket( p+1, count+1) ;
    else if(count > 0 && *p == ')') return bracket( p+1, count-1) ;
    else if(count <= 0 && *p == ')') return -1 ;
    return bracket( p+1, count);
}

int main(int argc, char* argv[]) {
    char *str = "aaa(bb(()c))";
    int tmp = bracket(str, 0) ;
    printf("bracket result:%s\n", tmp==0?"yes":"no");
    return 0 ;
}

