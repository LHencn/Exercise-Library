/*************************************************************************
	> File Name: pra1.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月04日 星期四 10时03分52秒
 ************************************************************************/

#include<stdio.h>

union IP {
    struct {
        unsigned char arr[4];   //无符号字符型可存放最大数字为255，char可存放最大整数为127
    } ip;
    unsigned int num;
};

int main () {
    int a, b, c, d;
    IP ip;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.ip.arr[0] = a;
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d\n", ip.num);
    }
    return 0;
}
