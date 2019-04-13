/*************************************************************************
	> File Name: paLouTi.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月08日 星期六 19时27分12秒
 ************************************************************************/


#include <stdio.h>

int main() {

    int a[51] = {0};
    a[1] = 0;
    a[2] = a[3] = 1;
    int i;
    for (i = 4; i < 51; i++) {
        a[i] = a[i - 2] + a[i - 3];
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", a[n]);
    }
    return 0;
}
