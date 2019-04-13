/*************************************************************************
	> File Name: 11.KMP.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月11日 星期四 20时13分13秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; i < strlen(pattern); i++) {
        int ind = next[i - 1];
        while (ind != -1 && pattern[ind + 1] != pattern[i]) ind = next[ind];
        if (pattern[ind + 1] == pattern[i]) next[i] = ind + 1;
        else next[i] = -1;
    }
    
    for (int i = 0; i < strlen(pattern); i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    int i = 0, ind = -1;
    while (str[i]) {
        while (ind != -1 && pattern[ind + 1] != str[i]) ind = next[ind];
        if (pattern[ind + 1] == str[i]) {
            ind += 1;
        }
        i += 1;
        if (pattern[ind + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

int main() {
    char str[50];
    scanf("%s", str);
    char pattern[20];
    scanf("%s", pattern);
    printf("KMP is %d\n", KMP(str, pattern));

    return 0;
}
