/*************************************************************************
	> File Name: 201809-2.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月15日 星期六 18时17分16秒
 ************************************************************************/

//由题目区间t-s可知题中区间为左闭右开

#include<stdio.h>
#define max 2000
int main() {
    int a[max + 5][2] = {0}, b[max + 5][2] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &b[i][0], &b[i][1]);
    }
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i][0] <= b[i][0]) {
            if (a[i][1] >= b[i][0] && a[i][1] <= b[i][1]) {
                ans += (a[i][1] - b[i][0]);
            } else if (a[i][1] >= b[i][1]) {
                ans += (b[i][1] - b[i][0]);
            }
        }
        
        if (a[i][0] >= b[i][0] && a[i][0] <= b[i][1]) {
            if (a[i][1] <= b[i][1]) 
                ans += (a[i][1] - a[i][0]);
            else if (a[i][1] >= b[i][1]) 
                ans += (b[i][1] - a[i][0]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
