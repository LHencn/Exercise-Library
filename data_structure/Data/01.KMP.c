/*************************************************************************
	> File Name: 01.KMP.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月16日 星期二 15时25分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST(func, a, b) { \
    printf("%s(\"%s\", \"%s\") = %d\n", #func, a, b, func(a, b));\
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    int i = 1, j = 0;
    for ( ; i < strlen(pattern); i++) {
        j = next[i - 1];
        while (j != -1 && pattern[i] != pattern[j + 1]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    i = 0, j = -1;
    for (i = 0; i < strlen(str); i++) {
        while (j != -1 && str[i] != pattern[j]) j = next[j - 1];
        if (pattern[j + 1] == str[i]) j += 1;
        if (pattern[j] == '\0') return i - strlen(pattern) + 1;
    }
    return -1;
}

int main() {
    char str[50];
    char pattern[20];
    scanf("%s%s", str, pattern);
    printf("KMP = %d\n", KMP(str, pattern));
    return 0;
}
