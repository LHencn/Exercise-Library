/*************************************************************************
	> File Name: pra.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月30日 星期二 21时58分02秒
 ************************************************************************/

#include<stdio.h>

int main() {

    int a = 5; 
    int b = 6;
    a = a + b - (b = a);
    printf("a = %d ,b = %d", a, b);
    return 0;
}
