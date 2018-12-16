/*************************************************************************
	> File Name: 201809-2.1.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月15日 星期六 19时17分30秒
 ************************************************************************/
//结尾较小与开始较大的做差
#include<stdio.h>
#define max 2000
typedef struct Data {
    int b, e;
} Data;

Data arr[max + 5];

int count(Data &x, Data &y) {
    int b = x.b > y.b ? x.b : y.b;
    int e = x.e < y.e ? x.e : y.e;
    if (e < b) return 0;
    return (e - b);
}

int main() {
    int n, ans = 0;
    Data temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr[i].b, &arr[i].e);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &temp.b, &temp.e);
        for (int j = 0; j <= n; j++) {
            ans += count(arr[j], temp);
        }
    }
    printf("%d\n", ans);
    return 0;

}
