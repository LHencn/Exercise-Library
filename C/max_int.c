/*************************************************************************
	> File Name: max_int.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月20日 星期四 19时22分46秒
 ************************************************************************/

#include<stdio.h>
#define P(func) {\
    printf("%s = %d\n", #func, func); \
}

int is_prime(int x);
int max_int(int n, ...);

int main () {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) 
            printf("%d ", i);
    }    

    P(max_int(3, 1, 2, 3));
    P(max_int(4, 1, 2, 3, 4));
    P(max_int(5, 1, 2, 3 ,9 ,10));
    return 0;
}


