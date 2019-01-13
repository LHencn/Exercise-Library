/*************************************************************************
	> File Name: 5.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月02日 星期三 20时33分55秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 1000

char* longestPalindrome(char *s) {
    


    return 
}

void getNext(char *pattern, int *next) {
    next[0] = -1;
    for (int i = 1, match = -1; pattern[i]; i++) {
        while (match >= 0 && pattern[i] != pattern[match + 1]) {
            match = next[match];
        }
    }
}




int main() {
    
    return 0;
}
