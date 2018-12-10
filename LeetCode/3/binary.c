/*************************************************************************
	> File Name: binary.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年11月08日 星期四 19时09分28秒
 ************************************************************************/

#include<stdio.h>
//二分查找，111111100000000，找最后一个1,将某种问题转化的思维框架

int check(char *s, int len) {
    int num[256] = {0}, cnt = 0;
    for (int i = 0; s[i]; i++) {
        num[s[i]] += 1;
        cnt += (num[s[i]] == 1);
        if (i >= len) {
            num[s[i - len]]--;
            cnt -= (num[s[i - len]] == 0);
        }
        if (cnt == len) return 1;
    }
    return 0;
}

int lengthOfLongestSubstring(char *s) {
    int head = 0, tail = strlen(s), mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (check(s, mid) == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}
