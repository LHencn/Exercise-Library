/*************************************************************************
	> File Name: heap_soat.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年11月06日 星期二 15时54分40秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typedef(a) __temp = a; a = b; b = __temp; \
}

void heap_soat(int *arr, int n) {
    int *p = arr - 1; //下标重映射
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind > 1) {
            if (p[ind] <= p[ind >> 1]) break;
            swap(p[ind], p[ind >> 1]);
            ind >> 1;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {

        }
    }
}






int main() {
    
    return 0;
}
