/*************************************************************************
	> File Name: 1.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年11月08日 星期四 18时12分36秒
 ************************************************************************/

#include<stdio.h>

#define swap(a, b) { \ }

void quick_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z;
    swap(num[l], num[(l + r) >> 1]);
    z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
}


int* twoSum(int *nums, int numsSize, int target) {
    int *temp_num = (int *)malloc(sizeof(int) *(numsSize));
    memcpy()
}
