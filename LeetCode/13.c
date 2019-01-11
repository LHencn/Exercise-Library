/*************************************************************************
	> File Name: 13.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月11日 星期五 18时30分14秒
 ************************************************************************/

#include<stdio.h>

int romanToInt(char *str) {
    int sum = 0;
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case 'I': {
                if (str[i + 1] == 'V') {
                    sum += 4;
                } else if (str[i + 1] == 'X') {
                    sum += 9;
                } else {
                    sum += 1;   
                }
                break;
            }
            case 'X': {
                if (str[i + 1] == 'L') {
                    sum += 40;
                } else if (str[i + 1] == 'C') {
                    sum += 90;
                } else if (str[i - 1] == 'I') {
                    break;
                } else{
                    sum += 10;
                }
                break;
            }
            case 'C': {
                if (str[i + 1] == 'D') {
                    sum += 400;
                } else if (str[i + 1] == 'M') {
                    sum += 900;
                } else if (str[i - 1] == 'X') {
                    break;
                } else {
                    sum += 100;
                }
                break;
            }
            case 'V': {
                if (str[i - 1] == 'I') break; 
                sum += 5;
                break;
            }
            case 'L': {
                if (str[i - 1] == 'X') {
                    break;
                } else {
                    sum += 50;
                    break;
                }
            }
            case 'D': {
                if (str[i - 1] == 'C') {
                    break;
                } else {
                    sum += 500;
                    break;
                }
            }
            case 'M': {
                if (str[i - 1] == 'C') {
                    break;
                } else {
                    sum += 1000;
                    break;
                }
            }
        }
    }
    return sum;
}

int main() {
    char str[50];
    scanf("%s", str);
    int n = romanToInt(str);
    printf("%d\n", n);
    return 0;
}
