/*************************************************************************
	> File Name: a.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月21日 星期日 09时34分15秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void raddix_sort(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65537] = {0};
    for (int i = 0; i < n; i++) cnt[num[i] & 0xffff) + 1]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[((temp[i] >> 16) & 0xffff) + 1]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) num[cnt[(temp[i] >> 16) & 0xffff]++] = temp[i];
    return ;
}

void output(int *num, int n) {
    for (int i = 0; i < n; i++) {
        i && num[i] < num[i - 1] && printf("error");
        printf("%d ", num[i]);
    }
    printf("\n");
    return ;
}
