/*************************************************************************
	> File Name: quick_sort.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年11月08日 星期四 14时50分25秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int* quick_sort(int *nums, int numsSize) {
    int key = nums[0];
    int p = 0, q = numsSize - 1;
    while (q != p) {
        do {
            if (nums[q] < key) {
                nums[0] = nums[q];
                break;
            }
        } while (q--);
        do {
            if (nums[p] > key) {
                nums[q] = nums[p];
                break;
            }
        } while (p++);
    }
    nums[p] = key;
    return nums;
}

int main() {
    int a[10] = {2,3,4,5,6,7,1,8,9,10};
    quick_sort(a, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
