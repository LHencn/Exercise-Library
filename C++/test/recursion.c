/*************************************************************************
	> File Name: recursion.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 19时11分45秒
 ************************************************************************/

#include<stdio.h>
//尾递归
int fab(int n, int protect) {
    if (n == 0) {
        return protect;
    }
    protect = n * protect;
    return fab(n - 1, protect);
}

int main() {
    fab(4, 1);
    return 0;
}
