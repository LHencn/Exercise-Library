/*************************************************************************
	> File Name: fprintf.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月13日 星期四 18时54分47秒
 ************************************************************************/


#include <stdio.h>

int main() {
    
    int n;
    char str[100];
    FILE *fout = fopen("/dev/null", "w");
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", fprintf(fout, "%d", n));
    }
    return 0;
}
