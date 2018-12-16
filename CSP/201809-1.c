/*************************************************************************
	> File Name: 201809-1.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月15日 星期六 16时44分57秒
 ************************************************************************/

#include<stdio.h>
#define max 10000
int arr[max + 5];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || printf(" ");
        printf("%d", (arr[i - 1] + arr[i] + arr[i + 1]) / ((i == 1 || i == n) ? 2 : 3));
    }
    
    return 0;
}
