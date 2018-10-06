/*************************************************************************
	> File Name: little.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月06日 星期六 12时49分46秒
 ************************************************************************/

#include<stdio.h>

int main() {
    short int x;
    char x0, x1;
    x = 0x1122;
    x0 = ((char *)&x)[0];
    x1 = ((char *)&x)[1];
    printf("%x %x", x0, x1);
    return 0;
}
