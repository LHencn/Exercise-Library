/*************************************************************************
	> File Name: binary_search.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月23日 星期日 10时41分09秒
 ************************************************************************/


#include <stdio.h>

int binary_search(int *arr, int x, int n) {
    int left = 0, right = n - 1;
    int mix;
    while (left <= right) {
        mix = (left + right) >> 1;
        if (*(arr + mix) == n) return mix;
        else if (*(arr + mix) < n) {
            left = mix;
        }
        else if (*(arr + mix) > n) {
            right = mix;
        }
    }
    return 0;
}

int main() {
    
    return 0;
}
