/*************************************************************************
	> File Name: statble_sort.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月19日 星期六 11时18分09秒
 ************************************************************************/
/*
 * 稳定排序：插入排序、
 */

#include<stdio.h>

void swap(int &a, int &b) {
    a ^= b ^= a ^= b;
}

void insert_sort(int (&a)[10]) {
    int n = 10;
    for (int i = 0; i < n; i++) {
        for (int j = i; a[j] >= a[j - 1]; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                break;
            }
        }
    }
}

void output(int a[], int n, char *str) {
    printf("%s: \n", str);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
}
int main() {
    int n = 10;
    //scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    //insert_sort(a);
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                if (a[j - 1] >= a[j - 2]) break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    //output(a, n, "insert_sort");

    return 0;
}
