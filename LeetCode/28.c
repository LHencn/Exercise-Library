/*************************************************************************
	> File Name: 28.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月13日 星期日 18时51分59秒
 ************************************************************************/

#include<stdio.h>

int strStr(char *haystack, char *needle) {
    int len = 0;
    int pos[256] = {0};
    memset(pos, -1, sizeof(pos)); //
    for (; needle[len]; len++) pos[needle[len]] = len;
    int i = 0, len2 = strlen(haystack);
    while (i + len <= len2) {
        int j = 0;
    }
}
