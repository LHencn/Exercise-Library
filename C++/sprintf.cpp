/*************************************************************************
	> File Name: sprintf.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月13日 星期四 18时56分43秒
 ************************************************************************/

#include <stdio.h>

int main() {
    
    int n;
    char str[100];
    for (int i = 1, j = 0; i <= 20; i++) {
        j += sprintf(str + j, "%d", i);
    }
    printf("%s", str);
    return 0;
}
