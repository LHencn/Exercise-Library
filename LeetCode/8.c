/*************************************************************************
	> File Name: 8.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月10日 星期四 09时35分18秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 0x7fffffff
#define MIN 0x80000000

int myAtoi(char* str) {
    int flag = 1; //正负号
    int i = 0;
    long long sum = 0;
    for (; str[i]; i++) {
        if (str[i] == ' ') {
            continue;
        }
        if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
            if (str[i] == '-') {
                flag = 0;
            } 
            break;
        } else {
            return 0;
        }
    }
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        sum = sum * 10 + (str[i] - '0');
        if (flag && sum >= MAX) {
            return MAX;
        }
        if (!flag && sum >= -MIN) {
            return MIN;
        }
    }
    printf("%d", sum);
    
        if (flag && sum >= MAX) {
            return MAX;
        }
        if (!flag && sum >= -MIN) {
            return MIN;
        }
    if (!flag) sum = -sum;
    return sum;
}

int main() {
    char str[50];
    while (1) {
        gets(str);
        int n = myAtoi(str);
        printf("%d\n", n);
    }

    return 0;
}
