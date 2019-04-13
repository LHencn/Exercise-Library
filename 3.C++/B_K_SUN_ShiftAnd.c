/*************************************************************************
	> File Name: B_K_SUN_ShiftAnd.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月04日 星期五 07时35分14秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int BF(char *str, char *pattern) {
    for (int i = 0; str[i]; i++) {
        int flag = 1;
        for (int j = 0; pattern[j]; j++) {
            if (str[i + j] == pattern[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    } 
    return -1;
}

void getNext(char *pattern, int *next) {
    next[0] = -1;
    for (int i = 0, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[match + 1] != pattern[i]) match = next[match];
        if (pattern[match + 1] == pattern[i]) match++;
        next[i] = match;
    }
}

int find(char *str, char *pattern, int *next) {
    for (int i = 0, match = -1; i < strlen(str); i++) {
        while (match >= 0 && pattern[match + 1] != str[i]) {
            match = next[match];
        }
        if (pattern[match + 1] == str[i]) match++;
        if (match == strlen(pattern) - 1) return i - match;
    }
    return -1;
}

 

int KMP(char *str, char *pattern, int *next) {
    getNext(pattern, next);
    int loc = find(str, pattern, next);
    return loc;
}

int Sunday(char *str, char *pattern) {
    #define BASE 128
    int code[BASE] = {0}, len = strlen(pattern), max_len = strlen(str);
    for (int i = 0; i < BASE; i++) {
        code[i] = len + 1;
    }
    for (int i = 0; i < len; i++) {
        code[pattern[i]] = len - i;
    }
    int i = 0;
    while (i < max_len) {
        int flag = 1;
        for (int j = 0; j < len; j++) {
            if (str[i + j] == pattern[j]) {
                continue;
            }
            i += code[str[i + len]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
    #undef BASE
}

int ShiftAnd(char *str, char *pattern) {
    #define BASE 128
    int code[128] = {0}, len = 0;
    for (; pattern[len]; len++) {
        code[pattern[len]] |= (1 << len);
    }
    int p = 0;
    for (int i = 0; str[i]; i++) {
        p = (((p << 1) | 1) & code[str[i]]);
        if (p & (1 << (len - 1))) return i - len + 1;
    } 
    return -1;
    #undef BASE 
}



int main() {
    char *str = (char *)calloc(sizeof(char), 50);
    char *pattern = (char *)calloc(sizeof(char), 50);
    int *next = (int *)calloc(sizeof(int), 50);
    while (1) {
    scanf("%s%s", str, pattern);
    printf("BF = %d\n", BF(str, pattern));
    printf("KMP = %d\n", KMP(str, pattern, next));
    printf("Sunday = %d\n", Sunday(str, pattern));
    printf("ShiftAnd = %d\n", ShiftAnd(str, pattern));
    }
   return 0;
}
