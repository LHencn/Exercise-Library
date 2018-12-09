/*************************************************************************
	> File Name: 1.binary_search.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年11月06日 星期二 19时27分01秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>


// 1 2 4 5
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail)  {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}



// 1111111100000000找到最后一个1的位置
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        //printf("head = %d, tail = %d\n", mid, mid + 1);
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//000000000011111111 找到第一个1
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

#define P(func) {\
    printf("%s = %d\n", #func, func); \
}

int main() {
    int arr1[10] = {1,2,3,4,5,6,7,8,9};
    int arr2[10] = {1,1,1,0,0,0,0,0,0,0};
    int arr3[10] = {0,0,0,1,1,1,1,1,1,1};
    P(binary_search1(arr1, 10, 3));
    P(binary_search2(arr2, 10));
    P(binary_search3(arr3, 10));
    return 0;
}
