/*************************************************************************
	> File Name: zifu.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月13日 星期四 15时31分02秒
 ************************************************************************/
#include <stdio.h>
void upper_case_count(char string[31]) {
    // 请在下面实现统计并输出大写字母个数的功能
    int sum = 0;
    for (int i = 1; i <= 30; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') 
        	sum++;     
     }
	printf("%d\n", sum);
}
void lower_case_count(char string[31]) {
    // 请在下面实现统计并输出小写字母个数的功能
    int sum = 0;
    for (int i = 1; i <= 30; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') 
        	sum++;     
     }
	printf("%d\n", sum);
}
void digit_count(char string[31]) {
    // 请在下面实现统计并输出数字个数的功能
    int sum = 0;
    for (int i = 1; i <= 30; i++) {
        if (string[i] >= '0' && string[i] <= '9') 
        	sum++;     
     }
	printf("%d\n", sum);
}
void space_count(char string[31]) {
    // 请在下面实现统计并输出空格个数的功能
    int sum = 0;
    for (int i = 1; i <= 30; i++) {
        if (string[i] == ' ') 
        	sum++;     
     }
	printf("%d\n", sum);
}

int main() {
    char string[31];
    int i = 1;
    while (scanf("%c", &string[i++]) != EOF) {if (i == 31) break;}
    
    upper_case_count(string);
    lower_case_count(string);
    digit_count(string);
    space_count(string);
    return 0;
    
}

