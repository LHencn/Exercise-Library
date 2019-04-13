/*************************************************************************
	> File Name: test.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月23日 星期日 13时04分57秒
 ************************************************************************/

#include <stdio.h>

#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

#define MAX(a, b) ({ \
    typeof (a) _a = a; \
    typeof (b) _b = b; \
    (void) (&_a == &_b); \
    (_a) > (_b) ? (_a) : (_b); \
})

int main() {
    P(MAX(2, 3));
    P(5 + MAX(1,  3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    int a = 7;
    P(MAX(a++, 6));
    printf("a = %d\n", a);
    return 0;
}
