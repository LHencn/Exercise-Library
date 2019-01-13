/*************************************************************************
	> File Name: 14.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月11日 星期五 19时54分12秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    char temp[50];
    strcpy(temp, strs[0]);
    for (int i = 1; i < strsSize; i++) {
        for (int j = 0; temp[j]; j++) {
            if (temp[j] != strs[i][j]) {
                temp[j] = '\0';
                break;
            }
        }
    }
    const char 
    return temp;
}

int main() {
    char str[3][50] = {"flower", "flight", "float"};
    char *temp = longestCommonPrefix(str, 3);
    printf("%s", temp);
    return 0;
}
